use proconio::input;
use std::collections::VecDeque;
use proconio::marker::Chars;
fn main() {
    input! {
        s: Chars,
    }
    let mut stack = VecDeque::new();
    for c in s {
        if stack.len() > 1 {
            let x_1 = stack.pop_back().unwrap();
            let x_2 = stack.pop_back().unwrap();
            if x_1 == 'B' && x_2 == 'A' && c == 'C' {
                continue;
            }
            stack.push_back(x_2);
            stack.push_back(x_1);
        } 
        stack.push_back(c);
    }
    let mut ans = String::new();
    for c in stack {
        ans += &c.to_string();
    }
    println!("{}", ans);
}