#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pop pop_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

int main(){
    IOS
    int n;
    cin >> n;
    vector<int> nums;
    int tmp;
    FOR(n){
        cin >> tmp;
        nums.pb(tmp);
    }
    int min_val = nums[0];
    int max_val = nums[0];
    int min_pos = 0;
    int max_pos = 0;
    FOR(nums.size()){
        if(max_val < nums[i]){
            max_val = nums[i];
            max_pos = i;
        }
    }
    nums.erase(nums.begin() + max_pos);
    nums.insert(nums.begin(), max_val);
    FOR(nums.size()){
        if(min_val >= nums[i]){
            min_val = nums[i];
             min_pos = i;
         }
    }
    cout << (max_pos + (nums.size() - 1 - min_pos)) << endl;
    //debug(min_val);
    //debug(min_pos);
    //debug(max_val);
    //debug(max_pos);
    return 0;
}
