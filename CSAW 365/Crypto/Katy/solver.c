#include <stdio.h>

int main()
{
    int seed = 1364650861;
    int i;
    for(i = 0; i < 10000000000; i++){
        int v0 = (25214903917 * i + 11) & 0xFFFFFFFFFFFF;
        if(v0 == seed){
            printf("%i", i);
            break;
        }
    }

    return 0;
}
