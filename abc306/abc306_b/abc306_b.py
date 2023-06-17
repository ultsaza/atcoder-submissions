a = list(map(int, input().split()))
ans = 0

for i in range(64):
    if a[i] == 1:
        ans += (1 << i)

print(ans)
