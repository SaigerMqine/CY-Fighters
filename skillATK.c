float skillATK (character* c){
  c->ATK=c->ATK+((c->ATK*40)/100);
  c->skill.dcd=c->skill.cd;
}
float antiskillATK (character* c){
  c->ATK=c->ATK-((c->ATK*40)/100);
}
