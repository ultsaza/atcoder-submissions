use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        n: usize,
        q: usize,
    }

    let mut a = (1..=n).collect::<Vec<_>>();
    let mut id = 0;

    for _ in 0..q {
        input! {
            t: usize,
        }
        match t {
            1 => {
                input! {
                    p: Usize1,
                    x: usize,
                }
                a[(n +p - id) % n] = x;
            }
            2 => {
                input! {
                    p: Usize1,
                }
                println!("{}", a[(n + p - id) % n]);
            }
            3 => {
                input! {
                    k: usize,
                }
                id = (id + n - (k % n)) % n;
            }
            _ => unreachable!(),
        }
    } 
}