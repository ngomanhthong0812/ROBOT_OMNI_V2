void kep_tay_trai() {
  servo_trai_truoc.write(110);
  servo_trai_sau.write(83);
}
void mo_tay_trai() {
  servo_trai_truoc.write(0);
  servo_trai_sau.write(180);
}
void kep_tay_phai() {
  servo_phai_truoc.write(83);
  servo_phai_sau.write(100);
}
void mo_tay_phai() {
  servo_phai_truoc.write(180);
  servo_phai_sau.write(0);
}