
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
long mycount=0;
void DFS(int v, bool visited[], vector<int> adj[]){
   visited[v]=true;
   mycount++;
   vector<int>::iterator i;
   for(i=adj[v].begin();i!=adj[v].end();i++){
       if(!visited[*i]){
           DFS(*i,visited,adj);
       }
    }
}   

// Complete the journeyToMoon function below.
long journeyToMoon(int n, vector<vector<int>> astronaut) {
    int arr[n]={0};
      int m= astronaut.size();
    vector<int> adj[n];
    for(int i=0;i<m;i++){
         int u=astronaut[i][0];
         int v=astronaut[i][1];
         adj[u].push_back(v);
         adj[v].push_back(u);
         arr[u]=1;
         arr[v]=1;
    }

    bool visited[n];
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            visited[i]=false;
        }else{
            visited[i]=true;
        }
    }
    long curr=0,prev=0,p[n]={1},j=0,no_of_vertices=0,val=0;//p is an array to store no of adjacent vertices 
    long M=1000000007;
    for(int i=0;i<n;i++){
        if(!visited[i]){
             
           DFS(i,visited,adj);
         
            curr=(mycount)%M;  // my count variable gives total no of vertices that has been visited after each iteration of DFS
            
            p[j]=curr-prev;
            no_of_vertices=p[j]+prev;
         
            val+=(p[j]*prev)%M;    //a*b+(a+b)*c+....
               prev=curr;
            j++;
        }
        
    }/*
    while(n-mycount!=0){
        curr=curr+1;
        p[j]=(curr-prev)%M;
        no_of_vertices+=p[j];
        val+=((p[j])%M*(prev)%M)%M;    //a*b+(a+b)*c+....
        prev=curr;
        j++;
        n--;
        
    }
*/
long l=n-mycount;
val=val+(l)*no_of_vertices+l*(l-1)/2;
return val;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
