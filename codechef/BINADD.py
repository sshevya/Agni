t = int(input())
for i in range(t):
    n1 = input()
    n2 = input()
    l = len(n2)

    num1 = int(n1,2)
    num2 = int(n2,2)
    count=0

    while num2>0:
        count+=1
        u = num1 ^ num2
        v = num1 & num2
        num1 = u
        num2 =  v << 1
    print(count)