import math

def reduce_frac(a,b):
    if a == 0:
        return 0
    if b == 1:
        return a
    if b == -1:
        return -a
    if a < 0 and b < 0:
        return f"{-a}/{-b}"
    if b < 0:
        return f"{-a}/{-b}"
        
    return f"{a}/{b}"


# print(reduce_frac(3,-5))
case = (int)(input())

for i in range(case):
    eqn = input()
    expression = eqn.replace("=","-(")+")"
    grouped = eval(expression.replace("x",'1j'))
    imag = (int)(grouped.imag)
    real = (int)(grouped.real)
    if imag == 0:
        if real == 0:
            print(f"Case {i+1}: infinitely many solutions")
        else:
            print(f"Case {i+1}: no solution")
        continue
    gcd = math.gcd(imag, real)
    imag //= gcd
    real //= gcd
    print(f"Case {i+1}: {reduce_frac(-real, imag)}")