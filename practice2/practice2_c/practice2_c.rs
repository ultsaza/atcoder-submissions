use ac_library::floor_sum;
use argio::proconio::input;
fn main() {
    input! {
        t: usize,
    }
    for _ in 0..t {
        input! {
            n: i64,
            m: i64,
            a: i64,
            b: i64,
        }
        println!("{}", floor_sum(n, m, a, b));
    }
}
