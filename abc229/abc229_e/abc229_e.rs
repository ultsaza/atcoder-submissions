use proconio::{input, marker::Usize1};
use ac_library::Dsu;
fn main() {
    input! {
        n: usize,
        m: usize,
        mut ab: [(Usize1, Usize1); m],
    }
    let mut ans = vec![0;n];
    let mut edge = vec![vec![];n];
    for (a, b) in ab {
        edge[a].push(b);
    }
    let mut uf = Dsu::new(n);
    let mut cnt = n;
    for i in (0..n).rev() {
        ans[i] = cnt - i - 1;
        for &e in edge[i].iter() {
            if !uf.same(i,e) {
                cnt -=1;
            }
            uf.merge(i,e);
        }
    }
    ans.iter().for_each(|x| println!("{}", x));
}