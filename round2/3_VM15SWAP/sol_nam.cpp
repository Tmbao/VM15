/* 
 	Ouput format:

	if (x0+y0 > max(m,n))
		x0 y0
		num swap
		R i j (swapRow(i,j)) or 
		C i j (swapCol(i,j))

	if (x0+y0 <= max(m,n)) should output "0 0"
*/

#include <bits/stdc++.h>
using namespace std;

struct Result{
	char type; int i, j;
	Result(char type, int i, int j) : type(type), i(i), j(j) {}
};

ostream& operator << (ostream& os, const Result& r){
	os << r.type << " " << r.i << " " << r.j;
	return os;
}

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

	if ( (int)(result_x.size() + result_y.size()) <= max(m,n) ){
		cout << "0 0\n";
		return;
	}

	vector<Result> result;
	set<int> :: iterator p;
	p = result_x.begin();
	for(int i=0; i<(int)result_x.size(); ++i, ++p)
		if (i != (*p))
			result.push_back( Result('R', i+1, (*p)+1 ) );
	
	p = result_y.begin();
	for(int i=0; i<(int)result_y.size(); ++i, ++p)
		if (i != (*p))
			result.push_back( Result('C', (*p)+1, i+1 ) );

	cout << result_x.size() << " " << result_y.size() << "\n";
	cout << result.size() << "\n";
	for(int i=0; i<(int)result.size(); ++i)
		cout << result[i] << "\n";
}

int main(){
	input();
	matching();
	print();
}
