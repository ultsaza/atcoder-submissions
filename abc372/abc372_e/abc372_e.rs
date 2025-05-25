use std::collections::BTreeSet;

use proconio::{input, marker::Usize1};

pub struct UnionFind {
    parent: Vec<usize>,
    size: Vec<usize>,
    set: Vec<BTreeSet<usize>>,
}

impl UnionFind {
    pub fn new(n: usize) -> Self {
        let mut set = vec![BTreeSet::new(); n];
        for i in 0..n {
            set[i].insert(i);
        }
        Self {
            parent: (0..n).collect(),
            size: vec![1; n],
            set,
        }
    }
    
    pub fn find(&mut self, x: usize) -> usize {
        if self.parent[x] == x {
            x
        } else {
            self.parent[x] = self.find(self.parent[x]);
            self.parent[x]
        }
    }
    
    pub fn merge(&mut self, x: usize, y: usize)-> bool {
        let mut x = self.find(x);
        let mut y = self.find(y);
        if x == y {
            false
        } else {
            if self.size[x] < self.size[y] {
                std::mem::swap(&mut x, &mut y);
            }
            self.parent[y] = x;
            self.size[x] += self.size[y];
            let y_set = std::mem::take(&mut self.set[y]);
            for u in y_set.iter() {
                self.set[x].insert(*u);
            }
            true
        }
    }
    
    pub fn same(&mut self, x: usize, y: usize) -> bool {
        self.find(x) == self.find(y)
    }
    
    pub fn size(&mut self, x: usize) -> usize {
        let x = self.find(x);
        self.size[x]
    }
    
    pub fn set(&mut self, x: usize) -> &BTreeSet<usize> {
        let x = self.find(x);
        &self.set[x]
    }
}

fn main() {
    input! {
        n: usize,
        q: usize,
        tuv: [(Usize1, Usize1, Usize1); q],
    }
    let mut uf = UnionFind::new(n);
    for (t, u, v) in tuv {
        if t == 0 {
            uf.merge(u, v);
        } else {
            let st = uf.set(u);
            if st.len() > v {
                let v_th = st.iter().nth_back(v).unwrap();
                println!("{}", v_th+1);
            } else {
                println!("-1");
            }
        }
    }
}

