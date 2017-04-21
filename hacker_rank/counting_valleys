#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

int main(){
	vector<char> chr_array;
	string str;
	int number;
	cin >> number;
	cin >> str;
	for(int i = 0; i < number; i++){
		chr_array.push_back(str[i]);
	}
	bool is_lower = false;
	int sea_level = 0;
	int pos = sea_level;
	int valley = 0;
	for(int i = 0; i < chr_array.size(); i++){
		if(chr_array[i] == 'U'){
			pos++;
			if(pos >= sea_level && is_lower == true){
				valley++;
				is_lower = false;
			} 
		}
		else if(chr_array[i] == 'D'){
			pos--;
			if(pos < sea_level) is_lower = true;
		}
	}
	cout << valley << endl;
	return 0;
}
