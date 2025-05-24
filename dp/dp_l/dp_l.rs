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
    if l > r {
        return 0;
    }
    let t = n - (r - l + 1);
    let mut res;
    if l == r {
        match t%2 {
            0 => {
                res = a[l] ;
            }
            1 => {
                res = -a[l] ;
            }
            _ => unreachable!(),
        }
        return res;
    }
    match t%2 {
        0 => {
            res = isize::MIN;
            res=res.max(dfs(l+1, r, n, a) + a[l] as isize).max(dfs(l, r-1, n, a) + a[r] as isize);
        }
        1 => {
            res = isize::MAX;
            res=res.min(dfs(l+1, r, n, a) - a[l] as isize).min(dfs(l, r-1, n, a) - a[r] as isize);
        }
        _ => unreachable!(),
    }
    return res;
}