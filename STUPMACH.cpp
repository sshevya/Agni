#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        ll mini = 1e9+1;
        ll count=0;
        for (int i = 0; i < n; ++i)
        {
            ll inp;
            cin>>inp;
            if(inp<mini)
            {
                mini = inp;
            }
            count+=mini;

        }
        cout<<count<<endl;
    }
    return 0;
}