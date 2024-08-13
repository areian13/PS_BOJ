while True:
    n = int(input())

    if n == 0:
        break

    result = "PREMIADO" if n % 42 == 0 else "TENTE NOVAMENTE"
    print(result)