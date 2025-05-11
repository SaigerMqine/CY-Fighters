float skillATK (character* c1,character c2){
  c2.ATK=c2.ATK*c1->Skill1.val;
  c1->skill1.dcd=c1->skill1.cd;
  return c2.ATK;
}
float antiskillATK (character* c1,character c2){
  c2.ATK=c2.ATK/c1->Skill1.val;
  return c2.ATK;
}
