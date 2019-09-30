#include <bits/stdc++.h>
using namespace std;

int lexical_compare(string s1, string s2){
    for(int i = 0; s1[i]; i++){
        int tmp1 = int(tolower(s1[i]));
        int tmp2 = int(tolower(s2[i]));
        if(tmp1 < tmp2){
            return -1; //s1 < s2
        }
        else if(tmp1 > tmp2){
            return 1;
        }
    }
    return 0;
}

int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << lexical_compare(s1, s2) << endl;
    return 0;
}
