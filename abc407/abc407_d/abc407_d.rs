use memoise::memoise_map;
use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
        a: [[u64; w]; h],
    }
    println!("{}", dp(0, h, w, &a));
}

#[memoise_map(b)]
fn dp(b: usize, h: usize, w: usize, a: &Vec<Vec<u64>>) -> u64 {
    let mut res = 0;
    for i in 0..h*w {
        if b >> i & 1 == 0{
            res ^= a[i/w][i%w];
        } 
    }
    for i in 0..h*w {
        if i/w < h-1 && b>>i & 1 == 0 && b>>(i+w) & 1 == 0 {
            res = res.max(dp(b | 1 << i | 1 << (i+w), h, w, a));
        }
        if i%w < w-1 && b>>i & 1 == 0 && b>>(i+1) & 1 == 0 {
            res = res.max(dp(b | 1 << i | 1 << (i+1), h, w, a));
        }
    }
    return res;
}