use ac_library::{FenwickTree, fenwicktree};
use argio::proconio::{input, marker::Bytes};

fn main() {
    input! {
        n: usize,
        s: Bytes,
    }
    let mut d = vec![0 as isize; n + 1];
    for i in 0..n {
        d[i + 1] = d[i];
        if s[i] == b'A' {
            d[i + 1] += 1;
        } else if s[i] == b'B' {
            d[i + 1] -= 1;
        }
    }
    let mut fw = FenwickTree::new(2 * n + 1, 0 as isize);
    let mut ans = 0 as usize;
    for i in 0..=n {
        fw.add((d[i] + n as isize) as usize, 1);

        ans += fw.sum(0..(d[i] + n as isize) as usize) as usize;
    }
    println!("{}", ans);
}
