#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Max_name_length 25

typedef struct {
    char nom[50];
    char type[20];
    float valeur;
    int duree_restante;
} Effet;

typedef struct{     // create class special skills
    char name[50];
    float value;
    float duration;
    float cd;
    float dcd;
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
    Effet effets[3];
    int nb_effets
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
} Jeu;

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

void affiche_effets(Character c) {
    if (c.nb_effets == 0) {
        printf("Aucun effet actif sur %s.\n", c.name);
        return;
    }

    printf("Effets actifs sur %s :\n", c.name);
    for (int i = 0; i < c.nb_effets; i++) {
        printf(" - %s (%s : %.2f) [%d tour(s) restant(s)]\n", c.effets[i].nom, c.effets[i].type, c.effets[i].valeur, c.effets[i].duree_restante);
    }
}

int equipe_en_vie(Team* t) {
    return (t->p1.ActHP > 0 || t->p2.ActHP > 0 || t->p3.ActHP > 0);
}

float calcul_des_dégats_pris(Character* p1,Character p2){ //p1=perso qui attaque, p2=perso  attaqué
    int i=0;
    i=(rand()%100)+1;
    if(i<=p2.RES){
        return p2.ActHP;
    }
    else{
        p2.ActHP=p2.ActHP-p1->ATK*(1-(p1->DEF/100));
        return p2.ActHP;
    }
}

Character* maxi(Character* p1, Character* p2){
    if (p1->ATK_bar >= p2->ATK_bar) {
    return  p1; }
    else {
        return p2; 
    }
}

Character* prochainperso(Jeu* j){
    Character* m1 = maxi(&j->t1.p1, &j->t1.p2);
    Character* m2 = maxi(&j->t1.p3, &j->t2.p1);
    Character* m3 = maxi(&j->t2.p2, &j->t2.p3);
    Character* m4 = maxi(m1, m2);
    Character* m5 = maxi(m3, m4);
    if (m5->ATK_bar >= 500)
        return m5;
    return NULL;
}

