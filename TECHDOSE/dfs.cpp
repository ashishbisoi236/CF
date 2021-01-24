#include<bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> g[], bool*vis){
	vis[s] = true;
	cout << s << " ";
	for(int i = 0; i < g[s].size(); i++){
		if(vis[g[s][i]] == false)
			dfs(g[s][i], g, vis);
	}
}

int main(){
	int N,E;
	cin >> N >> E;

	// adjacency list 
	vector<int> g[N];
	bool vis[N];
	memset(vis, false, sizeof(vis));

	int u, v;
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	// for directed graph also
	for(int i = 0; i < N; i++)
		if(vis[i] == false)
			dfs(i, g, vis);
	cout << "\n";
}