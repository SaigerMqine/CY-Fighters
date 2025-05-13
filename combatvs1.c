#include <stdio.h>
void vs1(Character tabC[],Jeu* j){            //combat joueur contre joueur
Jeu jeu;
    int n=0;
    int d=0;
    int ds1=10000;
    int ds2=10000;
    int ds3=10000;
    int ds4=0;
    int ds5=0;
    int ds6=0;
    int ds7=0;
    int ds8=0;
    int ds9=0;
    int ds10=0;
    int ds11=0;
    int ds12=0;
    Character tab1[3];
    Character tab2[3];
    Character tab3[3];
    Character tab4[3];
    Character tab1eff2[3];
    Character tab2eff2[3];
    jeu.t1 = MakeTeam(tabC)
    jeu.t2 = MakeTeambot(tabC);
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
                    ds4==prochainperso(j)->ch_skill1.duration;
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
                    ds5==prochainperso(j)->ch_skill1.duration;
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
                    ds1==prochainperso(j)->ch_skill1.duration;
                    if(tab1eff2[0].MaxHP==prochainperso(j)->MaxHP){
                        prochainperso(j)->ATK=skillATK(prochainperso(j),jeu.t1.p1);
                          tab1eff2[0].ATK==prochainperso(j)->ATK;
                      jeu.1.p1.ATK=prochainperso(j)->ATK;
                  
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
                    ds3==prochainperso(j)->ch_skill1.duration;
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
                    ds2==prochainperso(j)->ch_skill1.duration;
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
                    ds6==prochainperso(j)->ch_skill1.duration;
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
              ds10==prochainperso(j)->ch_skill2.duration;
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
            ds7==prochainperso(j)->ch_skill2.duration;
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
              ds9==prochainperso(j)->ch_skill2.duration;
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
              ds8==prochainperso(j)->ch_skill2.duration;
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
            if(&jeu.t1.p1 == prochainperso(&jeu)){            //remise a 0 de atk bar
                jeu.t1.p1.ATK_bar =0;
            }
            if(&jeu.t1.p2 == prochainperso(&jeu)){
                jeu.t1.p2.ATK_bar =0;
            }
            if(&jeu.t1.p3 == prochainperso(&jeu)){
                jeu.t1.p3.ATK_bar =0;
            }
                else {
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
                    j->t1.p1.DEF=tab1eff3[0].DEF;
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
            }//2eme joueur avec le meme fonctionnement
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




