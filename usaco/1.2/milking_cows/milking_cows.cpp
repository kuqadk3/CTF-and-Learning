/*
ID: kuqadk31
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>
#include <array>
using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

int main(){
    IOS
    ofstream fout ("milk2.out");
    ifstream fin2 ("milk2.in");
    int T;
    fin2 >> T;
    int prev_s = 5001;
    int prev_e = 0;
    array<int, 2> arr[T];
    for(int i = 0; i < T; i++){
        int tmp_s, tmp_e;
        fin2 >> tmp_s  >> tmp_e;
        arr[i][0] = tmp_s;
        arr[i][1] = tmp_e;
        }
    //cout << prev_s << " " << prev_e << endl;
    //fin >> prev_s >> prev_e;
    sort(arr, arr+T);
    prev_s = arr[0][0];
    prev_e = arr[0][1];
    int max_milking = prev_e - prev_s;
    int max_no_milking = 0;
    for(int i = 1; i < T; i++){
        int tmp_s, tmp_e;
        tmp_s = arr[i][0];
        tmp_e = arr[i][1];
        //cout << tmp_s << " " <<  tmp_e << endl;
        if(tmp_s <= prev_e){
            prev_s = min(tmp_s, prev_s);
            prev_e = max(tmp_e, prev_e);
        }
        else{
            if(tmp_s - prev_e > max_no_milking) max_no_milking = tmp_s - prev_e;
            prev_s = tmp_s;
            prev_e = tmp_e;
        }
        if(prev_e - prev_s > max_milking){
            max_milking = prev_e - prev_s;
        }
        //cout << tmp_s << " " << tmp_e << " " << prev_s << " " << prev_e << " " << max_no_milking << endl;
    }
    fout << max_milking << " " << max_no_milking << endl;
    return 0;
}

