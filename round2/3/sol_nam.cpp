#include <bits/stdc++.h>
using namespace std;

const int limit = 1000 + 5;
int a[limit][limit];
int m,n;
int cnt_match = 0;
int match_x[limit], match_y[limit];
bool b[limit];

void input(){
	scanf("%d%d",&m,&n);
	for(int i=0; i<m; ++i)
	for(int j=0; j<n; ++j){
		scanf("%d",&a[i][j]);
		a[i][j] ^= 1;
	}
}

bool visit(int i){
	if (i == -1) return true;
	if (b[i]) return false;
	b[i] = true;
	
	for(int j=0; j<n; ++j)
		if (a[i][j] && visit(match_y[j])){
			match_x[i] = j;
			match_y[j] = i;
			return true;
		}	
	return false;
}


void matching(){
	memset(match_x, -1, sizeof match_x);
	memset(match_y, -1, sizeof match_y);
	for(int old=-1; old!=cnt_match; ){
		memset(b, false, sizeof b); old = cnt_match;
		for(int i=0; i<m; ++i)
			if (match_x[i]==-1 && visit(i)) cnt_match++;
	}	
}

void print(){
	set<int> result_x, result_y;
	for(int i=0; i<m; ++i) result_x.insert(i);
	for(int j=0; j<n; ++j) result_y.insert(j);
	
	for(int i=0; i<m; ++i)
		if (match_x[i] != -1){
			if (b[i]){
				for(int j=0; j<n; ++j)
					if (a[i][j]) result_y.erase(j);
			} else {
				result_x.erase(i);
			}		
		}
		
	for(int i: result_x)
	for(int j: result_y) assert(a[i][j]==0);
			
}

int main(){
	using namespace chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	input();
	matching();
	print();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);	
	cerr << time_span.count() << endl;
}