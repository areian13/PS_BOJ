def IsOp(op):
 	return op == '+' or op == '-' or op == '*' or op == '/'

if __name__ == "__main__":
    form_oct = input()

    oct1, oct2 = "", ""
    op = ""
    for i in range(1, len(form_oct)):
        if IsOp(form_oct[i]):
            op = form_oct[i]
            oct1 = form_oct[:i]
            oct2 = form_oct[i + 1:]
            break

    form_dec = (str(int(oct1, 8)) + op + str(int(oct2, 8))).replace('/', "//")
    try:
        result = format(eval(form_dec), 'o')
        print(result)
    except:
        print("invalid")