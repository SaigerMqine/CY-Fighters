#include <stdio.h>
void 1vs1(){
int n=0;
int d=0;
Character tab1[3];
Character tab2[3];
    MakeTeambot(Character characters[]);
    Makejeu(Team t1, Team t2);
    tab1[0]=jeu.t1.p1;
    tab1[1]=jeu.t1.p2;
    tab1[2]=jeu.t1.p3;
    tab2[0]=jeu.t2.p1;
    tab2[1]=jeu.t2.p2;
    tab2[2]=jeu.t2.p3;
    while(jeu.t1.p1.ActHP > 0 && jeu.t1.p2.ActHP > 0 && jeu.t1.p3.ActHP > 0 || jeu.t2.p1.ActHP > 0 && jeu.t2.p2.ActHP > 0 && jeu.t2.p3.ActHP > 0){
        Team1.p1.ATK_bar=Team1.p1.ATK_bar+Team1.p1.SPD;
        Team1.p2.ATK_bar=Team1.p2.ATK_bar+Team1.p2.SPD;
        Team1.p3.ATK_bar=Team1.p3.ATK_bar+Team1.p3.SPD;
        Team2.p1.ATK_bar=Team2.p1.ATK_bar+Team2.p1.SPD;
        Team2.p2.ATK_bar=Team2.p2.ATK_bar+Team2.p2.SPD;
        Team2.p3.ATK_bar=Team2.p3.ATK_bar+Team2.p3.SPD;
        if(jeu.t1.p1.ActHP > 500 || jeu.t1.p2.ActHP > 500 || jeu.t1.p3.ActHP > 500 || jeu.t2.p1.ActHP > 500 || jeu.t2.p2.ActHP > 500 || jeu.t2.p3.ActHP > 500){
            affichage1vs1();
            printf("quelle capacité voulez vous utiliser");
            n=verifint()
            if(n==1){
                printf("quelle personnage voulez vous cibler");
                d=verifint();
                calcul_des_dégats_pris(prochainperso(),tab[d])
        }
    }   
}
       
