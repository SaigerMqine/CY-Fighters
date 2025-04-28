void ordifacile(){           //fonction pour jouer contre l'ordi mais c'est le debut et il faut mettre les bons perso dans le tableau 
    character tabcharacter[6];
    int tab[6];
    MakeTeam(les characters);
    MakeTeambot(les characters);
    while(p1.ActHP != 0 && p2.ActHP != 0 && p3.ActHP != 0 ){
        for (int i=0 i<6 i++){
            tab[i]+= tabcharacter[i].SPD
            if (tab[i] >= 100){       // 100 c'est une valeur temporaire  
                if (i<3){
                AffichageDuPerso()   // dans l'affichage on mais aussi les verifint
                }
                else{
                    // ici on met quand l'ordi attaque 
                }
            }      
        }
    }
}// je vous laisse l'ameliorer normalement le debut sera toujours pareil pour chaque ordi et pour le 1 contre 1 il faudra juste changer ChoixOrdiEquipe aussi j ai mis des fonction mais je sais pas quelle nom vous voulez mettre 
