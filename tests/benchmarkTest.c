#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE_BLOCK 100

int main()
{
    printf("Running benchmark test \n");

    clock_t time;
    time = clock();

    char *ptr1 = (char *)malloc(123155156924/124314*1231);
    free(ptr1);

    char * ptr2 = ( char * ) malloc ( 1200 );
    char * ptr3 = ( char * ) malloc ( 1200 );

    free( ptr2 );
    free( ptr3 );

    char *mill_ptr[1000000];

    for(int i = 0; i <= 1000000; i++) {
        mill_ptr[i] = (char *)malloc(SIZE_BLOCK);
    }

    for(int i = 0; i <= 999999; i++) {
        free(mill_ptr[i]);
    }

    free(mill_ptr[1000000]);

    time = clock() - time;
    printf("I took %f seconds. \n", ((float)time) / CLOCKS_PER_SEC);
    
    return 0;
}