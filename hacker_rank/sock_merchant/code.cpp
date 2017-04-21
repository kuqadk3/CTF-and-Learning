#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
	int number_sock, number;
	cin >> number_sock;
	vector<int> price_list;
	for(int i = 0; i < number_sock; i++){
		cin >> number;
		price_list.push_back(number);
	}
	std::sort(price_list.begin(), price_list.end());
	int num_pair = 0;
	for(int i = 0; i < price_list.size(); i++){
		if(price_list[i] == price_list[i + 1]){
			i++;
			num_pair++;
		}
	}
	cout << num_pair << endl;
	return 0;
}
