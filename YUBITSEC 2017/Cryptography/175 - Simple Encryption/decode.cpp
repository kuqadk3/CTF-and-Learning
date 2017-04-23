#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
	std::fstream myfile("encrypted.txt", std::ios_base::in);
	int number;
	while(myfile >> number){
		cout << (char)(number^62);
	}
	cout << endl;
	system("pause");
	return 0;
}