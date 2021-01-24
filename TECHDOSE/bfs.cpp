#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> g[], bool *vis) {
	queue<int> q;
	vis[s] = true;
	q.push(s);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		for(int i = 0; i < g[curr].size(); i++) {
			if(vis[g[curr][i]] == false) {
				q.push(g[curr][i]);
				vis[g[curr][i]] = true;
			}
		}
	}
}

int main(){
	int N, E;
	cin >> N >> E;
	std::vector<int> g[N];
	bool vis[N] = {false};

	int u, v;
	for(int i = 0; i < E; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	// for(int i = 0; i < N; i++)
	// 	if(vis[i] == false)
			bfs(2, g, vis);

	return 0;
}