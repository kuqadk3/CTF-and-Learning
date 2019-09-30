#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

bool check(int n,int m,int k, vector<int> arr){
    for(int i = 0; i < n; i++){
        if(i == n - 1 && m >= 0){
            return true;
        }
        else{
            if( m < 0){
                return false;
            }
            int tmp = arr[i + 1] - k;
            if(tmp <= 0){
                tmp = 0;
            }
            //cout << i << " " << tmp << endl;
            m += arr[i] - tmp;
        }
    }
    return true;
}
int main(){
    IOS
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n, m, k;
        cin >> n >> m >> k;
        //cout << "Here " << n; 
        int num;
        vector<int> arr;
        for(int j = 0; j < n; j++){
            cin >> num;
            arr.pb(num);
        }
        //for(int t = 0; t < arr.size(); t++){
            //cout << arr[t] << " ";
        //}
        //cout << endl;
        if(check(n, m, k, arr) == true){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
