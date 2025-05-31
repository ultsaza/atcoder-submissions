use ac_library::{Max, Segtree};
use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        d: usize,
        r: usize,
        h: [Usize1; n],
    }
    let mut dp = vec![0; n];
    let mut a = vec![0; n];
    for i in 0..n {
        a[h[i]] = i;
    }
    let mut seg = Segtree::<Max<i64>>::new(n);
    for i in 0..n {
        seg.set(i, i64::MIN);
    }
    for i in 0..n {
        if i >= d {
            seg.set(a[i-d], dp[a[i-d]]);
        }
        dp[a[i]] = dp[a[i]].max(seg.prod(a[i].saturating_sub(r)..(r+a[i]+1).min(n)) + 1);
    }
    println!("{}", dp.iter().max().unwrap());
}
