use ac_library::dsu;
use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        q: usize
    }
    let mut uf = dsu::Dsu::new(n);
    for _ in 0..q {
        input! {
            t: usize,
            u: usize,
            v: usize
        }
        match t {
            0 => {
                uf.merge(u, v);
            }
            1 => {
                if uf.same(u, v) {
                    println!("{}", 1);
                } else {
                    println!("{}", 0);
                }
            }
            _ => unreachable!()
        }
    }
}
