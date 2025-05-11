float skillATK (character* c1,character c2){
  c2.ATK=c2.ATK*c1->Skill.val;
  c1->skill.dcd=c1->skill.cd;
}
float antiskillATK (character* c1,character c2){
  c2.ATK=c2.ATK/c1->Skill.val;
}
