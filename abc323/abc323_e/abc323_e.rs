use ac_library::ModInt998244353 as mint;
use memoise::memoise_map;
use proconio::input;

fn main() {
    input! {
        n: usize,
        x: usize,
        t: [usize; n],
    }
    let mut ans = mint::new(0); 
    let tmin = *t.iter().min().unwrap();
    for i in (x+1).saturating_sub(t[0])..=x {
        ans += dp(i, n, &t, tmin);
    }
    println!("{}", ans);
}

#[memoise_map(x)]
fn dp(x: usize, n: usize,t: &Vec<usize>, m: usize) -> mint {
    if x == 0{
        mint::new(n).inv()
    }
    else {
        let mut res = mint::new(0);
        for i in 0..n {
            if x >= t[i] {
                res += dp(x-t[i], n, t, m);
            }
        }
        res * mint::new(n).inv()
    }
}