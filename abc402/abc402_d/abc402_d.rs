use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        n: usize,
        m: usize,
        ab: [(Usize1, Usize1); m],
    }
    let mut cnt = vec![0; n];
    for (a, b) in ab {
        cnt[(a+b)%n] += 1;
    }
    let mut ans= 0;
    for cnt in cnt {
        ans += cnt * (m - cnt);
    }
    println!("{}", ans/2);
}
