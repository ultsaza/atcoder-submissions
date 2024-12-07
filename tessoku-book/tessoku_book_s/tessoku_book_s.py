def main():
    # 入力
    N, C = map(int, input().split())
    v = [None] * (N + 1)
    w = [None] * (N + 1)
    for i in range(1, N + 1):
        v[i], w[i] = map(int, input().split())

    """
    dp[i][j]: サンプル1からサンプルiのうち, サンプルをいくつか
              選んで合計質量をjにする選ぶときの合計重要度の最大値.
    dp[0][0]は何も選ばないときの重要度の最大値なので初期値は0に対応させた
    """

    # 十分小さい値でdpを初期化(不正な遷移を排除する)
    dp = [[-2 * 10**6] * (C + 1) for _ in range(N + 1)]
    dp[0][0] = 0

    for i in range(1, N + 1):
        for j in range(0, C + 1):
            if j < v[i]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - v[i]] + w[i])

    # 出力
    print(max(dp[N]))


if __name__ == "__main__":
    main()
