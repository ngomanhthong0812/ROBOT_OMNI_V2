void dk_nang_tay_trai() {
  analogWrite(pwm_nang_tay_toi, 255);
  analogWrite(pwm_nang_tay_lui, 0);
}
void dk_nang_tay_phai() {
  analogWrite(pwm_nang_tay_toi, 0);
  analogWrite(pwm_nang_tay_lui, 255);
}
void dk_dung_dong_co_nang() {
  analogWrite(pwm_nang_tay_lui, 0);
  analogWrite(pwm_nang_tay_toi, 0);
}