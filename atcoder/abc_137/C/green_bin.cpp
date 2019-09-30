#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

bool check(map<char, int> s1map, map<char, int> s2map){
    for(map<char, int>::iterator it = s1map.begin(); it != s1map.end(); ++it){
        if (s1map[it->first] != s2map[it->first]){
            return false;
        }
    }
    return true;
    
}

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
    map<string, map<char, int> > smap;
    vector<string> svector;
    FOR(n){
        cin >> s;
        svector.pb(s);
        smap[s][s[0]] = 0;
        for(int j = 1; s[j]; j++){
            if (smap[s].count(s[j])){
                smap[s][s[j]] += 1;
            }
            else{
                smap[s][s[j]] = 0;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < svector.size() - 1; i++){
        int tmp_count = 1;
        for(int j = i + 1; j < svector.size(); j++){
            //cout << svector[i] << " " << svector[j] << endl;
            if (check(smap[svector[i]], smap[svector[j]]) == true){
                tmp_count += 1;
                svector.erase(svector.begin() + j);
            }
        }
        count += calc_comb(tmp_count);      
        //debug(count);
    }
    cout << count << endl;
    return 0;
}
