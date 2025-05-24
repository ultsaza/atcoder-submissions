use proconio::{input, marker::Bytes};

fn main() {
    input! {
        s: Bytes
    }
    let mut cntl = vec![vec![0;s.len()+1];26];
    let mut cntr = vec![vec![0;s.len()+1];26];
    for i in 0..s.len() {
        for j in 0..26 {
            if s[i] == b'A' + j as u8 {
                cntl[j][i+1] = cntl[j][i] + 1;
            } else {
                cntl[j][i+1] = cntl[j][i];
            }
        }
    }
    for i in (0..s.len()).rev() {
        for j in 0..26 {
            if s[i] == b'A' + j as u8 {
                cntr[j][i] = cntr[j][i+1] + 1;
            } else {
                cntr[j][i] = cntr[j][i+1];
            }
        }
    }
    let mut ans: u128 = 0;
    for i in 1..s.len()-1 {
        for c in 0..26 {
            ans += cntl[c][i] * cntr[c][i+1];
        }
    }
    println!("{}", ans);
}