Team MakeTeam(Character characters[], int nb) {
    Team team1;
    printf("Entrez le nom de votre équipe : ");
    strcpy(team1.name, verifname());
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    while (i < 3) {
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

Team MakeTeambot(Character characters[], int nb) {
    Team team2;
    strcpy(team2.name, "Bot");
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    srand(time(NULL));

    while (i < 3) {
        int choix = rand() % nb;
        int deja_choisi = 0;
        for (int k = 0; k < i; k++) {
            if (choix == choisis[k]) {
                deja_choisi = 1;
                break;
            }
        }

        if (deja_choisi) continue;

        choisis[i] = choix;
        if (i == 0) team2.p1 = characters[choix];
        else if (i == 1) team2.p2 = characters[choix];
        else team2.p3 = characters[choix];

        i++;
    }

    return team2;
}

Team MakeTeamJ1(Character characters[], int nb) {
    Team team1;
    printf("Entrez le nom de votre équipe : ");
    strcpy(team1.name, verifname());
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    while (i < 3) {
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
    strcpy(team2.name, verifname());
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    while (i < 3) {
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


 void affichenom(Team t1){
     printf("|  ");
     printf("%s",t1.p1.name);
     if(t1.p1.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |1|");
     }
     for(int i=strlen(t1.p1.name) ;i<32 ;i++){
        printf(" ");
    }
     printf("%s",t1.p2.name);
     if(t1.p2.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |2|");
     }
     for(int i=strlen(t1.p2.name) ;i<32 ;i++){
        printf(" ");
    }
     printf("%s",t1.p3.name);
     if(t1.p3.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |3|");
     }
    for(int i=strlen(t1.p3.name) ;i<20 ;i++){
        printf(" ");
    }
     printf("|");
 }
 
 void hpsp(Character p1,Character p2, Character p3 ){
     printf("| [ ");
    for(int i=0; i<(p1.ActHP) ;i=i+25){
    printf("#");
    }
    for(int i=p1.ActHP ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p2.ActHP) ;i=i+25){
    printf("#");
    }
    for(int i=p2.ActHP ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p3.ActHP) ;i=i+25){
    printf("#");
    }
    for(int i=p3.ActHP ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("] |");

    printf("\n");
    printf("| [ ");
    for(int i=0; i<(p1.ATK_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p1.ATK_bar ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p2.ATK_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p2.ATK_bar  ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p3.ATK_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p3.ATK_bar  ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("] |");
 }
  
 void afficheperso(Character p1){
     printf("\n");
     printf("|   %s",p1.name);
     for(int i=strlen(p1.name);i<94;i++){
         printf(" ");
     }
     printf(" |\n");
     printf("|   TECHNIQUES SPECIALES");
     for(int i=0;i<75;i++){
         printf(" ");
     }
     printf("|\n");
     printf("|      |1| attaque normal(peut etre utiliser a chaque tour)                                        |");
      printf("\n");
     if (p1.ch_skill1.cd == 0){
         printf("|      |2|");
         printf(" %s (duree:%f tours)",p1.ch_skill1.name ,p1.ch_skill1.duration);
         for(int i=strlen(p1.ch_skill1.name);i<58;i++){
         printf(" ");
        }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %f duree:%f tours)",p1.ch_skill1.name,p1.ch_skill1.cd ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill1.name);i<46;i++){
         printf(" ");
        }
        printf("|\n");
     }
     printf("|            %s",p1.ch_skill1.description);
     for(int i=strlen(p1.ch_skill1.description);i<86;i++){
         printf(" ");
    }
     printf("|\n");
     
          if (p1.ch_skill2.cd == 0){
         printf("|      |3|");
         printf(" %s (duree:%f tours)",p1.ch_skill2.name ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<58;i++){
         printf(" ");
        }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %f duree:%f tours)",p1.ch_skill2.name,p1.ch_skill2.cd ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<46;i++){
             printf(" ");
        }
        printf("|\n");
     }
      printf("|            %s",p1.ch_skill1.description);
     for(int i=strlen(p1.ch_skill2.description);i<86;i++){
         printf(" ");
    }
     printf("|");
     
 }

 void affichageteam(Team t1){
     printf("┌──[");
    for(int i=0; i<strlen(t1.name)-1;i++){
    printf("%c",t1.name[i]);
    }
    printf("]");
 
     for(int i=strlen(t1.name);i<95;i++){
         printf("─");
     }
     printf("┐");
     printf("\n");
     affichenom(t1);
     printf("\n");
     hpsp(t1.p1,t1.p2,t1.p3);
 }
 void affichagefin(){
     printf("\n|");
     for (int i=0;i<98;i++){
         printf(" ");
     }
     printf("|\n");
     printf("└");
     for (int i=0;i<98;i++){
         printf("─");
     }
     printf("┘");
 }

void affichage1v1(Jeu j){ // fonction prochainperso a code il faut qu'elle renvoie le perso qui attaque   
     if(&j.t1.p1 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team1)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t1.p1);
         affichagefin();
         printf("\n");
         
         
     }
     else if(&j.t1.p2 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
        affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team2)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t1.p2);
         affichagefin();
         printf("\n");
         
         
     }
     else if(&j.t1.p3 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team1)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t1.p3);
         affichagefin();
         printf("\n");
         
         
     }
     else if(&j.t2.p1 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team2)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t2.p1);
         affichagefin();
         printf("\n");
         
         
     }
     else if(&j.t2.p2 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team2)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t2.p2);
         affichagefin();
         printf("\n");
         
     }
     else if(&j.t2.p3 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team2)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t2.p3);
         affichagefin();
         printf("\n");
     }
    
}


