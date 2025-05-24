use proconio::{input, marker::Bytes};

fn main() {
    input! {
        s: Bytes
    }
    let mut cntl:Vec<usize> = vec![0;26];
    let mut cntr:Vec<usize> = vec![0;26];
    for c in s.iter() {
        cntr[(c-b'A') as usize] += 1;
    }
    let mut ans: usize = 0;
    for c in s {
        cntr[(c-b'A') as usize] -= 1;
        for i in 0..26 {
            ans += cntl[i] * cntr[i];
        }
        cntl[(c-b'A') as usize] += 1;
    }
    println!("{}", ans);
}