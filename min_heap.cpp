#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> *heap,int index)
{
    if(index>=(*heap).size())
        return;
    int smallest = index;
    if(2*index+1<(*heap).size())
    {
        if((*heap)[2*index+1]<(*heap)[smallest])
        smallest = 2*index+1;
    }
    if(2*index+1<(*heap).size())
    {
        if((*heap)[2*index+2]<(*heap)[smallest])
            smallest = 2*index+2;
    }
    if(smallest!=index)
    {
        (*heap)[index] = (*heap)[smallest]+(*heap)[index]-((*heap)[smallest]=(*heap)[index]);
        heapify(heap,smallest);
    }
    
        
}

int extractmin(vector<int> *heap)
{
    
    int val = (*heap)[0];
    (*heap)[0] = (*heap).back();
    (*heap).pop_back();
    cout<<"hi"<<endl;
    heapify(heap,0);
    return val;
}


void insert(int val,vector<int> *heap)
{
    (*heap).push_back(val);
    int i = (*heap).size()-1;
    while(i!=0 && ((*heap)[i]<(*heap)[(int)((i-1)/2)]))
    {
        (*heap)[i] = (*heap)[i]+(*heap)[(int)((i-1)/2)]-((*heap)[(int)((i-1)/2)]=(*heap)[i]);
        i = (int)((i-1)/2);
    }
}


int main()

{
    vector<int> heap;
    while(1)
    {
        int c;
        cin>>c;
        if(c==-1)
            break;
        else if(c==-2)
        {
            for(int x:heap)
                cout<<x<<" ";
            cout<<endl;
        }
        else if(c==-3)
        {   
            if(heap.size()==0)
            {
                cout<<"Empty Heap"<<endl;
                continue;
            }
            cout<<extractmin(&heap)<<endl;
        }
        else
        {
            insert(c,&heap);
        }
        
    }
    return 0;
}
