use proconio::input;
use std::collections::BTreeMap;

fn main() {
    input! {
        n: usize,
        mut lr: [(usize, usize); n]
    }
    lr.sort();
    let mut mp = <BTreeMap<(usize, usize), isize>>::new();
    for &(l, r) in lr.iter() {
        *mp.entry((l,0)).or_insert(0) += 1;
        *mp.entry((r,1)).or_insert(0) += 1;
    }
    let mut ans: usize = 0;
    let mut cnt = 0;
    for (&(pos, t), &v) in mp.iter() {
        match t {
            0 => {
                cnt += v;
            }
            1 => {
                cnt -= v;
                ans += cnt as usize * v as usize + v as usize * (v as usize - 1)/2;
            }
            _ => unreachable!(),
        }
    }
    println!("{}", ans);
}