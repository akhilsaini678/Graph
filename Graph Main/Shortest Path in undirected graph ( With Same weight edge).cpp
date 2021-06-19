#include<bits/stdc++.h>
using namespace std;

void shortest_path(vector<pair<int,int>> graph[],int src,vector<int> &distance)
{
	queue<int> q;
	q.push(src);
	distance[src]=0;
	while(!q.empty())
	{
		int x= q.front();
		q.pop();
		for(auto it : graph[x])
		{
			if(distance[x]+it.second<distance[it.first])
			{
				distance[it.first]=distance[x]+it.second;
				q.push(it.first);
			}
		}
	}
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
		graph[v].push_back({u,weight});
	}

	vector<int> distance(vertices,1e9);

	shortest_path(graph,0,distance);

	for(int i=0;i<vertices;i++)
	{
		cout<<distance[i]<<" ";
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