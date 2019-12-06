t = int(input())
for i in range(t):
    freq = {0:0,2:0}
    n = int(input())
    num_str = input().split()
    for i in num_str:
        if int(i)==0 or int(i)==2:
            freq[int(i)] += 1

    count = freq[0]*(freq[0]-1)/2 + freq[2]*(freq[2]-1)/2
    
    print(int(count))