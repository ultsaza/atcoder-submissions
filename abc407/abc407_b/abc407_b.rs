use proconio::input;

fn main() {
    input! {
        x: usize,
        y: usize,
    }
    let mut cnt = 0;
    for i in 1..=6 {
        for j in 1..=6 {
            if (i + j) >= x  || (i).abs_diff(j) >= y {
                cnt += 1;
            }
        }
    }
    println!("{:.20}", cnt as f64 / 36.0);
}