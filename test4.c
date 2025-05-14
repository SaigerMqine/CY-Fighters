#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Max_name_length 25

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

typedef struct{     // create class team
    char name[50];
    Character p1;
    Character p2;
    Character p3;
}Team;

typedef struct {        //create class jeu
    Team t1;
    Team t2;
} Jeu;

int verifint(){            //verifie les int
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


char* verifname(){            //verifie les noms
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

Character* maxi(Character* p1, Character* p2){        //est utiliser dans prochain perso
    if (p1->ATK_bar >= p2->ATK_bar) {
    return  p1; }
    else {
        return p2; 
    }
}

Character* prochainperso(Jeu* j){            //renvoie le prochain perso qui attaque
    Character* m1 = maxi(&j->t1.p1, &j->t1.p2);
    Character* m2 = maxi(&j->t1.p3, &j->t2.p1);
    Character* m3 = maxi(&j->t2.p2, &j->t2.p3);
    Character* m4 = maxi(m1, m2);
    Character* m5 = maxi(m3, m4);
    if (m5->ATK_bar >= 500)
        return m5;
    return NULL;
}
float calcul_des_dégats_pris(Character* p1,Character p2){ //p1=perso attaqué, p2=perso qui attaque
    int i=0;
    i=(rand()%100)+1;
    if(i<=p1->RES){
        return p1->ActHP;
    }
    else{
        p1->ActHP=p1->ActHP-p2.ATK*(1-(p1->DEF/100));
        return p1->ActHP;
    }
}

void afficher_perso(Character c, int index) {            // afficher le perso quand on le choisit
    printf(" ┌────────────────────────────────┐\n");
    printf(" │ Personnage %d : %s ", index + 1, c.name);
    for(int i=strlen(c.name);i<21;i++){
         printf(" ");
     }
     printf("│\n");
    printf(" ├────────────────────────────────┤\n");
    printf(" │ HP  : %.1f                          │\n", c.MaxHP);
    printf(" │ ATK : %.1f                           │\n", c.ATK);
    printf(" │ DEF : %.1f                           │\n", c.DEF);
    printf(" │ RES : %.1f                           │\n", c.RES);
    printf(" │ SPD : %.1f                           │\n", c.SPD);
    printf(" │ Skill 1 : %s", c.ch_skill1.name);
    for(int i=strlen(c.ch_skill1.name);i<27;i++){
         printf(" ");
     }
    printf("|\n");
    printf(" │ Skill 2 : %s", c.ch_skill2.name);
    for(int i=strlen(c.ch_skill2.name);i<27;i++){
         printf(" ");
     }
    printf("|\n");
    printf(" └────────────────────────────────┘\n");
}


Team MakeTeam(Character characters[], int nb) {            //le joueur crrer l'equipe
    Team team1;
    printf("Entrez le nom de votre équipe : ");
    strcpy(team1.name , verifname());
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    for (int j = 0; j < nb; j++) afficher_perso(characters[j], j);
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

Team MakeTeambot(Character characters[], int nb) {            //le bot creer son equipe
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


 
 void affichenom(Team t1){            //afficher le nom et quand les perso sont mort
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
 
 void hpsp(Character p1,Character p2, Character p3 ){            //afficher les bar de point de vie et de vitesse
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
 
 
float skillSPD (Character* c1,Character c2){      //augmente SPD
  c2.SPD=c2.SPD*c1->ch_skill1.value;
  c1->ch_skill1.dcd=c1->ch_skill1.cd;
  return c2.SPD;
}
float antiskillSPD (Character* c1,Character c2){    // diminue SPD
  c2.SPD=c2.SPD/c1->ch_skill1.value;
  return c2.SPD;
}
float skillATK (Character* c1,Character c2){        //augmente attaque
  c2.ATK=c2.ATK*c1->ch_skill1.value;
  c1->ch_skill1.dcd=c1->ch_skill1.cd;
  return c2.ATK;
}
float antiskillATK (Character* c1,Character c2){        //diminue attaque
  c2.ATK=c2.ATK/c1->ch_skill1.value;
  return c2.ATK;
}
float skillDEF (Character* c1,Character c2){        //augment la def sur soi
  c2.DEF=c2.DEF*c1->ch_skill2.value;
  c1->ch_skill2.dcd=c1->ch_skill2.cd;
  return c2.DEF;
}
float antiskillDEF (Character* c1,Character c2){        //diminue la def
  c2.DEF=c2.DEF/c1->ch_skill2.value;
  return c2.DEF;
}
float skillDEFene (Character* c1,Character c2){        //diminue la def sur l'ennemie
  c2.DEF=c2.DEF/c1->ch_skill2.value;
  c1->ch_skill2.dcd=c1->ch_skill2.cd;
  return c2.DEF;
}
float antiskillDEFene (Character* c1,Character c2){        //augmente la def
  c2.DEF=c2.DEF*c1->ch_skill2.value;
  return c2.DEF;
}
float skillHEAL (Character* c1,Character c2){        //heal les allier
  c2.ActHP=c2.ActHP+(c2.MaxHP*c1->ch_skill2.value);
  c1->ch_skill2.dcd=c1->ch_skill2.cd;
  return c2.ActHP;
}
  
  float skillRES (Character* c1,Character c2){        //augmente l'esquive
  c2.RES=c2.RES*c1->ch_skill2.value;
  c1->ch_skill2.dcd=c1->ch_skill2.cd;
  return c2.RES;
}
float antiskillRES (Character* c1,Character c2){        //diminue l'equive
  c2.RES=c2.RES/c1->ch_skill2.value;
  return c2.RES;
}

float skillSPDene (Character* c1,Character c2){      //debuff SPD
  c2.SPD=c2.SPD/c1->ch_skill2.value;
  c1->ch_skill2.dcd=c1->ch_skill2.cd;
  return c2.SPD;
}
float antiskillSPDene (Character* c1,Character c2){      //antiDEBUFF SDP
  c2.SPD=c2.SPD*c1->ch_skill2.value;
  return c2.SPD;
}
 void afficheperso(Character p1){            //afficher les attaque du perso et ce qu'il peut utiliser
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
     if (p1.ch_skill1.dcd == 0){
         printf("|      |2|");
         printf(" %s (duree:%f tours)",p1.ch_skill1.name ,p1.ch_skill1.duration);
         for(int i=strlen(p1.ch_skill1.name);i<58;i++){
             printf(" ");
         }
         printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %f duree:%f tours)",p1.ch_skill1.name,p1.ch_skill1.dcd ,p1.ch_skill2.duration);
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
     if (p1.ch_skill2.dcd == 0){
         printf("|      |3|");
         printf(" %s (duree:%f tours)",p1.ch_skill2.name ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<58;i++){
             printf(" ");
         }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %f duree:%f tours)",p1.ch_skill2.name,p1.ch_skill2.dcd ,p1.ch_skill2.duration);
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

 void affichageteam(Team t1){            //afficher toute la team
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
 

void affichage1v1(Jeu j){         //affiche le combat   
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
         printf("\n|   (Team1)");
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

   
void botdifficile(Character tabC[]){
    Jeu jeu;
    Jeu*j;
    j=&jeu;
    int n=0;
    int d=0;
    int a=0;
    int ds1=10000;
    int ds2=10000;
    int ds3=10000;
    int ds4=10000;
    int ds5=10000;
    int ds6=10000;
    int ds7=10000;
    int ds8=10000;
    int ds9=10000;
    int ds10=10000;
    int ds11=10000;
    int ds12=10000;
    int ds13=10000;
    int ds14=10000;
    int ds15=10000;
    int ds16=10000;
    int ds17=10000;
    int ds18=10000;
    int ds19=10000;
    int ds20=10000;
    Character tab1[3];
    Character tab2[3];
    Character tab3[3];
    Character tab4[3];
    Character tab1eff2[3];
    Character tab2eff2[3];
    jeu.t1 = MakeTeam(tabC,6);
    jeu.t2 = MakeTeambot(tabC,3);
    tab1[0]=jeu.t1.p1;
    tab1[1]=jeu.t1.p2;
    tab1[2]=jeu.t1.p3;
    tab2[0]=jeu.t2.p1;
    tab2[1]=jeu.t2.p2;
    tab2[2]=jeu.t2.p3;
    tab3[0]=jeu.t1.p1;
    tab3[1]=jeu.t1.p2;
    tab3[2]=jeu.t1.p3;
    tab4[0]=jeu.t2.p1;
    tab4[1]=jeu.t2.p2;
    tab4[2]=jeu.t2.p3;
    tab1eff2[0]=jeu.t1.p2;
    tab1eff2[1]=jeu.t1.p2;
    tab1eff2[2]=jeu.t1.p3;
    tab2eff2[0]=jeu.t2.p1;
    tab2eff2[1]=jeu.t2.p2;
    tab2eff2[2]=jeu.t2.p3;
    while(jeu.t1.p1.ActHP > 0 && jeu.t1.p2.ActHP > 0 && jeu.t1.p3.ActHP > 0 || jeu.t2.p1.ActHP > 0 && jeu.t2.p2.ActHP > 0 && jeu.t2.p3.ActHP > 0){
        if (jeu.t1.p1.ATK_bar<500&&jeu.t1.p2.ATK_bar<500&&jeu.t1.p3.ATK_bar<500&&jeu.t1.p1.ATK_bar<500&&jeu.t1.p2.ATK_bar<500&&jeu.t1.p3.ATK_bar<500){
        jeu.t1.p1.ATK_bar=jeu.t1.p1.ATK_bar+jeu.t1.p1.SPD;
        jeu.t1.p2.ATK_bar=jeu.t1.p2.ATK_bar+jeu.t1.p2.SPD;
        jeu.t1.p3.ATK_bar=jeu.t1.p3.ATK_bar+jeu.t1.p3.SPD;
        jeu.t2.p1.ATK_bar=jeu.t2.p1.ATK_bar+jeu.t2.p1.SPD;
        jeu.t2.p2.ATK_bar=jeu.t2.p2.ATK_bar+jeu.t2.p2.SPD;
        jeu.t2.p3.ATK_bar=jeu.t2.p3.ATK_bar+jeu.t2.p3.SPD;}
        if(jeu.t1.p1.ATK_bar >= 500 || jeu.t1.p2.ATK_bar >= 500 || jeu.t1.p3.ATK_bar >= 500){
            if(prochainperso(j)->MaxHP==290){
            ds11-=1;
            ds17-=1;
            }
            if(prochainperso(j)->MaxHP==210){
            ds12-=1;
            ds18-=1;
            }
            if(prochainperso(j)->MaxHP==190){
            ds13-=1;
            ds19-=1;
            }
            if(prochainperso(j)->MaxHP==230){
            ds14-=1;
            }
            if(prochainperso(j)->MaxHP==330){
            ds15-=1;
            ds20-=1;
            }
            if(prochainperso(j)->MaxHP==300){
            ds16-=1;
            }
            if (ds11<0){
                if(tab1eff2[0].ATK!=tab3[0].ATK){
                       tab1eff2[0].ATK=antiskillATK(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.ATK=tab1eff2[0].ATK;
                }
                if(tab1eff2[1].ATK!=tab3[1].ATK){
                       tab1eff2[1].ATK=antiskillATK(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab2eff2[1].ATK;
                }
                if(tab1eff2[2].ATK!=tab3[2].ATK){
                       tab1eff2[2].ATK=antiskillATK(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].ATK;
                }
                ds11=10000;
            }
            if (ds12<0){
               if(tab1eff2[0].SPD!=tab3[0].SPD){
                       tab1eff2[0].SPD=antiskillSPD(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.SPD=tab1eff2[0].SPD;
                }
                if(tab1eff2[1].SPD!=tab3[1].SPD){
                       tab1eff2[1].SPD=antiskillSPD(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].SPD;
                }
                if(tab1eff2[2].SPD!=tab3[2].SPD){
                       tab1eff2[2].SPD=antiskillSPD(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.SPD=tab1eff2[2].SPD;
                }
                ds12=10000;
            }
            if (ds13<0){
               if(tab1eff2[0].ATK!=tab3[0].ATK){
                       tab1eff2[0].ATK=antiskillATK(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.ATK=tab1eff2[0].ATK;
                }
                if(tab1eff2[1].ATK!=tab3[1].ATK){
                       tab1eff2[1].ATK=antiskillATK(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].ATK;
                }
                if(tab1eff2[2].ATK!=tab3[2].ATK){
                       tab1eff2[2].ATK=antiskillATK(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].ATK;
                }
                ds13=10000;
            }
            if (ds14<0){
                if(tab1eff2[0].ATK!=tab3[0].ATK){
                       tab1eff2[0].ATK=antiskillATK(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.ATK=tab1eff2[0].ATK;
                }
                if(tab1eff2[1].ATK!=tab3[1].ATK){
                       tab1eff2[1].ATK=antiskillATK(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].ATK;
                }
                if(tab1eff2[2].ATK!=tab3[2].ATK){
                       tab1eff2[2].ATK=antiskillATK(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].ATK;
                }
                ds14=10000;
            }
            if (ds15<0){
                 if(tab1eff2[0].ATK!=tab3[0].ATK){
                       tab1eff2[0].ATK=antiskillATK(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.ATK=tab1eff2[0].ATK;
                }
                if(tab1eff2[1].ATK!=tab3[1].ATK){
                       tab1eff2[1].ATK=antiskillATK(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].ATK;
                }
                if(tab1eff2[2].ATK!=tab3[2].ATK){
                       tab1eff2[2].ATK=antiskillATK(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].ATK;
                }
                ds15=10000;
            }
            if (ds16<0){
                if(tab1eff2[0].SPD!=tab3[0].SPD){
                       tab1eff2[0].SPD=antiskillSPD(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.SPD=tab1eff2[0].SPD;
                }
                if(tab1eff2[1].SPD!=tab3[1].SPD){
                       tab1eff2[1].SPD=antiskillSPD(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].SPD;
                }
                if(tab1eff2[2].SPD!=tab3[2].SPD){
                       tab1eff2[2].SPD=antiskillSPD(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.SPD=tab1eff2[2].SPD;
                }
                ds16=10000;
            }
          if (ds17<0){
                if(tab1eff2[0].DEF!=tab3[0].DEF){
                       tab1eff2[0].DEF=antiskillDEF(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.DEF=tab1eff2[0].DEF;
                }
                if(tab1eff2[1].DEF!=tab3[1].DEF){
                       tab1eff2[1].DEF=antiskillDEF(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.DEF=tab1eff2[1].DEF;
                }
                if(tab1eff2[2].DEF!=tab3[2].DEF){
                       tab1eff2[2].DEF=antiskillDEF(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.DEF=tab1eff2[2].DEF;
                }
                ds17=10000;
            }
          if (ds18<0){
                if(tab1eff2[0].RES!=tab3[0].RES){
                       tab1eff2[0].RES=antiskillRES(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.RES=tab1eff2[0].RES;
                }
                if(tab1eff2[1].RES!=tab3[1].RES){
                       tab1eff2[1].RES=antiskillRES(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.RES=tab1eff2[1].RES;
                }
                if(tab1eff2[2].RES!=tab3[2].RES){
                       tab1eff2[2].RES=antiskillRES(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.RES=tab1eff2[2].RES;
                }
                ds18=10000;
            }
          if (ds19<0){
                if(tab2eff2[0].SPD!=tab4[0].SPD){
                       tab2eff2[0].SPD=antiskillSPDene(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.SPD=tab2eff2[0].SPD;
                }
                if(tab2eff2[1].SPD!=tab4[1].SPD){
                       tab2eff2[1].SPD=antiskillSPDene(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.ATK=tab2eff2[1].SPD;
                }
                if(tab2eff2[2].SPD!=tab4[2].SPD){
                       tab2eff2[2].SPD=antiskillSPDene(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.SPD=tab2eff2[2].SPD;
                }
                ds19=10000;
            }
            if (ds20<0){
                if(tab2eff2[0].DEF!=tab4[0].DEF){
                       tab2eff2[0].DEF=antiskillDEFene(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.DEF=tab2eff2[0].DEF;
                }
                if(tab2eff2[1].DEF!=tab4[1].DEF){
                       tab2eff2[1].DEF=antiskillDEFene(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.DEF=tab2eff2[1].DEF;
                }
                if(tab2eff2[2].DEF!=tab4[2].DEF){
                       tab2eff2[2].DEF=antiskillDEFene(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.ATK=tab2eff2[2].DEF;
                }
                ds20=10000;
            }
            
            prochainperso(j)->ch_skill1.dcd -= 1;
            prochainperso(j)->ch_skill2.dcd -= 1;
            if (prochainperso(j)->ch_skill2.dcd<0){
                prochainperso(j)->ch_skill2.dcd=0;
            }
            if (prochainperso(j)->ch_skill1.dcd<0){
                prochainperso(j)->ch_skill1.dcd=0;
            }
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
               tab2[d].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
            }
            if(n==2){
               if(prochainperso(j)->MaxHP==230||prochainperso(j)->MaxHP==330){
                    d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                tab2[d].ATK=skillATK(prochainperso(j),tab2[d]);
                if(prochainperso(j)->MaxHP==230){
                    ds4=prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==tab1[d].MaxHP){
                        tab1eff2[0].ATK==tab1[d].ATK;
                    }
                    if(tab1eff2[1].MaxHP==tab1[d].MaxHP){
                        tab1eff2[1].ATK==tab1[d].ATK;
                    }
                    if(tab1eff2[2].MaxHP==tab1[d].MaxHP){
                        tab1eff2[2].ATK==tab1[d].ATK;
                    }                    
                }
                 if(prochainperso(j)->MaxHP==330){
                    ds5=prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==tab1[d].MaxHP){
                        tab1eff2[0].ATK==tab1[d].ATK;
                    }
                    if(tab1eff2[1].MaxHP==tab1[d].MaxHP){
                        tab1eff2[1].ATK==tab1[d].ATK;
                    }
                    if(tab1eff2[2].MaxHP==tab1[d].MaxHP){
                        tab1eff2[2].ATK==tab1[d].ATK;
                    }
                 }
               if (tab1[d].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.ATK=tab1[d].ATK;
               }
               if (tab1[d].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.ATK=tab1[d].ATK;

               }
               if (tab1[d].MaxHP==jeu.t1.p3.MaxHP){
                    jeu.t1.p3.ATK=tab1[d].ATK;
               }
              }
            
                   if(prochainperso(j)->MaxHP==290){
                    ds1=prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p1);
                          tab1eff2[0].ATK==prochainperso(j)->ATK;
                      jeu.t1.p1.ATK=prochainperso(j)->ATK;
                  
                        if(tab1eff2[1].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p2);
                          tab1eff2[1].ATK==prochainperso(j)->ATK;
                      jeu.t1.p2.ATK=prochainperso(j)->ATK;
                   }
                   if (prochainperso(j)->MaxHP==tab1eff2[2].MaxHP){
                       prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p3);  
                     tab1eff2[2].ATK==prochainperso(j)->ATK;
                     jeu.t1.p3.ATK=prochainperso(j)->ATK;
                   }
                    }
                   }
                    if(prochainperso(j)->MaxHP==190){
                    ds3=prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p1);
                          tab1eff2[0].ATK==prochainperso(j)->ATK;
                      jeu.t1.p1.ATK=prochainperso(j)->ATK;
                    }
                        if(tab1eff2[1].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p2);
                          tab1eff2[1].ATK==prochainperso(j)->ATK;
                      jeu.t1.p2.ATK=prochainperso(j)->ATK;
                   }
                   if (prochainperso(j)->MaxHP==tab1eff2[2].MaxHP){
                       prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p3);  
                     tab1eff2[1].ATK==prochainperso(j)->ATK;
                     jeu.t1.p3.ATK=prochainperso(j)->ATK;
                   }
                    }
                if(prochainperso(j)->MaxHP==210){
                    ds2=prochainperso(j)->ch_skill1.duration;
                    if (prochainperso(j)->MaxHP==jeu.t1.p1.MaxHP){
                        prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p1);
                         tab1eff2[0].SPD==prochainperso(j)->SPD;
                        jeu.t1.p1.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t1.p2.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p2);
                      tab1eff2[1].SPD==prochainperso(j)->SPD;
                        jeu.t1.p2.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t1.p3.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p3);
                       tab1eff2[2].SPD==prochainperso(j)->SPD;
                        jeu.t1.p3.SPD=prochainperso(j)->SPD;
                   }
                }
                if(prochainperso(j)->MaxHP==300){
                    ds6=prochainperso(j)->ch_skill1.duration;
                   if (prochainperso(j)->MaxHP==jeu.t1.p1.MaxHP){
                        prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p1);
                         tab1eff2[0].SPD==prochainperso(j)->SPD;
                        jeu.t1.p1.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t1.p2.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p2);
                      tab1eff2[1].SPD==prochainperso(j)->SPD;
                        jeu.t1.p2.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t1.p3.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p3);
                       tab1eff2[2].SPD==prochainperso(j)->SPD;
                        jeu.t1.p3.SPD=prochainperso(j)->SPD;
                   }
                }
            }
            }
             if(n==3){
               if(prochainperso(j)->MaxHP==230||prochainperso(j)->MaxHP==300){
                   d=verifint() -1;
                while (tab1[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                    tab1[d].ActHP=skillHEAL(prochainperso(j),tab1[d]);
                 if (tab1[d].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.ActHP=tab1[d].ActHP;
               }
               if (tab1[d].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.ActHP=tab1[d].ActHP;
               }
               if (tab1[d].MaxHP==jeu.t1.p3.MaxHP){
                    jeu.t1.p3.ActHP=tab1[d].ActHP;
               }
            if(prochainperso(j)->MaxHP==330){
                   d=verifint() -1;
                while (tab1[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                    tab2[d].DEF=skillDEFene(prochainperso(j),tab2[d]);
                 if (tab2[d].MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.DEF=tab2[d].DEF;
               }
               if (tab2[d].MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.DEF=tab2[d].DEF;

               }
               if (tab2[d].MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.DEF=tab2[d].DEF;
               }
              ds10=prochainperso(j)->ch_skill2.duration;
                if(tab2eff2[0].MaxHP==tab2[d].MaxHP){
                    tab2eff2[0].DEF==tab2[d].DEF;
                }
                if(tab2eff2[1].MaxHP==tab2[d].MaxHP){
                    tab2eff2[1].DEF==tab2[d].DEF;
                }
                if(tab2eff2[2].MaxHP==tab2[d].MaxHP){
                    tab2eff2[2].DEF==tab2[d].DEF;
                }
                }
            if(prochainperso(j)->MaxHP==290){
            ds7=prochainperso(j)->ch_skill2.duration;
                 if (prochainperso(j)->MaxHP==jeu.t1.p1.MaxHP){
                      prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t1.p1);
                    tab1eff2[0].DEF==prochainperso(j)->DEF;
                   jeu.t1.p1.DEF=prochainperso(j)->DEF;
               }
               if (prochainperso(j)->MaxHP==jeu.t1.p2.MaxHP){
                    prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t1.p2);
                 tab1eff2[1].DEF==prochainperso(j)->DEF;
                    jeu.t1.p2.DEF=prochainperso(j)->DEF;

               }
               if (prochainperso(j)->MaxHP==jeu.t1.p3.MaxHP){
                    prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t1.p3);
                 tab1eff2[2].DEF==prochainperso(j)->DEF;
                    jeu.t1.p3.DEF=prochainperso(j)->DEF;
               }
               }
            if(prochainperso(j)->MaxHP==190){
                    d=verifint() -1;
                while (tab1[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                    tab2[d].SPD=skillSPDene(prochainperso(j),tab2[d]);
              ds9=prochainperso(j)->ch_skill2.duration;
                 if (tab2[d].MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t1.p1.SPD=tab2[d].SPD;
               }
               if (tab2[d].MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.SPD=tab2[d].SPD;
               }
               if (tab2[d].MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.SPD=tab2[d].SPD;
               }
                if(tab2eff2[0].MaxHP==tab2[d].MaxHP){
                    tab2eff2[0].DEF==tab2[d].DEF;
                }
                if(tab2eff2[1].MaxHP==tab2[d].MaxHP){
                    tab2eff2[1].DEF==tab2[d].DEF;
                }
                if(tab2eff2[2].MaxHP==tab2[d].MaxHP){
                    tab2eff2[2].DEF==tab2[d].DEF;
                }
                }
            if(prochainperso(j)->MaxHP==210){
              ds8=prochainperso(j)->ch_skill2.duration;
                 if (prochainperso(j)->MaxHP==jeu.t1.p1.MaxHP){
                      prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t1.p1);
                   tab1eff2[0].RES==prochainperso(j)->RES;
                   jeu.t1.p1.RES=prochainperso(j)->RES;
               }
               if (prochainperso(j)->MaxHP==jeu.t1.p2.MaxHP){
                    prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t1.p2);
                 tab1eff2[1].RES==prochainperso(j)->RES;
                    jeu.t1.p2.RES=prochainperso(j)->RES;

               }
               if (prochainperso(j)->MaxHP==jeu.t1.p3.MaxHP){
                    prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t1.p3);
                 tab1eff2[2].RES==prochainperso(j)->RES;
                    jeu.t1.p3.RES=prochainperso(j)->RES;
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
        }
        else if(jeu.t2.p1.ATK_bar >= 500 || jeu.t2.p2.ATK_bar >= 500 || jeu.t2.p3.ATK_bar >= 500){
            if(prochainperso(j)->MaxHP==290){
            ds1-=1;
            ds7-=1;
            }
            if(prochainperso(j)->MaxHP==210){
            ds2-=1;
            ds8-=1;
            }
            if(prochainperso(j)->MaxHP==190){
            ds3-=1;
            ds9-=1;
            }
            if(prochainperso(j)->MaxHP==230){
            ds4-=1;
            }
            if(prochainperso(j)->MaxHP==330){
            ds5-=1;
            ds10-=1;
            }
            if(prochainperso(j)->MaxHP==300){
            ds6-=1;
            }
            if (ds1<0){
                if(tab2eff2[0].ATK!=tab4[0].ATK){
                       tab2eff2[0].ATK=antiskillATK(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.ATK=tab2eff2[0].ATK;
                }
                if(tab2eff2[1].ATK!=tab4[1].ATK){
                       tab2eff2[1].ATK=antiskillATK(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.ATK=tab2eff2[1].ATK;
                }
                if(tab2eff2[2].ATK!=tab4[2].ATK){
                       tab2eff2[2].ATK=antiskillATK(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.ATK=tab2eff2[2].ATK;
                }
                ds1=10000;
            }
            if (ds2<0){
               if(tab2eff2[0].SPD!=tab4[0].SPD){
                       tab2eff2[0].SPD=antiskillSPD(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.SPD=tab2eff2[0].SPD;
                }
                if(tab2eff2[1].SPD!=tab4[1].SPD){
                       tab2eff2[1].SPD=antiskillSPD(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.ATK=tab2eff2[1].SPD;
                }
                if(tab2eff2[2].SPD!=tab4[2].SPD){
                       tab2eff2[2].SPD=antiskillSPD(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.SPD=tab2eff2[2].SPD;
                }
                ds2=10000;
            }
            if (ds3<0){
               if(tab2eff2[0].ATK!=tab4[0].ATK){
                       tab2eff2[0].ATK=antiskillATK(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.ATK=tab2eff2[0].ATK;
                }
                if(tab2eff2[1].ATK!=tab4[1].ATK){
                       tab2eff2[1].ATK=antiskillATK(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.ATK=tab2eff2[1].ATK;
                }
                if(tab2eff2[2].ATK!=tab4[2].ATK){
                       tab2eff2[2].ATK=antiskillATK(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.ATK=tab2eff2[2].ATK;
                }
                ds3=10000;
            }
            if (ds4<0){
                if(tab2eff2[0].ATK!=tab4[0].ATK){
                       tab2eff2[0].ATK=antiskillATK(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.ATK=tab2eff2[0].ATK;
                }
                if(tab2eff2[1].ATK!=tab4[1].ATK){
                       tab2eff2[1].ATK=antiskillATK(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.ATK=tab2eff2[1].ATK;
                }
                if(tab2eff2[2].ATK!=tab4[2].ATK){
                       tab2eff2[2].ATK=antiskillATK(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.ATK=tab2eff2[2].ATK;
                }
                ds4=10000;
            }
            if (ds5<0){
                 if(tab2eff2[0].ATK!=tab4[0].ATK){
                       tab2eff2[0].ATK=antiskillATK(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.ATK=tab2eff2[0].ATK;
                }
                if(tab2eff2[1].ATK!=tab4[1].ATK){
                       tab2eff2[1].ATK=antiskillATK(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.ATK=tab2eff2[1].ATK;
                }
                if(tab2eff2[2].ATK!=tab4[2].ATK){
                       tab2eff2[2].ATK=antiskillATK(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.ATK=tab2eff2[2].ATK;
                }
                ds5=10000;
            }
            if (ds6<0){
                if(tab2eff2[0].SPD!=tab4[0].SPD){
                       tab2eff2[0].SPD=antiskillSPD(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.SPD=tab2eff2[0].SPD;
                }
                if(tab2eff2[1].SPD!=tab4[1].SPD){
                       tab2eff2[1].SPD=antiskillSPD(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.ATK=tab2eff2[1].SPD;
                }
                if(tab2eff2[2].SPD!=tab4[2].SPD){
                       tab2eff2[2].SPD=antiskillSPD(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.SPD=tab2eff2[2].SPD;
                }
                ds6=10000;
            }
          if (ds7<0){
                if(tab2eff2[0].DEF!=tab4[0].DEF){
                       tab2eff2[0].DEF=antiskillDEF(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.DEF=tab2eff2[0].DEF;
                }
                if(tab2eff2[1].DEF!=tab4[1].DEF){
                       tab2eff2[1].DEF=antiskillDEF(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.DEF=tab2eff2[1].DEF;
                }
                if(tab2eff2[2].DEF!=tab4[2].DEF){
                       tab2eff2[2].DEF=antiskillDEF(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.DEF=tab2eff2[2].DEF;
                }
                ds7=10000;
            }
          if (ds8<0){
                if(tab2eff2[0].RES!=tab4[0].RES){
                       tab2eff2[0].RES=antiskillRES(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.RES=tab2eff2[0].RES;
                }
                if(tab2eff2[1].RES!=tab4[1].RES){
                       tab2eff2[1].RES=antiskillRES(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.RES=tab2eff2[1].RES;
                }
                if(tab2eff2[2].RES!=tab4[2].RES){
                       tab2eff2[2].RES=antiskillRES(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.RES=tab2eff2[2].RES;
                }
                ds8=10000;
            }
          if (ds9<0){
                if(tab1eff2[0].SPD!=tab3[0].SPD){
                       tab1eff2[0].SPD=antiskillSPDene(prochainperso(j),tab2eff2[0]);
                    j->t1.p1.SPD=tab1eff2[0].SPD;
                }
                if(tab1eff2[1].SPD!=tab3[1].SPD){
                       tab1eff2[1].SPD=antiskillSPDene(prochainperso(j),tab2eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].SPD;
                }
                if(tab1eff2[2].SPD!=tab3[2].SPD){
                       tab1eff2[2].SPD=antiskillSPDene(prochainperso(j),tab2eff2[2]);
                    j->t1.p3.SPD=tab1eff2[2].SPD;
                }
                ds9=10000;
            }
            if (ds10<0){
                if(tab1eff2[0].DEF!=tab3[0].DEF){
                       tab1eff2[0].DEF=antiskillDEFene(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.DEF=tab1eff2[0].DEF;
                }
                if(tab1eff2[1].DEF!=tab3[1].DEF){
                       tab1eff2[1].DEF=antiskillDEFene(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.DEF=tab1eff2[1].DEF;
                }
                if(tab1eff2[2].DEF!=tab3[2].DEF){
                       tab1eff2[2].DEF=antiskillDEFene(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].DEF;
                }
                ds10=10000;
            }
            
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
                                tab1[2].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                                j->t1.p3.ActHP=tab1[2].ActHP;
                            }
                         else{
                            tab1[1].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                             j->t1.p2.ActHP=tab1[1].ActHP;
                            }
                        }
                else{
                        tab1[0].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                        j->t1.p1.ActHP=tab1[0].ActHP;
                }
            }
            else if(tab1[1].ActHP<=tab1[0].ActHP && tab1[1].ActHP<=tab1[2].ActHP){
            if(tab1[1].ActHP==0){
                        if(tab1[2].ActHP<=tab1[0].ActHP && tab1[2].ActHP>=0){
                                tab1[2].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                                j->t1.p3.ActHP=tab1[2].ActHP;
                            }
                         else{
                            tab1[0].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                             j->t1.p1.ActHP=tab1[0].ActHP;
                            }
                        }
                else{
                        tab1[1].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                        j->t1.p2.ActHP=tab1[1].ActHP;
                }
            }
            else if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP<=tab1[0].ActHP){
            if(tab1[2].ActHP==0){
                        if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP>=0){
                                tab1[0].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                                j->t1.p1.ActHP=tab1[0].ActHP;
                            }
                         else{
                            tab1[1].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                             j->t1.p2.ActHP=tab1[1].ActHP;
                            }
                        }
                else{
                        tab1[2].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                        j->t1.p3.ActHP=tab1[2].ActHP;
                }
            }
            }
            else if(prochainperso(j)->ch_skill1.dcd == 0){
                // fonction skill1 du perso
              if(prochainperso(j)->MaxHP==230||prochainperso(j)->MaxHP==330){
                    a=(rand()%3);
                while (tab2[a].ActHP<=0){
                    a=(rand()%3);
                }
                tab2[a].ATK=skillATK(prochainperso(j),tab2[a]);
                if(prochainperso(j)->MaxHP==230){
                    ds4=prochainperso(j)->ch_skill1.duration;
                    if(tab2eff2[0].MaxHP==tab2[a].MaxHP){
                        tab2eff2[0].ATK==tab2[a].ATK;
                    }
                    if(tab2eff2[1].MaxHP==tab2[a].MaxHP){
                        tab2eff2[1].ATK==tab2[a].ATK;
                    }
                    if(tab2eff2[2].MaxHP==tab2[a].MaxHP){
                        tab2eff2[2].ATK==tab2[a].ATK;
                    }                    
                }
                 if(prochainperso(j)->MaxHP==330){
                    ds5=prochainperso(j)->ch_skill1.duration;
                    if(tab2eff2[0].MaxHP==tab2[a].MaxHP){
                        tab2eff2[0].ATK==tab2[a].ATK;
                    }
                    if(tab2eff2[1].MaxHP==tab2[a].MaxHP){
                        tab2eff2[1].ATK==tab2[a].ATK;
                    }
                    if(tab2eff2[2].MaxHP==tab2[a].MaxHP){
                        tab2eff2[2].ATK==tab2[a].ATK;
                    }
               if (tab2[a].MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.ATK=tab2[a].ATK;
               }
               if (tab2[a].MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.ATK=tab2[a].ATK;

               }
               if (tab2[a].MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.ATK=tab2[a].ATK;
               }
              }
            
                   if(prochainperso(j)->MaxHP==290){
                    ds1=prochainperso(j)->ch_skill1.duration;
                    if(tab2eff2[0].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t2.p1);
                          tab2eff2[0].ATK==prochainperso(j)->ATK;
                      jeu.t2.p1.ATK=prochainperso(j)->ATK;
                  
                        if(tab2eff2[1].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t2.p2);
                          tab2eff2[1].ATK==prochainperso(j)->ATK;
                      jeu.t2.p2.ATK=prochainperso(j)->ATK;
                   }
                   if (prochainperso(j)->MaxHP==(tab2eff2[2].MaxHP)){
                       prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t2.p3);  
                     tab2eff2[2].ATK==prochainperso(j)->ATK;
                     jeu.t2.p3.ATK=prochainperso(j)->ATK;
                   }
                    }
                   }
                    if(prochainperso(j)->MaxHP==190){
                    ds3=prochainperso(j)->ch_skill1.duration;
                    if(tab2eff2[0].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t2.p1);
                          tab2eff2[0].ATK==prochainperso(j)->ATK;
                      jeu.t2.p1.ATK=prochainperso(j)->ATK;
                  
                        if(tab2eff2[1].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t2.p2);
                          tab2eff2[1].ATK==prochainperso(j)->ATK;
                      jeu.t2.p2.ATK=prochainperso(j)->ATK;
                   }
                   if (prochainperso(j)->MaxHP==(tab2eff2[2].MaxHP)){
                       prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t2.p3);  
                     tab2eff2[1].ATK==prochainperso(j)->ATK;
                     jeu.t2.p3.ATK=prochainperso(j)->ATK;
                   }
                    }
                   }
                if(prochainperso(j)->MaxHP==210){
                    ds2=prochainperso(j)->ch_skill1.duration;
                    if (prochainperso(j)->MaxHP==jeu.t2.p1.MaxHP){
                        prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t2.p1);
                         tab2eff2[0].SPD==prochainperso(j)->SPD;
                        jeu.t2.p1.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t2.p2.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t2.p2);
                      tab2eff2[1].SPD==prochainperso(j)->SPD;
                        jeu.t2.p2.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t2.p3.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t2.p3);
                       tab2eff2[2].SPD==prochainperso(j)->SPD;
                        jeu.t2.p3.SPD=prochainperso(j)->SPD;
                   }
                }
                if(prochainperso(j)->MaxHP==300){
                    ds6=prochainperso(j)->ch_skill1.duration;
                   if (prochainperso(j)->MaxHP==jeu.t2.p1.MaxHP){
                        prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t2.p1);
                         tab2eff2[0].SPD==prochainperso(j)->SPD;
                        jeu.t2.p1.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t2.p2.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t2.p2);
                      tab2eff2[1].SPD==prochainperso(j)->SPD;
                        jeu.t2.p2.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t2.p3.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t2.p3);
                       tab2eff2[2].SPD==prochainperso(j)->SPD;
                        jeu.t2.p3.SPD=prochainperso(j)->SPD;
                   }
                }
            }
            }
            else if(prochainperso(j)->ch_skill2.dcd == 0){
             if(prochainperso(j)->MaxHP==230||prochainperso(j)->MaxHP==300){
                  a=(rand()%3);
                while (tab2[a].ActHP<=0){
                    a=(rand()%3);
                }
                    tab2[a].ActHP=skillHEAL(prochainperso(j),tab2[a]);
                 if (tab2[a].MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.ActHP=tab2[a].ActHP;
               }
               if (tab2[a].MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.ActHP=tab2[a].ActHP;
               }
               if (tab2[a].MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.ActHP=tab2[a].ActHP;
               }
            if(prochainperso(j)->MaxHP==330){
                    a=(rand()%3);
                while (tab1[a].ActHP<=0){
                    a=(rand()%3);
                }
                    tab1[a].DEF=skillDEFene(prochainperso(j),tab1[a]);
                 if (tab1[a].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.DEF=tab1[a].DEF;
               }
               if (tab1[a].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.DEF=tab1[a].DEF;

               }
               if (tab1[a].MaxHP==jeu.t1.p3.MaxHP){
                    jeu.t1.p3.DEF=tab1[a].DEF;
               }
              ds10=prochainperso(j)->ch_skill2.duration;
                if(tab1eff2[0].MaxHP==tab1[a].MaxHP){
                    tab1eff2[0].DEF==tab1[a].DEF;
                }
                if(tab1eff2[1].MaxHP==tab1[a].MaxHP){
                    tab1eff2[1].DEF==tab1[a].DEF;
                }
                if(tab1eff2[2].MaxHP==tab1[a].MaxHP){
                    tab1eff2[2].DEF==tab2[a].DEF;
                }
                }
            if(prochainperso(j)->MaxHP==290){
            ds7=prochainperso(j)->ch_skill2.duration;
                 if (prochainperso(j)->MaxHP==jeu.t2.p1.MaxHP){
                      prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t2.p1);
                    tab2eff2[0].DEF==prochainperso(j)->DEF;
                   jeu.t2.p1.DEF=prochainperso(j)->DEF;
               }
               if (prochainperso(j)->MaxHP==jeu.t2.p2.MaxHP){
                    prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t2.p2);
                 tab2eff2[1].DEF==prochainperso(j)->DEF;
                    jeu.t2.p2.DEF=prochainperso(j)->DEF;

               }
               if (prochainperso(j)->MaxHP==jeu.t2.p3.MaxHP){
                    prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t2.p3);
                 tab2eff2[2].DEF==prochainperso(j)->DEF;
                    jeu.t2.p3.DEF=prochainperso(j)->DEF;
               }
               }
            if(prochainperso(j)->MaxHP==190){
                    a=(rand()%3);
                while (tab1[a].ActHP<=0){
                    a=(rand()%3);
                }
                    tab1[a].SPD=skillSPDene(prochainperso(j),tab1[a]);
              ds9=prochainperso(j)->ch_skill2.duration;
                 if (tab1[a].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.SPD=tab1[a].SPD;
               }
               if (tab1[a].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.SPD=tab1[a].SPD;
               }
               if (tab1[a].MaxHP==jeu.t1.p3.MaxHP){
                    jeu.t1.p3.SPD=tab1[a].SPD;
               }
                if(tab1eff2[0].MaxHP==tab1[a].MaxHP){
                    tab1eff2[0].DEF==tab1[a].DEF;
                }
                if(tab1eff2[1].MaxHP==tab1[a].MaxHP){
                    tab1eff2[1].DEF==tab1[a].DEF;
                }
                if(tab1eff2[2].MaxHP==tab1[a].MaxHP){
                    tab1eff2[2].DEF==tab1[a].DEF;
                }
                }
            if(prochainperso(j)->MaxHP==210){
              ds8=prochainperso(j)->ch_skill2.duration;
                 if (prochainperso(j)->MaxHP==jeu.t2.p1.MaxHP){
                      prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t2.p1);
                   tab2eff2[0].RES==prochainperso(j)->RES;
                   jeu.t2.p1.RES=prochainperso(j)->RES;
               }
               if (prochainperso(j)->MaxHP==jeu.t2.p2.MaxHP){
                    prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t2.p2);
                 tab2eff2[1].RES==prochainperso(j)->RES;
                    jeu.t2.p2.RES=prochainperso(j)->RES;

               }
               if (prochainperso(j)->MaxHP==jeu.t2.p3.MaxHP){
                    prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t2.p3);
                 tab2eff2[2].RES==prochainperso(j)->RES;
                    jeu.t2.p3.RES=prochainperso(j)->RES;
               }
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
        jeu.t1.p1.ATK_bar=0;
           }
    if(jeu.t1.p2.ActHP <= 0){
        jeu.t1.p2.SPD=0;
        jeu.t1.p2.ATK_bar=0;
   } 
    if(jeu.t1.p3.ActHP <= 0){
        jeu.t1.p3.SPD=0;
        jeu.t1.p3.ATK_bar=0;
   } 
    if(jeu.t2.p1.ActHP <= 0){
        jeu.t2.p1.SPD=0;
        jeu.t2.p1.ATK_bar=0;
   } 
    if(jeu.t2.p2.ActHP <= 0){
        jeu.t2.p2.SPD=0;
        jeu.t2.p2.ATK_bar=0;
   } 
    if(jeu.t2.p3.ActHP <= 0){
        jeu.t2.p3.SPD=0;
        jeu.t2.p3.ATK_bar=0;
   } 
    }
        }
}
}

    
    
    
    
void botmoyen(Character tabC[]){
    Jeu jeu;
    Jeu* j;
    j=&jeu;
    int n=0;
    int d=0;
    jeu.t1 = MakeTeam(tabC,6);
    jeu.t2 = MakeTeambot(tabC,6);
    strcpy(jeu.t2.name , "bot");
    int a=0;
    int ds11=10000;
    int ds12=10000;
    int ds13=10000;
    int ds14=10000;
    int ds15=10000;
    int ds16=10000;
    int ds17=10000;
    int ds18=10000;
    int ds19=10000;
    int ds20=10000;
    Character tab1[3];
    Character tab2[3];
    Character tab3[3];
    Character tab4[3];
    Character tab1eff2[3];
    Character tab2eff2[3];
    jeu.t1 = MakeTeam(tabC,6);
    jeu.t2 = MakeTeambot(tabC,3);
    tab1[0]=jeu.t1.p1;
    tab1[1]=jeu.t1.p2;
    tab1[2]=jeu.t1.p3;
    tab2[0]=jeu.t2.p1;
    tab2[1]=jeu.t2.p2;
    tab2[2]=jeu.t2.p3;
    tab3[0]=jeu.t1.p1;
    tab3[1]=jeu.t1.p2;
    tab3[2]=jeu.t1.p3;
    tab4[0]=jeu.t2.p1;
    tab4[1]=jeu.t2.p2;
    tab4[2]=jeu.t2.p3;
    tab1eff2[0]=jeu.t1.p2;
    tab1eff2[1]=jeu.t1.p2;
    tab1eff2[2]=jeu.t1.p3;
    tab2eff2[0]=jeu.t2.p1;
    tab2eff2[1]=jeu.t2.p2;
    tab2eff2[2]=jeu.t2.p3;
    while(jeu.t1.p1.ActHP > 0 && jeu.t1.p2.ActHP > 0 && jeu.t1.p3.ActHP > 0 || jeu.t2.p1.ActHP > 0 && jeu.t2.p2.ActHP > 0 && jeu.t2.p3.ActHP > 0){
        if (jeu.t1.p1.ATK_bar<500&&jeu.t1.p2.ATK_bar<500&&jeu.t1.p3.ATK_bar<500&&jeu.t1.p1.ATK_bar<500&&jeu.t1.p2.ATK_bar<500&&jeu.t1.p3.ATK_bar<500){
        jeu.t1.p1.ATK_bar=jeu.t1.p1.ATK_bar+jeu.t1.p1.SPD;
        jeu.t1.p2.ATK_bar=jeu.t1.p2.ATK_bar+jeu.t1.p2.SPD;
        jeu.t1.p3.ATK_bar=jeu.t1.p3.ATK_bar+jeu.t1.p3.SPD;
        jeu.t2.p1.ATK_bar=jeu.t2.p1.ATK_bar+jeu.t2.p1.SPD;
        jeu.t2.p2.ATK_bar=jeu.t2.p2.ATK_bar+jeu.t2.p2.SPD;
        jeu.t2.p3.ATK_bar=jeu.t2.p3.ATK_bar+jeu.t2.p3.SPD;}
        if(jeu.t1.p1.ATK_bar >= 500 || jeu.t1.p2.ATK_bar >= 500 || jeu.t1.p3.ATK_bar >= 500){
            if(prochainperso(j)->MaxHP==290){
            ds11-=1;
            ds17-=1;
            }
            if(prochainperso(j)->MaxHP==210){
            ds12-=1;
            ds18-=1;
            }
            if(prochainperso(j)->MaxHP==190){
            ds13-=1;
            ds19-=1;
            }
            if(prochainperso(j)->MaxHP==230){
            ds14-=1;
            }
            if(prochainperso(j)->MaxHP==330){
            ds15-=1;
            ds20-=1;
            }
            if(prochainperso(j)->MaxHP==300){
            ds16-=1;
            }
            if (ds11<0){
                if(tab1eff2[0].ATK!=tab3[0].ATK){
                       tab1eff2[0].ATK=antiskillATK(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.ATK=tab1eff2[0].ATK;
                }
                if(tab1eff2[1].ATK!=tab3[1].ATK){
                       tab1eff2[1].ATK=antiskillATK(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab2eff2[1].ATK;
                }
                if(tab1eff2[2].ATK!=tab3[2].ATK){
                       tab1eff2[2].ATK=antiskillATK(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].ATK;
                }
                ds11=10000;
            }
            if (ds12<0){
               if(tab1eff2[0].SPD!=tab3[0].SPD){
                       tab1eff2[0].SPD=antiskillSPD(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.SPD=tab1eff2[0].SPD;
                }
                if(tab1eff2[1].SPD!=tab3[1].SPD){
                       tab1eff2[1].SPD=antiskillSPD(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].SPD;
                }
                if(tab1eff2[2].SPD!=tab3[2].SPD){
                       tab1eff2[2].SPD=antiskillSPD(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.SPD=tab1eff2[2].SPD;
                }
                ds12=10000;
            }
            if (ds13<0){
               if(tab1eff2[0].ATK!=tab3[0].ATK){
                       tab1eff2[0].ATK=antiskillATK(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.ATK=tab1eff2[0].ATK;
                }
                if(tab1eff2[1].ATK!=tab3[1].ATK){
                       tab1eff2[1].ATK=antiskillATK(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].ATK;
                }
                if(tab1eff2[2].ATK!=tab3[2].ATK){
                       tab1eff2[2].ATK=antiskillATK(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].ATK;
                }
                ds13=10000;
            }
            if (ds14<0){
                if(tab1eff2[0].ATK!=tab3[0].ATK){
                       tab1eff2[0].ATK=antiskillATK(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.ATK=tab1eff2[0].ATK;
                }
                if(tab1eff2[1].ATK!=tab3[1].ATK){
                       tab1eff2[1].ATK=antiskillATK(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].ATK;
                }
                if(tab1eff2[2].ATK!=tab3[2].ATK){
                       tab1eff2[2].ATK=antiskillATK(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].ATK;
                }
                ds14=10000;
            }
            if (ds15<0){
                 if(tab1eff2[0].ATK!=tab3[0].ATK){
                       tab1eff2[0].ATK=antiskillATK(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.ATK=tab1eff2[0].ATK;
                }
                if(tab1eff2[1].ATK!=tab3[1].ATK){
                       tab1eff2[1].ATK=antiskillATK(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].ATK;
                }
                if(tab1eff2[2].ATK!=tab3[2].ATK){
                       tab1eff2[2].ATK=antiskillATK(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.ATK=tab1eff2[2].ATK;
                }
                ds15=10000;
            }
            if (ds16<0){
                if(tab1eff2[0].SPD!=tab3[0].SPD){
                       tab1eff2[0].SPD=antiskillSPD(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.SPD=tab1eff2[0].SPD;
                }
                if(tab1eff2[1].SPD!=tab3[1].SPD){
                       tab1eff2[1].SPD=antiskillSPD(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.ATK=tab1eff2[1].SPD;
                }
                if(tab1eff2[2].SPD!=tab3[2].SPD){
                       tab1eff2[2].SPD=antiskillSPD(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.SPD=tab1eff2[2].SPD;
                }
                ds16=10000;
            }
          if (ds17<0){
                if(tab1eff2[0].DEF!=tab3[0].DEF){
                       tab1eff2[0].DEF=antiskillDEF(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.DEF=tab1eff2[0].DEF;
                }
                if(tab1eff2[1].DEF!=tab3[1].DEF){
                       tab1eff2[1].DEF=antiskillDEF(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.DEF=tab1eff2[1].DEF;
                }
                if(tab1eff2[2].DEF!=tab3[2].DEF){
                       tab1eff2[2].DEF=antiskillDEF(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.DEF=tab1eff2[2].DEF;
                }
                ds17=10000;
            }
          if (ds18<0){
                if(tab1eff2[0].RES!=tab3[0].RES){
                       tab1eff2[0].RES=antiskillRES(prochainperso(j),tab1eff2[0]);
                    j->t1.p1.RES=tab1eff2[0].RES;
                }
                if(tab1eff2[1].RES!=tab3[1].RES){
                       tab1eff2[1].RES=antiskillRES(prochainperso(j),tab1eff2[1]);
                    j->t1.p2.RES=tab1eff2[1].RES;
                }
                if(tab1eff2[2].RES!=tab3[2].RES){
                       tab1eff2[2].RES=antiskillRES(prochainperso(j),tab1eff2[2]);
                    j->t1.p3.RES=tab1eff2[2].RES;
                }
                ds18=10000;
            }
          if (ds19<0){
                if(tab2eff2[0].SPD!=tab4[0].SPD){
                       tab2eff2[0].SPD=antiskillSPDene(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.SPD=tab2eff2[0].SPD;
                }
                if(tab2eff2[1].SPD!=tab4[1].SPD){
                       tab2eff2[1].SPD=antiskillSPDene(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.ATK=tab2eff2[1].SPD;
                }
                if(tab2eff2[2].SPD!=tab4[2].SPD){
                       tab2eff2[2].SPD=antiskillSPDene(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.SPD=tab2eff2[2].SPD;
                }
                ds19=10000;
            }
            if (ds20<0){
                if(tab2eff2[0].DEF!=tab4[0].DEF){
                       tab2eff2[0].DEF=antiskillDEFene(prochainperso(j),tab2eff2[0]);
                    j->t2.p1.DEF=tab2eff2[0].DEF;
                }
                if(tab2eff2[1].DEF!=tab4[1].DEF){
                       tab2eff2[1].DEF=antiskillDEFene(prochainperso(j),tab2eff2[1]);
                    j->t2.p2.DEF=tab2eff2[1].DEF;
                }
                if(tab2eff2[2].DEF!=tab4[2].DEF){
                       tab2eff2[2].DEF=antiskillDEFene(prochainperso(j),tab2eff2[2]);
                    j->t2.p3.ATK=tab2eff2[2].DEF;
                }
                ds20=10000;
            }
            
            prochainperso(j)->ch_skill1.dcd -= 1;
            prochainperso(j)->ch_skill2.dcd -= 1;
            if (prochainperso(j)->ch_skill2.dcd<0){
                prochainperso(j)->ch_skill2.dcd=0;
            }
            if (prochainperso(j)->ch_skill1.dcd<0){
                prochainperso(j)->ch_skill1.dcd=0;
            }
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
               tab2[d].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
               if (d==0){
                   j->t2.p1.ActHP=tab2[d].ActHP;
               }
               if (d==1){
                   j->t2.p2.ActHP=tab2[d].ActHP;
               }
               if (d==2){
                   j->t2.p3.ActHP=tab2[d].ActHP;
               }
            }
            if(n==2){
               if(prochainperso(j)->MaxHP==230||prochainperso(j)->MaxHP==330){
                    d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                tab2[d].ATK=skillATK(prochainperso(j),tab2[d]);
                if(prochainperso(j)->MaxHP==230){
                    ds14=prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==tab1[d].MaxHP){
                        tab1eff2[0].ATK==tab1[d].ATK;
                    }
                    if(tab1eff2[1].MaxHP==tab1[d].MaxHP){
                        tab1eff2[1].ATK==tab1[d].ATK;
                    }
                    if(tab1eff2[2].MaxHP==tab1[d].MaxHP){
                        tab1eff2[2].ATK==tab1[d].ATK;
                    }                    
                }
                 if(prochainperso(j)->MaxHP==330){
                    ds15=prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==tab1[d].MaxHP){
                        tab1eff2[0].ATK==tab1[d].ATK;
                    }
                    if(tab1eff2[1].MaxHP==tab1[d].MaxHP){
                        tab1eff2[1].ATK==tab1[d].ATK;
                    }
                    if(tab1eff2[2].MaxHP==tab1[d].MaxHP){
                        tab1eff2[2].ATK==tab1[d].ATK;
                    }
                 }
               if (tab1[d].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.ATK=tab1[d].ATK;
               }
               if (tab1[d].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.ATK=tab1[d].ATK;

               }
               if (tab1[d].MaxHP==jeu.t1.p3.MaxHP){
                    jeu.t1.p3.ATK=tab1[d].ATK;
               }
              }
            
                   if(prochainperso(j)->MaxHP==290){
                    ds11=prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p1);
                          tab1eff2[0].ATK==prochainperso(j)->ATK;
                      jeu.t1.p1.ATK=prochainperso(j)->ATK;
                  
                        if(tab1eff2[1].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p2);
                          tab1eff2[1].ATK==prochainperso(j)->ATK;
                      jeu.t1.p2.ATK=prochainperso(j)->ATK;
                   }
                   if (prochainperso(j)->MaxHP==tab1eff2[2].MaxHP){
                       prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p3);  
                     tab1eff2[2].ATK==prochainperso(j)->ATK;
                     jeu.t1.p3.ATK=prochainperso(j)->ATK;
                   }
                    }
                   }
                    if(prochainperso(j)->MaxHP==190){
                    ds13=prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p1);
                          tab1eff2[0].ATK==prochainperso(j)->ATK;
                      jeu.t1.p1.ATK=prochainperso(j)->ATK;
                    }
                        if(tab1eff2[1].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p2);
                          tab1eff2[1].ATK==prochainperso(j)->ATK;
                      jeu.t1.p2.ATK=prochainperso(j)->ATK;
                   }
                   if (prochainperso(j)->MaxHP==tab1eff2[2].MaxHP){
                       prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p3);  
                     tab1eff2[1].ATK==prochainperso(j)->ATK;
                     jeu.t1.p3.ATK=prochainperso(j)->ATK;
                   }
                    }
                if(prochainperso(j)->MaxHP==210){
                    ds12=prochainperso(j)->ch_skill1.duration;
                    if (prochainperso(j)->MaxHP==jeu.t1.p1.MaxHP){
                        prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p1);
                         tab1eff2[0].SPD==prochainperso(j)->SPD;
                        jeu.t1.p1.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t1.p2.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p2);
                      tab1eff2[1].SPD==prochainperso(j)->SPD;
                        jeu.t1.p2.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t1.p3.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p3);
                       tab1eff2[2].SPD==prochainperso(j)->SPD;
                        jeu.t1.p3.SPD=prochainperso(j)->SPD;
                   }
                }
                if(prochainperso(j)->MaxHP==300){
                    ds16=prochainperso(j)->ch_skill1.duration;
                   if (prochainperso(j)->MaxHP==jeu.t1.p1.MaxHP){
                        prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p1);
                         tab1eff2[0].SPD==prochainperso(j)->SPD;
                        jeu.t1.p1.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t1.p2.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p2);
                      tab1eff2[1].SPD==prochainperso(j)->SPD;
                        jeu.t1.p2.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t1.p3.MaxHP){
                       prochainperso(j)->SPD=skillSPD(prochainperso(j),jeu.t1.p3);
                       tab1eff2[2].SPD==prochainperso(j)->SPD;
                        jeu.t1.p3.SPD=prochainperso(j)->SPD;
                   }
                }
            }
            }
             if(n==3){
               if(prochainperso(j)->MaxHP==230||prochainperso(j)->MaxHP==300){
                   d=verifint() -1;
                while (tab1[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                    tab1[d].ActHP=skillHEAL(prochainperso(j),tab1[d]);
                 if (tab1[d].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.ActHP=tab1[d].ActHP;
               }
               if (tab1[d].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.ActHP=tab1[d].ActHP;
               }
               if (tab1[d].MaxHP==jeu.t1.p3.MaxHP){
                    jeu.t1.p3.ActHP=tab1[d].ActHP;
               }
            if(prochainperso(j)->MaxHP==330){
                   d=verifint() -1;
                while (tab1[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                    tab2[d].DEF=skillDEFene(prochainperso(j),tab2[d]);
                 if (tab2[d].MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.DEF=tab2[d].DEF;
               }
               if (tab2[d].MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.DEF=tab2[d].DEF;

               }
               if (tab2[d].MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.DEF=tab2[d].DEF;
               }
              ds20=prochainperso(j)->ch_skill2.duration;
                if(tab2eff2[0].MaxHP==tab2[d].MaxHP){
                    tab2eff2[0].DEF==tab2[d].DEF;
                }
                if(tab2eff2[1].MaxHP==tab2[d].MaxHP){
                    tab2eff2[1].DEF==tab2[d].DEF;
                }
                if(tab2eff2[2].MaxHP==tab2[d].MaxHP){
                    tab2eff2[2].DEF==tab2[d].DEF;
                }
                }
            if(prochainperso(j)->MaxHP==290){
            ds17=prochainperso(j)->ch_skill2.duration;
                 if (prochainperso(j)->MaxHP==jeu.t1.p1.MaxHP){
                      prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t1.p1);
                    tab1eff2[0].DEF==prochainperso(j)->DEF;
                   jeu.t1.p1.DEF=prochainperso(j)->DEF;
               }
               if (prochainperso(j)->MaxHP==jeu.t1.p2.MaxHP){
                    prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t1.p2);
                 tab1eff2[1].DEF==prochainperso(j)->DEF;
                    jeu.t1.p2.DEF=prochainperso(j)->DEF;

               }
               if (prochainperso(j)->MaxHP==jeu.t1.p3.MaxHP){
                    prochainperso(j)->DEF=skillDEF(prochainperso(j),jeu.t1.p3);
                 tab1eff2[2].DEF==prochainperso(j)->DEF;
                    jeu.t1.p3.DEF=prochainperso(j)->DEF;
               }
               }
            if(prochainperso(j)->MaxHP==190){
                    d=verifint() -1;
                while (tab1[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
                    tab2[d].SPD=skillSPDene(prochainperso(j),tab2[d]);
              ds19=prochainperso(j)->ch_skill2.duration;
                 if (tab2[d].MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t1.p1.SPD=tab2[d].SPD;
               }
               if (tab2[d].MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.SPD=tab2[d].SPD;
               }
               if (tab2[d].MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.SPD=tab2[d].SPD;
               }
                if(tab2eff2[0].MaxHP==tab2[d].MaxHP){
                    tab2eff2[0].DEF==tab2[d].DEF;
                }
                if(tab2eff2[1].MaxHP==tab2[d].MaxHP){
                    tab2eff2[1].DEF==tab2[d].DEF;
                }
                if(tab2eff2[2].MaxHP==tab2[d].MaxHP){
                    tab2eff2[2].DEF==tab2[d].DEF;
                }
                }
            if(prochainperso(j)->MaxHP==210){
              ds18=prochainperso(j)->ch_skill2.duration;
                 if (prochainperso(j)->MaxHP==jeu.t1.p1.MaxHP){
                      prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t1.p1);
                   tab1eff2[0].RES==prochainperso(j)->RES;
                   jeu.t1.p1.RES=prochainperso(j)->RES;
               }
               if (prochainperso(j)->MaxHP==jeu.t1.p2.MaxHP){
                    prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t1.p2);
                 tab1eff2[1].RES==prochainperso(j)->RES;
                    jeu.t1.p2.RES=prochainperso(j)->RES;

               }
               if (prochainperso(j)->MaxHP==jeu.t1.p3.MaxHP){
                    prochainperso(j)->RES=skillRES(prochainperso(j),jeu.t1.p3);
                 tab1eff2[2].RES==prochainperso(j)->RES;
                    jeu.t1.p3.RES=prochainperso(j)->RES;
               }
            }
                }
        }
         if(&jeu.t1.p1 == prochainperso(&jeu)){
                j->t1.p1.ATK_bar =0;
            }
            if(&jeu.t1.p2 == prochainperso(&jeu)){
                j->t1.p2.ATK_bar =0;
            }
            if(&jeu.t1.p3 == prochainperso(&jeu)){
                j->t1.p3.ATK_bar =0;
            }
         if(&jeu.t2.p1 == prochainperso(&jeu) || &jeu.t2.p2 == prochainperso(&jeu) || &jeu.t2.p3 == prochainperso(&jeu)){
            affichage1v1(jeu);
                if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP<=tab1[2].ActHP){
                    if(tab1[0].ActHP==0){
                        if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP>=0){
                                jeu.t1.p3.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                            }
                         else{
                            jeu.t1.p2.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            }
                        }
                else{
                        jeu.t1.p1.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                }
            }
            else if(tab1[1].ActHP<=tab1[0].ActHP && tab1[1].ActHP<=tab1[2].ActHP){
            if(tab1[1].ActHP==0){
                        if(tab1[2].ActHP<=tab1[0].ActHP && tab1[2].ActHP>=0){
                                jeu.t1.p3.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                            }
                         else{
                            jeu.t1.p1.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            }
                        }
                else{
                        jeu.t1.p2.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                }
            }
            else if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP<=tab1[0].ActHP){
            if(tab1[2].ActHP==0){
                        if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP>=0){
                                jeu.t1.p1.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            }
                         else{
                            jeu.t1.p2.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            }
                        }
                else{
                        jeu.t1.p3.ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                }
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
   }}
    





int mode(){            //debut du code choisir les different mode
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
 

int main(){

    Skill S1;      // initialising special skill : Rugissement -40% DEF
    strcpy(S1.name, "Rugissement");
    S1.value = 0.6;
    S1.duration = 1;
    S1.cd = 2;

    Skill S2;      // initialising special skill : Hurlement de chasse +30% ATT de groupe
    strcpy(S2.name, "Hurlement de chasse");
    S2.value = 1.3;
    S2.duration = 1;
    S2.cd = 3;

    Character c1;         // initialising character : c1
    strcpy(c1.name, "Loup");
    c1.MaxHP = 334;
    c1.ActHP = 334;
    c1.ATK = 25;
    c1.DEF = 18;
    c1.RES = 10;
    c1.SPD = 99;
    c1.ATK_bar = 0;
    c1.ch_skill1 =S1;
    c1.ch_skill2 =S2;

    
    Skill sk1;
    strcpy(sk1.name , "coup de sabre lazer");
    sk1.value =2;
    sk1.duration =1;
    sk1.cd=5 ;
    strcpy(sk1.description, "double ses propre degat");
    
    Skill sk2;
    strcpy(sk2.name, "force");
    sk2.value=2;
    sk2.duration=2;
    sk2.cd=4;
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
    perso1.ch_skill1=sk1;
    perso1.ch_skill2=sk2;



    Skill sk3;
    strcpy(sk3.name,"soin");
    sk3.value=0.3;
    sk3.duration=100;
    sk3.cd=6;
    strcpy(sk3.description, "donne 30 pourcent des hp max");
    
    Skill sk4;
    strcpy(sk4.name, "buff");
    sk4.value=2;
    sk4.duration=1;
    sk4.cd=5;
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
    
    Skill S3;
    strcpy(S3.name, "coup de vent");
    S3.value=2;
    S3.duration=2;
    S3.cd=4;
    strcpy(S3.description, "double vitesse pendant 2 tours");
    
    Skill S4;
    strcpy(S4.name, "atterissage");
    S4.value=1.2;
    S4.duration=100000;
    S4.cd=4;
    strcpy(S4.description, "soigne 20 pourcent des PV max");
    
    Character c2;         // initialising character : c2
    strcpy(c2.name, "Griffon");
    c2.MaxHP = 300;
    c2.ActHP = 300;
    c2.ATK = 13;
    c2.DEF = 20;
    c2.RES = 12;
    c2.SPD = 90;
    c2.ATK_bar = 0;
    c2.ch_skill1 =S3;
    c2.ch_skill2 =S4;
    
    Skill S5;
    strcpy(S5.name, "coup rapide");
    S5.value=1.5;
    S5.duration=1;
    S5.cd=3;
    strcpy(S5.description, "augmente la vitesse de 50%");
    
    Skill S6;
    strcpy(S6.name, "dash");
    S6.value=10;
    S6.duration=1;
    S6.cd=6;
    strcpy(S6.description, "esquive tout pendant 1 tour");
    
    Character c3;         // initialising character : c3
    strcpy(c3.name, "hollowk");
    c3.MaxHP = 210;
    c3.ActHP = 210;
    c3.ATK = 23;
    c3.DEF = 15;
    c3.RES = 10;
    c3.SPD = 88;
    c3.ATK_bar = 0;
    c3.ch_skill1 =S5;
    c3.ch_skill2 =S6;
    
    Skill S7;
    strcpy(S7.name, "chargeur");
    S7.value=1.5;
    S7.duration=1;
    S7.cd=3;
    strcpy(S7.description, "augmente l'attaque de 50%");
    
    Skill S8;
    strcpy(S8.name, "toile élek");
    S8.value=0.5;
    S8.duration=1;
    S8.cd=5;
    strcpy(S8.description, "esquive tout pendant 1 tour");
    
    Character c4;         // initialising character : c4
    strcpy(c4.name, "Rajone");
    c4.MaxHP = 190;
    c4.ActHP = 190;
    c4.ATK = 40;
    c4.DEF = 10;
    c4.RES = 15;
    c4.SPD = 95;
    c4.ATK_bar = 0;
    c4.ch_skill1 =S7;
    c4.ch_skill2 =S8;
    
    
    Character tabC[6];
    tabC[0]=perso2;
    tabC[1]=perso1;
    tabC[2]=c1;
    tabC[3]=c2;
    tabC[4]=c3;
    tabC[5]=c4;
    



    printf("tape 2 si tu veux pas jouer\ntape 1 pour jouer\n");        //savoir si tu veux jouer ou pas
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

        break;
        case 2 :
      botmoyen(tabC);
        break;
        case 3 :
        botdifficile(tabC);
        break;
        case 4 :
       
        break;
    }
    return 0;
}
