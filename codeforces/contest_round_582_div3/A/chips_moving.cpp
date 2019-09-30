#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define debug(x) cout << x << endl;
#define FOR(x) for(int i =0; i < (x) ; i++)

long long int map_count(map<int, int> arr, int cd){
    long long int total = 0;
    for(int i = 1; i <= 100; i++){
        if(arr[i] != 0){
            total += abs(cd - i)%2 * arr[i];
        }
    }
    return total;
}
int main(){
  IOS;
  map<int, int> arr;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    long long int tmp;
    cin >> tmp;
    if(arr.count() > 0){
        arr[tmp] += 1;
    }
    else{
        arr[tmp] = 1;
    }
  }
  long long int min = pow(2,32) + 1;
  for(int i = 1; i <= 100; i++){
    if(arr[i] != 0){
        long long int tmp_total = map_count(arr, i);
        if(tmp_total < min){
            min = tmp_total;
        }
    }
  }
  cout << min << endl;
  //FOR(arr.size()) cout << arr[i] << endl;
  return 0;
}
