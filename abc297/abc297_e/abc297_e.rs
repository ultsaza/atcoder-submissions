use proconio::input;
use std::cmp::Reverse;
use std::collections::BinaryHeap;

fn main() {
    input! {
        n: usize,
        k: usize,
        a: [usize; n],
    }
    let mut pq = BinaryHeap::new();
    for i in 0..n {
        pq.push(Reverse(a[i]));
    }
    let mut ans = vec![0; k+1];
    for i in 0..k {
        while let Some(u) = pq.pop() {
            if ans[i] == u.0 && i != 0 {
                continue;
            } else {
                ans[i+1] = u.0;
                break;
            }
        }
        for j in 0..n {
            pq.push(Reverse(ans[i+1] + a[j]));
        }
    }
    println!("{}", ans[k]);
}