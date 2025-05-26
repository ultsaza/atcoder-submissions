use std::collections::BTreeMap;
use proconio::input;

fn main() {
    input! {
        n: usize,
        sc: [(usize, usize); n]
    }
    let mut mp = BTreeMap::<usize, usize>::new();
    for (s, c) in sc {
        let mut a = s;
        let mut cnt = 0;
        while a%2 == 0 {
            a /= 2;
            cnt += 1;
        }
        *mp.entry(a).or_insert(0) += (1<<cnt) * c;
    }
    let ans = mp.iter().fold(0, |res, (_, v)| {
        res + v.count_ones()
    });
    println!("{}", ans);
}
