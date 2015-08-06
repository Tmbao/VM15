#include "../../lib/testlib.h"
#include <bits/stdc++.h>
using namespace std;

const long long MAX_VALUE = 1000000000000LL;

int main(){
	registerValidation();
	int n = inf.readInt(1,100,"n");
	inf.readEoln();
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j){
			if (i==j)
				inf.readLong(0,0);
			else
				inf.readLong(-MAX_VALUE, MAX_VALUE);

			if (j+1<n)
				inf.readSpace();
			else
				inf.readEoln();
		}

	inf.readEof();
}
