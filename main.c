#include <stdio.h>
#include <string.h>

int mode(){
    //  n=1 facile n=2 difficile n=3 infernal n=4 1v1
    int d=0;
    int n = 0;
    printf("tape 1 pour jouer contre l'ordinateur \ntape 2 pour jouer contre un ami\n");
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
    c1.ch_skill1 = Rugissement;
    c1.ch_skill2 = Hurlement_de_chasse;

    
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
    perso1.SPD=80
    perso1.ATK_bar=0;
    perso1.ch_skill1= coup_de_sabre_lazer;
    perso1.ch_skill2=force;



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
    perso2.ch_skill1= soin;
    perso2.ch_skill2= buff;


    Skill sk5;
    strcpy(sk5.name,"chargeur");
    sk5.value=1.5;
    sk5.duration=1;
    sk5.cd=3;
    strcpy(sk5.description, "augmente l'attaque de 50% au prochain tour");
    
    Skill sk6;
    strcpy(sk6.name, "toile éleck");
    sk6.value=0.5;
    sk6.duration=1;
    sk6.cd=5;
    strcpy(sk6.description, "vitesse de l'ennemie est divisé par 2 au prochain tour");


    Character ch1;
    strcpy(ch1.name , "rajone");
    ch1.MaxHP= 190;
    ch1.ActHP=190;
    ch1.ATK=40;
    ch1.DEF=10;
    ch1.RES=15;
    ch1.SPD=100;
    ch1.ATK_bar=0;
    ch1.ch_skill1= sk5;
    ch1.ch_skill2=sk6;


    Skill sk7;
    strcpy(sk7.name,"coup_rapide");
    sk7.value=1.5;
    sk7.duration=1;
    sk7.cd=3;
    strcpy(sk7.description, "augmente la vitesse de 50% au prochain tour");
    
    Skill sk8;
    strcpy(sk8.name, "dash");
    sk8.value=10;
    sk8.duration=1;
    sk8.cd=6;
    strcpy(sk8.description, "esquive tout les attaques pendant un tour");


    Character ch2;
    strcpy(ch2.name , "hollowk");
    ch2.MaxHP= 210;
    ch2.ActHP=210;
    ch2.ATK=23;
    ch2.DEF=15;
    ch2.RES=10;
    ch2.SPD=88;
    ch2.ATK_bar=0;
    ch2.ch_skill1= sk7;
    ch2.ch_skill2=sk8;



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
        ordifacile()
        break;
        case 2 :
        ordimoyen()
        break;
        case 3 :
        ordidifficile()
        break;
        case 4 :
        1vs1()
        break;
    }
    return 0;