float dégats_pris(Character p1,Character p2){ //p1=perso attaqué, p2=perso qui attaque
    int i=0;
    i=(rand()%100)+1;
    if(i<=p1.RES){
        return p1.ActHP;
    }
    else{
        p1.ActHP=p1.ActHP-p2.ATK*(1-(p1.DEF/100));
        return p1.ActHP;
    }
}
void botfacile(Character tabC[]){
    Jeu jeu;
    Jeu* j;
    j=&jeu;
    int a=10;
    int n=0;
    int d=0;
    Character tab1[3];
    Character tab2[3];
    jeu.t1 = MakeTeam(tabC,6);
    jeu.t2 = MakeTeambot(tabC,6);
    strcpy(jeu.t2.name , "bot");
    tab1[0]=jeu.t1.p1;
    tab1[1]=jeu.t1.p2;
    tab1[2]=jeu.t1.p3;
    tab2[0]=jeu.t2.p1;
    tab2[1]=jeu.t2.p2;
    tab2[2]=jeu.t2.p3;
    while(equipe_en_vie(&jeu.t1) && equipe_en_vie(&jeu.t2)){
        jeu.t1.p1.ATK_bar=jeu.t1.p1.ATK_bar+jeu.t1.p1.SPD;
        jeu.t1.p2.ATK_bar=jeu.t1.p2.ATK_bar+jeu.t1.p2.SPD;
        jeu.t1.p3.ATK_bar=jeu.t1.p3.ATK_bar+jeu.t1.p3.SPD;
        jeu.t2.p1.ATK_bar=jeu.t2.p1.ATK_bar+jeu.t2.p1.SPD;
        jeu.t2.p2.ATK_bar=jeu.t2.p2.ATK_bar+jeu.t2.p2.SPD;
        jeu.t2.p3.ATK_bar=jeu.t2.p3.ATK_bar+jeu.t2.p3.SPD;
        while(jeu.t1.p1.ATK_bar > 500 || jeu.t1.p2.ATK_bar > 500 || jeu.t1.p3.ATK_bar > 500|| jeu.t2.p1.ATK_bar > 500||jeu.t2.p2.ATK_bar > 500 || jeu.t2.p3.ATK_bar > 500){
        if(&jeu.t1.p1 == prochainperso(&jeu) || &jeu.t1.p2 == prochainperso(&jeu) || &jeu.t1.p3 == prochainperso(&jeu)){
            affichage1v1(jeu);
            printf("\n quelle capacité voulez vous utiliser");
            n=verifint();
            if(n==1){
                printf("\n quelle personnage voulez vous cibler");
                d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
               tab2[d].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
               if (tab2[d].SPD==jeu.t2.p1.SPD){
                   jeu.t2.p1.ActHP=tab2[d].ActHP;
               }
               if (tab2[d].SPD==jeu.t2.p2.SPD){
                    jeu.t2.p2.ActHP=tab2[d].ActHP;

               }
               if (tab2[d].SPD==jeu.t2.p1.SPD){
                    jeu.t2.p3.ActHP=tab2[d].ActHP;

               }
            }
            }
            if(&jeu.t1.p1 == prochainperso(&jeu)){
                jeu.t1.p1.ATK_bar =0;
            }
            if(&jeu.t1.p2 == prochainperso(&jeu)){
                jeu.t1.p2.ATK_bar =0;
            }
            if(&jeu.t1.p3 == prochainperso(&jeu)){
                jeu.t1.p3.ATK_bar =0;
            }
        if(&jeu.t2.p1 == prochainperso(&jeu) || &jeu.t2.p2 == prochainperso(&jeu) || &jeu.t2.p3 == prochainperso(&jeu)){
            affichage1v1(jeu);
            a=(rand()%3)+1;
            while (tab2[a].ActHP<=0){
                    a=(rand()%3);
                }
            tab1[a].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[a]);
            if (tab2[d].SPD==jeu.t2.p1.SPD){
                   jeu.t1.p1.ActHP=tab1[a].ActHP;
               }
               if (tab2[d].SPD==jeu.t2.p2.SPD){
                    jeu.t1.p2.ActHP=tab1[a].ActHP;

               }
               if (tab2[d].SPD==jeu.t2.p3.SPD){
                    jeu.t1.p3.ActHP=tab1[a].ActHP;

               }
               if(&jeu.t2.p1 == prochainperso(&jeu)){
                jeu.t2.p1.ATK_bar =0;
            }
            if(&jeu.t2.p2 == prochainperso(&jeu)){
                jeu.t2.p2.ATK_bar =0;
            }
            if(&jeu.t2.p3 == prochainperso(&jeu)){
                jeu.t2.p3.ATK_bar =0;
            }
    }
    if(jeu.t1.p1.ActHP <= 0){
        jeu.t1.p1.SPD=0;
           }
    if(jeu.t1.p2.ActHP <= 0){
        jeu.t1.p2.SPD=0;
   } 
    if(jeu.t1.p3.ActHP <= 0){
        jeu.t1.p3.SPD=0;
   } 
    if(jeu.t2.p1.ActHP <= 0){
        jeu.t2.p1.SPD=0;
   } 
    if(jeu.t2.p2.ActHP <= 0){
        jeu.t2.p2.SPD=0;
   } 
    if(jeu.t2.p3.ActHP <= 0){
        jeu.t2.p3.SPD=0;
   }
    }
    }
   }
    
    
    
    
    
