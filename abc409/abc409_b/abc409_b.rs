use proconio::input;

fn main() {
    input! {
        n: usize,
        mut a: [usize; n],
    }

    a.sort_by(|a, b| b.cmp(a));
    let mut ans = 0;

    for i in 0..n {
        if a[i] >= i+1 {
            ans = i+1;
        }
    }
    println!("{}", ans);
}