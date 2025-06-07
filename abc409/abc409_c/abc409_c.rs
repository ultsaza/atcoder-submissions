use std::collections::BTreeMap;

use proconio::input;

fn main() {
    input! {
        n: usize,
        l: usize,
        d: [usize; n-1],
    }
    let mut cnt: Vec<i64> = vec![0; l];
    let mut acc = 0;
    cnt[0] = 1;
    for i in 0..n-1 {
        acc += d[i];
        acc %= l;
        cnt[acc] += 1;
    }
    let mut ans = 0;
    for i in 0..l/3 {
        ans += cnt[i] * cnt[i+l/3] * cnt[i+2*l/3];
    }
    println!("{}", if l%3 == 0 { ans } else { 0 });
}