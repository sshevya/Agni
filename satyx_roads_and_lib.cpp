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

long int roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
    long int comp = components(&cities,n);
    long int cost1 = c_road*(n-comp)+c_lib*comp;
    long int cost2 = (long int)(n)*c_lib;
        if(cost2>cost1)
            return cost1;
        else
            return cost2;

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
	    cout<<roadsAndLibraries(n,c_l,c_r,adj)<<endl;
        
    }
	return 0;
}
