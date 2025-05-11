float skillHEAL (character* c1,character c2){
  c2.ActHP=c2.ActHP+(c2.MaxHP*c1->Skill2.val);
  c1->skill2.dcd=c1->skill2.cd;
}
