use std::collections::BinaryHeap;
use std::cmp::Reverse;

use ac_library::Dsu;
use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        q: usize,
    }
    let mut xy = vec![(0, 0); n+q];
    let mut siz = n;
    for i in 0..n {
        input! { x: usize, y: usize };
        xy[i] = (x, y);
    }
    let mut pq = BinaryHeap::<Reverse<(usize, (usize, usize))>>::new();
    for i in 0..n {
        for j in i+1..n {
            pq.push(Reverse((l1(xy[i], xy[j]), (i, j))));
        }
    }
    let mut uf = Dsu::new(n+q);
    let mut cnt = n;
    for i in 0..q {
        input! {t: usize};
        match t {
            1 => {
                input! {a: usize, b: usize};
                xy[siz] = (a, b);
                for j in 0..siz {
                    pq.push(Reverse((l1(xy[siz], xy[j]), (siz, j))));
                }
                cnt += 1;
                siz += 1;
            }
            2 => {
                if cnt == 1 {
                    println!("-1");
                } else {
                    let mut m = usize::MAX;
                    let mut to_merge = vec![];
                    while let Some(Reverse((d, (u, v)))) = pq.pop() {
                        if !uf.same(u, v) {
                            m = d;
                            to_merge.push((u, v));
                            break;
                        }
                    }
                    while !pq.is_empty() && pq.peek().unwrap().0.0 == m {
                        let Reverse((_d, (u, v))) = pq.pop().unwrap();
                        if !uf.same(u, v) {
                            to_merge.push((u, v));
                        }
                    }
                    for (u, v) in to_merge {
                        if !uf.same(u, v) {
                            uf.merge(u, v);
                            cnt -= 1;
                        }
                    }
                    println!("{}", m);
                }
            }
            3 => {
                input! {u: Usize1, v: Usize1};
                if uf.same(u, v) {
                    println!("Yes");
                } else {
                    println!("No");
                }
            }
            _ => unreachable!()
        }
    }
}

fn l1(p: (usize, usize), q: (usize, usize)) -> usize {
    p.0.abs_diff(q.0) + p.1.abs_diff(q.1)
}