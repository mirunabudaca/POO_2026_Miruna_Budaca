#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define MAX_WORDS 200

int compare(const void* a, const void* b) {
    const char* cuv1 = *(const char**)a;
    const char* cuv2 = *(const char**)b;

    int l1 = (int)strlen(cuv1);
    int l2 = (int)strlen(cuv2);

    if (l1 != l2) return l2 - l1;     

    return strcmp(cuv1, cuv2);            
}

int main(void) {
    char prop[MAX_LEN];

    if (!fgets(prop, sizeof(prop), stdin)) {
        return 0;
    }

    prop[strcspn(prop, "\r\n")] = '\0';

    char* cuv[MAX_WORDS];
    int nr = 0;

    const char* delim = " \t";

    char* token = strtok(prop, delim);
    while (token != NULL) {
        if (nr < MAX_WORDS) {
            cuv[nr++] = token;
        }
        token = strtok(NULL, delim);
    }

    if (nr == 0) return 0;

    qsort(cuv, nr, sizeof(cuv[0]), compare);

    for (int i = 0; i < nr; i++) {
        printf("%s\n", cuv[i]);
    }

    return 0;
}