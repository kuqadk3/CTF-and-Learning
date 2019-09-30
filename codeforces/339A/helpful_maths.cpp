#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    //vector<int> nums;
    if(s.length() == 1){
        cout << s << endl;
        exit(0);
    }
    for(int i = 0; i < s.length() - 2; i += 2){
        for(int j = 0; j < s.length() - i - 2; j += 2){
            if(int(s[j]) > int(s[j + 2])){
                char tmp = s[j];
                s[j] = s[j+2];
                s[j+2] = tmp;
            }
        }
    }
    cout << s << endl;
    return 0;
}
