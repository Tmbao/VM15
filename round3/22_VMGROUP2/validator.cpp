/*
 	Input
	n m k
	next m lines denote edge i j
*/

#include "../../lib/testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	registerValidation();

	int n = inf.readInt(1,500,"n");
	inf.readSpace();
	int m = inf.readInt(1,n*(n-1)/2,"m");
	inf.readSpace();
	int k = inf.readInt(1,n,"k");
	inf.readEoln();
	ensuref(n%k==0, "n mod k must be 0");

	while (m--){
		inf.readInt(1,n,"i");
		inf.readSpace();
		inf.readInt(1,n,"j");		
		inf.readEoln();
	}
	inf.readEof();

}
