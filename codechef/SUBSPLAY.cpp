/*#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int t;
    cin>>t;
    while(t-->0)
    {
        long int c = 0;
        bool flag = true;
        int freq[26] = {0};
        int l;
        int type=0;
        cin>>l;
        string str;
        cin>>str;
        for(int i=0;i<l;i++)
        {
            if(freq[str[i]-'a']==0)
                type++;
            freq[str[i]-'a']++;
        }

        for (int i = 0; i < 26; ++i)
        {
            if(freq[i]==0)
                continue;
            double val = pow(2,freq[i]-1)-1;
            if(val!=0)
            {
                c += val;
                flag = true;
            }
            cout<<"yes "<<c<<endl;
        }
        c += pow(2,l-type)-1;
        if(flag)
            cout<<c<<endl;
        else
            cout<<0;
    }
    return 0;
 }

// C++ program to count common subsequence in two strings 
#include <bits/stdc++.h> 
using namespace std; 

// return the number of common subsequence in 
// two strings 
int CommomSubsequencesCount(string s, string t) 
{ 
    int n1 = s.length(); 
    int n2 = t.length(); 
    int dp[n1+1][n2+1]; 

    for (int i = 0; i <= n1; i++) { 
        for (int j = 0; j <= n2; j++) { 
            dp[i][j] = 0; 
        } 
    } 

    // for each character of S 
    for (int i = 1; i <= n1; i++) { 

        // for each character in T 
        for (int j = 1; j <= n2; j++) { 

            // if character are same in both 
            // the string 
            if (s[i - 1] == t[j - 1]) 
                dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];          
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - 
                                        dp[i - 1][j - 1];            
        } 
    } 

    return dp[n1][n2]; 
} 

// Driver Program 
int main() 
{ 
    string s = "abcdefgh"; 
    string t = "aefcnbtdi"; 

    cout << CommomSubsequencesCount(s, s)<< endl; 
    return 0; 
} */
// C++ program to count number of distinct 
// subsequences of a given string. 
#include <bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 256; 

// Returns count of distinct sunsequences of str. 
int countSub(string str) 
{ 
    // Create an array to store index 
    // of last 
    vector<int> last(MAX_CHAR, -1); 

    // Length of input string 
    int n = str.length(); 

    // dp[i] is going to store count of distinct 
    // subsequences of length i. 
    int dp[n+1]; 

    // Empty substring has only one subsequence 
    dp[0] = 1; 

    // Traverse through all lengths from 1 to n. 
    for (int i=1; i<=n; i++) 
    { 
        // Number of subsequences with substring 
        // str[0..i-1] 
        dp[i] = 2*dp[i-1]; 

        // If current character has appeared 
        // before, then remove all subsequences 
        // ending with previous occurrence. 
        if (last[str[i-1]] != -1) 
            dp[i] = dp[i] - dp[last[str[i-1]]]; 

        // Mark occurrence of current character 
        last[str[i-1]] = (i-1); 
    } 

    return dp[n]; 
} 

// Driver code 
int main() 
{ 
cout << countSub("abcdefghjklmnopqrstuvwxyz123456789,./';"); 
return 0; 
} 

