#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}


long long int calc_comb(int n){
    int k = 2;
    if(n <= 1) return 0;
    if(n == 2) return 1;
    debug(n);
    debug(factorial(n));
    debug(factorial(n-k));
    debug(factorial(k));
    return factorial(n)/(factorial(n - k) * factorial(k));
}
int main(){
    IOS
    int n;
    cin >> n;
    string s;
    map<string, int> smap;
    int count = 0;
    FOR(n){
        cin >> s;
        sort(s.begin(), s.end());
        if(smap.count(s)){
            smap[s] += 1;
        }
        else{
            smap[s] = 1;
        }
    }
    cout << "Here : " << factorial(100) << endl;
    for(map<string, int>::iterator it = smap.begin(); it != smap.end(); it++){
        //string s = it->first;
        //debug(s);
        count += calc_comb(smap[it->first]);
    }
    cout << count << endl;
    return 0;
}

