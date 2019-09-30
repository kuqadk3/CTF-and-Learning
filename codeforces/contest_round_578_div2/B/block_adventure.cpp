#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

int main(){
    IOS
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int m, n, k;
        cin >> n >> m >> k;
        vector<int> arr;
        int tmp;
        for(int j = 0; j < n; j++){
            cin >> tmp;
            arr.pb(tmp);
        }
    
    int char_pos = 0;
    for(int j = 0; j < arr.size(); j++){
        if(char_pos == n || (char_pos == n - 1 && arr[char_pos] + m >= arr[n] - k)){
            cout << "YES" << endl;
            break;
        }
        else if(char_pos != n && arr[j] < arr[j+1] && arr[j] + m < arr[j +1] - k){
            cout << "NO" << endl;
            break;
        }
        else if(arr[j] >= arr[j + 1]){
                // will greedy and get as much as he can
            int tmp_num = arr[j + 1] - k;
            if (tmp_num <= 0){
                tmp_num = arr[j + 1];
            }
            m +=  arr[j] - tmp_num;
            arr[j] = tmp_num;
            char_pos = j + 1;  
        }
        else if(arr[j] < arr[j +1]){
            int delta = arr[j + 1] - k - arr[j];
            if(delta > 0){
                m -= delta;
                arr[j] += delta;
                char_pos = j +1;
            }
            else if(delta < 0){
                m += delta;
                arr[j] -= delta;
                char_pos = j + 1;
            }
            else{
                char_pos = j + 1;
            }
        }
    }
    }
    return 0;
}
