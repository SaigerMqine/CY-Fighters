#include <stdio.h>
void vs1(){
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
        j.t1.p1.ATK_bar=j.t1.p1.ATK_bar+j.t1.p1.SPD;
        j.t1.p2.ATK_bar=j.t1.p2.ATK_bar+j.t1.p2.SPD;
        j.t1.p3.ATK_bar=j.t1.p3.ATK_bar+j.t1.p3.SPD;
        j.t2.p1.ATK_bar=j.t2.p1.ATK_bar+j.t2.p1.SPD;
        j.t2.p2.ATK_bar=j.t2.p2.ATK_bar+j.t2.p2.SPD;
        j.t2.p3.ATK_bar=j.t2.p3.ATK_bar+j.t2.p3.SPD;
        if(jeu.t1.p1.ATK_bar > 500 || jeu.t1.p2.ATK_bar > 500 || jeu.t1.p3.ATK_bar > 500 || jeu.t2.p1.ATK_bar > 500 || jeu.t2.p2.ATK_bar > 500 || jeu.t2.p3.ATK_bar > 500){
            affichage1vs1();
            printf("quelle capacité voulez vous utiliser");
            n=verifint()
            if(n==1){
                if (&jeu.t1.p1== prochainperso(%j) || if &jeu.t1.p2== prochainperso(%j) || if &jeu.t1.p3== prochainperso(%j)){
                printf("quelle personnage voulez vous cibler");
                d=verifint-1
                    while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer")
                    d=verifint() -1;
                }
                tab2[d].ActHP=calcul_des_dégats_pris(prochainperso(&j),tab2[d]);
                }
                else {
                    printf("quelle personnage voulez vous cibler");
                    d=verifint();
                    while (tab1[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer")
                    d=verifint() -1;
                }
                    tab1[d].ActHP=calcul_des_dégats_pris(prochainperso(&j),tab1[d]);
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





void vs1(Character tabC[],Jeu* j){
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
    while(jeu.t1.p1.ActHP > 0 && jeu.t1.p2.ActHP > 0 && jeu.t1.p3.ActHP > 0 || jeu.t2.p1.ActHP > 0 && jeu.t2.p2.ActHP > 0 && jeu.t2.p3.ActHP > 0){
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
