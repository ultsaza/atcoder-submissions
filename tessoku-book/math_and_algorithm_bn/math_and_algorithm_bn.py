n = int(input())
tmp = []
l = [0] * (n+1)
r = [0] * (n+1)

for i in range(1, n+1):
    l[i], r[i] = map(int, input().split())
    tmp.append((r[i], l[i]))

tmp.sort()

for i in range(1, n+1):
    r[i] = tmp[i-1][0]
    l[i] = tmp[i-1][1]

cur = 0
ans = 0

for i in range(1, n+1):
    if cur <= l[i]:
        cur = r[i]
        ans += 1

print(ans)
