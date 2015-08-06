#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
long long a[MAXN][MAXN];
long long sumRow[MAXN];
int n;

int main(){
	cin >> n; char c;
	long long sum = 0;
	for(int i=0; i<n; ++i)
	for(int j=0; j<n; ++j){
		if (i==j) cin >> c;
		else cin >> a[i][j];

		sum += a[i][j];
		sumRow[i] += a[i][j];
	}

	sum = sum/(n-1);
	for(int i=0; i<n; ++i) a[i][i] = sum-sumRow[i];
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j){
			cout << a[i][j];
			if (j+1<n) cout << " "; else cout << "\n";
		}
}
