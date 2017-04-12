#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int buyFullBottle(int money, int price, int sell_price){
	int yogurt_litre = 0;
	while(money >= price){
		yogurt_litre++;
		money -= price;
		money += sell_price;
	}
	return yogurt_litre;
}

int buyPlasticBottleFirst(int money, int price_plastic, int price_glass, int sell_price){
	int yogurt_litre = 0;
	while(money >= price_plastic || money >= price_glass){
		if(money >= price_plastic){
			money -= price_plastic;
			yogurt_litre++;
		}
		if(money >= price_glass){
			money -= price_glass;
			yogurt_litre++;
			money += sell_price;
		}
	}
	return yogurt_litre;
}

int buyGlassBottleFirst(int money, int price_plastic, int price_glass, int sell_price){
	int yogurt_litre = 0;
	while(money >= price_glass || money >= price_plastic){
		if(money >= price_glass){
			money -= price_glass;
			yogurt_litre++;
			money += sell_price;
		}
		if(money >= price_plastic){
			money -= price_plastic;
			yogurt_litre++;
		}
	}
	return yogurt_litre;
}

int main(){
	vector<int> maximum_yogurt;
	int money_have, price_plastic_bottle , price_glass_bottle, price_sell_glass_bottle;
	cin >> money_have >> price_plastic_bottle >> price_glass_bottle >> price_sell_glass_bottle;
	maximum_yogurt.push_back(buyFullBottle(money_have, price_plastic_bottle, 0));
	maximum_yogurt.push_back(buyFullBottle(money_have, price_glass_bottle, price_sell_glass_bottle));
	maximum_yogurt.push_back(buyGlassBottleFirst(money_have, price_plastic_bottle, price_glass_bottle, price_sell_glass_bottle));
	maximum_yogurt.push_back(buyPlasticBottleFirst(money_have, price_plastic_bottle, price_glass_bottle, price_sell_glass_bottle));
	std::sort(maximum_yogurt.begin(), maximum_yogurt.end());

	cout << maximum_yogurt[3] << endl;
	return 0;
}