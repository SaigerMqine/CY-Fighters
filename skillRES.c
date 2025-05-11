float skillRES (character* c1,character c2){
  c2.RES=c2.RES*c1->Skill.val;
  c1->skill.dcd=c1->skill.cd;
}
float antiskillRES (character* c1,character c2){
  c2.RES=c2.RES/c1->Skill.val;
}
