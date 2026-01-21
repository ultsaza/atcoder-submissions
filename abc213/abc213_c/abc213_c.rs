use argio::proconio::input;
use superslice::Ext;

fn main() {
    input! {
        _h: usize,
        _w: usize,
        n: usize,
        ab: [(usize, usize); n]
    }

    let (mut a, mut b): (Vec<_>, Vec<_>) = ab.iter().copied().unzip();
    a.sort();
    a.dedup();
    b.sort();
    b.dedup();

    let ca = |x| a.lower_bound(&x) + 1;
    let cb = |y| b.lower_bound(&y) + 1;

    for (x, y) in ab {
        println!("{} {}", ca(x), cb(y));
    }
}
