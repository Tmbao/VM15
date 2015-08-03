#include <bits/stdc++.h>
using namespace std;
const int limit = 1000 + 5;
int a[limit][limit];
int sumRow[limit], sumCol[limit];
int rowId[limit], colId[limit];
int result = 0;
int m,n;

int main(){
	scanf("%d%d",&m,&n);
	for(int i=0; i<m; ++i)
	for(int j=0; j<n; ++j){
		scanf("%d",&a[i][j]);
		sumRow[i] += a[i][j];
		sumCol[j] += a[i][j];
	}
	
	for(int i=0; i<m; ++i) rowId[i] = i;
	for(int j=0; j<n; ++j) colId[j] = j;
	result = max(m,n);
	
	sort(rowId, rowId+m, [](int i, int j) {
		return sumRow[i] > sumRow[j];
	});
	
	sort(colId, colId+n, [](int i, int j) {
		return sumCol[i] > sumCol[j];
	});
	
	int nn = -1;
	for(int i=0,j=0; i<m; ++i){
		for(j=0; j<n && a[rowId[i]][colId[j]]; ++j);
		if (nn == -1 || nn>j-1) nn=j-1;
		if (nn < 0) break;
		result = max(result, i+nn+2);
	}
	cout << result << endl;


}