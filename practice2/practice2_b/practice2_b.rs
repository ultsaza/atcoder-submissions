use ac_library::fenwicktree;
use proconio::input;

fn main() {
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
    }
    let mut fw = fenwicktree::FenwickTree::new(n, 0usize);
    for i in 0..a.len() {
        fw.add(i, a[i]);
    }
    for _ in 0..q {
        input! {
            t: usize,
            xy: (usize, usize)
        }
        match t {
           0 => {
                fw.add(xy.0, xy.1);
           } 
           1 => {
                println!("{}",fw.sum(xy.0..xy.1));
           }
           _ => unreachable!()
        }
    }
}