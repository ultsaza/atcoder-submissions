use proconio::{input, marker::Bytes};

fn main() {
    input! {
        s: Bytes,
        k: usize,
    }
    let mut e = vec![0;s.len()+1];
    for i in 0..s.len() {
        if s[i] == b'.' {
            e[i+1] = e[i] + 1;
        } else {
            e[i+1] = e[i];
        }
    }
    let mut ans = 0;
    let mut l = 0;
    let mut r = 0;
    while r <= s.len() {
        if e[r] - e[l] <= k {
            ans = ans.max(r - l);
            r += 1;
        } else {
            l += 1;
        }
    }
    println!("{}", ans);
}