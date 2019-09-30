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
        int n;
        cin >> n;
        //vector<int> arr;
        int num;
        long long total;
        for(int i = 0; i < 4*n; i++){
            cin >> num;
            total *= num;
        }
        if(pow(total, 1/float(n*2)) != int(pow(total, 1/float(n*2)))){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
