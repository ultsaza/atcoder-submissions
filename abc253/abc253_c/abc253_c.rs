use proconio::input;
use std::collections::{HashMap, BinaryHeap};
use std::cmp::Reverse;
fn main() {
    input! {
        q: usize
    }
    let mut mp: HashMap<usize, usize> = HashMap::new();
    let mut pq_mx: BinaryHeap<usize> = BinaryHeap::new();
    let mut pq_mn: BinaryHeap<Reverse<usize>> = BinaryHeap::new();

    for _ in 0..q {
        input! {
            t: usize,
        }
        match t {
            1 => {
                input! {
                    x: usize
                }
                *mp.entry(x).or_insert(0) += 1;
                pq_mx.push(x);
                pq_mn.push(Reverse(x));
            }
            2 => {
                input! {
                    x: usize,
                    c: usize
                }
                *mp.entry(x).or_insert(0) -= c.min(*mp.entry(x).or_insert(0));
            }
            3 => {
                while mp[&pq_mx.peek().unwrap()] == 0 {
                    pq_mx.pop();
                }
                while mp[&pq_mn.peek().unwrap().0] == 0 {
                    pq_mn.pop();
                }
                println!("{}", pq_mx.peek().unwrap() - pq_mn.peek().unwrap().0);
            }
            _ => {}
        }
    }
}