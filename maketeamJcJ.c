Character characters[6];
Team MakeTeam(les characters){
    int n;
    int a;
    int b;
    printf("choisissez un perso parmi ci-dessus en taper 1,2,3,4,5,6 respectivement");
    n=verifint();
    if(n==1){
        Team.p1 = c1
        a=1;  
    }
    if(n==2){
        Team.p1 = c2
        a=2;   
    }
    if(n==3){
        Team.p1 = c3
        a=3;    
    }
    if(n==4){
        Team.p1 = c4
        a=4;   
    }
    if(n==5){
        Team.p1 = c5
        a=5;    
    }
    if(n==6){
        Team.p1 = c6
        a=6;   
    }
    printf("choisissez un perso parmi ci-dessus en taper 1,2,3,4,5,6 respectivement");
    n=verifint();
    while (n==a){
        printf("choisissez un perso parmi ci-dessus en taper 1,2,3,4,5,6 respectivement");
        n=verifint();    
    }
    if(n==1){
        Team.p2 = c1
        b=1;    
    }
    if(n==2){
        Team.p2 = c2
        b=2;    
    }
    if(n==3){
        Team.p2 = c3
        b=3;    
    }
    if(n==4){
        Team.p2 = c4
        b=4;    
    }
    if(n==5){
        Team.p2 = c5
        b=5;    
    }
    if(n==6){
        Team.p2 = c6
        b=6;    
    }
    printf("choisissez un perso parmi ci-dessus en taper 1,2,3,4,5,6 respectivement");
    n=verifint();
    while (n==a || n==b){
        printf("choisissez un perso parmi ci-dessus en taper 1,2,3,4,5,6 respectivement");
        n=verifint();   
    }
    if(n==1){
        Team.p3 = c1
    }
    if(n==2){
        Team.p3 = c2  
    }
    if(n==3){
        Team.p3 = c3    
    }
    if(n==4){
        Team.p3 = c4    
    }
    if(n==5){
        Team.p3 = c5
    }
    if(n==6){
        Team.p3 = c6
    }
    return Team;
}
Team MakeTeam(Character characters[], int nb) {
    int n;
    int a;
    int b;
    n=(rand()%6)+1;
    if(n==1){
        Team.p1 = c1
        a=1;  
    }
    if(n==2){
        Team.p1 = c2
        a=2;   
    }
    if(n==3){
        Team.p1 = c3
        a=3;    
    }
    if(n==4){
        Team.p1 = c4
        a=4;   
    }
    if(n==5){
        Team.p1 = c5
        a=5;    
    }
    if(n==6){
        Team.p1 = c6
        a=6;   
    }
    n=(rand()%6)+1;
    while (n==a){
        n=(rand()%6)+1    
        }
        if(n==1){
            Team.p2 = c1
            b=1;    
        }
        if(n==2){
            Team.p2 = c2
            b=2;    
        }
        if(n==3){
            Team.p2 = c3
            b=3;    
        }
        if(n==4){
            Team.p2 = c4
            b=4;    
        }
        if(n==5){
            Team.p2 = c5
            b=5;    
        }
        if(n==6){
            Team.p2 = c6
            b=6;    
        }
    n=(rand()%6)+1;
    while (n==a || n==b){
        n=(rand()%6)+1;   
        }
        if(n==1){
            Team.p3 = c1
        }
        if(n==2){
            Team.p3 = c2  
        }
        if(n==3){
            Team.p3 = c3    
        }
        if(n==4){
            Team.p3 = c4    
        }
        if(n==5){
            Team.p3 = c5
        }
        if(n==6){
            Team.p3 = c6
        }
    return Team;
}
