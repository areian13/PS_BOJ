import math

tc = int(input())

while tc > 0:
    n, m = map(int, input().split())
    str_facto = str(math.factorial(n))

    result = str_facto.count(chr(m))
    print(result)

    tc -= 1