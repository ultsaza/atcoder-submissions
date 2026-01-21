use argio::proconio::input;
use superslice::Ext;

fn main() {
    input! {
        h: usize,
        w: usize,
        n: usize,
        ab: [(usize, usize); n]
    }

    let mut a = vec![];
    let mut b =vec![];
    for (x,y) in &ab {
        a.push(x);
        b.push(y);
    }
    a.sort();
    a.dedup();
    b.sort();
    b.dedup();
    for (x, y) in &ab {
        println!(
            "{} {}",
            a.lower_bound(&x) + 1,
            b.lower_bound(&y) + 1
        )
    }
}
