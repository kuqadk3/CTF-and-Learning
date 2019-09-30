#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

int main(){
    IOS
    int matrix[5][5];
    int tmp;
    int target_col, target_row;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> tmp;
            matrix[i][j] = tmp;
            if(tmp == 1){
                target_col = j;
                target_row = i;
            }
        }
    }
    cout << abs(target_col - 2) + abs(target_row - 2) << endl;
    //debug(target_col);
    //debug(target_row);
//    for(int i = 0; i < 5; i++){
//        for(int j = 0; j < 5; j++){
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
