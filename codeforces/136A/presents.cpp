#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i <= x.size(); i++){ cout << x.at(i) << endl; }  
int main(){
    IOS
    int n;
    cin >> n;
    map<int, int> nums;
    int tmp;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        nums[tmp] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}
