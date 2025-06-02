use std::collections::BTreeSet;
use ac_library::Dsu;
use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        m: usize,   
        uv: [(Usize1, Usize1); m],
        k: usize,
        xy: [(Usize1, Usize1); k],
        q: usize,
        pq: [(Usize1, Usize1); q],
    }

    let mut uf = Dsu::new(n);
    for (u, v) in uv {
        uf.merge(u, v);
    }
    let mut st = BTreeSet::<(usize, usize)>::new();
    for (x, y) in xy {
        st.insert((uf.leader(x), uf.leader(y)));
        st.insert((uf.leader(y), uf.leader(x)));
    }
    for (p, q) in pq {
        if st.contains(&(uf.leader(p), uf.leader(q))) {
            println!("No");
        } else {
            println!("Yes");
        }
    }
}