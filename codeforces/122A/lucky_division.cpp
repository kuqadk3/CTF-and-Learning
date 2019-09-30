#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;

bool check_almost_lucky_number(int n){
    string s = to_string(n);
    //debug(s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '4' && s[i] != '7'){
            return false;
        }
    }
    return true;
}
int main(){
    IOS
    int n;
    cin >> n;
    //debug(n);
    for(int i = 4; i <= n; i++){
        if(n%i == 0 && check_almost_lucky_number(i) == true){
            cout << "YES" << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;
    return 0;
}
