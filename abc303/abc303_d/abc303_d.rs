use proconio::{input, marker::Chars};

fn main() {
    input! {
        x: usize,
        y: usize,
        z: usize,
        s: Chars
    }
    let mut dp_on = z;
    let mut dp_off = 0;
    for c in s {
        let mut ndp_on = dp_on;
        let mut ndp_off = dp_off;
        match c {
            'a' => {
                ndp_on = (dp_on + 2 * z + x.min(y)).min(dp_off + x.min(y) + z).min(dp_on + y);
                ndp_off = (dp_off + x).min(dp_on + z + x.min(y));
            }
            'A' => {
                ndp_on = (dp_on + x).min(dp_off + z + x.min(y));
                ndp_off = (dp_off + y).min(dp_on + x.min(y) + z).min(dp_off + 2 * z + x.min(y));
            }
            _ => unreachable!(),
        }
        dp_on = ndp_on;
        dp_off = ndp_off;
    }
    println!("{}", dp_on.min(dp_off));
}