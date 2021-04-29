// Right angled column numbered left triangle
#include <stdio.h>

int main(void) {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if(j <= i)
                printf("%d", j);
            else 
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
