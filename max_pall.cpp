#include<bits/stdc++.h>
#define ll long long
#define num (ll)(1e9+7)
using namespace std;


ll fact[100001]={0};

ll factorial(ll x)
{
    
    if(fact[x]!=0)
        return fact[x];
    ll temp = ((ll)((ll)x%num)*factorial(x-1))%num;
    if(x<=10000)
    {
         fact[x] = temp;
    }   
    return temp;
}

ll gcdExtended(ll a,ll b,ll *x,ll *y)
{
    if (a == 0) {
      *x = 0;
      *y = 1;
      return b;
   }
   ll x1, y1;
   ll gcd = gcdExtended(b%a, a, &x1, &y1);
   *x = y1 - (b/a) * x1;
   *y = x1;
   return gcd;
}

ll inv_mod(ll a)
{
    ll x,y;
    ll temp = gcdExtended(a,num,&x,&y);
    return (x%num+num)%num;
}


ll func(string str,ll l,ll r)
{
    ll odd=0;
    ll sum=0;
    map<char,ll> mp;
    for(ll i=l;i<=r;i++)
    {
        mp[str[i]]++;
    }

    map<char,ll>::iterator itr;

    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        if((itr->second)%2!=0)
        {
            odd++;
            mp[itr->first]--;
        }
        mp[itr->first]/=2;
        sum+=mp[itr->first];
    }
    
    ll res = factorial(sum);
    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        if((itr->second)==0)
            continue;
        ll inv = inv_mod(factorial(itr->second));
        res = ((ll)res*inv)%num;
    }
    
    if(odd!=0)
        res = ((ll)res*odd)%num;
    return res;
}

int main()
{   
    fact[0]=1;
    fact[1]=1;
    string str;
    cin>>str;
    ll q;
    cin>>q;
    while(q-->0)
    {
        ll l,r;
        cin>>l>>r;
        cout<<func(str,l-1,r-1)<<endl;
    }
    return 0;
}