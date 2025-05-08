float calcul_des_dégats_pris(character p1,character p2){ //p1=perso attaqué, p2=perso qui attaque
    int i=0;
    i=(rand()%100)+1;
    if(i<=p1.RES){
        return p1.actHP;
    }
    else{
        p1.actHP=p1.actHP-p2.ATK*(1-(p1.DEF/100));
        return p1.actHP;
    }
}
