/*
 	Compile with C++11
	Example: 0, 21
	Test 1-8: 1<=m,n<=20
	Test 9-20: m,n<=1000
*/

#include "../../lib/testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
int a[MAXN][MAXN];
string PATH = "tests/";

string getString(int i){
	stringstream ss; ss<<i;
	return ss.str();
}

void swapRow(int i, int j, int n){
	for(int k=1; k<=n; ++k) swap(a[i][k], a[j][k]);
}

void swapCol(int i, int j, int m){
	for(int k=1; k<=m; ++k) swap(a[k][i], a[k][j]);
}

void genTest(int id, int m, int n, bool isExample = false){
	memset(a, 0, sizeof a);
	
	int minAnswer = rnd.next( max(m,n), m+n );
	int mm = rnd.next(minAnswer-n, m);
	int nn = minAnswer - mm;
	bool kill_greedy = rnd.next(3)==0;
	
	for(int i=1; i<=m; ++i)
	for(int j=1; j<=n; ++j)
		if ( (i<=mm && j<=nn) || (kill_greedy && i==mm+1 && j>n-nn-2) )
			a[i][j] = 1;
		else
			if (rnd.next(3)==0) a[i][j]=1;	
	
	//Random permutation
	for(int i=1; i<=m; ++i)
		swapRow(i, rnd.next(1,i), n);
	for(int i=1; i<=n; ++i)
		swapCol(i, rnd.next(1,i), m);
	
	if (isExample) a[1][1] = 0;
	
	ofstream fi(PATH+getString(id)+".in");	
	fi << m << " " << n << "\n";
	const char *ss = " \n";
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j) 
			fi << a[i][j] << ss[(int)(j==n)];
	
	fi.close();
	
	cerr << "Test #" << " " << id <<  endl;
}

void genSubtask(int from, int to, int loN, int hiN){
	for(int i=from; i<=to; ++i)
		genTest(
			i,
			rnd.next(loN, hiN),
			rnd.next(loN, hiN)			
		);
}

void genExample(){
	genTest(0,3,3,true);
	genTest(21,3,1,true);
}

int main(){
	rnd.setSeed(123456789);
	system("mkdir tests");
	genExample();
	genSubtask(1,8,1,20);
	genSubtask(9,18,200, 1000);	
	genSubtask(19,20,1000,1000);
}
