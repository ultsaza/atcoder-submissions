n, m = map(int, input().split())
t = list(map(str, input().split()))
s = set(map(str, input().split()))
for tt in t:
    if tt in s:
        print("Yes")
    else:
        print("No")