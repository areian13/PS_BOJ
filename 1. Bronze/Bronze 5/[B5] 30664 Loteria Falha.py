while True:
    n = int(input())

    if n == 0:
        break

    result = [ "PREMIADO","TENTE NOVAMENTE" ][n % 42 != 0]
    print(result)