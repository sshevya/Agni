#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int arr[8] = {0};
        int sum=0;
        int n;
        cin>>n;
        while(n-->0)
        {
            int a,b;
            cin>>a>>b;
            if(a>=9)
                continue;
            if(arr[a-1]<b)
            {
                sum = sum-arr[a-1]+b;
                arr[a-1]=b;
            }
        }
        cout<<sum<<endl;

    }
    return 0;
}