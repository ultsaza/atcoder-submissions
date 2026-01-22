use std::collections::BinaryHeap;

use argio::proconio::input;
use itertools::Itertools;

fn main() {
    input! {
        n: usize,
        k: isize,
        mut x: usize,
        mut a: [isize; n]
    }
    a.sort_by(|a, b| b.cmp(a));
    let d = a.windows(2).map(|x| x[0] - x[1]).collect_vec();
    let mut pq = BinaryHeap::new();
    let mut ch = vec![0; n];
    ch[0] = k;
    pq.push((a[0] * k, ch, 1));
    while let Some((ans, ch, pre)) = pq.pop() {
        println!("{}", ans);
        x -= 1;
        if x == 0 {
            break;
        }
        for i in pre..n {
            if ch[i - 1] > ch[i] {
                let mut nch = ch.clone();
                nch[i] += 1;
                pq.push((ans - d[i - 1], nch, i));
            }
        }
    }
}
