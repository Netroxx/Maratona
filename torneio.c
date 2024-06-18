#include <stdio.h>

int main() {
    char result[6];
    int i, vitoria = 0;

 
    for (i = 0; i < 6; i++) {
        scanf("%c", &result[i]);
    }

  
    for (i = 0; i < 6; i++) {
        if (result[i] == 'V') {
            vitoria++;
        }
    }

 
    if (vitoria >= 5) {
        printf("1\n");
    } else if (vitoria >= 3) {
        printf("2\n");
    } else if (vitoria >= 1) {
        printf("3\n");
    } else {
        printf("-1\n");
    }

    return 0;
}