typedef struct {
    Team t1;
    Team t2;
} Jeu


 
 void affichenom(Team t1){
     printf("|  ");
     printf("%s",t1.p1.name);
     if(t1.p1.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |1|");
     }
     for(int i=strlen(t1.p1.name) ;i<36 ;i++){
        printf(" ");
    }
     printf("%s",t1.p2.name);
     if(t1.p2.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |2|");
     }
     for(int i=strlen(t1.p2.name) ;i<36 ;i++){
        printf(" ");
    }
     printf("%s",t1.p3.name);
     if(t1.p3.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |3|");
     }
    for(int i=strlen(t1.p3.name) ;i<25 ;i++){
        printf(" ");
    }
     printf("|")
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
 
 void afficheeffet(){
     // il faut le faire
 }

  
 void afficheperso(character p1){
     printf("|   %s",p1.name);
     for(int i=strlen(p1.name);i<95-;i++){
         printf(" ");
     }
     printf("|\n");
     printf("|   TECHNIQUES SPECIALES");
     for(int i=0;i<75-;i++){
         printf(" ");
     }
     printf("|\n");
     printf("|      |1| attaque normal(peut etre utiliser a chaque tour)                                            |");
     if (p1.ch_skill1.cd == 0){
         printf("|      |2|");
         printf(" %s (duree:%d tours)",p1.ch_skill1.name ,p1.ch_skill1.duration);
         for(int i=strlen(p1.ch_skill1.name);i<73;i++){
         printf(" ");
        }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %d duree:%d tours)",p1.ch_skill2.name,p1.ch_skill2.cd ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill1.name);i<61;i++){
         printf(" ");
        }
        printf("|\n");
     }
     printf("|            %s",p1.ch_skill1.description);
     for(int i=strlen(p1.ch_skill1.description);i<87;i++){
         printf(" ");
    }
     printf("|\n");
     
          if (p1.ch_skill2.cd == 0){
         printf("|      |3|");
         printf(" %s (duree:%d tours)",p1.ch_skill2.name ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<73;i++){
         printf(" ");
        }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %d duree:%d tours)",p1.ch_skill2.name,p1.ch_skill2.cd ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<61;i++){
             printf(" ");
        }
        printf("|\n");
     }
      printf("|            %s",p1.ch_skill1.description);
     for(int i=strlen(p1.ch_skill1.description);i<87;i++){
         printf(" ");
    }
     printf("|\n");
     
 }

 
 void affichageteam(Team t1){
     printf("┌──[%s]",t1.name);// il faut faire les 2 team
     for(int i=strlen(t1.name);i<94-;i++){
         printf("─");
     }
     printf("┐");
     printf("\n| ");
     affichenom(t1);
     afficheeffet();
     hpsp(t1.p1,t1.p2,t1.p3);
     printf("\n|");
     for (int i=0;i<98;i++){
         printf(" ");
     }
     printf("|");
 }
 void affichagefin(){
     printf("\n|");
     for (int i=0;i<98;i++){
         printf(" ");
     }
     printf("|\n");
     printf("└");
     for (int i=0;i<98;i++){
         printf("─");
     }
 }
 
void affichage1v1(jeu j){ // fonction prochainperso a code il faut qu'elle renvoie le perso qui attaque   
     if(j.t1.p1 == prochainperso()){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99-;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99-;i++){
             printf(" ");
         }
         afficheperso(j.t1.p1);
         affichagefin();
         
         
     }
     else if(j.t1.p2 == prochainperso()){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
        affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99-;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99-;i++){
             printf(" ");
         }
         afficheperso(j.t1.p2);
         affichagefin();
         
         
     }
     else if(j.t1.p3 == prochainperso()){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99-;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99-;i++){
             printf(" ");
         }
         afficheperso(j.t1.p3);
         affichagefin();
         
         
     }
     else if(j.t2.p1 == prochainperso()){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99-;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99-;i++){
             printf(" ");
         }
         afficheperso(j.t2.p1);
         affichagefin();
         
         
     }
     else if(j.t2.p2 == prochainperso()){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99-;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99-;i++){
             printf(" ");
         }
         afficheperso(j.t2.p2);
         affichagefin();
         
     }
     else if(j.t2.p3 == prochainperso()){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<99-;i++){
             printf("─");
         }
         printf("┐");
         printf("\n| ");
         for(int i=0;i<99-;i++){
             printf(" ");
         }
         afficheperso(j.t2.p3);
         affichagefin();
         
     }
    
}


