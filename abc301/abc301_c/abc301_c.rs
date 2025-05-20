use proconio::input;
use proconio::marker::Chars;
fn main() {
    input! {
        mut s: Chars,
        mut t: Chars,
    }
    let n = s.len();
    let mut cnts: i32 = s.iter().filter(|&c| *c == '@').count() as i32;
    let mut cntt: i32 = t.iter().filter(|&c| *c == '@').count() as i32;
    let mut s_c = vec![0; 26];
    let mut t_c = vec![0; 26];
    for i in 0..n {
        if s[i] != '@' {
            s_c[s[i] as usize - 'a' as usize] += 1;
        }
        if t[i] != '@' {
            t_c[t[i] as usize - 'a' as usize] += 1;
        }
    }
    let atcoder = ['a', 't', 'c', 'o', 'd', 'e', 'r'];
    for i in 0..26 {
        if !atcoder.contains(&((b'a' + i as u8) as char)) {
            if s_c[i] != t_c[i] {
                println!("No");
                return;
            }
        }
        if s_c[i] > t_c[i] {
            cntt -= s_c[i] - t_c[i];
        } else if s_c[i] < t_c[i] {
            cnts -= t_c[i] - s_c[i];
        }
        if cnts < 0 || cntt < 0 {
            println!("No");
            return;
        }
    }
    println!("Yes");
}