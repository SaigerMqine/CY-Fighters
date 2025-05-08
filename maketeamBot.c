Team MakeTeam(Character characters[], int nb) {
    Team team1;
    printf("Entrez le nom de votre équipe : ");
    team1.name = verifname();
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    while (i < 3) {
        for (int j = 0; j < nb; j++) afficher_perso(characters[j], j);
        printf("Choisissez le personnage %d (1 à %d) : ", i + 1, nb);
        int choix = verifint() - 1;

        int deja_choisi = 0;
        for (int k = 0; k < i; k++) {
            if (choix == choisis[k]) {
                deja_choisi = 1;
                break;
            }
        }

        if (deja_choisi) {
            printf("Personnage déjà choisi !\n");
            continue;
        }

        choisis[i] = choix;
        if (i == 0) team1.p1 = characters[choix];
        else if (i == 1) team1.p2 = characters[choix];
        else team1.p3 = characters[choix];

        i++;
    }

    return team1;
}

Team MakeTeambot(Character characters[], int nb) {
    Team team2;
    strcpy(team2.name, "Bot");
    int choisis[3] = {-1, -1, -1};
    int i = 0;
    srand(time(NULL));

    while (i < 3) {
        int choix = rand() % nb;
        int deja_choisi = 0;
        for (int k = 0; k < i; k++) {
            if (choix == choisis[k]) {
                deja_choisi = 1;
                break;
            }
        }

        if (deja_choisi) continue;

        choisis[i] = choix;
        if (i == 0) team2.p1 = characters[choix];
        else if (i == 1) team2.p2 = characters[choix];
        else team2.p3 = characters[choix];

        i++;
    }

    return team2;
}