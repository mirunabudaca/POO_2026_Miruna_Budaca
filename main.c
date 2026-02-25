#include <stdio.h>
#include <stdlib.h>


int conversie_int(const char* s) {
    int rez = 0;
    int i = 0;
    int semn = 1;

    if (s[i] == '-') {
        semn = -1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        rez = rez * 10 + (s[i] - '0');
        i++;
    }

    return semn * rez;
}
char buffer[128];
int main() {


    FILE* f = fopen("in.txt", "r");

    if (f == NULL) {
        printf("Error opening file");
        return 1;
    }

    
    int sum = 0;

    while (fgets(buffer, sizeof(buffer), f)) {
        sum += conversie_int(buffer);
    }

    printf("Sum = %d\n", sum);

    fclose(f);
    return 0;
}