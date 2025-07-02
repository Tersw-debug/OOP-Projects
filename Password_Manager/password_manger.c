#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void scrub(void *p, size_t n)
{
    volatile unsigned char *m = p;
    while(n-- > 0) m[n] = 0;
}

void get_rid_of(char *y){
    remove(y);
    scrub(y,strlen(y));
}
extern void passwrod_generator(char* key, int size)
{
    if (size > 20){
        get_rid_of(key);
    }
    else {
            int i;
            srand(time(NULL));
            int sec = rand() % sizeof(int);
            int index = 0;
            char strin[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            for (i = 0; i < size ; i++){
                key[i] = strin[rand() % (sec % sizeof(strin) -1) ];
            }
        key[++i] = '\0';
    }
}





int main(void){


}
