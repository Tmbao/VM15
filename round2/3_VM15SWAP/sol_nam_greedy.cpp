#include <bits/stdc++.h>
using namespace std;
const int limit = 1000 + 5;
int a[limit][limit];
int sumRow[limit], sumCol[limit];
int rowId[limit], colId[limit];
int result = 0;
int m,n;

struct Data{
	char type; int i, j;
	Data(char type, int i, int j) : type(type), i(i), j(j) {}	
};
vector<Data> step;

void mySort(int n, int id[], int sum[], char type){
	for(int i=0; i<n; ++i){
		int minIndex = i;
		for(int j=i+1; j<n; ++j)
			if (sum[ id[j] ] > sum[ id[minIndex] ])
				minIndex = j;
		swap(id[i], id[minIndex]);
		if (i != minIndex)
			step.push_back( Data(type, i+1, minIndex+1) );
	}
}	

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
	
	mySort(m, rowId, sumRow, 'R');
	mySort(n, colId, sumCol, 'C');
	
	int nn = -1;
	int x0 = -1, y0 = -2;
	for(int i=0,j=0; i<m; ++i){
		for(j=0; j<n && a[rowId[i]][colId[j]]; ++j);
		if (nn == -1 || nn>j-1) nn=j-1;
		if (nn < 0) break;
		if (result < i+nn+2) {
			result = i+nn+2;
			x0 = i+1;
			y0 = nn+1;
		}
	}
	
	if (result == max(m,n))
		cout << "0 0\n";
	else {
		cout << x0 << " " << y0 << "\n";
		cout << step.size() << "\n";
		for(int k=0; k<(int)step.size(); ++k)
			cout << step[k].type << " " << step[k].i << " " << step[k].j << "\n";
	}
}