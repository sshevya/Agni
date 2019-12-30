#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int arr[26]={0};
    for (int i = 0; i < str.length(); ++i)
    {
        arr[str[i]-'a']++;
    }
    std::vector<int> v;
    bool flag = true;
    for (int i = 0; i < 26; ++i)
    {
        if(arr[i]!=0)
        {
            //cout<<arr[i]<<flag<<endl;
            if(v.size()==0)
                v.push_back(arr[i]);
            else if(v.size()==1)
            {
                 if(v[0]==arr[i])
                    continue;
                 else if(abs(v[0]-arr[i])<=1)
                 {
                    v.push_back(arr[i]);
                 }
                 else
                 {
                    //cout<<"yo\n";
                    flag=false;
                    break;
                 }
            }
            else if(v.size()==2)
            {
                if(v[0]!=arr[i] && v[1]!=arr[i])
                {
                    //cout<<"yes\n";
                    flag=false;
                    break;
                }
            }


        }
    }
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";        

    return 0;
}