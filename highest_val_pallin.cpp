#include<bits/stdc++.h>
using namespace std;

string func(string num,int n,int k)
{
    int diff = 0;
    int i=0,j=n-1;
    while(i<j)
    {
        if(num[i++]!=num[j--])
        {
            diff++;
        }
    }
    if(diff>k)
    {
        return "-1";
    }
    else
    {
        if(n%2==0)
        {
            int pos=1;
            int mid = n/2;
            while(k<2*diff)
            {
                if(num[mid-pos] != num[mid+pos-1])
                {
                    char maxi = max(num[mid-pos],num[mid+pos-1]);
                    num[mid-pos] = num[mid+pos-1] = maxi;
                    diff--;
                    k--;
                }
                
                pos++;
            }
            if(k!=0)
            {
                int var=0;
                while(var<=mid-pos && k>1)
                {
                    num[var] = num[n-var-1] = '9';
                    k-=2;
                    var++;
                }
            }
        }
        else
        {
            int pos=1;
            int mid = (n-1)/2;
            while(k<2*diff)
            {
                if(num[mid-pos] != num[mid+pos])
                {
                    char maxi = max(num[mid-pos],num[mid+pos]);
                    num[mid-pos] = num[mid+pos] = maxi;
                    diff--;
                    k--;
                }
                pos++;
            }
            if(k!=0)
            {
                int var=0;
                while(var<=mid-pos && k>1)
                {
                    if(num[var]!='9' || num[n-var-1]!='9')
                    {
                        num[var] = num[n-var-1] = '9';
                        k-=2;
                    }
                    var++;
                }
            }
            if(k>0)
                num[mid] = '9';
        }
        return num;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    string num;
    cin>>num;
    cout<<func(num,n,k)<<endl;
    return 0;
}