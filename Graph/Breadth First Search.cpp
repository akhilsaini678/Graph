#include<bits/stdc++.h>
using namespace std;
#define ll   long long int

//BFS
void bfs(vector<ll> v[],ll start)
{
    bool visited[100]={false};   //boolean array to keep the track of visited nodes.
    queue<ll> q;
    q.push(start);         //Push the first element from where you want to traverse.
    visited[start]=true;
    while(!q.empty())     
    {
        ll x=q.front();
        cout<<x<<" ";      //Printing the vertices of the graph
        q.pop();
        for(ll i=0;i!=v[x].size();i++)
        {
            if(visited[v[x][i]]==false)
            {
                visited[v[x][i]]=true;
                q.push(v[x][i]);
            }
        }
    }
}



int main()
{
    ll n,i,x,y,start=1,count=0,edge;
    cin>>n>>edge;
    vector<ll> v[n+1];       //Array of vector to store the edges.
    for(i=0;i<edge;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);    //For directed graph make it as a comment.
    }
    bfs(v,start);
    return 0;
}
