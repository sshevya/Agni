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
        stack<char> s;
        s.push(str[0]);
        int c=0;
        for (int i = 1; i < str.length(); ++i)
        {
            if(s.top()!=str[i])
                s.push(str[i]);
            else
                c++;
        }
        cout<<c<<endl;
    }
    return 0;
 }