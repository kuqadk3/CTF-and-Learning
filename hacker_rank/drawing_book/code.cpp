#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
	int last_page, page_to_go_to;
	cin >> last_page >> page_to_go_to;
	if(page_to_go_to %2 != 0) page_to_go_to--;
	int page_from_1 = 0;
	int page_from_last = 0;
	int i = 1;
	while(i < page_to_go_to){
		page_from_1++;
		i += 2;
	}
	if(page_to_go_to %2 == 0) page_to_go_to++;
	if(last_page%2 != 0) last_page--;
	int j = last_page;
	while(j > page_to_go_to){
		page_from_last++;
		j -= 2;
	}
	if(page_from_1 > page_from_last) cout << page_from_last;
	else cout << page_from_1;
	return 0;
}
