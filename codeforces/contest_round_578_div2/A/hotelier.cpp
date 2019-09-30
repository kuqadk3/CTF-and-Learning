#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

vector<int> move_left(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0){
            arr[i] = 1;
            return arr;
        }
    }
    return arr;
}
vector<int> move_right(vector<int> arr){
    for(int j = arr.size() - 1; j >= 0; j--){
        if(arr[j] == 0){
            arr[j] = 1;
            return arr;
        }
    }
    return arr;
}
int main(){
    IOS
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr;
    for(int i = 0; i <= 9 ; i++){
        arr.pb(0);
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            arr = move_left(arr);
        }
        else if(s[i] == 'R'){
            arr = move_right(arr);
        }
        else{
            int tmp = s[i] - 48;
            arr[tmp] = 0;
        }
        //debug(s[i]);
        //FOR(arr.size()){
         //cout << arr[i] << " ";
     //}
        //cout << endl;
    }
    stringstream output;
    copy(arr.begin(), arr.end(), ostream_iterator<int>(output, ""));
    cout << output.str() << endl;
    return 0;
}
