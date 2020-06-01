#include<bits/stdc++.h>
using namespace std;
#define ll   long long int

bool visited[100]={false};
stack<ll> st;

//Topological Sorting
void topological_sort(vector<ll> v[],ll start)
{
    visited[start]=true;
    for(ll i=0;i!=v[start].size();i++)
    {
        if(visited[v[start][i]]==false)
            topological_sort(v,v[start][i]);
    }
    st.push(start);
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
        //v[y].push_back(x);
    }
    for(ll i=0;i<nodes;i++)
    {
    if(visited[i]==false)
    {
        topological_sort(v,i);
    }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}