#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Character lire_personnage(const char *filename) {
    Character c;
    char ligne[200];
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        exit(EXIT_FAILURE);
    }

    while (fgets(ligne, sizeof(ligne), f)) {
        char *valeur = strchr(ligne, ':');
        if (!valeur) continue;
        *valeur = '\0';
        valeur++; while (*valeur == ' ') valeur++; // ignorer espace

        if (strcmp(ligne, "Nom") == 0) strcpy(c.name, valeur);
        else if (strcmp(ligne, "MaxHP") == 0) c.MaxHP = atof(valeur);
        else if (strcmp(ligne, "ActHP") == 0) c.ActHP = atof(valeur);
        else if (strcmp(ligne, "ATK") == 0) c.ATK = atof(valeur);
        else if (strcmp(ligne, "DEF") == 0) c.DEF = atof(valeur);
        else if (strcmp(ligne, "RES") == 0) c.RES = atof(valeur);
        else if (strcmp(ligne, "SPD") == 0) c.SPD = atof(valeur);
        else if (strcmp(ligne, "Skill1") == 0) strcpy(c.ch_skill1.name, valeur);
        else if (strcmp(ligne, "Skill1_Val") == 0) c.ch_skill1.value = atof(valeur);
        else if (strcmp(ligne, "Skill1_Duration") == 0) c.ch_skill1.duration = atof(valeur);
        else if (strcmp(ligne, "Skill1_CD") == 0) c.ch_skill1.cd = atof(valeur);
        else if (strcmp(ligne, "Skill1_Desc") == 0) strcpy(c.ch_skill1.description, valeur);
        else if (strcmp(ligne, "Skill2") == 0) strcpy(c.ch_skill2.name, valeur);
        else if (strcmp(ligne, "Skill2_Val") == 0) c.ch_skill2.value = atof(valeur);
        else if (strcmp(ligne, "Skill2_Duration") == 0) c.ch_skill2.duration = atof(valeur);
        else if (strcmp(ligne, "Skill2_CD") == 0) c.ch_skill2.cd = atof(valeur);
        else if (strcmp(ligne, "Skill2_Desc") == 0) strcpy(c.ch_skill2.description, valeur);
    }

    fclose(f);
    return c;
}