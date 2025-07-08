TC = int(input())

for tc in range(1, TC+1):
    n, x = map(int, input().split())

    result = n % x
    print(f"Case {tc}: {result}")