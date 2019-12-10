#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, int m, vector<vector<int> > edges, int s)
{
    map<int,vector<int> > mp;
    vector<int> anc(n,-1);
    vector<int> dis(n,-1);
    dis[s-1]=0;
    for(auto it = edges.begin(); it!=edges.end();it++)
    {
        mp[(*it)[0]].push_back((*it)[1]);
        mp[(*it)[1]].push_back((*it)[0]);
    }
    
    
    vector<bool> visited(n,false);
    visited[s-1]=true;
    list<int> queue;
    queue.push_back(s);
    while(!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();
        for(int x:mp[u])
        {
            if(!visited[x-1])
            {   visited[x-1] = true;
                dis[x-1] = dis[u-1]+6;  
                anc[x-1] = u-1;
                queue.push_back(x);
            }
        }
    }
    
    return dis;
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++)
    {
        edges[i].resize(2);
        int a,b;
        cin>>a>>b;
        edges[i][0] = a;
        edges[i][1] = b;
    }
    
    int s;
    cin>>s;
    vector<int> dist = bfs(n,m,edges,s);
    for(int i=0;i<n;i++)
    {
        if(i==s-1)
            continue;
        cout<<dist[i]<<" ";
    }        
    cout<<endl;
    return 0;
}
