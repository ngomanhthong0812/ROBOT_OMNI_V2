void kiem_tra_co_bong() {
  int cb_phb = 1;

  do {
    cb_phb = digitalRead(cb_phat_hien_bong);
    Serial.println("chk co bong");
  } while (cb_phb == 1);
    Serial.println("co bong");
}