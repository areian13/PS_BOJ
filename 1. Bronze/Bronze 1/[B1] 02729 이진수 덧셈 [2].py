tc = int(input())

while tc:
	a, b = map(str, input().split())
	print(bin(int(a, 2) + int(b, 2))[2:])
	tc -= 1
# 파이썬 개사기