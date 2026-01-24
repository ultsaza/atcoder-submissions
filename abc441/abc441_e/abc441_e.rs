use ac_library::FenwickTree;
use argio::proconio::{input, marker::Bytes};

fn main() {
    input! {
        n: isize,
        s: Bytes,
    }
    let mut d = vec![0isize; n as usize + 1];
    for (i, &c) in s.iter().enumerate() {
        d[i + 1] = d[i]
            + match c {
                b'A' => 1,
                b'B' => -1,
                _ => 0,
            };
    }
    let mut fw = FenwickTree::new(2 * n as usize + 1, 0isize);
    let mut ans = 0isize;
    for x in d {
        fw.add((n + x) as usize, 1);
        ans += fw.sum(0..((n + x) as usize));
    }
    println!("{}", ans);
}
