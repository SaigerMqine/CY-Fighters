float skillRES (character* c1,character c2){
  c2.RES=c2.RES*c1->Skill2.val;
  c1->skill2.dcd=c1->skill2.cd;
}
float antiskillRES (character c1,character c2){
  c2.RES=c2.RES/c1.Skill2.val;
}
