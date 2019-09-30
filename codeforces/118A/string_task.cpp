#include <bits/stdc++.h>
using namespace std;

bool check(char c){
    char a[7] = {'a', 'o', 'y', 'e', 'u', 'i'};
    for(int i = 0; i < 7; i++){
        if(c == a[i]){
            return false;
        }
    }
    return true;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; s[i]; i++){
       if(check(tolower(s[i])) == true){
           cout << "." << char(tolower(s[i]));
       }
    }
    return 0;
}
