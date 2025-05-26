use proconio::input;

fn main() {
    input! {
        aa: (i64, i64),
        bb: (i64, i64),
        cc: (i64, i64),
    }
    let ans = (bb.0 - aa.0) * (cc.1 - aa.1) - (cc.0 - aa.0) * (bb.1 - aa.1);
    println!("{:.20}", ans.abs() as f64 / 2.0);
}