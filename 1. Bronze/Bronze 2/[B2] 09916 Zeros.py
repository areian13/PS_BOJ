import math

n = int(input())

result = str(math.factorial(n)).count('0')
print(result)