#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        int arr[n];
        bool flag=true;
        int cnt=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        for (int i = n-1; i >=0; --i)
        {
            if(arr[i]!=i+1)
            {
                if(i-1>=0 && arr[i-1]==i+1)
                {
                    cnt++;
                    arr[i-1]=arr[i];
                    arr[i]=i+1;
                }
                else if(i-2>=0 && arr[i-2]==i+1)
                {
                    cnt+=2;
                    arr[i-2]=arr[i-1];
                    arr[i-1]=arr[i];
                    arr[i]=i+1;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            cout<<cnt<<endl;
        else
            cout<<"Too chaotic\n";
    }
    return 0;
}