#include<bits/stdc++.h>
using namespace std;

void find_dist(int s, int n,int m,vector<vector<int> > adj, vector<int> *dist)
{
    vector<int> pred(n,-1);
    pred[s]=s;
    list<int> queue;
    vector<bool> visited(n,false);
    queue.push_back(s);
    visited[s]=true;
    (*dist)[s]=0;
    while(!queue.empty())
    {
        int z = queue.front();
        queue.pop_front();
        if((*dist)[z]>(*dist)[pred[z]]+6 || (*dist)[z]==-1)
            (*dist)[z]=(*dist)[pred[z]]+6;
        for(int x:adj[z])
        {
            if(visited[x]==false)
            {
                visited[x]=true;
                queue.push_back(x);
                pred[x] = z;
            }
        }
    }

}

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > adj(n,vector<int>(0));
        for (int i = 0; i < m; ++i)
        {
            int a,b;
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        int s;
        cin>>s;
        vector<int> dist(n,-1);
        find_dist(s-1,n,m,adj,&dist);
        for (int i = 0; i < n; ++i)
        {
            if(i==s-1)
                continue;
            if(i!=n-1)
                cout<<dist[i]<<" ";
            else
                cout<<dist[i]<<endl;
        }
    }
    return 0;

}