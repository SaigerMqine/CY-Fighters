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

Team MakeTeamJ1(Character characters[], int nb) {
    Team team1;
    printf("Entrez le nom de votre équipe : ");
    strcpy(team1.name, verifname());
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    while (i < 3) {
        for (int j = 0; j < nb; j++) afficher_perso(characters[j], j);
        printf("Choisissez le personnage %d (1 à %d) : ", i + 1, nb);
        int choix = verifint() - 1;
        while (choix!= 1 && choix!= 2 && choix!= 3 && choix!= 4 && choix!= 5 && choix!= 0){
            printf("Erreur, Tape  un perso valide \n");
            choix = verifint()-1;
        }   

        int deja_choisi = 0;
        for (int k = 0; k < i; k++) {
            if (choix == choisis[k]) {
                deja_choisi = 1;
                break;
            }
        }

        if (deja_choisi) {
            printf("Personnage déjà choisi !\n");
            continue;
        }

        choisis[i] = choix;
        if (i == 0) team1.p1 = characters[choix];
        else if (i == 1) team1.p2 = characters[choix];
        else team1.p3 = characters[choix];

        i++;
    }

    return team1;
}

Team MakeTeamJ2(Character characters[], int nb) {
    Team team2;
    printf("Entrez le nom de votre équipe : ");
    strcpy(team1.name, verifname());
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    while (i < 3) {
        for (int j = 0; j < nb; j++) afficher_perso(characters[j], j);
        printf("Choisissez le personnage %d (1 à %d) : ", i + 1, nb);
        int choix = verifint() - 1;
        while (choix!= 1 && choix!= 2 && choix!= 3 && choix!= 4 && choix!= 5 && choix!= 0){
            printf("Erreur, Tape  un perso valide \n");
            choix = verifint()-1;
        }   

        int deja_choisi = 0;
        for (int k = 0; k < i; k++) {
            if (choix == choisis[k]) {
                deja_choisi = 1;
                break;
            }
        }

        if (deja_choisi) {
            printf("Personnage déjà choisi !\n");
            continue;
        }

        choisis[i] = choix;
        if (i == 0) team2.p1 = characters[choix];
        else if (i == 1) team2.p2 = characters[choix];
        else team2.p3 = characters[choix];

        i++;
    }

    return team2;
}

Character maxi(Character p1,Character p2){            // le perso avec la plus grande atk_bar
    if(p1.ATK_bar>=p2.ATK_bar){
        return p1;
    }
    else{
        return p2;
    }
}

Character prochainperso(Jeu j){            // le prochain personnage a attaquer
    if(maxi(maxi(maxi(j.t1.p1,j.t1.p2),maxi(j.t1.p3,j.t2.p1)),maxi(j.t2.p2,j.t2.p3)).ATK_bar>=500){
        return maxi(maxi(maxi(j.t1.p1,j.t1.p2),maxi(j.t1.p3,j.t2.p1)),maxi(j.t2.p2,j.t2.p3));
    }
}
