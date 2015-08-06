/*
 	Test 1-12: -2000 <= a[i][j] <= 2000
	Test 13-20: -1e12 <= a[i][j] <= 1e12
*/
#include "../../lib/testlib.h"
#include <bits/stdc++.h>
using namespace std;

string PATH = "tests/";
const int MAXN = 100 + 5;
const long long MAX_VALUE = 10000000000LL;
long long a[MAXN][MAXN];
int n;

string getString(int i){
	stringstream ss; ss<<i;
	return ss.str();
}

void printTest(int id){
	ofstream fi(PATH+getString(id)+".in");
	fi << n << "\n";
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if (i==j) fi << "?";
			else fi << a[i][j];

			if (j<n) fi<<" "; else fi<<"\n";
		}			
	}
	fi.close();

	ofstream fo(PATH+getString(id)+".out");
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			fo << a[i][j];
			if (j<n) fo << " "; else fo<<"\n";
		}
	}
	fo.close();
	cerr << "Test " << id << endl;
}

void genExample(){
	n = 3;
	a[1][1] = 2; a[1][2] = 9; a[1][3] = 4;
	a[2][1] = 7; a[2][2] = 5; a[2][3] = 3;
	a[3][1] = 6; a[3][2] = 1; a[3][3] = 8;
	printTest(0);
}

bool checkBoard(long long minValue, long long maxValue){
	minValue *= 20; maxValue *= 20;
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)
		if (a[i][j]<minValue || maxValue<a[i][j]) return false;

	set<long long> sum;
	for(int i=1; i<=n; ++i){
		long long curSum = 0;
		for(int j=1; j<=n; ++j) curSum += a[i][j];
		sum.insert(curSum);
	}
	
	for(int j=1; j<=n; ++j){
		long long curSum = 0;
		for(int i=1; i<=n; ++i) curSum += a[i][j];
		sum.insert(curSum);
	}

	long long sum1 = 0, sum2 = 0;
	for(int i=1; i<=n; ++i){
		sum1 += a[i][i];
		sum2 += a[i][n-i+1];
	}

	sum.insert(sum1); sum.insert(sum2);
	return sum.size()==1;
}

//Does not work with n<4
void genBoard(long long minValue, long long maxValue){
	memset(a, 0, sizeof a);
	long long sum = 0;
	//First row
	for(int j=1; j<=n; ++j){
		a[1][j] = rnd.next(minValue,maxValue);
		sum += a[1][j];
	}
	
	for(int i=2; i+2<=n; ++i){
		long long curSum = 0;
		for(int j=1; j<n; ++j){
			a[i][j] = rnd.next(minValue, maxValue);
			curSum += a[i][j];
		}
		a[i][n] = sum - curSum;
	}

	//Next to last row
	a[n-1][1] = a[n-1][2] = rnd.next(minValue, maxValue);
	a[n-1][n-1] = a[n-1][n] = rnd.next(minValue, maxValue);
	for(int i=1; i<n-1; ++i){
		a[n-1][2] += a[i][1] - a[i][n-i+1];
		a[n-1][n-1] += a[i][n] - a[i][i];
	}
	for(int j=3; j<n-2; ++j)
		a[n-1][j] = rnd.next(minValue, maxValue);
	a[n-1][n-2] = sum;
	for(int j=1; j<=n; ++j)
		if (j!=n-2) a[n-1][n-2] -= a[n-1][j];

	//Last row
	for(int j=1; j<=n; ++j){
		long long curSum = 0;
		for(int i=1; i<n; ++i) curSum += a[i][j];
		a[n][j] = sum-curSum;
	}
}

void genTest(int id, int minN, int maxN, long long minValue, long long maxValue, bool canEven=true){
	do{
		n = rnd.next(minN, maxN);
	} while (n%2==0 && !canEven);

	do{
		genBoard(minValue, maxValue);
	}while (!checkBoard(minValue, maxValue));
	
	printTest(id);
}

int main(){
	rnd.setSeed(123456789);
	string command = "mkdir "+PATH;
	system(command.c_str());
	genExample();
	for(int i=1; i<=12; ++i) genTest(i, 4, 100, -100, 100);
	for(int i=13; i<=20; ++i) genTest(i, 50, 100, -MAX_VALUE, MAX_VALUE, false);
}
