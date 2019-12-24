#include <bits/stdc++.h>
#define INF 99999
using namespace std;

vector<string> split_string(string);

int main()
{
    int nodes;
    int edges;
    cin>>nodes>>edges;
    int ve[nodes][nodes];

   for(int i=0;i<nodes;i++){
       for(int j=0;j<nodes;j++){
           ve[i][j]=INF;
           if(i==j){
               ve[i][j]=0;
           }
       }
   }



    for(int i=0;i<edges;i++){
        int u,v,w;
      cin >> u >> v >> w;
      ve[u-1][v-1]=w;  
    }
    int i, j, k;
    for(k=0;k<nodes;k++){
        for(i=0;i<nodes;i++){
            for(j=0;j<nodes;j++){
                    if(ve[i][k]+ve[k][j]<ve[i][j]){
                        ve[i][j]=ve[i][k]+ve[k][j];
                    }
            }
        }

    }
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int u,v;
       cin>>u>>v;
       if(ve[u-1][v-1]==INF){
           cout<<-1<<endl;
       }else{
       cout<<ve[u-1][v-1]<<endl;
       }
    }
   


    return 0;
}


