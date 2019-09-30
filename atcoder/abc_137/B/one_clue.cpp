#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

int main(){
    IOS
    //edit
    int k, x;
    cin >> k >> x;
    for(int i = x - k + 1; i < k + x; i++){
        cout << i << " ";
    }
    return 0;
}
