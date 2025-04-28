typedef struct {
    Team t1;
    Team t2;
} Jeu


 
 void affichenom(Team t1){
     printf("%s",t1.p1.name[])
     printf("%s",t1.p2.name[])
     printf("%s",t1.p3.name[])
     // faut la faire j'ai pas eu le temps entre les print faut mettre les bon nombre d'espaces 
 }
 
 void hpsp(Character p1,Character p2, Character p3 ){
     printf("| [ ");
    for(int i=0; i<(p1.ActHp) ;i=i+25){
    printf("#");
    }
    for(int i=p1.ActHp ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p2.ActHp) ;i=i+25){
    printf("#");
    }
    for(int i=p2.ActHp ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p3.ActHp) ;i=i+25){
    printf("#");
    }
    for(int i=p3.ActHp ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("] |");

    printf("\n");
    printf("| [ ");
    for(int i=0; i<(p1.Atk_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p1.Atk_bar ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p2.Atk_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p2.Atk_bar  ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p3.Atk_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p3.Atk_bar  ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("] |");
 }
 
 void affichageteam(Team t1){
     printf("┌──[%s]",t1.name[]);// il faut faire les 2 team
     for(int i=strlen(t1.name);i<94-;i++){
         printf("─");
     }
     printf("┐")
     printf("\n| ")
     affichenom()
     hpsp(t1.p1,t1.p2,t1.p3);
 }
