#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

bool check1(map<int, int> arr){
    int total_key = 1;
    int total_val = 1;
    for(auto it : arr){
        int tmp = it.first;
        total_key *= it.first;
        total_val *= (tmp ** arr[it.first]);
        //cout << it.first << " " << arr[it.first] << endl;
        if(arr[it.first] % 2 != 0){
            return false;
        }
    }
    if(total_key ** 2 != total_val){
        return false;
    }
    return true;
}

int main(){
    IOS
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;
        //vector<int> arr;
        int num;
        map<int, int> arr;
        for(int i = 0; i < 4*n; i++){
            cin >> num;
            if(arr.count(num) > 0){
                arr[num] += 1;
            }
            else{
                arr[num] = 1;
            }
        }
        if(check1(arr) == false){
            cout << "NO" << endl;
        }


    }
    return 0;
}
