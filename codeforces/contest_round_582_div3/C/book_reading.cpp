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
        int n, m;
        cin >> n >> m;
        int tmp = n/m;
        int num = tmp/2;
        int res = (tmp - num) * m;
        cout << tmp << " " << num << " " << res << endl;
        cout << res << endl;
    }
    return 0;
}
