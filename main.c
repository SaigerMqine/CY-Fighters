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
void ordifacile(){           //fonction pour jouer contre l'ordi mais c'est le debut et il faut mettre les bons perso dans le tableau 
    character tabcharacter[6] 
    float tab[6]
    choixordiequipe()
    while(p1.ActHP != 0 && p2.ActHP != 0 && p3.ActHP != 0 ){
        for (int i=0 i<6 i++){
            tab[i]+= tabcharacter[i].SPD
            if (tab[i] >= 100){       // 100 c'est une valeur temporaire  
                if (i<3){
                AffichageDuPerso()   // dans l'affichage on mais aussi les verifint
                }
                else{
                    // ici on met quand l'ordi attaque 
                }
            }      
        }
    }
}       // je vous laisse l'ameliorer normalement le debut sera toujours pareil pour chaque ordi et pour le 1 contre 1 il faudra juste changer ChoixOrdiEquipe aussi j ai mis des fonction mais je sais pas quelle nom vous voulez mettre 

int main(){

    Skill Rugissement;      // initialising special skill : Rugissement -40% DEF
    strcpy(Rugissement.name, "Rugissement");
    Rugissement.value = 0.6;
    Rugissement.duration = 1;
    Rugissement.cd = 2;

    Skill Hurlement_de_chasse;      // initialising special skill : Hurlement de chasse +30% ATT de groupe
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

