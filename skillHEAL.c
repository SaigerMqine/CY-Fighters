float skillHEAL (character* c1,character c2){
  c2.ActHP=c2.ActHP+(c2.MaxHP*c1->Skill.val);
  c1->skill.dcd=c1->skill.cd;
}
