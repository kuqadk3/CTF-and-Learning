#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%10 == 4){
        cout << "Co" << endl;
    }
    else if(n%10 == 3){
        cout << "Ba" << endl;
    }
    else{
        cout << "Khong" << endl;
    }
    return 0;
}
