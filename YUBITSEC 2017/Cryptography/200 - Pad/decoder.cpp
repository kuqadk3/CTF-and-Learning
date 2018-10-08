#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	string encrypted_message, key;
	cin >> encrypted_message >> key;
	char start_char = ' '; //32
	char end_char = '~' ;//126
	int modular = int(end_char) - int(start_char) + 1;
	vector<int> sum_calculatedchar_startchar;
	for(int i = 0; i < encrypted_message.length(); i++){
		sum_calculatedchar_startchar.push_back(int(encrypted_message[i]) - int(start_char) + modular + 2*int(start_char) - int(key[i]));
		cout << char(sum_calculatedchar_startchar[i]);
	}
	cout << endl;
	
	return 0;
}
