float skillDEFene (character* c1,character c2){
  c2.DEF=c2.DEF/c1->Skill2.val;
  c1->skill2.dcd=c1->skill2.cd;
  return c2.DEF
}
float antiskillDEFene (character* c1,character c2){
  c2.DEF=c2.DEF*c1->Skill2.val;
  return c2.DEF
}
