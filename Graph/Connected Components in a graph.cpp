#include<bits/stdc++.h>
using namespace std;
#define ll   long long int

bool visited[100]={false};
stack<ll> st;

//Connected Components in a graph.
void conn_comp(vector<ll> v[],ll start)
{
    visited[start]=true;
    for(ll i=0;i!=v[start].size();i++)
    {
        if(visited[v[start][i]]==false)
            conn_comp(v,v[start][i]);
    }
}


//Main function
int main()
{
    ll nodes,x,y,start=1,count=0,edge;
    cin>>nodes>>edge;
    vector<ll> v[nodes+1];     
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(ll i=1;i<=nodes;i++)
    {
    if(visited[i]==false)
    {
        count++;
        conn_comp(v,i);
    }
    }
    cout<<count<<endl;
    return 0;
}
