WIDTH = 70

n, p = map(int, input().split())

result = str(n ** p)
for i in range (0, len(result), WIDTH):
    print(result[i:i + WIDTH])