void ordifacile(){           //fonction pour jouer contre l'ordi mais c'est le debut et il faut mettre les bons perso dans le tableau 
    MakeTeam(les characters);
    MakeTeambot(les characters);
    while(Team1.p1.ActHP > 0 && Team1.p2.ActHP > 0 && Team1.p3.ActHP > 0 || Team2.p1.ActHP > 0 && Team2.p2.ActHP > 0 && Team2.p3.ActHP > 0){
        Team1.p1.ATK_bar=Team1.p1.ATK_bar+Team1.p1.SPD;
        Team1.p2.ATK_bar=Team1.p2.ATK_bar+Team1.p2.SPD;
        Team1.p3.ATK_bar=Team1.p3.ATK_bar+Team1.p3.SPD;
        Team2.p1.ATK_bar=Team2.p1.ATK_bar+Team2.p1.SPD;
        Team2.p2.ATK_bar=Team2.p2.ATK_bar+Team2.p2.SPD;
        Team2.p3.ATK_bar=Team2.p3.ATK_bar+Team2.p3.SPD;
                if (Team1.p1.ATK_bar >=500 ||   Team1.p2.ATK_bar >= 500 || Team1.p3.ATK_bar >= 500 || Team2.p1.ATK_bar >= 500 || Team2.p2.ATK_bar >= 500 || Team2.p3.ATK_bar >= 500){
                
                    
                    AffichageDuPerso()   // dans l'affichage on met aussi les verifint pour choix de l'atk
                
                }
            }      
        }
    }
}// je vous laisse l'ameliorer normalement le debut sera toujours pareil pour chaque ordi et pour le 1 contre 1 il faudra juste changer ChoixOrdiEquipe aussi j ai mis des fonction mais je sais pas quelle nom vous voulez mettre 
