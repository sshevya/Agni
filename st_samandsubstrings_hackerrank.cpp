#include <bits/stdc++.h>

using namespace std;
// Complete the substrings function below.

long long substrings(string n) {
    long long len=n.length();
    long long num[len];
    const long long M=1000000007;
     // converts character to int
    long long sum=0,f=1;
    
    for(long long i=len-1;i>=0;i--){
    
              num[i]=n[i]-'0';
        sum+=(num[i]*f*len)%M;  
        f=(f*10+1)%M;    //larger the number, difficult it is to find mod, hence find mod after each step
        len--;  
    }
return sum%M;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    long long result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
