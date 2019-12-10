#include<bits/stdc++.h>
using namespace std;


int find(vector<int> parent,int i)
{
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}

void Union(vector<int> *parent,vector<int> *rank,int x, int y)
{
    int xset = find(*parent,x);
    int yset = find(*parent,y);
    if(xset==yset)
    {
        (*parent)[xset] = yset;
        (*rank)[yset]++;
    }
    else if((*rank)[xset]>(*rank)[yset])
    {
        (*parent)[yset] = xset;
    }
    else
    {
        (*parent)[xset] = yset;
    }
    //return parent;
}

int kruskal(int n,vector<int> src, vector<int> des, vector<int> w)
{
    vector<int> parent(n,-1);
    vector<int> rank(n,0);
    pair<int,pair<int,int> > pr[w.size()];
    vector<pair<int,int> > adj;
    for(int i=0;i<w.size();i++)
    {
        pr[i].first = w[i];
        (pr[i].second).first = src[i];
        (pr[i].second).second = des[i];
    }
    
    sort(pr,pr+w.size());
    

    int sum = 0;

    for(int i=0;i<w.size();i++)
    {
        
        adj.push_back(make_pair((pr[i].second).first,(pr[i].second).second));
        int x = find(parent,(pr[i].second).first);
        int y = find(parent,(pr[i].second).second);
        
        if(x!=y)
        {
                    sum+=pr[i].first;
                    Union(&parent,&rank,x,y);
        }
        else
        {
            adj.pop_back();
        }
        
    }
    
    return sum;
    
}

int main()
{
	int n,e;
	cin>>n>>e;
	
	vector<int> src(e);
	vector<int> des(e);
	vector<int> weight(e);
	
	for(int i=0;i<e;i++)
	{
	    int a,b,w;
	    cin>>a>>b>>w;
	    src[i]=a-1;
	    des[i]=b-1;
	    weight[i]=w;
	}
    
	cout<<kruskal(n,src,des,weight)<<endl;
	return 0;
}
