#include<bits/stdc++.h>
using namespace std;
#define ll   long long int

bool visited[100]={false},local_visited[100]={false};    //boolean array to keep the track of visited nodes.


//Detect cycle in a directed graph.
bool dfs_cycle(vector<ll> v[],ll start)
{
    if(visited[start]==false)
    {
        visited[start]=true;
        local_visited[start]=true;
        for(ll i=0;i!=v[start].size();i++)
        {
        if(visited[v[start][i]]==false)
        {
            if(dfs_cycle(v,v[start][i]))         //Recursive Call To visit in depth.
             return true;
        }
        else
        {
            if(local_visited[v[start][i]]==true)       //If the next vertices is already visited in the current dfs cycle,
                return true;                          // then we must have traverse it already. So we have reached at the cycle.
        }
        }
    }
     local_visited[start]=false;           //Make the vertices in local bollean array as false again.
     return false;                        //If there is no cycle, then return false.
}


//Main function
int main()
{
    ll nodes,x,y,start=1,count=0,edge,parent=0;
    bool sign=false;
    cin>>nodes>>edge;
    vector<ll> v[nodes+1];
    for(ll i=0;i<edge;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
      //v[y].push_back(x);    //For directed graph make it as a comment.
    }
    for(ll i=1;i<=nodes;i++)
    {
        if(visited[i]==false)
        {
            if(dfs_cycle(v,i))  //If dfs_cycle = true then there must be a cycle.
                sign=true;
        }
    }
    if(sign)
        cout<<"There is a cycle."<<endl;
    else
        cout<<"There is no cycle."<<endl;
    return 0;
}