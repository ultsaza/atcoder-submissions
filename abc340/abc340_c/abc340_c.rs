#![allow(unused_imports)]
use itertools::*;
use itertools_num::*;
use maplit::*;
use memoise::memoise_map;
use num::integer::{Integer, Roots};
use proconio::{marker::*, *};
use std::cmp::{Ordering::*, Reverse};
use std::collections::*;
use superslice::*;

fn main() {
    input! {
        n: usize,
    }
    println!("{}", f(n));    
}

#[memoise_map(n)]
fn f(n: usize) -> usize {
    if n < 2 {
        0
    } else {
        f(n/2) + f((n+1)/2) + n
    }
}