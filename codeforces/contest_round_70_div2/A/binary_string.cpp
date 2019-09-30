#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <stdio.h>

using namespace std;

string IntToString(long long int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

long long int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

string toBinary(long long int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        long long x, y;
        cin >> x >> y;
        //cout << x << " " << y << endl;
        long long int xDec, yDec;
        xDec = convertBinaryToDecimal(x);
        yDec = convertBinaryToDecimal(y);
        //cout << xDec << " " << yDec;
        //cout << xDec << " " << yDec;
        int k = 0;
        //long long int tmp;
        //strRev = IntToString(convertDecimalToBinary(xDec + yDec * (pow(2, k))));
        int min_k = 0;
        string minimal =  toBinary(xDec + yDec * (pow(2, 0)));
        //cout << minimal << endl;
        //string strRev = IntToString(convertDecimalToBinary(xDec + yDec * (pow(2, 0))));
        reverse(minimal.begin(), minimal.end());
        while(true){
            string strRev = toBinary(xDec + yDec * (pow(2, k)));
            reverse(strRev.begin(), strRev.end());
            if(strRev < minimal){
                minimal = strRev;
                min_k = k;         
            }
            if(strRev.size() > minimal.size()){
                cout << min_k << endl;
                break;
            }
            k += 1;
        }
        //cout << min_k << endl;
    
    }
    return 0;
}
