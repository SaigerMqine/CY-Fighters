
Character* maxi(Character* p1, Character* p2){
    if (p1->ATK_bar >= p2->ATK_bar) {
    return  p1; }
    else {
        return p2; 
    }
}

Character* prochainperso(Jeu* j){
    Character* m1 = maxi(&j->t1.p1, &j->t1.p2);
    Character* m2 = maxi(&j->t1.p3, &j->t2.p1);
    Character* m3 = maxi(&j->t2.p2, &j->t2.p3);
    Character* m4 = maxi(m1, m2);
    Character* m5 = maxi(m3, m4);
    if (m5->ATK_bar >= 500)
        return m5;
    return NULL;
}
