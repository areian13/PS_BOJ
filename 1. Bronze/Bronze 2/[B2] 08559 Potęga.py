if __name__ == "__main__":
    n = int(input())
    result = [2, 4, 8, 6][(n - 1) % 4] if n > 0 else 1
    print(result)