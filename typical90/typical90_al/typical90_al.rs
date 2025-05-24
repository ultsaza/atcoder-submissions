use proconio::input;

fn main() {
    input! {
        a: u128,
        b: u128,
    }
    let g = gcd(a, b);
    let ans = a * b / g;
    if ans > 10u128.pow(18) {
        println!("Large");
    } else {
        println!("{}", ans);
    }
}

fn gcd(a: u128, b: u128) -> u128 {
    if b == 0{
        a
    } else {
        gcd(b, a%b)
    }
}