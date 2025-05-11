#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Character lire_personnage(const char* nom_fichier) {
    FILE* f = fopen(nom_fichier, "r");
    if (!f) {
        printf("Erreur : impossible d’ouvrir %s\n", nom_fichier);
        exit(EXIT_FAILURE);
    }

    Character perso;
    Skill s1, s2;
    char ligne[256];

    while (fgets(ligne, sizeof(ligne), f)) {
        if (strncmp(ligne, "Nom:", 4) == 0)
            sscanf(ligne, "Nom: %49[^\n]", perso.name);
        else if (strncmp(ligne, "MaxHP:", 6) == 0)
            sscanf(ligne, "MaxHP: %f", &perso.MaxHP);
        else if (strncmp(ligne, "ActHP:", 6) == 0)
            sscanf(ligne, "ActHP: %f", &perso.ActHP);
        else if (strncmp(ligne, "ATK:", 4) == 0)
            sscanf(ligne, "ATK: %f", &perso.ATK);
        else if (strncmp(ligne, "DEF:", 4) == 0)
            sscanf(ligne, "DEF: %f", &perso.DEF);
        else if (strncmp(ligne, "RES:", 4) == 0)
            sscanf(ligne, "RES: %f", &perso.RES);
        else if (strncmp(ligne, "SPD:", 4) == 0)
            sscanf(ligne, "SPD: %f", &perso.SPD);
        else if (strncmp(ligne, "ATK_bar:", 8) == 0)
            sscanf(ligne, "ATK_bar: %d", &perso.ATK_bar);

        else if (strncmp(ligne, "Skill1:", 7) == 0)
            sscanf(ligne, "Skill1: %49[^\n]", s1.name);
        else if (strncmp(ligne, "Skill1_Val:", 11) == 0)
            sscanf(ligne, "Skill1_Val: %f", &s1.value);
        else if (strncmp(ligne, "Skill1_Duration:", 16) == 0)
            sscanf(ligne, "Skill1_Duration: %f", &s1.duration);
        else if (strncmp(ligne, "Skill1_CD:", 10) == 0)
            sscanf(ligne, "Skill1_CD: %f", &s1.cd);
        else if (strncmp(ligne, "Skill1_DCD:", 11) == 0)
            sscanf(ligne, "Skill1_DCD: %f", &s1.dcd);
        else if (strncmp(ligne, "Skill1_Desc:", 12) == 0)
            sscanf(ligne, "Skill1_Desc: %99[^\n]", s1.description);

        else if (strncmp(ligne, "Skill2:", 7) == 0)
            sscanf(ligne, "Skill2: %49[^\n]", s2.name);
        else if (strncmp(ligne, "Skill2_Val:", 11) == 0)
            sscanf(ligne, "Skill2_Val: %f", &s2.value);
        else if (strncmp(ligne, "Skill2_Duration:", 16) == 0)
            sscanf(ligne, "Skill2_Duration: %f", &s2.duration);
        else if (strncmp(ligne, "Skill2_CD:", 10) == 0)
            sscanf(ligne, "Skill2_CD: %f", &s2.cd);
        else if (strncmp(ligne, "Skill2_DCD:", 11) == 0)
            sscanf(ligne, "Skill2_DCD: %f", &s2.dcd);
        else if (strncmp(ligne, "Skill2_Desc:", 12) == 0)
            sscanf(ligne, "Skill2_Desc: %99[^\n]", s2.description);
    }

    fclose(f);

    perso.ch_skill1 = s1;
    perso.ch_skill2 = s2;

    return perso;
}