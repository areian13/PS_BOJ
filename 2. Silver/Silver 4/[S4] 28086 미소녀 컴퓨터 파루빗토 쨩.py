def IsOp(op):
 	return op == '+' or op == '-' or op == '*' or op == '/'

def Calc(oct1, op, oct2):
    result = "invalid"
    dec1 = int(oct1, 8);
    dec2 = int(oct2, 8);
    if(op == '+'):
        result = format(dec1 + dec2, 'o')
    if(op == '-'):
        result = format(dec1 - dec2, 'o')
    if(op == '*'):
        result = format(dec1 * dec2, 'o')
    if(op == '/' and dec2 != 0):
        result = format(dec1 // dec2, 'o')
    return result
form = input()

oct1, oct2 = "", ""
op = ''
for i in range(1, len(form)):
    if(IsOp(form[i])):
        op = form[i]
        oct1 = form[:i]
        oct2 = form[i + 1:]
        break
print(Calc(oct1, op, oct2))