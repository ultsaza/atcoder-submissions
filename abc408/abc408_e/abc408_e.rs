use ac_library::Dsu;
use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        m: usize,
        uvw: [(Usize1, Usize1, usize); m],
    }

    let mut uf = Dsu::new(n);

    let mut ans: usize = (1 << 30) - 1;
    for i in (0..30).rev() {
        for (u, v, _w) in uvw.iter().filter(|(_, _, w) | (ans - (1 << i)) | w == (ans - (1 << i))) {
            uf.merge(*u, *v);
        }
        if uf.same(0, n - 1) {
            ans -= 1 << i;
        }
        uf = Dsu::new(n);
    }
    println!("{}", ans);
}