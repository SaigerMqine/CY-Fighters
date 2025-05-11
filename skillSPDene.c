float skillSPDene (character* c1,character c2){
  c2.SPD=c2.SPD/c1->Skill.val;
  c1->skill.dcd=c1->skill.cd;
}
float antiskillSPDene (character* c1,character c2){
  c2.SPD=c2.SPD*c1->Skill.val;
}
