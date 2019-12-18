#include<bits/stdc++.h>
using namespace std;

long getWays(int n, vector<long> c) {
    sort(c.begin(),c.end());
   long m=c.size();
   long L[m][n+1];
   for(int i=0;i<m;i++){
       L[i][0]=1;
   }
   long x,y;
   for(long i=0;i<m;i++){
       for(long j=1;j<n+1;j++){
            x=(j-c[i]>=0)?L[i][j-c[i]]:0;
            y=(i>=1)?L[i-1][j]:0;
            L[i][j]=x+y;

       }
   }

return L[m-1][n];
}
int main() 
{ 
    vector<long> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3); 
   
    int n = 4; 
    cout << getWays(n,v); 
    return 0; 
} 
  
