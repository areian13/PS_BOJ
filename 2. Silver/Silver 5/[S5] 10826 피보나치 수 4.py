def fib(n):
    dp = [0 for i in range(n + 2)]
    dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

if __name__ == "__main__":
    n = int(input())

    result = fib(n)
    print(result)