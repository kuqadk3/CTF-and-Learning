#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

int main(){
    IOS;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;
        vector<int> arr;
        int tmp;
        cin >> tmp;
        arr.pb(tmp);
        int count = 0;
        for(int j = 1; j < n; j++){
            cin >> tmp;
            while(arr.size() > 0 && tmp < arr.back()){
                count += 1;
                arr.pop_back();   
            }
            arr.pb(tmp);
        }
        cout << count << endl;
  }
  return 0;
}
