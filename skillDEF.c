float skillDEF (character* c1,character c2){
  c2.DEF=c2.DEF*c1->Skill2.val;
  c1->skill2.dcd=c1->skill2.cd;
}
float antiskillDEF (character c1,character c2){
  c2.DEF=c2.DEF/c1.Skill2.val;
}
