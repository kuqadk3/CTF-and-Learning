#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> coins;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        coins.push_back(val);
    }
    sort(coins.begin(), coins.end(), greater<int>());
    int med = accumulate(coins.begin(), coins.end(), 0)/2;
    int sum = 0;
    int count = 0;
    //cout << med << endl;
    for(int i = 0; i < coins.size(); i++){
        sum += coins.at(i);
        count += 1;
        if(sum > med){
            break;
        }
    }
    cout << count << endl;
    //for(int i = 0; i < coins.size(); i++){
    //    cout << coins.at(i) << endl;
    //}
    return 0;
}
