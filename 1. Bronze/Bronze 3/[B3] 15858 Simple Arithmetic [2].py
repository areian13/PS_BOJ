from decimal import Decimal

a, b, c = map(int, input().split())
result = Decimal(a * b) / Decimal(c)
print(result)