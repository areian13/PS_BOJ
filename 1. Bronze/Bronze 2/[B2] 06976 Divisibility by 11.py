TC = int(input())

for tc in range(1, TC+1):
    n = input()

    t = n
    while len(t) > 2:
        print(t)
        t = str(int(t[:-1]) - int(t[-1]))
    print(t)

    result = (int(t) % 11 == 0)
    print(f"The number {n} {'is' if result == True else 'is not'} divisible by 11.")
    print()