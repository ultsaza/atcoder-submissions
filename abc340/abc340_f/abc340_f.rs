use proconio::input;

fn main() {
    input! {
        x: i64,
        y: i64,
    }
    let g = gcd(x.abs(), y.abs());
    if g > 2 {
        println!("-1");
        return;
    }
    let (a, b) = ext_gcd(y, -x);
    println!("{} {}", a*2/g, b*2/g);
}

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

fn ext_gcd(a: i64, b: i64) -> (i64, i64) {
    if b == 0 {
        return (1, 0);
    } else {
        let (y, x) = ext_gcd(b, a % b);
        return (x, y - (a / b) * x);
    }
}