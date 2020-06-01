#include<bits/stdc++.h>
using namespace std;
#define ll   long long int

bool visited[100]={false};    //boolean array to keep the track of visited nodes.


//Detect cycle in an undirected graph.
bool dfs_cycle(vector<ll> v[],ll start,ll parent)
{
    visited[start]=true;
    for(ll i=0;i!=v[start].size();i++)
    {
        if(visited[v[start][i]]==false)
        {
            if(dfs_cycle(v,v[start][i],start))         //Recursive Call To visit in depth.
             return true;
        }
        else
        {
            if(v[start][i]!=parent)       //If the next vertices is already visited, and it is not parent,
                return true;              // then we must have traverse it already. So we have reached at the cycle.
        }
    }
     return false;              //If there is no cycle, then return false.
}


//Main function
int main()
{
    ll nodes,x,y,start=1,count=0,edge,parent=0;
    cin>>nodes>>edge;
    vector<ll> v[nodes+1];       //Array of vector to store the edges.
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);    //For directed graph make it as a comment.
    }
    if(dfs_cycle(v,start,parent))
        cout<<"There is a cycle."<<endl;
    else
        cout<<"There is no cycle."<<endl;
    return 0;
}