tc = int(input())

while tc > 0:
    n = int(input())

    result = [ "NO","YES" ][n % 9 == 0]
    print(result)

    tc -= 1