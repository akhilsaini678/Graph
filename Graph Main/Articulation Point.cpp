#include<bits/stdc++.h>
using namespace std;


void articulation_point(vector<int> graph[],int src,int parent,vector<bool> &visited,vector<int> &intime,vector<int> &outtime,int &time,vector<bool> &articulation)
{
	intime[src] = outtime[src] = time++;
	visited[src] = true;
	int child=0;
	for(auto it : graph[src])
	{
		if(it==parent) continue;
		if(visited[it]==false)
		{
			articulation_point(graph,it,src,visited,intime,outtime,time,articulation);
			outtime[src]=min(outtime[src],outtime[it]);
			if(outtime[it]>=intime[src]&&parent!=-1)
			{
				articulation[src]=true;
			}
			child++;
		}
		else
		{
			outtime[src]=min(intime[it],outtime[src]);
		}
	}

	if(parent==-1&&child>1)
	{
		articulation[src]=true;
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
	vector<bool> articulation(vertices,false);
	articulation_point(graph,0,-1,visited,intime,outtime,time,articulation);
	for(int i=0;i<vertices;i++) if(articulation[i]==true) cout<<i<<" "<<endl;
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