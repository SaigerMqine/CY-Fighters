#include <stdio.h>
#include <string.h>

int verifint(){
    int d=0;
    char err;
    while (scanf("%d",&d)!= 1 ){
        printf("erreur");
        scanf("%1s",&err);
    }
    return d;
}



char verifc(){
    float err=0;
    char d;
    while (scanf("%c",&d)!= 1 ){
        printf("erreur");
        scanf("%f",&err);
        }
    return d;
}



float verifloat(){
    float d=0;
    char err;
    while (scanf("%f",&d)!= 1 ){
        printf("erreur");
        scanf("%1s",&err);
            }
    return d;
}



char verifs(){
    float err=0;
    char d;
    while (scanf("%s",&err)!= 1 ){
        printf("erreur");
        scanf("%f",&err);
            }
    return d;
}

typedef struct{     // create class special skills
    char name[50];
    float value;
    float duration;
    float cd;
}Skill;

typedef struct{     // create class characters 
    float MaxHP;
    float ActHP;
    float ATK;
    float DEF;
    float RES;
    float SPD;
    Skill ch_skill1;
    Skill ch_skill2;
}Character;

typedef struct{     // create class special skills
    char name[50];
    Character p1;
    Character p2;
    Character p3;
}Equipe;

int main(){

Skill Rugissement;      // initialising special skill : Rugissement -40% DEF
strcpy(Rugissement.name, "Rugissement");
Rugissement.value = 0.6;
Rugissement.duration = 1;
Rugissement.cd = 2;

Skill Hurlement_de_chasse;      // initialising special skill : Hurlement de chasse +30% DEF
strcpy(Hurlement_de_chasse.name, "Hurlement de chasse");
Hurlement_de_chasse.value = 1.3;
Hurlement_de_chasse.duration = 1;
Hurlement_de_chasse.cd = 3;

Character Loup;         // initialising character : Loup
Loup.MaxHP = 334;
Loup.ActHP = 334;
Loup.ATK = 25;
Loup.DEF = 18;
Loup.RES = 10;
Loup.SPD = 107;
Loup.ch_skill1 = Rugissement;
Loup.ch_skill2 = Hurlement_de_chasse;

 printf("Personnage : Loup\n");
 printf("HP : %f\nATK : %f\nDEF : %f\nRES : %f\nSPD : %f\nskill 1 : %s\nskill 2 : %s\n", Loup.MaxHP, Loup.ATK, Loup.DEF, Loup.RES, Loup.SPD, Loup.ch_skill1.name, Loup.ch_skill2.name);
    return 0;
}





