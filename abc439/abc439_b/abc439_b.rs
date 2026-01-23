use argio::proconio::input;

fn main() {
    input! {
        n: usize
    }
    let mut res = n;
    for _ in 0..(1 << 18) {
        if res == 1 {
            println!("Yes");
            return;
        }
        res = f(res);
    }
    println!("No");
}

fn f(mut n: usize) -> usize {
    let mut res = 0 as usize;
    while n != 0 {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}
