void afficher_perso(Character c, int index) {
    printf(" ┌────────────────────────────────┐\n");
    printf(" │ Personnage %d : %-16s │\n", index + 1, c.name);
    printf(" ├────────────────────────────────┤\n");
    printf(" │ HP  : %-22.1f │\n", c.MaxHP);
    printf(" │ ATK : %-22.1f │\n", c.ATK);
    printf(" │ DEF : %-22.1f │\n", c.DEF);
    printf(" │ RES : %-22.1f │\n", c.RES);
    printf(" │ SPD : %-22.1f │\n", c.SPD);
    printf(" │ Skill 1 : %-16s │\n", c.ch_skill1.name);
    printf(" │ Skill 2 : %-16s │\n", c.ch_skill2.name);
    printf(" └────────────────────────────────┘\n");
}