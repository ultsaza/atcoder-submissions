use memoise::memoise_map;
use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [isize; n]
    }
    let ans = dfs(0, n-1, n, &a);
    println!("{}", ans);
}

#[memoise_map(l,r)]
fn dfs(l: usize, r: usize, n: usize,a: &[isize]) -> isize {
    let t = n - (r - l + 1);
    if l > r {
        return 0;
    }
    if l == r {
        match t%2 {
            0 => {
                return a[l];
            }
            1 => {
                return -a[l];
            }
            _ => unreachable!(),
        }
    }
    match t%2 {
        0 => {
            return isize::MIN.max(dfs(l+1, r, n, a) + a[l]).max(dfs(l, r-1, n, a) + a[r]);
        }
        1 => {
            return isize::MAX.min(dfs(l+1, r, n, a) - a[l]).min(dfs(l, r-1, n, a) - a[r]);
        }
        _ => unreachable!(),
    }
}