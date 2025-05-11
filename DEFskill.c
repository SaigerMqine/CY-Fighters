float skillDEF (character* c1,character c2){
  c2.DEF=c2.DEF+((c2.DEF*c1->Skill.val)/100);
  c1->skill.dcd=c1->skill.cd;
}
float antiskillDEF (character* c1,character c2){
  c2.DEF=c2.DEF-((c2.DEF*c1->Skill.val)/100);
}
