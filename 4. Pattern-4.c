// Right angled consecutive numbered left triangle

#include <stdio.h>

int main(void) {
    int k=0;
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            if(j <= i)
                printf("%d", ++k);
            else 
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}