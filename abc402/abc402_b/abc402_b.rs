use std::collections::vec_deque;
use proconio::input;
fn main() {
    input! {
        q: usize,
    }
    let mut deque = vec_deque::VecDeque::new();
    for _ in 0..q {
        input! {
            t: u8,
        }
        if t == 1 {
            input! { x: u64 };
            deque.push_back(x);
        } else {
            println!("{}", deque.pop_front().unwrap());
        }
    }
}