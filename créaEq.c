typedef struct{     // create class special skills
    char name[50];
    float value;
    float duration;
    float cd;
}Skill;

typedef struct{     // create class characters 
    float MaxHP;
    float ActHP;
    float ATK;
    float DEF;
    float RES;
    float SPD;
    Skill ch_skill1;
    Skill ch_skill2;
}Character;

typedef struct{     // create class special skills
    char name[50];
    Character p1;
    Character p2;
    Character p3;
}Team;


Team MakeTeam(les characters){
int n;
int a;
int b;
printf("Personnage : Loup\n");
 printf("HP : %f\nATK : %f\nDEF : %f\nRES : %f\nSPD : %f\nskill 1 : %s\nskill 2 : %s\n", Loup.MaxHP, Loup.ATK, Loup.DEF, Loup.RES, Loup.SPD, Loup.ch_skill1.name, Loup.ch_skill2.name);
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
