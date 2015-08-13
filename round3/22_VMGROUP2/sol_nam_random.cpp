#include <bits/stdc++.h>

using namespace std;

const int limit = 500 + 5;
int a[limit][limit];
int result;
int n, m, k;
vector<int> result_group;

int calculate(const vector<int>& cur){
	int result = 0;
	int sz = n/k;
	for(int i=0; i<n; ++i)
	for(int j=i+1; j<n; ++j)
		if (i/sz != j/sz) result += a[ cur[i] ][ cur[j] ];
	return result;
		
}

int main(){	
	scanf("%d %d %d",&n,&m,&k);
	while (m--){
		int i, j; scanf("%d%d",&i,&j);
		a[i-1][j-1] = a[j-1][i-1] = 1;
	}
	
	srand(123456789);
	vector<int> cur; for(int i=0; i<n; ++i) cur.push_back(i);
	
	result = n*n;
	for(int iter=0; iter < 100; ++iter){
		random_shuffle(cur.begin(), cur.end());
		int cur_cost = calculate(cur);
		if (cur_cost < result){
			result = cur_cost;
			result_group = cur;
		}
		//next_permutation(cur.begin(), cur.end());
	}
	
	cout << result << endl;
	int sz = n/k;
	for(int i=0; i<n; ++i){
		cout << result_group[i]+1;
		if (i%sz == sz-1) cout << "\n"; else cout << " ";
	}
	
}