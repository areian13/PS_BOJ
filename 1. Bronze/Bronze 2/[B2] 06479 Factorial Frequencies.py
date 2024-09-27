import math

while True:
    n = int(input())

    if n == 0:
        break;

    input()

    print(f"{n}! --")
    facto = str(math.factorial(n))

    cnt = [0] * 10
    for c in facto:
        cnt[int(c)] += 1

    for i in range(10):
        print(f"   ({i}){cnt[i]:>5}", end=' ')
        if i % 5 == 4:
            print()