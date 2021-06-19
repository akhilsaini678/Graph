#include<bits/stdc++.h>
using namespace std;


void bridges(vector<int> graph[],int src,int parent,vector<bool> &visited,vector<int> &intime,vector<int> &outtime,int &time)
{
	intime[src] = outtime[src] = time++;
	visited[src] = true;
	for(auto it : graph[src])
	{
		if(it==parent) continue;
		if(visited[it]==false)
		{
			bridges(graph,it,src,visited,intime,outtime,time);
			outtime[src]=min(outtime[src],outtime[it]);
			if(outtime[it]>intime[src])
			{
				cout<<src<<" <-> "<<it<<endl;
			}
		}
		else
		{
			outtime[src]=min(intime[it],outtime[src]);
		}
	}
}


void solve()
{

	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<int> graph[vertices+1];
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int time = 0;
	vector<int> intime(vertices);
	vector<int> outtime(vertices);
	vector<bool> visited(vertices);
	bridges(graph,0,-1,visited,intime,outtime,time);
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