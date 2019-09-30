#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define debug_vt(x) for(int i = 0; i < x.size(); i++){ cout << x[i] << " "; }
#define FOR(x) for(int i =0; i < (x) ; i++)

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int calc_comb(int n){
    int k = 2;
    if(n <= 1) return 0;
    return factorial(n)/(factorial(n - k) * factorial(k)); 
}
int main(){
    IOS
    int n;
    cin >> n;
    string s;
    vector<string> sv;
    FOR(n){
        cin >> s;
        sort(s.begin(), s.end());
        sv.pb(s);
    }
    int count = 0;
    for(int i = 0; i < sv.size() - 1; i++){
        int tmp_count = 1;
        for(int j = i + 1; j < sv.size(); j++){
            if (sv[i] == sv[j]){
                tmp_count += 1;
                sv.erase(sv.begin() + j);
            }
            //debug_vt(sv);
        }
        //debug(tmp_count);
        count += calc_comb(tmp_count);
    }
    cout << count << endl;
    return 0;
}
