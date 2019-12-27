#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int dist(std::vector<std::vector<int> > adj,std::vector<std::vector<int> > dad)
{
    int l;
    cin>>l;
    for (int i = 0; i < l; ++i)
    {
        //cout<<"ladder:";
        int a,b;
        cin>>a;
        cin>>b;
        for(int x:dad[a-1])
        {
            replace(adj[x].begin(),adj[x].end(),a-1,b-1);
            replace(dad[b-1].begin(),dad[b-1].end(),a-1,x);
        }
        adj[a-1].clear();
    }
    int s;
    cin>>s;
    for (int i = 0; i < s; ++i)
    {
        //cout<<"snake:";
        int a,b;
        cin>>a;
        cin>>b;
        for(int x:dad[a-1])
        {
            replace(adj[x].begin(),adj[x].end(),a-1,b-1);
            replace(dad[b-1].begin(),dad[b-1].end(),a-1,x);
        }
        adj[a-1].clear();
    }

    std::vector<int> pred(100,-1);
    pred[0] = 0;
    list<int> q;
    std::vector<int> min_d(100,INT_MAX);
    std::vector<bool> v(100,false);
    q.pb(0);
    min_d[0] = 0;
    v[0]=true;
    //cout<<"ready"<<endl;
    while(!q.empty())
    {

        int x = q.front();
        //cout<<x<<"->inside while"<<endl;
        q.pop_front();
        if(min_d[x]>min_d[pred[x]]+1)
            min_d[x] = min_d[pred[x]]+1;
        for(int nbr:adj[x])
        {
            if(!v[nbr])
            {
                v[nbr] = true;
                q.pb(nbr);
                pred[nbr] = x;
                   
            }
        }
    }
    return min_d[99]==INT_MAX?-1:min_d[99];

}

int main()
{
    int t;
    std::vector<std::vector<int> > adj(100,std::vector<int>(0));
    std::vector<std::vector<int> > dad(100,std::vector<int>(0));
        for (int i = 0; i < 100-1; ++i)
        {
            //cout<<"hey\n";
            for(int j=1;j<=min(6,99-i);j++)
            {
                adj[i].pb(i+j);
                dad[i+j].pb(i);
            }
        }
    cin>>t;
    while(t-->0)
    {

        cout<<dist(adj,dad)<<endl;
    }
    return 0;
    
}