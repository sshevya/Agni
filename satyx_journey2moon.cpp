#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.

int BFS(int pos,vector<bool> *visited,vector<vector<int>> astronaut)
{
    list<int> queue;
    queue.push_back(pos);
    (*visited)[pos]=true;
    int count = 0;
    while(!queue.empty())
    {
        count++;
        int x = queue.front();
        (*visited)[x] = true;
        queue.pop_front();
        for(int y:astronaut[x])
        {
        
            if(!(*visited)[y])
            {
                (*visited)[y] = true;
                queue.push_back(y);
            }
        }
    }
    return count;
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    int comp = 0;
    vector<int> count;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            int count_node = BFS(i,&visited,astronaut);
            count.push_back(count_node);
        }
    }
    
    
    int pnc = 0;
    int temp=0;
    for(int i=0;i<count.size();i++)
    {
        pnc += temp*count[i];
        temp += count[i];
    }
    return pnc;
}

int main()
{
    int n,p;
    cin>>n>>p;
    vector<vector<int>> astronaut(n,vector<int>(0));
    for(int i=0;i<p;i++)
    {
        int a,b;
        cin>>a>>b;
        astronaut[a].push_back(b);
        astronaut[b].push_back(a);
    }
    cout<<journeyToMoon(n,astronaut)<<endl;
    return 0;
}
