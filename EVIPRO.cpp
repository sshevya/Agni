#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string str;
        cin>>str;
        int l = str.length();
        int arr[l][l] = {0};
        for (int i = 0; i < l; ++i)
        {
            for (int j = i+1; j < l; ++j)
            {
                if(str[j]==str[j-1])
                    arr[i][j] = arr[i][j-1]+1;
                else
                    arr[i][j] = arr[i][j-1];
            }
        }
        /*for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/
                int count=0;
        for (int i = 0; i < l; ++i)
        {
            for (int j = i; j < l; ++j)
            {
                count+=arr[i][j];
                if(i!=0)
                {
                    if(str[i]!=str[i-1])
                        count+=arr[0][i-1]+1;
                    else
                        count+=arr[0][i-1];
                }
                if(j!=l-1)
                {
                    if(str[j]!=str[j+1])
                        count+=arr[j+1][l-1]+1;
                    else
                        count+=arr[j+1][l-1];
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}