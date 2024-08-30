void chay_do_encoder(int huong_robot, int encoder_dat, int chay_dung, int toc_do_trai, int toc_do_phai) {
  xung_encoder1 = xung_encoder2 = xung_encoder3 = xung_encoder4 = 0;
  do {
    dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
  } while ((huong_robot == chay_cheo_trai) ? (xung_encoder1 <= encoder_dat) : (xung_encoder2 <= encoder_dat));
  if (chay_dung == 1) {
    dung_dong_co();
  }
}
void chay_toi_bat_cam_bien_dau() {
  int cb_d_trai = 0;
  int cb_d_phai = 0;
  do {
    cb_d_trai = digitalRead(cb_dau_trai);
    cb_d_phai = digitalRead(cb_dau_phai);
    Serial.print(cb_d_trai);
    dieu_khien_dong_co(chay_toi, 105, 100);
  } while (cb_d_trai == 0 || cb_d_phai == 0);
    dung_dong_co();


  if (cb_d_trai == 0) {
    do {
      cb_d_trai = digitalRead(cb_dau_trai);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, 0, 100, 0, 100);
    } while (cb_d_trai == 0);
      dung_dong_co();
  }else {
    do {
      cb_d_phai == digitalRead(cb_dau_phai);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, 100, 0, 100, 0);
    } while (cb_d_phai == 0);
      dung_dong_co();
  }
   dung_dong_co();
  // chay_do_encoder(chay_lui, 100, int chay_dung, 100, 100);
}