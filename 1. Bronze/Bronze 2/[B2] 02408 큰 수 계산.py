n = int(input())
result = eval(''.join([input() for _ in range(n * 2 - 1)]).replace('/', '//'))
print(result)