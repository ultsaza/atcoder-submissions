use proconio::input;

fn main() {
    input! {
        n: usize,
    }
    let mut a = vec![false;n + 1];

    for i in 2..=n {
        if a[i] {
            continue;
        } else {
            for j in (i..=n).skip(i).step_by(i) {
                a[j] = true;
            }
        }
    }
    for i in 2..=n {
        if !a[i] {
            println!("{}", i);
        }
    }
}