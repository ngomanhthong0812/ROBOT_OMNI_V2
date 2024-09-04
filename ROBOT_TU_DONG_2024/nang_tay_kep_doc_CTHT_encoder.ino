void nang_tay_trai_doc_CTHT() {
  int cb_tay_trai = 1;  // Đọc giá trị từ cảm biến tay trái
  int cb_tay_phai = 1;  // Đọc giá trị từ cảm biến tay phải
  dk_nang_tay_trai();
  delay(500);
  do {
    dk_nang_tay_trai();
    cb_tay_trai = digitalRead(cam_bien_tay_trai);
    cb_tay_phai = digitalRead(cam_bien_tay_phai);
  } while (cb_tay_trai == 1 && cb_tay_phai == 1);
  dk_dung_dong_co_nang();
}

void nang_tay_phai_doc_CTHT() {
  int cb_tay_trai = 1;  // Đọc giá trị từ cảm biến tay trái
  int cb_tay_phai = 1;  // Đọc giá trị từ cảm biến tay phải
  dk_nang_tay_phai();
  delay(500);
  do {
    dk_nang_tay_phai();
    cb_tay_trai = digitalRead(cam_bien_tay_trai);
    cb_tay_phai = digitalRead(cam_bien_tay_phai);
  } while (cb_tay_trai == 1 && cb_tay_phai == 1);
  dk_dung_dong_co_nang();
}

void nang_tay_encoder(int huong_tay_nang, int encoder_dat) {
  do {
    switch (huong_tay_nang) {
      case nang_tay_trai:
        dk_nang_tay_trai();
        Serial.println(xung_encoder_nang_tay);
        break;
      case nang_tay_phai:
        dk_nang_tay_phai();
        Serial.println(xung_encoder_nang_tay);
        break;
      default:
        break;
    }
  } while (xung_encoder_nang_tay <= encoder_dat);
  dk_dung_dong_co_nang();
}

void khoi_dong_nang_tay() {
  nang_tay_phai_doc_CTHT();
  nang_50_tay_trai();
}

