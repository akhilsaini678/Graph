#include<bits/stdc++.h>
using namespace std;

bool cycledetect(vector<int> graph[],int src,vector<bool> &visited,vector<bool> &localvisited)
{
	localvisited[src] = visited[src] = true;
	for(auto it: graph[src])
	{
		if(visited[it]==false)
		{
			if(cycledetect(graph,it,visited,localvisited)) return true;
		}
		else if(localvisited[it]==true)
		{
			return true;
		}
	}
	localvisited[src]=false;
	return false;
}

void solve()
{

	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<int> graph[vertices+1];
	vector<int> indegree(vertices,0);
	bool sign=false;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		// graph[v].push_back(u);
	}

	vector<bool> visited(vertices+1,false);
	vector<bool> localvisited(vertices+1,false);

	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==false)
			if(cycledetect(graph,i,visited,localvisited))
			{
				sign=true;
				break;
			}
	}
	if(sign)
		cout<<"There is a cycle."<<endl;
	else
		cout<<"There is no cycle."<<endl;
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