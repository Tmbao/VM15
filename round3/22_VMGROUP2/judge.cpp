#include "spoj.h"
#include <bits/stdc++.h>
using namespace std;

/*
	Output:
	The minimum needed value
	1..K next line, the ith line contain n/k integer denote vertex in group i
*/

const int MAX_N = 500 + 5;
const int MAX_LEN = 10000;
int n, m, k;
int a[MAX_N][MAX_N];
char tmp[MAX_LEN];
int group[MAX_N];

void read_input(){
	fscanf(spoj_p_in, "%d %d %d",&n,&m,&k);
	while (m--){
		int i, j;
		fscanf(spoj_p_in, "%d %d",&i,&j);
		a[i][j] = a[j][i] = 1;
	}
}

//return the output_score
int read_output(){
	int output_score;
	//read output score
	spoj_assert( fscanf(spoj_t_out, "%d\n", &output_score) == 1 );
	
	//read output group
	for(int i=1; i<=k; ++i){
		fgets(tmp, MAX_LEN, spoj_t_out);
		stringstream ss; ss << tmp;
		int cnt = 0;
		int value;
		while (ss >> value){
			cnt++;
			spoj_assert(1<=value && value<=n);
			spoj_assert(group[value] == 0);
			group[value] = i;
		}
		
		//Each line only contain n/k number
		spoj_assert(cnt == n/k);
	}
	
	return output_score;
}

void check_output_score(int output_score){
	for(int i=1; i<=n; ++i)
	for(int j=i+1; j<=n; ++j)
		if (group[i] != group[j])
			output_score -= a[i][j];	
	spoj_assert(output_score == 0);
}

int main(){
	spoj_init();
	
	read_input();
	int output_score = read_output();
	check_output_score(output_score);
	
	int sol_score; fscanf(spoj_p_out, "%d", &sol_score);
	double score = 1.*(sol_score+1)/(output_score+1);		
	fprintf(spoj_score,"%.6f", score);
}