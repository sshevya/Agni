#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
void DFS(long v,bool visited[],vector<long> adj[]){
    visited[v]=true;
   
    vector<long>::iterator i;
   
    for(i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
             DFS(*i,visited,adj);
            
        }
    }
    
}



// Complete the roadsAndLibraries function below.
// use long for n,c_lib,c_road as well otherwise it will pass half of the test cases
// find no of connected vcomponents,in each connected component one lib and no of nodes in that component -1 roads,
// total no of roads built would be (n- connected components)
long roadsAndLibraries(long n, long c_lib, long c_road, vector<vector<int>> cities) {

   if(c_lib <= c_road){
       long a=n*c_lib;
       return a;
   }else{
          
          long  m=cities.size(); 
          vector<long> adj[n];
       for(long i=0;i<m;i++){
          long v=cities[i][0];
           long w=cities[i][1];
           adj[v-1].push_back(w-1);
           adj[w-1].push_back(v-1);
       }
 bool *visited=new bool[n];
    
     for(long i=0;i<n;i++){
         visited[i]=false;
     }
   long connectedComponents=0;
      for(long i = 0;i < n;++i) {
         if(visited[i] == false)     {
             DFS(i,visited,adj);
             connectedComponents++;
         }
        }
        long ans=0;
        ans=(n-connectedComponents)*c_road+connectedComponents*c_lib;
     return ans;
   }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
