#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#include <string>
#include<fstream>
#include <stack>
using namespace std;

int how_many_duplicate_number_in_row(vector<int> arr, int number){
	int i = 0;
	int num = 0;
	for(int i = 0; i < arr.size(); i++){
		if(number == arr[i]) num++;
	}
	return num;
}

int main(){
	int number_list_one, number_list_two, number;
	vector<int> list_one, list_two;
	cin >> number_list_one;
	for(int i = 0; i < number_list_one; i++){
		cin >> number;
		list_one.push_back(number);
	}
	std::sort(list_one.begin(), list_one.end());
	cin >> number_list_two;
	for(int i = 0; i < number_list_two; i++){
		cin >> number;
		list_two.push_back(number);
	}
	std::sort(list_two.begin(), list_two.end());
	int max_size;
	for(int i = 0; i < list_one.size(); i++){
		int num_in_list_one = how_many_duplicate_number_in_row(list_one, list_one[i]);
		int num_in_list_two = how_many_duplicate_number_in_row(list_two, list_one[i]);
		if(num_in_list_one != num_in_list_two) cout << list_one[i] << " ";
		i += num_in_list_one - 1;
	}
	return 0;
}
