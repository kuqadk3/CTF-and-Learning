#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int tri_tuyet_doi(int num){
	if(num < 0) return (num *= -1);
	return num;
}
int main(){
	int number_item, not_eat_pos, brian_share;
	vector<int> item_price;
	cin >> number_item >> not_eat_pos;
	int price;
	int sum = 0;
	for(int i = 0; i < number_item; i++){
		cin >> price;
		item_price.push_back(price);
		sum += price;
	}
	cin >> brian_share;
	int real_share = (sum - item_price[not_eat_pos])/2;
	if(real_share == brian_share) cout << "Bon Appetit";
	else cout << tri_tuyet_doi(real_share - brian_share);
	return 0;
}
