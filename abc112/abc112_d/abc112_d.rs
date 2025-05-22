use proconio::input;

fn main() {
    input! {
        n: usize,
        m: usize,
    }

    let mut ans = 1;

    for g in 1..(m/n + 1) {
        if m%g == 0 {
            ans = g;
        }
    }

    println!("{}", ans);
}