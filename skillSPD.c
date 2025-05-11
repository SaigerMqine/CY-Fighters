float skillSPD (character* c1,character c2){      //buff SPD
  c2.SPD=c2.SPD*c1->Skill1.val;
  c1->skill1.dcd=c1->skill1.cd;
  return c2.SPD
}
float antiskillSPD (character* c1,character c2){    // antibuff SPD
  c2.SPD=c2.SPD/c1->Skill1.val;
  return c2.SPD
}
