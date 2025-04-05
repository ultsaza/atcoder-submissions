import sys

def solve():
    n = int(sys.stdin.readline())
    ans = 0

    for a in range(1, 64):
        pow_a = 1 << (a)
        
        l, r = 0, 1000000000

        while l < r:
            m = (l + r + 1) // 2

            if m == 0:
                 is_valid = True
            else:
                 m_squared = m * m
                 if m_squared > n // pow_a:
                      is_valid = False
                 else:
                      is_valid = (m_squared * pow_a <= n)


            if is_valid:
                l = m
            else:
                r = m - 1
        
        if l%2 == 0:
          ans += l//2
        else:
          ans += (l+1)//2

    print(ans)

if __name__ == "__main__":
    solve()