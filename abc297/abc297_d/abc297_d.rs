use proconio::input;
fn main() {
    input! {
        mut a: usize,
        mut b: usize,
    }
    if a > b {
        std::mem::swap(&mut a, &mut b);
    }
    println!("{}", f(a, b) - 1);
}

fn f(a: usize, b: usize) -> usize {
    if a == 0 {
        return 0;
    } else {
        return f(b%a, a) + b/a;
    }
}
    