// Right angled row numbered left triangle

#include <stdio.h>

int main(void) {
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=5; j++) {
            if(j <= i)
                printf("%d", i);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}