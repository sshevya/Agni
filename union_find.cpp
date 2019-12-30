#include<bits/stdc++.h>
using namespace std;

int find(vector<int> parent,int i)
{
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}

vector<int> Union(vector<int> parent,int x, int y)
{
    int xset = find(parent,x);
    int yset = find(parent,y);
    if(xset!=yset)
    {
        parent[xset] = yset;
    }   
    return parent;
}

int isCyclic(pair<int,int> pr[],int n,int m)
{
    vector<int> parent(n,-1);
    for(int i=0;i<m;i++)
    {
        int x = find(parent,pr[i].first);
        
        int y = find(parent,pr[i].second);
        if(x==y)
            return 1;
        parent = Union(parent,x,y);
        
    }
    return 0;
    
}

int main()
{
	int n,m;
    cin>>n>>m;
    pair<int,int> pr[m];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        pr[i].first = a-1;
        pr[i].second = b-1;
    }
    cout<<isCyclic(pr,n,m)<<endl;
	return 0;
}
