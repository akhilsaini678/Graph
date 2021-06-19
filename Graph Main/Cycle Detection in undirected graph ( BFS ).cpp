#include<bits/stdc++.h>
using namespace std;

bool cycle_detect(vector<int> graph[],int src,vector<bool> &visited)
{
	queue<pair<int,int>> q;
	q.push({src,-1});
	visited[src]=true;
	while(!q.empty())
	{
		pair<int,int> x = q.front();
		q.pop();
		for(auto it:graph[x.first])
		{
			if(visited[it]==false)
			{
				q.push({ it,x.first });
				visited[it]=true;
			}
			else if(it!=x.second)
			{
				return true;
			}
		}
	}
	return false;
}

void solve()
{

	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	bool sign = false;
	vector<int> graph[vertices+1];
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	vector<bool> visited(vertices+1,false);

	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==false)
			if(cycle_detect(graph,i,visited))
			{
				sign=true;
				break;
			}
	}
	if(sign)
		cout<<"There is a cycle.";
	else
		cout<<"There is no cycle.";
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