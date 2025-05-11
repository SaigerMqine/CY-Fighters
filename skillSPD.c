float skillSPD (character* c1,character c2){
  c2.SPD=c2.SPD*c1->Skill1.val;
  c1->skill1.dcd=c1->skill1.cd;
}
float antiskillATK (character c1,character c2){
  c2.SPD=c2.SPD/c1.Skill1.val;
}
