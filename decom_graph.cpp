#include<bits/stdc++.h>
using namespace std;
#define pb push_back


int update(int x,vector<vector<int> > *adj,vector<bool> visited)
{
    visited[x]=true;
    int count=0;
    for(int nbr:(*adj)[x])
    {
        if(!visited[nbr])
        {
            visited[nbr]=true;
            count+=update(nbr,adj,visited)+1;
        }
    }
    return count;
}

void insert(int a,int b,int n,vector<vector<int> > *adj,vector<int> *n_count,std::vector<int> *pred)
{
        (*adj)[a].pb(b);
        vector<bool> visited(n,false);
        (*pred)[b] = a;
        int temp;
        int ind = a;
        while(ind!=-1)
        {
            (*n_count)[ind] += update(b,adj,visited)+1;
            //cout<<ind+1<<":count:"<<(*n_count)[ind]<<endl;
            ind = (*pred)[ind];
        }
}


void DFS(int x,vector<vector<int> > adj, vector<int> n_count, int *count,vector<bool> *visited)
{
    (*visited)[x]=true;
    
    for(int nbr:adj[x])
    {
        if(!(*visited)[nbr])
        {
            //cout<<nbr<<":nbr:"<<n_count[nbr]<<endl;

            if(n_count[nbr]%2!=0)
                (*count)++;
            (*visited)[nbr] = true;
            DFS(nbr,adj,n_count,count,visited);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n,vector<int>(0));
    std::vector<int> n_count(n,0);
    vector<int> pred(n,-1);
    for (int i = 0; i < m; ++i)
    {
        int a,b;
        cin>>a>>b;
        insert(b-1,a-1,n,&adj,&n_count,&pred);
        
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<n_count[i]<<endl;
    }*/
    int count = 0;
    std::vector<bool> visited(n,false);
    DFS(0,adj,n_count,&count,&visited);
    cout<<count<<endl;
    return 0;

}