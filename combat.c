
void botfacile(){
    Jeu jeu;
    int a=10
    int n=0;
    int d=0;
    Character tab1[3];
    Character tab2[3];
    jeu.t1 = MakeTeam(tabC)
    jeu.t2 = MakeTeambot(tabC);
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
        if(jeu.t1.p1.ActHP >= 500 || jeu.t1.p2.ActHP >= 500 || jeu.t1.p3.ActHP >= 500){
            affichage1vs1(jeu);
            printf("quelle capacité voulez vous utiliser");
            n=verifint();
            if(n==1){
                printf("quelle personnage voulez vous cibler");
                d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer")
                    d=verifint() -1;
                }
               calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
            }
        }
        else if(jeu.t2.p1.ActHP >= 500 || jeu.t2.p2.ActHP >= 500 || jeu.t2.p3.ActHP >= 500){
            affichage1vs1(jeu);
            a=(rand()%3)+1;
            while (tab2[a].ActHP<=0){
                    a=(rand()%3)+1;
                }
            calcul_des_dégats_pris(prochainperso(&jeu),tab[a]);
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
    
    
    
    
void botmoyen(){
    Jeu jeu;
    int n=0;
    int d=0;
    Character tab1[3];
    Character tab2[3];
    jeu.t1 = MakeTeam(tabC);
    jeu.t2 = MakeTeambot(tabC);
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
        if(jeu.t1.p1.ActHP >= 500 || jeu.t1.p2.ActHP >= 500 || jeu.t1.p3.ActHP >= 500){
            affichage1vs1(jeu);
            printf("quelle capacité voulez vous utiliser");
            n=verifint();
            if(n==1){
                printf("quelle personnage voulez vous cibler");
                d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer")
                    d=verifint() -1;
                }
               calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
            }
        }
        else if(jeu.t2.p1.ActHP >= 500 || jeu.t2.p2.ActHP >= 500 || jeu.t2.p3.ActHP >= 500){
            affichage1vs1(jeu);
            if(tab[0].ActHP>=tab[1].ActHP&&tab[0].ActHP>=tab[2].ActHP){
            calcul_des_dégats_pris(prochainperso(&jeu),tab[0]);
            }
            else if(tab[1].ActHP>=tab[0].ActHP&&tab[1].ActHP>=tab[2].ActHP){
            calcul_des_dégats_pris(prochainperso(&jeu),tab[1]);
            }
            else if(tab[2].ActHP>=tab[1].ActHP&&tab[2].ActHP>=tab[0].ActHP){
            calcul_des_dégats_pris(prochainperso(&jeu),tab[2]);
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
       
void botdifficile(){
    Jeu jeu;
    int n=0;
    int d=0;
    Character tab1[3];
    Character tab2[3];
    jeu.t1 = MakeTeam(tabC)
    jeu.t2 = MakeTeambot(tabC);
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
        if(jeu.t1.p1.ActHP >= 500 || jeu.t1.p2.ActHP >= 500 || jeu.t1.p3.ActHP >= 500){
            affichage1vs1(jeu);
            printf("quelle capacité voulez vous utiliser");
            n=verifint();
            if(n==1){
                printf("quelle personnage voulez vous cibler");
                d=verifint() -1;
                while (tab2[d].ActHP<=0){
                    printf("ce personnageest deja mort reessayer")
                    d=verifint() -1;
                }
               calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
            }
        }
        else if(jeu.t2.p1.ActHP >= 500 || jeu.t2.p2.ActHP >= 500 || jeu.t2.p3.ActHP >= 500){
            prochainperso(jeu)->ch_skill1.dcd -= 1;
            prochainperso(jeu)->ch_skill2.dcd -= 1;
            if (prochainperso(jeu)->ch_skill2.dcd<0){
                prochainperso(jeu)->ch_skill2.dcd=0
            }
            if (prochainperso(jeu)->ch_skill1.dcd<0){
                prochainperso(jeu)->ch_skill1.dcd=0
            }
            if(prochainperso(jeu)->ch_skill1.dcd != 0 && prochainperso(jeu)->ch_skill2.dcd != 0){
            affichage1vs1(jeu);
            if(tab[0].ActHP<=tab[1].ActHP&&tab[0].ActHP<=tab[2].ActHP){
            calcul_des_dégats_pris(prochainperso(&jeu),tab[0]);
            }
            else if(tab[1].ActHP<=tab[0].ActHP&&tab[1].ActHP<=tab[2].ActHP){
            calcul_des_dégats_pris(prochainperso(&jeu),tab[1]);
            }
            else if(tab[2].ActHP<=tab[1].ActHP&&tab[2].ActHP<=tab[0].ActHP){
            calcul_des_dégats_pris(prochainperso(&jeu),tab[2]);
            }
            }
            else if(prochainperso(jeu)->ch_skill1.dcd == 0){
                // fonction skill1 du perso
                
                prochainperso(jeu)->ch_skill1.dcd ==prochainperso(jeu)->ch_skill1.cd ;
            }
            else if(prochainperso(jeu)->ch_skill2.dcd == 0){
                // fonction skill2 du perso
                
                prochainperso(jeu)->ch_skill2.dcd ==prochainperso(jeu)->ch_skill2.cd ; 
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
