#include<bits/stdc++.h>
using namespace std;
#define ll            long long int
#define infinite      1e18+1

//Shortest Path
void shortest_path(vector<ll> v[],ll start)
{
    bool visited[100]={false};
    vector<ll> distance(100,infinite);   
    queue<ll> q;
    q.push(start);
    distance[start]=0;
    while(!q.empty())   
    {
        ll x=q.front();
        if(visited[x]==true)
        continue;   
        visited[x]=true;
        q.pop();
        for(ll i=0;i!=v[x].size();i++)
        {
            if(distance[v[x][i]]>distance[x]+1)
            {
                distance[v[x][i]]=distance[x]+1;
                q.push(v[x][i]);
            }
        }
    }
    for(ll i=1;i<=6;i++)
    {
        cout<<distance[i]<<" ";
    }
}



int main()
{
    ll nodes,i,x,y,start=1,count=0,edge;
    cin>>nodes>>edge;
    vector<ll> v[nodes+1];   
    for(i=0;i<edge;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    shortest_path(v,start);
    return 0;
}