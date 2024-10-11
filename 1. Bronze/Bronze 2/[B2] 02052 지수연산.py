n = int(input())

result = str(5 ** n)
result = "0." + "0" * (n - len(result)) + result
print(result)