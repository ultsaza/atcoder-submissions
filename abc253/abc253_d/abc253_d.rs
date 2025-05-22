use proconio::input;

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        return a;
    } else  {
        return gcd (b, a%b);
    }
}
fn lcm(a: usize, b: usize) -> usize {
    return a * b / gcd(a, b)
}
fn main() {
    input! {
        n: usize,
        a: usize,
        b: usize,
    }
    let ans = n*(n+1)/2 - a * (n/a) * (n/a + 1)/2 - b * (n/b) * (n/b + 1)/2 + lcm(a, b) * (n/lcm(a, b)) * (n/lcm(a, b) + 1)/2;
    println!("{}", ans);
}