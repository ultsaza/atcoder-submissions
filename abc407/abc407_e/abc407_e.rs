use std::collections::BinaryHeap;
use proconio::input;

fn main() {
    input! {
        t: u64,
    }

    for _ in 0..t {
        input! {
            n: u64,
            a: [u64; 2 * n],
        }
        let mut pq: BinaryHeap<u64> = BinaryHeap::new();
        let mut ans: u64 = a[0];
        for i in 1..n {
            pq.push(a[2*i as usize]);
            pq.push(a[2*i as usize - 1]);
            let x = pq.pop().unwrap();
            ans += x;
            //println!("{}", x)
        }
        println!("{}", ans);
    }
}