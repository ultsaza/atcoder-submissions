use proconio::input;
use itertools::Itertools;
use ac_library::Dsu;
use proconio::marker::Usize1;

fn main() {
    input! {
        n: usize,
        m: usize,
        k: u64,
        uvw: [(Usize1, Usize1, u64); m],
    }
    let mut ans = u64::MAX;
    for p in (0..m).combinations(n-1) {
        let mut dsu = Dsu::new(n);
        let mut tmp = 0;
        for p in p {
            let (u, v, w) = uvw[p];
            dsu.merge(u, v);
            tmp += w;
            tmp %= k;
        }
        if dsu.groups().len() != 1 { //全域木かの確認.
            continue;
        }
        ans = ans.min(tmp as u64);
    }
    println!("{}", ans);
}