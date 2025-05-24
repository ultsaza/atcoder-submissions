use proconio::{input, marker::Bytes};

fn main() {
    input! {
        mut s: Bytes
    }
    s.reverse();
    let n = s.len();
    let mut cnt = 0;
    let mut ans: usize = 0;
    for i in 0..n {
        let x = (s[i] - b'0' + 10 - cnt) % 10;
        cnt += x;
        cnt %= 10;
        ans += x as usize + 1;
    }
    println!("{}", ans);
   
}