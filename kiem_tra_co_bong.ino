void kiem_tra_co_bong() {
  int cb_phb = 0;

  do {
    cb_phb = digitalRead(cb_phat_hien_bong);
  } while (cb_phb == 0);
}