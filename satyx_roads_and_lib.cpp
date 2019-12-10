#include<bits/stdc++.h>
using namespace std;

void BFS(int i,vector<vector<int> > *adj, vector<bool> *visited)
{
     
    list<int> queue;
    queue.push_back(i);

    while(!queue.empty())
    {
        int x = queue.front();
        (*visited)[x] = true;
        queue.pop_front();
        for(int z:(*adj)[x])
        {
            if(!(*visited)[z])
            {
                queue.push_back(z);
                (*visited)[z] = true;
            }
        }        
    }
}

int components(vector<vector<int> > *adj,int n)
{
    vector<bool> visited(n,false);
    int count = 0;
    for(int i=0;i<(*adj).size();i++)
    {
        
        if(!visited[i])
        {
            count++;
            BFS(i,adj,&visited);
        }
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,m,c_r,c_l;
        cin>>n>>m>>c_l>>c_r;
        vector<int> parent(n,-1);
        vector<int> key(n,INT_MAX);
        vector<vector<int> > adj(n,vector<int> (0));
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
                                           
        }
	   
        int comp = components(&adj,n);
        if(n*c_l>c_r*(n-comp)+c_l*comp)
            cout<<c_r*(n-comp)+c_l*comp<<endl;
        else
            cout<<n*c_l<<endl;
    }
	return 0;
}
