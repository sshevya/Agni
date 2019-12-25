#include <bits/stdc++.h>
#include<iterator>
using namespace std;
#define INF 99999
vector<string> split_string(string);
typedef pair<int,int> ipair;
// Complete the beautifulPath function below.
int beautifulPath(vector<vector<int>> edges, int A, int B, int n) {
    int m=edges.size();
    list<pair<int, int>> *adj;
    adj=new list<ipair> [n];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u-1].push_back(make_pair(v-1,w));
        adj[v-1].push_back(make_pair(u-1,w));
    }

    bool visited[n][1024];
    for(int i=0;i<n;i++){
        for(int j=0;j<1024;j++){
            visited[i][j]=false;
        }
    }
    visited[A-1][0]=true;
    queue<int> q;
    q.push(A-1);
    queue<int> d;
    d.push(0);
    while(!q.empty()){
        int u=q.front();
        int dist=d.front();
        q.pop();
        d.pop();
        list< pair<int, int> >::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++){
            if(!visited[(*i).first][dist | (*i).second]){
                    visited[(*i).first][dist | (*i).second]=true;
                    q.push((*i).first);
                    d.push(dist | (*i).second);
            }
        }
    }
    for (int i = 0; i < 1024; i++)
     {

        if (visited[B-1][i])
        {
            return i;
            
        }
     }

            return -1;
        




}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string AB_temp;
    getline(cin, AB_temp);

    vector<string> AB = split_string(AB_temp);

    int A = stoi(AB[0]);

    int B = stoi(AB[1]);

    int result = beautifulPath(edges, A, B, n);

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
