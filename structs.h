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
    float dcd;
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
