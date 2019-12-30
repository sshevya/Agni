#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main()
{
    int n,m;

    cin>>n>>m;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    int num = gcd(n,m);
    int jump = n/num;
    for (int i = 0; i < num; ++i)
    {
        int temp = arr[i];
        int j=i;
        while(1)
        {
            int k = j+m;
            if(k>=n)
                k-=n;
            if(k==i)
                break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j] = temp;
    }
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}