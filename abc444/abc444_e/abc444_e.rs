use std::collections::BTreeSet;

use argio::proconio::input;

fn main() {
    input! {
        n: usize,
        d: isize,
        a: [isize; n]
    }
    let mut s = BTreeSet::new();
    s.insert(-2e9 as isize);
    s.insert(2e9 as isize);
    let mut r = 0;
    let mut ans = 0;
    for l in 0..n {
        while r < n {
            let x = s.range(a[r]..).next().unwrap();
            let y = s.range(..=a[r]).next_back().unwrap();
            if a[r] - y >= d && x - a[r] >= d {
                s.insert(a[r]);
                r += 1;
            } else {
                break;
            }
        }
        s.remove(&a[l]);
        ans += r - l;
    }
    println!("{}", ans);
}
