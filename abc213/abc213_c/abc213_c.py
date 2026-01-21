h, w, n = list(map(int, input().split()))

x, y = [], []
for i in range(n):
    a, b = list(map(int, input().split()))
    x.append(a)
    y.append(b)

rx = {a: i + 1 for i, a in enumerate(sorted(set(x)))}
ry = {b: i + 1 for i, b in enumerate(sorted(set(y)))}

for i in range(n):
    print(rx[x[i]], ry[y[i]])
