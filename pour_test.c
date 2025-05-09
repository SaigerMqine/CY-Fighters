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
     for(int i=strlen(t1.p1.name) ;i<36 ;i++){
        printf(" ");
    }
     printf("%s",t1.p2.name);
     if(t1.p2.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |2|");
     }
     for(int i=strlen(t1.p2.name) ;i<36 ;i++){
        printf(" ");
    }
     printf("%s",t1.p3.name);
     if(t1.p3.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |3|");
     }
    for(int i=strlen(t1.p3.name) ;i<25 ;i++){
        printf(" ");
    }
     printf("|");
     // faut la faire j'ai pas eu le temps entre les print faut mettre les bon nombre d'espaces 
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
 
 void affiche_effet(){
     // il faut le faire
 }

  
 void afficheperso(Character p1){
     printf("|   %s",p1.name);
     for(int i=strlen(p1.name);i<95;i++){
         printf(" ");
     }
     printf("|\n");
     printf("|   TECHNIQUES SPECIALES");
     for(int i=0;i<75;i++){
         printf(" ");
     }
     printf("|\n");
     printf("|      |1| attaque normal(peut etre utiliser a chaque tour)                                            |");
     if (p1.ch_skill1.cd == 0){
         printf("|      |2|");
         printf(" %s (duree:%f tours)",p1.ch_skill1.name ,p1.ch_skill1.duration);
         for(int i=strlen(p1.ch_skill1.name);i<73;i++){
         printf(" ");
        }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %f duree:%f tours)",p1.ch_skill2.name,p1.ch_skill2.cd ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill1.name);i<61;i++){
         printf(" ");
        }
        printf("|\n");
     }
     printf("|            %s",p1.ch_skill1.description);
     for(int i=strlen(p1.ch_skill1.description);i<87;i++){
         printf(" ");
    }
     printf("|\n");
     
          if (p1.ch_skill2.cd == 0){
         printf("|      |3|");
         printf(" %s (duree:%f tours)",p1.ch_skill2.name ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<73;i++){
         printf(" ");
        }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %f duree:%f tours)",p1.ch_skill2.name,p1.ch_skill2.cd ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<61;i++){
             printf(" ");
        }
        printf("|\n");
     }
      printf("|            %s",p1.ch_skill1.description);
     for(int i=strlen(p1.ch_skill1.description);i<87;i++){
         printf(" ");
    }
     printf("|\n");
     
 }

 
 void affichageteam(Team t1){
     printf("┌──[%s]",t1.name);// il faut faire les 2 team
     for(int i=strlen(t1.name);i<94;i++){
         printf("─");
     }
     printf("┐");
     printf("\n| ");
     affichenom(t1);
     affiche_effet();
     hpsp(t1.p1,t1.p2,t1.p3);
     printf("\n|");
     for (int i=0;i<98;i++){
         printf(" ");
     }
     printf("|");
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
     if(j.t1.p1 == prochainperso(j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99;i++){
             printf(" ");
         }
         afficheperso(j.t1.p1);
         affichagefin();
         
         
     }
     else if(j.t1.p2 == prochainperso(j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
        affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99;i++){
             printf(" ");
         }
         afficheperso(j.t1.p2);
         affichagefin();
         
         
     }
     else if(j.t1.p3 == prochainperso(j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99;i++){
             printf(" ");
         }
         afficheperso(j.t1.p3);
         affichagefin();
         
         
     }
     else if(j.t2.p1 == prochainperso(j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99;i++){
             printf(" ");
         }
         afficheperso(j.t2.p1);
         affichagefin();
         
         
     }
     else if(j.t2.p2 == prochainperso(j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99;i++){
             printf(" ");
         }
         afficheperso(j.t2.p2);
         affichagefin();
         
     }
     else if(j.t2.p3 == prochainperso(j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99;i++){
             printf(" ");
         }
         afficheperso(j.t2.p3);
         affichagefin();
         
     }
    
}



float dégats_pris(Character p1,Character p2){ //p1=perso attaqué, p2=perso qui attaque
    int i=0;
    i=(rand()%100)+1;
    if(i<=p1.RES){
        return p1.actHP;
    }
    else{
        p1.actHP=p1.actHP-p2.ATK*(1-(p1.DEF/100));
        return p1.actHP;
    }
}

void ordifacile(){           //fonction pour jouer contre l'ordi mais c'est le debut et il faut mettre les bons perso dans le tableau 
    MakeTeam(tabC);
    MakeTeambot(tabC);
    while(Team1.p1.ActHP > 0 && Team1.p2.ActHP > 0 && Team1.p3.ActHP > 0 || Team2.p1.ActHP > 0 && Team2.p2.ActHP > 0 && Team2.p3.ActHP > 0){
        Team1.p1.ATK_bar=Team1.p1.ATK_bar+Team1.p1.SPD;
        Team1.p2.ATK_bar=Team1.p2.ATK_bar+Team1.p2.SPD;
        Team1.p3.ATK_bar=Team1.p3.ATK_bar+Team1.p3.SPD;
        Team2.p1.ATK_bar=Team2.p1.ATK_bar+Team2.p1.SPD;
        Team2.p2.ATK_bar=Team2.p2.ATK_bar+Team2.p2.SPD;
        Team2.p3.ATK_bar=Team2.p3.ATK_bar+Team2.p3.SPD;
                if (Team1.p1.ATK_bar >=500 ||   Team1.p2.ATK_bar >= 500 || Team1.p3.ATK_bar >= 500 || Team2.p1.ATK_bar >= 500 || Team2.p2.ATK_bar >= 500 || Team2.p3.ATK_bar >= 500){
                
                    
                    affichage1v1(j);  // dans l'affichage on met aussi les verifint pour choix de l'atk
                
                }
            }      
        }
// je vous laisse l'ameliorer normalement le debut sera toujours pareil pour chaque ordi et pour le 1 contre 1 il faudra juste changer ChoixOrdiEquipe aussi j ai mis des fonction mais je sais pas quelle nom vous voulez mettre 

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
    c1.SPD = 107;
    c1.ATK_bar = 0;
    c1.ch_skill1 = S1;
    c1.ch_skill2 = S2;

    
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
    perso1.ch_skill1= sk1;
    perso1.ch_skill2= sk2;



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
    switch(mode()){ // je sais pas si c'est bon ou pas comme on a pas les fonctions mais je le met quand meme 
        case 1:
        ordifacile();
        break;
        case 2 :
        ordimoyen();
        break;
        case 3 :
        ordidifficile();
        break;
        case 4 :
        1vs1();
        break;
    }
    return 0;
}
