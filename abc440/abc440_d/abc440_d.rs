use argio::proconio::input;
use itertools::Itertools;
use superslice::Ext;

fn main() {
    input! {
        n: usize,
        q: usize,
        mut a: [usize; n],
        xy: [(usize, usize); q]
    }
    a.push(0);
    a.sort();
    let aa = a.iter().enumerate().map(|(i, &a)| a - i).collect_vec();
    for (x, y) in xy {
        let t = a.lower_bound(&x);
        let d = aa.lower_bound(&(y + x - t))
            - 1;
        println!("{}", y + x + d - t);
    }
}
