#include <io.h>
#include "../../lib/testlib.h"

#include <cstdio>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#ifndef to_string
string to_string(int n) {
	stringstream ss;
	string s;
	ss << n;
	ss >> s;
	return s;
}
#endif


int n, k;
int w[100010];
vector<int> adj[100010];

pair<int, int> greedy(int u, int par, const int &limit) {
	int n_subtree = 0;

	int t_weight = w[u];
	vector<int> c_weight;

	for (int v : adj[u]) {
		if (v != par) {
			pair<int, int> x = greedy(v, u, limit);
			n_subtree += x.first;
			c_weight.push_back(x.second);
		}
	}

	sort(c_weight.begin(), c_weight.end());
	for (int i = 0; i < c_weight.size(); i++) {
		if (t_weight + c_weight[i] > limit) {
			n_subtree += c_weight.size() - i;
			break;
		} 
		t_weight += c_weight[i];
	}

	return make_pair(n_subtree, t_weight);
}

bool check(int limit) {
	return greedy(1, 0, limit).first <= k;
}

void solution() {
	scanf("%d%d", &n, &k);
	int l = 0, r = 1e9;
	for (int i = 1; i <= n; i++) {
		scanf("%d", w + i);
		l = max(l, w[i]);
		adj[i].clear();
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
}

void gen_test(int id, int n, int k, int x, int w) {

	// Generate Input
	string in_name = "tests/" + to_string(id) + ".in";
	freopen(in_name.c_str(), "w", stdout);

	printf("%d %d\n", n, k);
	for (int i = 1; i <= n; i++) {
		printf("%d", rnd.next(1, w));
		if (i < n) printf(" ");
		else printf("\n");
	}
	for (int i = 2; i <= n; i++) {
		int u, v = i;
		if (x) {
			u = i - rnd.next(1, x);
			if (u < 1) u = 1;
		}
		else
			u = rnd.next(1, i - 1);
		printf("%d %d\n", u, v);
	}

	fclose(stdout);

	// Generate Output
	string out_name = "tests/" + to_string(id) + ".out";
	freopen(in_name.c_str(), "r", stdin);
	freopen(out_name.c_str(), "w", stdout);

	solution();

	fclose(stdin);
	fclose(stdout);
}

// 10 tests / subtask
void gen_subtask(int id, int n, int w) {
	// Normal tree: 4 tests
	gen_test(id + 1, n, rnd.next(1, n), 0, w);
	gen_test(id + 2, n, rnd.next(1, n), 0, w);
	gen_test(id + 3, n, rnd.next(1, n / 5), 0, w);
	gen_test(id + 4, n, rnd.next(4 * n / 5, n), 0, w);

	// Deep tree
	gen_test(id + 5, n, rnd.next(1, n / 5), 1, w);
	gen_test(id + 6, n, rnd.next(4 * n / 5, n), 1, w);
	gen_test(id + 7, n, rnd.next(1, n / 5), 4, w);
	gen_test(id + 8, n, rnd.next(4 * n / 5, n), 4, w);

	// Shallow tree
	gen_test(id + 9, n, rnd.next(1, n / 5), 1000000, w);
	gen_test(id + 10, n, rnd.next(4 * n / 5, n), 10000000, w);
}

void gen_all_tests() {
	// Subtask 1: n <= 20 - 20%
	gen_subtask(0, 20, 10000);
	// Subtask 2: n <= 200 - 20%
	gen_subtask(10, 200, 10000);
	// Subtask 3: n <= 1000, w == 1 - 20%
	gen_subtask(20, 1000, 1);
	// Subtask 4: n <= 100000 - 20%
	gen_subtask(30, 100000, 10000);
	// Subtask 5: n <= 100000 - 20%
	gen_subtask(40, 100000, 10000);
}

int main() {
	for (int i = 0; i < 50; i++)
		cout << "#" << i << " ";
	return 0;
	rnd.setSeed(123456789);
	system("mkdir tests");
	gen_all_tests();
	return 0;
}