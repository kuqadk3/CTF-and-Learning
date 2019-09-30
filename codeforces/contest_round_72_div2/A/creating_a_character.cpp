#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

int bin_search(int tmp_str, int tmp_int, int tmp_exp){
    int l = 0;
    int r = tmp_exp;
    while(l < r){
        int m = (l+r)/2;
        if(tmp_str + l == tmp_int + r){
            return m;
        }
        else if(tmp_str + l < tmp_int + r){
            l = m + 1;
        }
        else if(tmp_str + l > tmp_int + r){
            r = m - 1;
        }
    }
    return -1;
}
int main(){
    IOS
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int tmp_str, tmp_int, tmp_exp;
        cin >> tmp_str >> tmp_int >> tmp_exp;
        cout << bin_search(tmp_str, tmp_int, tmp_exp) << endl;
    }
    return 0;
}
