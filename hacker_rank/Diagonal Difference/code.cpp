#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector< vector<int> > a(n,vector<int>(n));
	for(int a_i = 0;a_i < n;a_i++){
		for(int a_j = 0;a_j < n;a_j++){
			cin >> a[a_i][a_j];
		}
	}
	int j = 0;
	int sum_1 = 0;
	for(int i = 0; i < n; i++){
		sum_1 += a[i][j];
		j++;
	}
	int k = 0;
	int sum_2 = 0;
	for(int m = n - 1; m >= 0; m--){
		sum_2 += a[m][k];
		k++;
	}
	int sub = sum_1 - sum_2;
	if(sub < 0) sub *= -1;
	cout << sub << endl;
	return 0;
}
