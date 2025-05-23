use proconio::input;

fn main() {
    input! {
        n: usize,
        p: [usize; n],
    }
    let mut ans = vec![0;10009];
    ans[0] = 1;
    for i in 0..n {
        let mut tmp = vec![0;10009];
        for j in 0..10009 {
            if ans[j] > 0 {
                tmp[j] = ans[j];
            }
            if j >= p[i] && ans[j - p[i]] > 0 {
                tmp[j] = ans[j - p[i]] + p[i];
            }
        }
        ans = tmp;
    }
    let cnt = ans.iter().filter(|&x| *x > 0).count();
    println!("{}", cnt);
}