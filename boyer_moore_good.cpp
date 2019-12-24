#include<bits/stdc++.h>
using namespace std;

void case1(string pat,int *shift, int *bpos)
{
    int m = pat.length();
    int i = m;
    int j = m+1;
    bpos[i]=j;
    while(i>0)
    {
        while(j<=m && pat[i-1]!=pat[j-1])
        {
            if(shift[j]==0)
                shift[j]=j-1;
            j=bpos[j];
        }
        i--;
        j--;
        bpos[i]=j;
    }
}

void case2(string pat,int *shift, int *bpos)
{
    int j=bpos[0];
    int m = pat.length();
    for(int i=0;i<=m;i++)
    {
        if(shift[i]==0)
            shift[i]=j;
        if(i==j)
            j = bpos[j];
    }
}

void search(string text,string pat)
{
    int t = text.length();
    int p = pat.length();

    int shift[p+1] = {0};
    int bpos[p+1] = {0};

    case1(pat,shift,bpos);
    case2(pat,shift,bpos);

    int s=0;
    while(s<=t-p)
    {
        int j=p-1;
        while(j>=0 && text[s+j]==pat[j])
            j--;
        if(j<0)
        {
            cout<<"Found at pos "<<s<<endl;
            s+=shift[0];
        }
        else
        {
            s+=shift[j+1];
        }

    }
}

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string text,pat;
        cin>>text;
        cin>>pat;
        search(text,pat);
    }
    return 0;
}