#include<bits/stdc++.h>
using namespace std;


void shortest_path(vector<pair<int,int>> graph[],int src,vector<int> &distance,stack<int> &st)
{
	distance[src]=0;
	while(!st.empty())
	{
		int x = st.top();
		st.pop();
		if(distance[x]!=1e9)
		{
			for(auto it : graph[x])
			{
				if(distance[x]+it.second<distance[it.first])
				{
					distance[it.first]=distance[x]+it.second;
				}
			}
		}
	}	
}

void toposort(vector<pair<int,int>> graph[],int src,vector<bool> &visited,stack<int> &st)
{
	visited[src]=true;
	for(auto it : graph[src])
	{
		if(visited[it.first]==false)
			toposort(graph,it.first,visited,st);
	}
	st.push(src);
}

void solve()
{

	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<pair<int,int>> graph[vertices+1];
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph[u].push_back({v,weight});
		// graph[v].push_back(u);
	}
	stack<int> st;
	vector<bool> visited(vertices+1,false);
	vector<int> distance(vertices,1e9);
	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==false)
			toposort(graph,i,visited,st);	
	}

	shortest_path(graph,0,distance,st);
	for(auto it : distance)
	{
		cout<<it<<" ";
	}
	cout<<endl;
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