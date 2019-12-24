#include<bits/stdc++.h>
using namespace std;

int lps(string str)
{
    int len=0;
    int lps_[str.length()];
    lps_[len]=0;
    int i=1;
    while(i<str.length())
    {
        if(str[i]==str[len])
        {
            len++;
            lps_[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps_[len-1];
            }
            else
            {
                lps_[i]=0;
                i++;
            }
        }
    }
    return lps_[str.length()-1];
}
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string str;
        cin>>str;
        cout<<lps(str)<<endl;
    }
    return 0;
}