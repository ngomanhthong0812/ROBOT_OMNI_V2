void set_pwm(int pwm1, int pwm2, int pwm3, int pwm4, int value1, int value2, int value3, int value4) {
  analogWrite(pwm1, value1);
  analogWrite(pwm2, value2);
  analogWrite(pwm3, value3);
  analogWrite(pwm4, value4);
}

void dieu_khien_dong_co(int huong_robot, int toc_do_trai, int toc_do_phai) {
  //nếu chạy 4 động cơ
  //      trái   -------- phải
  //phải  bánh 1 -------- bánh 2  trái
  //trái  bánh 3 -------- bánh 4  phải
  //      phải   -------- trái

  // Điều khiển động cơ
  switch (huong_robot) {
    case chay_toi:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, 0, 0, 0, 0);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, toc_do_phai, toc_do_trai, toc_do_phai, toc_do_trai);
      break;

    case chay_lui:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, toc_do_phai, toc_do_trai, toc_do_phai, toc_do_trai);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, 0, 0, 0, 0);
      break;

    case chay_trai:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, 0, toc_do_trai, toc_do_phai, 0);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, toc_do_phai, 0, 0, toc_do_trai);
      break;

    case chay_phai:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, toc_do_phai, 0, 0, toc_do_trai);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, 0, toc_do_trai, toc_do_phai, 0);
      break;

    case chay_cheo_phai:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, 0, 0, 0, 0);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, 0, toc_do_trai, toc_do_phai, 0);
      break;

    case chay_cheo_trai:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, 0, 0, 0, 0);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, toc_do_phai, 0, 0, toc_do_trai);
      break;

    case chay_xoay_phai:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, toc_do_phai, 0, toc_do_phai, 0);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, 0, toc_do_trai, 0, toc_do_trai);
      break;

    case chay_xoay_trai:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, 0, toc_do_trai, 0, toc_do_trai);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, toc_do_phai, 0, toc_do_phai, 0);
      break;
    case dung_dong_co_chay:
      set_pwm(pwm1_lui, pwm2_lui, pwm3_lui, pwm4_lui, 0, 0, 0, 0);
      set_pwm(pwm1_toi, pwm2_toi, pwm3_toi, pwm4_toi, 0, 0, 0, 0);
      break;

    default:
      break;
  }
}
