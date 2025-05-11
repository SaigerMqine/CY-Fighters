#include <stdio.h>
void vs1(Character tabC[],Jeu* j){            //combat joueur contre joueur
int n=0;            //quelle attaque choisir
int d=0;            //quel perso cibler
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
    while(jeu.t1.p1.ActHP > 0 && jeu.t1.p2.ActHP > 0 && jeu.t1.p3.ActHP > 0 || jeu.t2.p1.ActHP > 0 && jeu.t2.p2.ActHP > 0 && jeu.t2.p3.ActHP > 0){            //condition d'arret du jeu 
        jeu.t1.p1.ATK_bar=jeu.t1.p1.ATK_bar+jeu.t1.p1.SPD;
        jeu.t1.p2.ATK_bar=jeu.t1.p2.ATK_bar+jeu.t1.p2.SPD;
        jeu.t1.p3.ATK_bar=jeu.t1.p3.ATK_bar+jeu.t1.p3.SPD;
        jeu.t2.p1.ATK_bar=jeu.t2.p1.ATK_bar+jeu.t2.p1.SPD;
        jeu.t2.p2.ATK_bar=jeu.t2.p2.ATK_bar+jeu.t2.p2.SPD;
        jeu.t2.p3.ATK_bar=jeu.t2.p3.ATK_bar+jeu.t2.p3.SPD;
        if(jeu.t1.p1.ATK_bar > 500 || jeu.t1.p2.ATK_bar > 500 || jeu.t1.p3.ATK_bar > 500 || jeu.t2.p1.ATK_bar > 500 || jeu.t2.p2.ATK_bar > 500 || jeu.t2.p3.ATK_bar > 500){
                if (&jeu.t1.p1== prochainperso(%j) || if &jeu.t1.p2== prochainperso(%j) || if &jeu.t1.p3== prochainperso(%j)){
                affichage1v1(jeu);
            printf("\n quelle capacité voulez vous utiliser");
            n=verifint();
                    while(n=!1||n=!2||n=!3){            //verifier n
                        n=verifint();
                    }
            if(n==1){            //attaque normale
                printf("\n quelle personnage voulez vous cibler");
                d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
               tab2[d].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
               if (tab2[d].MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.ActHP=tab2[d].ActHP;
               }
               if (tab2[d].MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.ActHP=tab2[d].ActHP;

               }
               if (tab2[d].MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.ActHP=tab2[d].ActHP;

               }
            }
                    else if(n==2){         //attaque skill 1
                    
                }
                else if(n==3){            //attaque skill 2
                    
                    }
            }
            if(&jeu.t1.p1 == prochainperso(&jeu)){            //remise a 0 de atk bar
                jeu.t1.p1.ATK_bar =0;
            }
            if(&jeu.t1.p2 == prochainperso(&jeu)){
                jeu.t1.p2.ATK_bar =0;
            }
            if(&jeu.t1.p3 == prochainperso(&jeu)){
                jeu.t1.p3.ATK_bar =0;
            }
                else {            //2eme joueur avec le meme fonctionnement
                affichage1v1(jeu);
            printf("\n quelle capacité voulez vous utiliser");
            n=verifint();
                    while(n=!1||n=!2||n=!3){          
                        n=verifint();
                    }
            if(n==1){
                printf("\n quelle personnage voulez vous cibler");
                d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
               tab1[d].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[d]);
               if (tab1[d].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.ActHP=tab1[d].ActHP;
               }
               if (tab1[d].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.ActHP=tab1[d].ActHP;

               }
               if (tab1[d].MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.ActHP=tab1[d].ActHP;

               }
            }
                    else if(n==2){
                    
                }
                else if(n==3){
                    
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
            
           
           if(jeu.t1.p1.ActHP <= 0){            //quand le perso est mort
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




