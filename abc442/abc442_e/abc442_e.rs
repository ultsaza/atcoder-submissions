use std::cmp::Ordering;

use argio::proconio::{input, marker::Usize1};
use itertools::Itertools;

struct Point {
    x: isize,
    y: isize,
}

impl Point {
    fn new(x: isize, y: isize) -> Self {
        Self { x, y }
    }

    fn cross(a: &Point, b: &Point) -> isize {
        a.x * b.y - a.y * b.x
    }

    fn cmp(a: &Point, b: &Point) -> Ordering {
        let ah = a.y < 0 || (a.y == 0 && a.x < 0);
        let bh = b.y < 0 || (b.y == 0 && b.x < 0);
        if ah != bh {
            ah.cmp(&bh)
        } else {
            let s = Self::cross(a, b);
            if s > 0 {
                Ordering::Less
            } else if s < 0 {
                Ordering::Greater
            } else {
                Ordering::Equal
            }
        }
    }

    fn sort_by_angle(points: &mut Vec<Point>) {
        points.sort_by(Self::cmp);
    }
}
fn main() {
    input! {
        n: usize,
        q: usize,
        xy: [(isize, isize); n],
        ab: [(Usize1, Usize1); q]
    }

    let xy = xy.into_iter().map(|(x, y)| Point::new(x, y)).collect_vec();
    let mut ord = (0..n).collect_vec();
    ord.sort_by(|&i, &j| Point::cmp(&xy[i], &xy[j]));
    ord.reverse();

    let mut rev = vec![0; n];
    for i in 0..n {
        rev[ord[i]] = i;
    }

    let mut l = vec![0; n];
    let mut r = vec![0; n];
    l[0] = 0;
    r[n - 1] = n;
    for i in 1..n {
        l[i] = if Point::cmp(&xy[ord[i]], &xy[ord[i - 1]]) == Ordering::Less {
            i
        } else {
            l[i - 1]
        };
    }

    for i in (0..n - 1).rev() {
        r[i] = if Point::cmp(&xy[ord[i + 1]], &xy[ord[i]]) == Ordering::Less {
            i + 1
        } else {
            r[i + 1]
        };
    }

    for (a, b) in ab {
        let L = l[rev[a]];
        let R = r[rev[b]];

        if L < R {
            println!("{}", R - L);
        } else {
            println!("{}", n - L + R);
        }
    }
}
