#include<bits/stdc++.h>
using namespace std;

bool cycle_detect(vector<int> graph[],int src,int prev,vector<bool> &visited)
{
	visited[src]=true;
	for(auto it : graph[src])
	{
		if(visited[it]==false)
		{
			if(cycle_detect(graph,it,src,visited)) return true;
		}
		else if(it!=prev)
		{
			return true;
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
			if(cycle_detect(graph,i,-1,visited))
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