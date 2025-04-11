#include <stdio.h>
#include <string.h>
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

int main(){

Skill Rugissement;      // initialising special skill : Rugissement 
strcpy(Rugissement.name, "Rugissement");
Rugissement.value = 0.6;
Rugissement.duration = 1;
Rugissement.cd = 2;

Skill Hurlement_de_chasse;      // initialising special skill :                                  Hurlement de chasse 
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
Loup.ch_skill2 = Hurlement_de_chasse; // ATK team +30%

 printf("Personnage : Loup\n");
 printf("HP : %f\nATK : %f\nDEF : %f\nRES : %f\nSPD : %f\nskill 1 : %s\nskill 2 : %s\n", Loup.MaxHP, Loup.ATK, Loup.DEF, Loup.RES, Loup.SPD, Loup.ch_skill1.name, Loup.ch_skill2.name);
    return 0;
}
