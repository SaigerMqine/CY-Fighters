#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifint(){
    int d=0;
    char c;
    char err;
    if(scanf("%d%c", &d, &c) == 2 && c == '\n'){ 
        return d;
    }
     else {
            while ((c = getchar()) != '\n' && c != EOF);
    }
}


char* verifname(){
    char* name = malloc(Max_name_length * sizeof(char)); 
    if (name == NULL) {
        printf("erreur malloc\n");
        exit(1);
    }
     if (fgets(name, Max_name_length, stdin) != NULL) {
        size_t len = strlen(name);
    }
else {
        printf("rentre un nom correct\n");
        free(name);
        return 0;
    }

    return name;
}