void botmoyen(Character tabC[]){
    Jeu jeu;
    *j=jeu;
    int n=0;
    int d=0;
    Character tab1[3];
    Character tab2[3];
    jeu.t1 = MakeTeam(tabC,6);
    jeu.t2 = MakeTeambot(tabC,6);
    strcpy(jeu.t2.name , "bot");
    tab1[0]=jeu.t1.p1;
    tab1[1]=jeu.t1.p2;
    tab1[2]=jeu.t1.p3;
    tab2[0]=jeu.t2.p1;
    tab2[1]=jeu.t2.p2;
    tab2[2]=jeu.t2.p3;
    while(equipe_en_vie(&jeu.t1) && equipe_en_vie(&jeu.t2)){      
        jeu.t1.p1.ATK_bar=jeu.t1.p1.ATK_bar+jeu.t1.p1.SPD;
        jeu.t1.p2.ATK_bar=jeu.t1.p2.ATK_bar+jeu.t1.p2.SPD;
        jeu.t1.p3.ATK_bar=jeu.t1.p3.ATK_bar+jeu.t1.p3.SPD;
        jeu.t2.p1.ATK_bar=jeu.t2.p1.ATK_bar+jeu.t2.p1.SPD;
        jeu.t2.p2.ATK_bar=jeu.t2.p2.ATK_bar+jeu.t2.p2.SPD;
        jeu.t2.p3.ATK_bar=jeu.t2.p3.ATK_bar+jeu.t2.p3.SPD;
        if(&jeu.t1.p1 == prochainperso(&jeu) || &jeu.t1.p2 == prochainperso(&jeu) || &jeu.t1.p3 == prochainperso(&jeu)){
            affichage1v1(jeu);
            printf("quelle capacité voulez vous utiliser");
            n=verifint();
            if(n==1){
                printf("quelle personnage voulez vous cibler");
                d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
               calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
            }
        }
        else if(&jeu.t2.p1 == prochainperso(&jeu) || &jeu.t2.p2 == prochainperso(&jeu) || &jeu.t2.p3 == prochainperso(&jeu)){
            affichage1v1(jeu);
                if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP<=tab1[2].ActHP){
                    if(tab1[0].ActHP==0){
                        if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                }
            }
            else if(tab1[1].ActHP<=tab1[0].ActHP && tab1[1].ActHP<=tab1[2].ActHP){
            if(tab1[1].ActHP==0){
                        if(tab1[2].ActHP<=tab1[0].ActHP && tab1[2].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                }
            }
            else if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP<=tab1[0].ActHP){
            if(tab1[2].ActHP==0){
                        if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                }
            }
    }
    if(jeu.t1.p1.ActHP <= 0){
        jeu.t1.p1.SPD=0;
           }
    if(jeu.t1.p2.ActHP <= 0){
        jeu.t1.p2.SPD=0;
   } 
    if(jeu.t1.p3.ActHP <= 0){
        jeu.t1.p3.SPD=0;
   } 
    if(jeu.t2.p1.ActHP <= 0){
        jeu.t2.p1.SPD=0;
   } 
    if(jeu.t2.p2.ActHP <= 0){
        jeu.t2.p2.SPD=0;
   } 
    if(jeu.t2.p3.ActHP <= 0){
        jeu.t2.p3.SPD=0;
   } 
   }}
       
