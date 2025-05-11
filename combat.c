
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
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
               tab2[d].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
            }
            prochainperso(jeu)->ATK_bar=0;
        }
        else if(jeu.t2.p1.ActHP >= 500 || jeu.t2.p2.ActHP >= 500 || jeu.t2.p3.ActHP >= 500){
            affichage1vs1(jeu);
            a=(rand()%3)+1;
            while (tab2[a].ActHP<=0){
                    a=(rand()%3)+1;
                }
            tab1[a].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[a]);
            prochainperso(jeu)->ATK_bar=0;
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
   }}
    
    
    
    
void botmoyen(Character tabC[]){
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
    while(jeu.t1.p1.ActHP > 0 && jeu.t1.p2.ActHP > 0 && jeu.t1.p3.ActHP > 0 || jeu.t2.p1.ActHP > 0 && jeu.t2.p2.ActHP > 0 && jeu.t2.p3.ActHP > 0){
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
               if (tab2[d].MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.ActHP=tab2[d].ActHP;
               }
               if (tab2[d].MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.ActHP=tab2[d].ActHP;

               }
               if (tab2[d].MaxHP==jeu.t2.p1.MaxHP){
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
        else if(&jeu.t2.p1 == prochainperso(&jeu) || &jeu.t2.p2 == prochainperso(&jeu) || &jeu.t2.p3 == prochainperso(&jeu)){
            affichage1v1(jeu);
                if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP<=tab1[2].ActHP){
                    if(tab1[0].ActHP==0){
                        if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                                jeu.t1.p3.ActHP=tab1[2].ActHP;
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            jeu.t1.p2.ActHP=tab1[1].ActHP;
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                        jeu.t1.p1.ActHP=tab1[0].ActHP;
                }
            }
            else if(tab1[1].ActHP<=tab1[0].ActHP && tab1[1].ActHP<=tab1[2].ActHP){
            if(tab1[1].ActHP==0){
                        if(tab1[2].ActHP<=tab1[0].ActHP && tab1[2].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                                jeu.t1.p3.ActHP=tab1[2].ActHP;
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            jeu.t1.p1.ActHP=tab1[0].ActHP;
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                        jeu.t1.p2.ActHP=tab1[1].ActHP;
                }
            }
            else if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP<=tab1[0].ActHP){
            if(tab1[2].ActHP==0){
                        if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP>=0){
                                calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                                jeu.t1.p1.ActHP=tab1[0].ActHP;
                            }
                         else{
                            calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            jeu.t1.p2.ActHP=tab1[1].ActHP;
                            }
                        }
                else{
                        calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                        jeu.t1.p3.ActHP=tab1[2].ActHP;
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
                    printf("ce personnageest deja mort reessayer");
                    d=verifint() -1;
                }
               tab2[d].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab2[d]);
            }
            prochainperso(jeu)->ATK_bar=0;
        }
        else if(jeu.t2.p1.ActHP >= 500 || jeu.t2.p2.ActHP >= 500 || jeu.t2.p3.ActHP >= 500){
            prochainperso(jeu)->ch_skill1.dcd -= 1;
            prochainperso(jeu)->ch_skill2.dcd -= 1;
            if (prochainperso(jeu)->ch_skill2.dcd<0){
                prochainperso(jeu)->ch_skill2.dcd=0
            }
            if (prochainperso(jeu)->ch_skill1.dcd<0){
                prochainperso(jeu)->ch_skill1.dcd=0;
            }
            if(prochainperso(jeu)->ch_skill1.dcd != 0 && prochainperso(jeu)->ch_skill2.dcd != 0){
            affichage1vs1(jeu);
                if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP<=tab1[2].ActHP){
                    if(tab[0].ActHP==0){
                        if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP>=0){
                                tab1[2].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                            }
                         else{
                            tab1[1].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            }
                        }
                else{
                        tab1[0].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                }
            }
            else if(tab1[1].ActHP<=tab1[0].ActHP && tab1[1].ActHP<=tab1[2].ActHP){
            if(tab[1].ActHP==0){
                        if(tab1[2].ActHP<=tab1[0].ActHP && tab1[2].ActHP>=0){
                                tab1[2].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                            }
                         else{
                            tab1[0].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            }
                        }
                else{
                        tab1[1].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                }
            }
            else if(tab1[2].ActHP<=tab1[1].ActHP && tab1[2].ActHP<=tab1[0].ActHP){
            if(tab[2].ActHP==0){
                        if(tab1[0].ActHP<=tab1[1].ActHP && tab1[0].ActHP>=0){
                                tab1[0].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[0]);
                            }
                         else{
                            tab1[1].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[1]);
                            }
                        }
                else{
                        tab1[2].ActHP=calcul_des_dégats_pris(prochainperso(&jeu),tab1[2]);
                }
            }
            }
            else if(prochainperso(jeu)->ch_skill1.dcd == 0){
                // fonction skill1 du perso
              if(prochainperso(j)->MaxHP==230||prochainperso(j)->MaxHP==330){
                    a=(rand()%3);
                while (tab2[a].ActHP<=0){
                    a=(rand()%3);
                }
                    tab2[a].ATK=skillATK(cprochainperso(jeu),tab2[a]);
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
                if(prochainperso(j)->MaxHP==290||prochainperso(j)->MaxHP==190){
                    prochainperso(j)->ATK=skillATK(cprochainperso(j),prochainperso(j)); 
                    if (prochainperso(j)->MaxHP==jeu.t2.p1.MaxHP){
                       jeu.t2.p1.ATK=prochainperso(j)->ATK;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t2.p2.MaxHP){
                        jeu.t2.p2.ATK=prochainperso(j)->ATK;
    
                   }
                   if (prochainperso(j)->MaxHP==jeu.t2.p3.MaxHP){
                        jeu.t2.p3.ATK=prochainperso(j)->ATK;
                   }
            }
            if(prochainperso(j)->MaxHP==210||prochainperso(j)->MaxHP==300){
                prochainperso(j)->SPD=skillSPD(cprochainperso(j),prochainperso(j)); 
                    if (prochainperso(j)->MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t2.p2.MaxHP){
                        jeu.t2.p2.SPD=prochainperso(j)->SPD;
                   }
                   if (prochainperso(j)->MaxHP==jeu.t2.p3.MaxHP){
                        jeu.t2.p3.SPD=prochainperso(j)->SPD;
                   }
            } 
            }
            }
            else if(prochainperso(jeu)->ch_skill2.dcd == 0){
             if(prochainperso(j)->MaxHP==230||prochainperso(j)->MaxHP==300){
                  a=(rand()%3);
                while (tab2[a].ActHP<=0){
                    a=(rand()%3);
                }
                    tab2[a].ActHP=skillHEAL(prochainperso(jeu),tab2[a]);
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
                while (tab2[a].ActHP<=0){
                    a=(rand()%3);
                }
                    tab1[a].DEF=skillDEFene(cprochainperso(jeu),tab1[a]);
                 if (tab1[a].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.DEF=tab1[a].DEF;
               }
               if (tab1[a].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.DEF=tab1[a].DEF;

               }
               if (tab1[a].MaxHP==jeu.t1.p3.MaxHP){
                    jeu.t1.p3.DEF=tab1[a].DEF;
               }
               }
            if(prochainperso(j)->MaxHP==290){
                    prochainperso(j)->DEF=skillDEF(cprochainperso(jeu),prochainperso(j));
                 if (prochainperso(j)->MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.DEF=prochainperso(j)->DEF;
               }
               if (prochainperso(j)->MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.DEF=prochainperso(j)->DEF;

               }
               if (prochainperso(j)->MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.DEF=prochainperso(j)->DEF;
               }
               }
            if(prochainperso(j)->MaxHP==190){
                    a=(rand()%3);
                while (tab2[a].ActHP<=0){
                    a=(rand()%3);
                }
                    tab1[a].SPD=skillSPDene(cprochainperso(jeu),tab1[a]);
                 if (tab1[a].MaxHP==jeu.t1.p1.MaxHP){
                   jeu.t1.p1.SPD=tab1[a].SPD;
               }
               if (tab1[a].MaxHP==jeu.t1.p2.MaxHP){
                    jeu.t1.p2.SPD=tab1[a].SPD;
               }
               if (tab1[a].MaxHP==jeu.t1.p3.MaxHP){
                    jeu.t1.p3.SPD=tab1[a].SPD;
               }
               }
            if(prochainperso(j)->MaxHP==210){
                    prochainperso(j)->RES=skillRES(cprochainperso(j),prochainperso(j));
                 if (prochainperso(j)->MaxHP==jeu.t2.p1.MaxHP){
                   jeu.t2.p1.RES=prochainperso(j)->RES;
               }
               if (prochainperso(j)->MaxHP==jeu.t2.p2.MaxHP){
                    jeu.t2.p2.RES=prochainperso(j)->RES;

               }
               if (prochainperso(j)->MaxHP==jeu.t2.p3.MaxHP){
                    jeu.t2.p3.RES=prochainperso(j)->RES;
               }
               }
            }
            prochainperso(jeu)->ATK_bar=0;
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
