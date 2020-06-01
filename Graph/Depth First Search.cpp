#include<bits/stdc++.h>
using namespace std;
#define ll   long long int

bool visited[100]={false};    //boolean array to keep the track of visited nodes.


//DFS
void dfs(vector<ll> v[],ll start)
{
    visited[start]=true;
    cout<<start<<" ";
    for(ll i=0;i!=v[start].size();i++)
    {
        if(visited[v[start][i]]==false)
            dfs(v,v[start][i]);         //Recursive Call To visit in depth.
    }
}


//Main function
int main()
{
    ll nodes,x,y,start=1,count=0,edge;
    cin>>nodes>>edge;
    vector<ll> v[nodes+1];       //Array of vector to store the edges.
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);    //For directed graph make it as a comment.
    }
    dfs(v,start);
    return 0;
}