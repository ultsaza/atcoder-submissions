use proconio::input;

fn main() {
    input! {
        n: usize,
        m: usize,
    }
    let mut ans: Vec<Vec<usize>> = vec![];
    for i in 1..11 {
        f(n, m, &mut vec![i], &mut ans, 0);
    }
    println!("{}", ans.len());
    for ans in ans {
        for i in ans {
            print!("{} ", i);
        }
        println!();
    }
}

fn f(n:usize, m:usize, cur: &mut Vec<usize>, ans: &mut Vec<Vec<usize>>, dep: usize) {
    if cur[dep] + 10 * (n-dep-1) > m {
        return;
    }
    if dep == n-1 {   
        ans.push(cur.clone());
        return;
    }
    for i in 10..21 {
        cur.push(cur[dep]+i);
        f(n, m, cur, ans, dep + 1);
        cur.pop();
    }
}