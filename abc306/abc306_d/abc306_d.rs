use proconio::input;

fn main() {
    input! {
        n: usize,
        xy: [(i64, i64); n],
    }
    let mut dp_1 = 0;
    let mut dp_0 = 0;
    for i in 0..n {
        let (x_i, y_i) = xy[i];
        let mut tmp_1 = 0;
        let mut tmp_0 = 0;
        match (x_i) {
            1 => {
                tmp_1 = dp_1.max(dp_0 + y_i);
                tmp_0 = dp_0;
            }
            0 => {
                tmp_1 = dp_1;
                tmp_0 = (dp_1 + y_i).max(dp_0.max(dp_0 + y_i));
            }
            _ => unreachable!(),
        }
        dp_1 = tmp_1;
        dp_0 = tmp_0;
    }
    println!("{}", dp_1.max(dp_0));
}