void botdifficile(Character tabC[]){
    Jeu jeu;
    *j= jeu;
    int n=0;
    int d=0;
    Character tab1[3];
    Character tab2[3];
    jeu.t1 = MakeTeam(tabC,6);
    jeu.t2 = MakeTeambot(tabC,6);
    strcpy(jeu.t2.name , "bot");
    tab1[0]=jeu.t1.p1;
    tab1[1]=jeu.t1.p2;
    tab1[2]=jeu.t1.p3;
    tab2[0]=jeu.t2.p1;
    tab2[1]=jeu.t2.p2;
    tab2[2]=jeu.t2.p3;
    while(equipe_en_vie(&jeu.t1) && equipe_en_vie(&jeu.t2)){
        jeu.t1.p1.ATK_bar=jeu.t1.p1.ATK_bar+jeu.t1.p1.SPD;
        jeu.t1.p2.ATK_bar=jeu.t1.p2.ATK_bar+jeu.t1.p2.SPD;
        jeu.t1.p3.ATK_bar=jeu.t1.p3.ATK_bar+jeu.t1.p3.SPD;
        jeu.t2.p1.ATK_bar=jeu.t2.p1.ATK_bar+jeu.t2.p1.SPD;
        jeu.t2.p2.ATK_bar=jeu.t2.p2.ATK_bar+jeu.t2.p2.SPD;
        jeu.t2.p3.ATK_bar=jeu.t2.p3.ATK_bar+jeu.t2.p3.SPD;
        if(&jeu.t1.p1 == prochainperso(&jeu) || &jeu.t1.p2 == prochainperso(&jeu) || &jeu.t1.p3 == prochainperso(&jeu)){
            affichage1v1(jeu);
            printf("quelle capacité voulez vous utiliser");
            n=verifint();
            if(n==1){
                printf("quelle personnage voulez vous cibler");
                d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
               calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
            }
        }
        else if(&jeu.t2.p1 == prochainperso(&jeu) || &jeu.t2.p2 == prochainperso(&jeu) || &jeu.t2.p3 == prochainperso(&jeu)){
            prochainperso(j)->ch_skill1.dcd -= 1;
            prochainperso(j)->ch_skill2.dcd -= 1;
            if (prochainperso(j)->ch_skill2.dcd<0){
                prochainperso(j)->ch_skill2.dcd=0;
            }
            if (prochainperso(j)->ch_skill1.dcd<0){
                prochainperso(j)->ch_skill1.dcd=0;
            }
            if(prochainperso(j)->ch_skill1.dcd != 0 && prochainperso(j)->ch_skill2.dcd != 0){
            affichage1v1(jeu);
                if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP<=tab1[2].ActHP){
                    if(tab1[0].ActHP==0){
                        if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                }
            }
            else if(tab1[1].ActHP<=tab1[0].ActHP && tab1[1].ActHP<=tab1[2].ActHP){
            if(tab1[1].ActHP==0){
                        if(tab1[2].ActHP<=tab1[0].ActHP && tab1[2].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                }
            }
            else if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP<=tab1[0].ActHP){
            if(tab1[2].ActHP==0){
                        if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                }
            }
            }
            else if(prochainperso(j)->ch_skill1.dcd == 0){
                // fonction skill1 du perso
                
                prochainperso(j)->ch_skill1.dcd ==prochainperso(j)->ch_skill1.cd ;
            }
            else if(prochainperso(j)->ch_skill2.dcd == 0){
                // fonction skill2 du perso
                
                prochainperso(j)->ch_skill2.dcd ==prochainperso(j)->ch_skill2.cd ; 
            }
            }
        if(jeu.t1.p1.ActHP <= 0){
        jeu.t1.p1.SPD=0;
           }
    if(jeu.t1.p2.ActHP <= 0){
        jeu.t1.p2.SPD=0;
   } 
    if(jeu.t1.p3.ActHP <= 0){
        jeu.t1.p3.SPD=0;
   } 
    if(jeu.t2.p1.ActHP <= 0){
        jeu.t2.p1.SPD=0;
   } 
    if(jeu.t2.p2.ActHP <= 0){
        jeu.t2.p2.SPD=0;
   } 
    if(jeu.t2.p3.ActHP <= 0){
        jeu.t2.p3.SPD=0;
   } 
    }
}


