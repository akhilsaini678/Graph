#include<bits/stdc++.h>
using namespace std;

bool cycledetect(vector<int> graph[],int src,vector<bool> &visited,vector<int> &indegree)
{

	queue<int> q;

	for(int i=0;i<indegree.size();i++)
		if(indegree[i]==0)
		{
			visited[i]=true;
			q.push(i);
		}

	int count=0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		count++;
		// cout<<x<<endl;
		for(auto it:graph[x])
		{
			indegree[it]--;
			if(indegree[it]==0)
			{
				q.push(it);
				visited[it]=true;
			}
		}
	}
	if(count==indegree.size())
		return false;
	else
		return true;
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

	for(int i=0;i<vertices;i++)
		for(auto it:graph[i])
			indegree[it]++;

	vector<bool> visited(vertices+1,false);

	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==false)
			if(cycledetect(graph,i,visited,indegree))
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