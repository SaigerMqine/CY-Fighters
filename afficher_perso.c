
void afficher_perso(Character c, int index) {
    printf(" ┌────────────────────────────────┐\n");
    printf(" │ Personnage %d : %s ", index + 1, c.name);
    for(int i=strlen(c.name);i<21;i++){
         printf(" ");
     }
     printf("│\n");
    printf(" ├────────────────────────────────┤\n");
    printf(" │ HP  : %.1f                          │\n", c.MaxHP);
    printf(" │ ATK : %.1f                           │\n", c.ATK);
    printf(" │ DEF : %.1f                           │\n", c.DEF);
    printf(" │ RES : %.1f                           │\n", c.RES);
    printf(" │ SPD : %.1f                           │\n", c.SPD);
    printf(" │ Skill 1 : %s", c.ch_skill1.name);
    for(int i=strlen(c.ch_skill1.name);i<27;i++){
         printf(" ");
     }
     printf("|\n");
    printf(" │ Skill 2 : %s", c.ch_skill2.name);
    for(int i=strlen(c.ch_skill2.name);i<27;i++){
         printf(" ");
     }
     printf("|\n");
    printf(" └────────────────────────────────┘\n");
}