void vs1(Character tabC[]){
Jeu jeu;
*j=jeu;
int n=0;
int d=0;
Character tab1[3];
Character tab2[3];
    jeu.t1=MakeTeam(tabC,6);
    jeu.t2=MakeTeam(tabC,6);
    tab1[0]=jeu.t1.p1;
    tab1[1]=jeu.t1.p2;
    tab1[2]=jeu.t1.p3;
    tab2[0]=jeu.t2.p1;
    tab2[1]=jeu.t2.p2;
    tab2[2]=jeu.t2.p3;
    while(equipe_en_vie(&jeu.t1) && equipe_en_vie(&jeu.t2)){
        jeu.t1.p1.ATK_bar=jeu.t1.p1.ATK_bar+jeu.t1.p1.SPD;
        jeu.t1.p2.ATK_bar=jeu.t1.p2.ATK_bar+jeu.t1.p2.SPD;
        jeu.t1.p3.ATK_bar=jeu.t1.p3.ATK_bar+jeu.t1.p3.SPD;
        jeu.t2.p1.ATK_bar=jeu.t2.p1.ATK_bar+jeu.t2.p1.SPD;
        jeu.t2.p2.ATK_bar=jeu.t2.p2.ATK_bar+jeu.t2.p2.SPD;
        jeu.t2.p3.ATK_bar=jeu.t2.p3.ATK_bar+jeu.t2.p3.SPD;
        if(&jeu.t1.p1 == prochainperso(&jeu) || &jeu.t1.p2 == prochainperso(&jeu) || &jeu.t1.p3 == prochainperso(&jeu) || &jeu.t2.p1 == prochainperso(&jeu) || &jeu.t2.p1 == prochainperso(&jeu) || &jeu.t2.p3 == prochainperso(&jeu)){
            affichage1v1(jeu);
            printf("quelle capacité voulez vous utiliser");
            n=verifint();
            if(n==1){
                if(&jeu.t1.p1 == prochainperso(&jeu) || &jeu.t1.p2 == prochainperso(&jeu) || &jeu.t1.p3 == prochainperso(&jeu)){
                printf("quelle personnage voulez vous cibler");
                d=verifint()-1;
                    while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                 calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
                }
                else {
                    printf("quelle personnage voulez vous cibler");
                    d=verifint();
                    while (tab1[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                     calcul_des_dégats_pris(prochainperso(&jeu),tab1[d]);
                }
           }
           if(jeu.t1.p1.ActHP <= 0){
           jeu.t1.p1.SPD=0;
           }
            if(jeu.t1.p2.ActHP <= 0){
           jeu.t1.p2.SPD=0;
           } 
            if(jeu.t1.p3.ActHP <= 0){
           jeu.t1.p3.SPD=0;
           } 
            if(jeu.t2.p1.ActHP <= 0){
           jeu.t2.p1.SPD=0;
           } 
            if(jeu.t2.p2.ActHP <= 0){
           jeu.t2.p2.SPD=0;
           } 
            if(jeu.t2.p3.ActHP <= 0){
           jeu.t2.p3.SPD=0;
           } 
       }   
    }
}       



int mode(){
    //  n=1 facile n=2 difficile n=3 infernal n=4 1v1
    int d=0;
    int n = 0;
    printf("tape 1 pour jouer contre l'ordinateur \ntape 2 pour jouer contre un ami\n");
    d = verifint();
    while (d!= 1 && d!= 2){
        printf("Erreur, Tape 1 ou 2\n");
     d = verifint();
    }
    if (d == 1){
        printf(" tape 1 mode facile \n tape 2 mode difficile \n tape 3 mode infernal\n");
        n= verifint();
        while (n!=1 && n!=2 && n!=3){
            printf("t a pas taper 1 2 ou 3 mon reuf peut tu reessayer");
            n= verifint();
        }
    }
    if(d==2){
        n=4;
    }
    return n;
}
 

int main() {
    Jeu* j = malloc(sizeof(Jeu));
    if (j == NULL) {
        exit(10);
    }

    Skill S1;      // initialising special skill : Rugissement -40% DEF
    strcpy(S1.name, "Rugissement");
    S1.value = 0.6;
    S1.duration = 1;
    S1.cd = 2;
    S1.dcd=0;

    Skill S2;      // initialising special skill : Hurlement de chasse +30% ATT de groupe
    strcpy(S2.name, "Hurlement de chasse");
    S2.value = 1.3;
    S2.duration = 1;
    S2.cd = 3;
    S2.dcd=0;

    Character c1;         // initialising character : c1
    strcpy(c1.name, "Loup");
    c1.MaxHP = 334;
    c1.ActHP = 334;
    c1.ATK = 25;
    c1.DEF = 18;
    c1.RES = 10;
    c1.SPD = 107;
    c1.ATK_bar = 0;
    c1.ch_skill1 = S1;
    c1.ch_skill2 = S2;

    
    Skill sk1;
    strcpy(sk1.name , "coup de sabre lazer");
    sk1.value =2;
    sk1.duration =1;
    sk1.cd=5 ;
    sk1.dcd=0;
    strcpy(sk1.description, "double ses propre degat");
    
    Skill sk2;
    strcpy(sk2.name, "force");
    sk2.value=2;
    sk2.duration=2;
    sk2.cd=4;
    sk2.dcd=0;
    strcpy(sk2.description,"la defence est doublé");


    
    Character perso1;
    strcpy(perso1.name , "yoda");
    perso1.MaxHP= 300;
    perso1.ActHP= 300;
    perso1.ATK=50;
    perso1.DEF=10;
    perso1.RES=10;
    perso1.SPD=80;
    perso1.ATK_bar=0;
    perso1.ch_skill1= sk1;
    perso1.ch_skill2= sk2;



    Skill sk3;
    strcpy(sk3.name,"soin");
    sk3.value=0.3;
    sk3.duration=100;
    sk3.cd=6;
    sk3.dcd=0;
    strcpy(sk3.description, "donne 30 pourcent des hp max");
    
    Skill sk4;
    strcpy(sk4.name, "buff");
    sk4.value=2;
    sk4.duration=1;
    sk4.cd=5;
    sk4.dcd=0;
    strcpy(sk4.description, "double les degats d'un allier");


    Character perso2;
    strcpy(perso2.name , "ange");
    perso2.MaxHP= 230;
    perso2.ActHP=230;
    perso2.ATK=20;
    perso2.DEF=12;
    perso2.RES=10;
    perso2.SPD=72;
    perso2.ATK_bar=0;
    perso2.ch_skill1= sk3;
    perso2.ch_skill2= sk4;
    
    Character tabC[6];
    tabC[0]=perso2;
    tabC[1]=perso1;
    tabC[2]=c1;


    printf("tape 2 si tu veux pas jouer\ntape 1 pour jouer\n");
    int n = verifint();
    while(n != 1 && n != 2){
        printf("Erreur, Tape 1 ou 2\n");
        n = verifint();
    }
    if (n == 2 ){
        printf("bah chao bye bye");
        return 0  ; 
    }
    switch(mode()){ 
        case 1:
        botfacile(tabC);
        break;
        case 2 :
        botmoyen(tabC);
        break;
        case 3 :
        botdifficile(tabC);
        break;
        case 4 :
        vs1(tabC);
        break;
    }
    return 0;
}

