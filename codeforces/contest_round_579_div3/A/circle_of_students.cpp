#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

bool check_next(vector<int> arr, int pos){
    if(arr.size() <= 1){
        return true;
    }
    for(int i = pos + 1; arr[i%arr.size()] != arr[pos]; i++){
        //cout << i << " " << arr[i%arr.size()] << " " << arr[(i - 1)%arr.size()] << endl;
        if(arr[(i + arr.size())%arr.size()] <= arr[(i + arr.size() - 1)%arr.size()]){
            //debug("false")
            return false;
        }
    }
    return true;
}

bool check_back(vector<int> arr, int pos){
    //cout << pos - 1 << " " << arr[(pos-1) % arr.size()] << endl;
    for(int i = pos - 1; arr[(i+arr.size())%arr.size()] != arr[pos] ; i--){
        //cout << i << " " << arr[(i + arr.size())%arr.size()] << " " << arr[(i + 1)%arr.size()] << endl;
        if(arr[(i + arr.size())%arr.size()] <= arr[(i + 1 + arr.size())%arr.size()]){
            //debug("false");
            return false;
        }
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
        vector<int> arr;
        int num;
        int min_val = 201;
        int min_pos = 0;
        for(int j = 0; j < n; j++){
            cin >> num;
            arr.pb(num);
            if(num < min_val){
                min_pos = j;
                min_val = num;
            }
        }
        //debug(check_next(arr, min_pos));
        if(check_next(arr, min_pos) == false && check_back(arr, min_pos) == false){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        //debug(min_val);
        //debug(min_pos);


    }
    return 0;
}
