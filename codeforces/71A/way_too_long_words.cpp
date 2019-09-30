#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int i;
    std::string line;
    for(i = 0; i < n; i++){
        std::cin >> line;
        if(line.length() <= 10){
            std::cout << line << std::endl;
        }
        else{
            int tmp = line.length() - 2;
            std::cout << line[0] << tmp << line[line.length() - 1] << std::endl;
        }
    }
    return 0;
}

