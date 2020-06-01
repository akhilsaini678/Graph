#include<bits/stdc++.h>
using namespace std;
#define ll   long long int

bool visited[100]={false},visited2[100]={false};
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
    st.push(start);
}



void strongly_conn_com(vector<ll> v[],ll start)
{
    visited2[start]=true;
    for(ll i=0;i!=v[start].size();i++)
    {
        if(visited2[v[start][i]]==false)
            strongly_conn_com(v,v[start][i]);
    }
}


//Main function
int main()
{
    ll nodes,x,y,start=1,count=0,edge;
    cin>>nodes>>edge;
    vector<ll> v[nodes+1],vtranspose[nodes+1];  
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        vtranspose[y].push_back(x);
    }
    for(ll i=1;i<=nodes;i++)
    {
    if(visited[i]==false)
    conn_comp(v,i);
    }
    while(!st.empty())
    {
        ll num=st.top();
        st.pop();
        if(visited2[num]==false)
        {
            count++;
            strongly_conn_com(vtranspose,num);
        }
    }
    cout<<count<<endl;
    return 0;
}