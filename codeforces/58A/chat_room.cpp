#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;

int main(){
    IOS
    string s;
    cin >> s;
    //string founded;
    string target = "hello";
    int j = 0;
    //debug(s.length())
    //debug(s[s.length()-1])
    for(int i = 0; i < s.length(); i++){
        if(j == target.length()){
            cout << "YES" << endl;
            exit(0);
        }        
        if(s[i] == target[j]){
            //cout << s[i] << " " << target[j] << " " << j << endl;
            j += 1;
        }
    }
    if(j == target.length()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO"<< endl;
    }
    return 0;
}
