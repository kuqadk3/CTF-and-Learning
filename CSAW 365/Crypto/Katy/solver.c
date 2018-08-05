#include <stdio.h>

int main()
{
    int seed = 1208101748 & 0xFFFFFFFFFFFF;
    int last_seed = (seed - 11)/25214903917;
    
    printf("%i", last_seed);

    return 0;
}
