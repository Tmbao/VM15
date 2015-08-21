#include <cstdio>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n, k;
int w[100010];
vector<int> adj[100010];
vector<int> c_weight[100010];

pair<int, int> greedy(int u, int par, const int &limit) {
	int n_subtree = 0;

	int t_weight = w[u];
	c_weight[u].clear();

	for (int v : adj[u]) {
		if (v != par) {
			pair<int, int> x = greedy(v, u, limit);
			n_subtree += x.first;
			c_weight[u].push_back(x.second);
		}
	}

	sort(c_weight[u].begin(), c_weight[u].end());
	for (int i = 0; i < c_weight[u].size(); i++) {
		if (t_weight + c_weight[u][i] > limit) {
			n_subtree += c_weight[u].size() - i;
			break;
		} 
		t_weight += c_weight[u][i];
	}

	return make_pair(n_subtree, t_weight);
}

bool check(int limit) {
	return greedy(1, 0, limit).first <= k;
}

int main() {
	scanf("%d%d", &n, &k);
	int l = 0, r = 1e9;
	for (int i = 1; i <= n; i++) {
		scanf("%d", w + i);
		l = max(l, w[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while (l < r) {
		int mid = (l + r) / 2;
		if (!check(mid)) l = mid + 1;
		else r = mid;
	}

	printf("%d", l);
	return 0;
}