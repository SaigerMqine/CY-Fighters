void afficher_perso(Character c, int index) {
    printf(" ┌────────────────────────────────┐\n");
    printf(" │ Personnage %d : %s │\n", index + 1, c.name);
    printf(" ├────────────────────────────────┤\n");
    printf(" │ HP  : %.1f │\n", c.MaxHP);
    printf(" │ ATK : %.1f │\n", c.ATK);
    printf(" │ DEF : %.1f │\n", c.DEF);
    printf(" │ RES : %.1f │\n", c.RES);
    printf(" │ SPD : %.1f │\n", c.SPD);
    printf(" │ Skill 1 : %s │\n", c.ch_skill1.name);
    printf(" │ Skill 2 : %s │\n", c.ch_skill2.name);
    printf(" └────────────────────────────────┘\n");
}