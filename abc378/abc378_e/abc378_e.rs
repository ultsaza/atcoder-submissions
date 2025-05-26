use ac_library::{Additive, Segtree};
use proconio::input;
use std::iter::once;

fn main() {
    input! {
        n: usize,
        m: usize,
        a: [usize; n],
    }

    let s = once(0).chain(a.iter().scan(0, |acc, &x| {
        *acc = (*acc + x) % m;
        Some(*acc)
    })).collect::<Vec<_>>();

    let mut seg = Segtree::<Additive<i64>>::new(m);
    let mut ans: i64 = 0;
    let mut sum_s: i64 = 0;
    for r in 1..=n {
        ans += r as i64 * s[r] as i64 - sum_s + m as i64 * seg.prod(s[r]+1..m) as i64;
        seg.set(s[r], seg.get(s[r]) + 1);
        sum_s += s[r] as i64;
    }
    println!("{}", ans);
}