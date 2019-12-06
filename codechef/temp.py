# Python3 program to count number of 
# distinct subseqences of a given string
num = [0 for i in range(10000)]
num[0]=1
pos = 0
def factorial(n) : 
    if n<=pos:
        return num[n]
    else:
        fact = num[pos]
        for i in range(pos+1, n + 1) : 
            fact = (fact*i)%1000000007
            num[i] = fact

    return num[n]

  
    
# Driver code 
t = int(input())
for i in range(t):
    n = input()
    m = input()
    if len(m)<len(n):
        m = "0"*(len(n)-len(m))+m
    elif len(n)<len(m):
        n = "0"*(len(m)-len(n))+n
    n1 = n.count('1')
    n0 = len(n)-n1
    m1 = m.count('1')
    m0 = len(m)-m1
    print(m0,m1,n0,n1)
    if(n1*n0>m1*m0):
        print(int(factorial(len(n))/(factorial(n1)*factorial(n0))%1000000007))
    else:
        print(int(factorial(len(m))/(factorial(m1)*factorial(m0))%1000000007))

# This code is contributed 
# by mohit kumar 29 
