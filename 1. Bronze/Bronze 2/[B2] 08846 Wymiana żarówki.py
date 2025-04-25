MOD = 500000009

if __name__ == "__main__":
    n = int(input())

    result = ((4 ** n) - 1) // 3 % MOD
    print(result)