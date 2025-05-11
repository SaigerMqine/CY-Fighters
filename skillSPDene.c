float skillSPDene (character* c1,character c2){
  c2.SPD=c2.SPD/c1->Skill2.val;
  c1->skill2.dcd=c1->skill2.cd;
}
float antiskillSPDene (character* c1,character c2){
  c2.SPD=c2.SPD*c1->Skill2.val;
}
