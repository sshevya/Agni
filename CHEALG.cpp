#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string str;
        cin>>str;
        string nstr = "";
        char c = str[0];
        int counter = 1;
        for (int i = 1; i < str.length(); ++i)
        {
            if(c==str[i])
                counter++;
            else
            {
                nstr+=c;
                nstr+=to_string(counter);
                counter = 1;
                c = str[i];
            }
        }
        nstr+=c;
        nstr+=to_string(counter);
        if(str.length()>nstr.length())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}