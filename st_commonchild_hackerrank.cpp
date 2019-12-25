/* see discussion, another solution where entire matrix is not needed only 2 rows would work */


#include <bits/stdc++.h>

using namespace std;
 
// Complete the commonChild function below.
long commonChild(string s1, string s2) {
    long m=s1.length();
    long n=s2.length();
    static long L[5001][5001];
   
    for(long i=0;i<=m;i++){
        for(long j=0;j<=n;j++){
            if(i==0 || j==0){
                L[i][j]=0;
           }
            else if(s1[i-1]==s2[j-1]){
                L[i][j]=1+L[i-1][j-1];

            }else{
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }

        }
    }
return L[m][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    long result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
