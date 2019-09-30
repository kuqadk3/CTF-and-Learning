 #include <iostream>

 using namespace std;

 int main(){
     int table_size, target;
     cin >> table_size >> target;
     //cout << table_size << endl << target << endl;
     //cout << table_size << target << endl;
     int count = 0;
     for(int i = 1; i <= table_size; i++){
         if(i == 1 && table_size >= target){
             count++;
         }
         else if(target % i == 0 && i * table_size >= target && i != 1){
             count++;
         }
     }
     cout << count << endl;
     return 0;
 }
