Character maxi(Character p1,Character p2){            // le perso avec la plus grande atk_bar
    if(p1.ATK_bar>=P2.ATK_bar){
        return p1
    }
    else{
        return p2
    }
}

Character prochainperso(Jeu j){            // le prochain personnage a attaquer
    if(maxi(maxi(maxi(j.t1.p1,j.t1.p2),maxi(j.t1.p3,j.t2.p1)),maxi(j.t2.p2,j.t2.p3)).ATK_bar>=500){
        return maxi(maxi(maxi(j.t1.p1,j.t1.p2),maxi(j.t1.p3,j.t2.p1)),maxi(j.t2.p2,j.t2.p3));
    }
}
