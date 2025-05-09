#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{     // create class special skills
    char name[50];
    float value;
    float duration;
    float cd;
    char description[100];
}Skill;

typedef struct{     // create class characters 
    char name[50];
    float MaxHP;
    float ActHP;
    float ATK;
    float DEF;
    float RES;
    float SPD;
    int ATK_bar;
    Skill ch_skill1;
    Skill ch_skill2;
}Character;

typedef struct{     // create class special skills
    char name[50];
    Character p1;
    Character p2;
    Character p3;
}Team;

typedef struct {
    Team t1;
    Team t2;
} Jeu

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
