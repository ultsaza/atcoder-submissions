use proconio::input;

fn main() {
    input! {
        n: usize,
        xyzw: [(usize, usize, usize, usize); n],
    }
    let mut g : Vec<Vec<i64>> = vec![vec![0; 1002]; 1002];
    for (x, y, z, w) in xyzw {
        g[x][y] += 1;
        g[x][w] -= 1;
        g[z][y] -= 1;
        g[z][w] += 1;
    }
    let mut ans = vec![0;n+1];
    for i in 0..1001 {
        for j in 1..1001 {
            g[i][j] += g[i][j-1];
        }
    }
    for i in 1..1001 {
        for j in 0..1001 {
            g[i][j] += g[i-1][j];
        }
    }
    for i in 0..=1000 {
        for j in 0..=1000 {
            ans[g[i][j] as usize] += 1;
        }
    }
    for i in 1..=n {
        println!("{}", ans[i]);
    }
}