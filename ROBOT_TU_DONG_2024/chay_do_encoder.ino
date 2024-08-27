void chay_do_encoder(int huong_robot, int encoder_dat, int chay_dung, int toc_do_trai, int toc_do_phai) {
  xung_encoder1 = xung_encoder2 = xung_encoder3 = xung_encoder4 = 0;
  do {
    dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
  } while ((huong_robot == chay_cheo_trai) ? (xung_encoder1 <= encoder_dat) : (xung_encoder2 <= encoder_dat));
  if (chay_dung == 1) {
    dung_dong_co();
  }
}