#include<bits/stdc++.h>
using namespace std;

void toposort(vector<int> graph[],int src,vector<bool> &visited,stack<int> &st)
{
	visited[src]=true;
	for(auto it : graph[src])
	{
		if(visited[it]==false)
			toposort(graph,it,visited,st);
	}
	st.push(src);
}

void solve()
{

	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<int> graph[vertices+1];
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		// graph[v].push_back(u);
	}
	stack<int> st;
	vector<bool> visited(vertices+1,false);
	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==false)
			toposort(graph,i,visited,st);	
	}
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
}

void fast()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("D:\\Online\\Coding\\Contest\\input.txt","r",stdin);
	freopen("D:\\Online\\Coding\\Contest\\output.txt","w",stdout);
	#endif
}

int main()
{
	fast();
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}