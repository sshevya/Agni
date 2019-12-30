t = int(input())
while t>0:
    t-=1
    inp = [int(i) for i in input().split()]
    a = inp[0]
    m = inp[1]

    div1 = [1]
    div2 = []
    for i in range(2,int(pow(m,0.5))+1):
        if m%i==0:
            div1.append(i)
            if(i*i!=m):
                div2.append(int(m/i))
    div = div1+div2
    num = []
    for n in div:
        lamb = (((m-n)/n)/a)
        if m%(n*a)==1:
            num.append(int(m*lamb/(a*lamb+1)))

    num.sort()
    length = len(num)
    print(length)
    for i in range(length):
        if i!=length-1:
            print(num[i],end=" ")
        else:
            print(num[i])