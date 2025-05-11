
 
 void affichenom(Team t1){
     printf("|  ");
     printf("%s",t1.p1.name);
     if(t1.p1.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |1|");
     }
     for(int i=strlen(t1.p1.name) ;i<32 ;i++){
        printf(" ");
    }
     printf("%s",t1.p2.name);
     if(t1.p2.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |2|");
     }
     for(int i=strlen(t1.p2.name) ;i<32 ;i++){
        printf(" ");
    }
     printf("%s",t1.p3.name);
     if(t1.p3.ActHP<=0){
         printf(" |x|");
     }
     else{
     printf(" |3|");
     }
    for(int i=strlen(t1.p3.name) ;i<20 ;i++){
        printf(" ");
    }
     printf("|");
 }
 
 void hpsp(Character p1,Character p2, Character p3 ){
     printf("| [ ");
    for(int i=0; i<(p1.ActHP) ;i=i+25){
    printf("#");
    }
    for(int i=p1.ActHP ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p2.ActHP) ;i=i+25){
    printf("#");
    }
    for(int i=p2.ActHP ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p3.ActHP) ;i=i+25){
    printf("#");
    }
    for(int i=p3.ActHP ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("] |");

    printf("\n");
    printf("| [ ");
    for(int i=0; i<(p1.ATK_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p1.ATK_bar ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p2.ATK_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p2.ATK_bar  ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("]");
    printf("            ");
    printf("[ ");
    for(int i=0; i<(p3.ATK_bar) ;i=i+25){
    printf(">");
    }
    for(int i=p3.ATK_bar  ;i<=500 ;i=i+25){
        printf(" ");
    }
    printf("] |");
 }
 
 void affiche_effet(){
     // il faut le faire
 }

  
 void afficheperso(Character p1){
     printf("\n");
     printf("|   %s",p1.name);
     for(int i=strlen(p1.name);i<94;i++){
         printf(" ");
     }
     printf(" |\n");
     printf("|   TECHNIQUES SPECIALES");
     for(int i=0;i<75;i++){
         printf(" ");
     }
     printf("|\n");
     printf("|      |1| attaque normal(peut etre utiliser a chaque tour)                                        |");
      printf("\n");
     if (p1.ch_skill1.cd == 0){
         printf("|      |2|");
         printf(" %s (duree:%f tours)",p1.ch_skill1.name ,p1.ch_skill1.duration);
         for(int i=strlen(p1.ch_skill1.name);i<58;i++){
         printf(" ");
        }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %f duree:%f tours)",p1.ch_skill1.name,p1.ch_skill1.dcd ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill1.name);i<46;i++){
         printf(" ");
        }
        printf("|\n");
     }
     printf("|            %s",p1.ch_skill1.description);
     for(int i=strlen(p1.ch_skill1.description);i<86;i++){
         printf(" ");
    }
     printf("|\n");
     
          if (p1.ch_skill2.cd == 0){
         printf("|      |3|");
         printf(" %s (duree:%f tours)",p1.ch_skill2.name ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<58;i++){
         printf(" ");
        }
        printf("|\n");
     }
     else{
         printf("|      |-|");
         printf(" %s (recharge: %f duree:%f tours)",p1.ch_skill2.name,p1.ch_skill2.dcd ,p1.ch_skill2.duration);
         for(int i=strlen(p1.ch_skill2.name);i<46;i++){
             printf(" ");
        }
        printf("|\n");
     }
      printf("|            %s",p1.ch_skill1.description);
     for(int i=strlen(p1.ch_skill2.description);i<86;i++){
         printf(" ");
    }
     printf("|");
     
 }

 void affichageteam(Team t1){
     printf("┌──[");
    for(int i=0; i<strlen(t1.name)-1;i++){
    printf("%c",t1.name[i]);
    }
    printf("]");
 
     for(int i=strlen(t1.name);i<95;i++){
         printf("─");
     }
     printf("┐");
     printf("\n");
     affichenom(t1);
     printf("\n");
     hpsp(t1.p1,t1.p2,t1.p3);
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
     printf("┘");
 }
 

void affichage1v1(Jeu j){ // fonction prochainperso a code il faut qu'elle renvoie le perso qui attaque   
     if(&j.t1.p1 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team1)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t1.p1);
         affichagefin();
      printf("\n");
         
         
     }
     else if(&j.t1.p2 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
        affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team2)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t1.p2);
         affichagefin();
         printf("\n");
         
     }
     else if(&j.t1.p3 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team1)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t1.p3);
         affichagefin();
      printf("\n");
         
         
     }
     else if(&j.t2.p1 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team2)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t2.p1);
         affichagefin();
      printf("\n");
         
         
     }
     else if(&j.t2.p2 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team2)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t2.p2);
         affichagefin();
         printf("\n");
         
     }
     else if(&j.t2.p3 == prochainperso(&j)){
         affichageteam(j.t2);
         affichagefin();
         printf("\n \n");
         affichageteam(j.t1);
         affichagefin();
         printf("\n \n");
         printf("┌");
         for(int i=0;i<98;i++){
             printf("─");
         }
         printf("┐");
         printf("\n|   (Team2)");
         for(int i=0;i<88;i++){
             printf(" ");
         }
         printf("|");
         afficheperso(j.t2.p3);
         affichagefin();
      printf("\n");
         
     }
    
}


