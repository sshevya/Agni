#include<bits/stdc++.h>
using namespace std;

void lps_func(string str, int* lps)
{
    int len = 0;
    lps[len] = 0;

    int M = str.length();
    int i =1;
    while(i<M)
    {
        if(str[i]==str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string str,string ptr)
{
    int lps[ptr.length()];
    lps_func(ptr,lps);
    int i = 0;
    int j = 0;
    int count = 0;
    while(i<str.length())
    {
        if(str[i]==ptr[j])
        {
            i++;
            j++;
            if(j==ptr.length())
            {    
                count++;
                j--;
            }
        }
        else
        {
            if(j==0)
            {
                i++;
                continue;
            }
            j=lps[j-1];
        }
    }
    cout<<count<<endl;

}


int main()
{
    string str = "abcabcabe";
    string ptr = "avcdeavav";
    kmp(str,ptr);
    return 0;
}