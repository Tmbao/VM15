#include "../../lib/testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	registerValidation();
	int m = inf.readInt(1,1000,"m");
	inf.readSpace();
	int n = inf.readInt(1,1000,"n");
	inf.readEoln();
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j){
			inf.readInt(0,1);
			if (j+1==n)
				inf.readEoln();
			else
				inf.readSpace();
		}
	inf.readEof();
}
