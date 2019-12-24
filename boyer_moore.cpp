#include<bits/stdc++.h>
using namespace std;

void func(string text,string pattern)
{
    map<char,int> mp;
    int m = pattern.length();
    int n = text.length();
    for(int i=0;i<pattern.length();i++)
    {
        mp[pattern[i]]=i+1;
    }
    
    
  
    
    int increment=0;
    for(int i=0;i<=text.length()-pattern.length();i+=increment)
    {
        increment = 0;
        for(int j=pattern.length()-1;j>=0;j--)
        {
            if(text[i+j]!=pattern[j])
            {
                if(mp[text[i+j]]!=0)
                {
                    increment=max(1,j-mp[text[i+j]-1]);
                }
                else
                {
                    increment = j+1;
                }
                break;
            
            }
        }
        if(increment==0)
        {
            cout<<"Pos:"<<i<<endl;
            increment=(i+m>n?m-mp[i+m]-1:1);
        }
    }
}

int main()
{
    string text,pattern;
    cin>>text>>pattern;
    func(text,pattern);
	return 0;
}
