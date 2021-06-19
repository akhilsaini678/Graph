#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int> graph[],int src,vector<bool> &visited)
{
	visited[src]=true;
	for(auto it : graph[src])
	{
		if(visited[it]==false)
			dfs(graph,it,visited);
	}
}


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

	int vertices,edge,u,v,weight;
	cin>>vertices>>edge;
	vector<int> graph[vertices+1];
	vector<int> transpose[vertices+1];
	vector<bool> visited(vertices,false);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
	}

	stack<int> st;
	toposort(graph,0,visited,st);

	for(int i=0;i<vertices;i++)
	{
		visited[i]=false;
		for(auto it : graph[i])
			transpose[it].push_back(i);
	}

	int count=0;
	while(!st.empty())
	{
		int x = st.top();
		// cout<<x<<endl;
		st.pop();
		if(visited[x]==false)
		{
			count++;
			dfs(transpose,x,visited);
		}
	}
	cout<<count<<endl;
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