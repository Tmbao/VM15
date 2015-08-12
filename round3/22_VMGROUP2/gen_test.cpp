#include "../../lib/testlib.h"
#include <bits/stdc++.h>

/*
	1 <= N <= 500
	40% sparse graph
	50% dense graph
	10% random graph
*/

using namespace std;
const int MAXN = 500;
vector<int> composite;


string getString(int id){
	stringstream ss; ss << id;
	return ss.str();
}

void genTest(int id, int n, int k, double density){
	cerr << "Test #" << " " << id << endl;		
		
	vector< pair<int,int> > edge;
	for(int i=1; i<=n; ++i)
	for(int j=i+1; j<=n; ++j)
		if (rnd.next() < density)
			edge.push_back( make_pair(i,j) );
			
	ofstream f("tests/" + getString(id)+".in");	
	f << n << " " << edge.size() << " " << k << endl;
	for(int k=0; k<(int)edge.size(); ++k)
		f << edge[k].first << " " << edge[k].second << endl;
	f.close();
}

void genExample(){
	genTest(0, 6, 3, 0.5);
}

void init_composite(){
	vector<bool> b(MAXN+1, false);
	for(int i=2; i*i<=MAXN; ++i)
		if (!b[i])
			for(int j=i*i; j<=MAXN; j+=i)
				b[j] = true;
				
	for(int i=4; i<=MAXN; ++i)
		if (b[i])
			composite.push_back(i);
}

int main(){
	init_composite();
	rnd.setSeed(123456789);
	mkdir("tests");	
	genExample();
	for(int i=1; i<60; ++i){
		int type = rnd.next(10);
		double density = 1;
		if (type < 4)
			density = rnd.next(0.3); //sparse graph
		else if (type < 9)
			density = rnd.next(0.5,0.8); //dense graph
		else
			density = rnd.next();
		
		int k = rnd.next(2,50);
		int sz = rnd.next(2, MAXN/k);
		int n = k*sz;
		genTest(i, n, k, density);	
	}

}

