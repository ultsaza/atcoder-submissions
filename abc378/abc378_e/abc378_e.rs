use ac_library::FenwickTree;
use proconio::input;

fn main() {
    input! {
        n: usize,
        m: usize,
        a: [usize; n],
    }
    let mut s = vec![0; n+1];
    for i in 0..n {
        s[i+1] = (s[i] + a[i]) % m;
    }
    let mut fw = FenwickTree::new(m,0);
    let mut ans: i64 = 0;
    let mut sum_s: i64 = 0;
    for r in 1..=n {
        ans += r as i64 * s[r] as i64 - sum_s + m as i64 * fw.sum(s[r]+1..m) as i64;
        fw.add(s[r], 1);
        sum_s += s[r] as i64;
    }
    println!("{}", ans);
}