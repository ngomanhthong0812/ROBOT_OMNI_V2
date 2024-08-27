void dong_tay_kep(int tay_kep) {
  switch (tay_kep) {
    case tay_kep_trai:
      KEPT.write(300);
      break;
    case tay_kep_phai:
      KEPP.write(160);
      break;
  }
}
void mo_tay_kep(int tay_kep) {
  switch (tay_kep) {
    case tay_kep_trai:
      KEPT.write(150);
      break;
    case tay_kep_phai:
      KEPP.write(130);
      break;
  }
}