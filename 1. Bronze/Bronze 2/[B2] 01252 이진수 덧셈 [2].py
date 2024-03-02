a, b = map(str, input().split())
result = bin(int(a, 2) + int(b, 2))[2:]
print(result)
# 파이썬 개사기