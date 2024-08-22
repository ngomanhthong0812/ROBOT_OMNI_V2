//CTHT => công tắc hành trình
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
  xung_encoder_nang_tay = 0;
  do {
    switch (huong_tay_nang) {
      case nang_tay_trai:
        dk_nang_tay_trai();
        break;
      case nang_tay_phai:
        dk_nang_tay_phai();
        break;
      default:
        break;
    }
  } while (xung_encoder_nang_tay <= encoder_dat);
  dk_dung_dong_co_nang();
}

void khoi_dong_nang_tay() {
  int cb_tay_trai = digitalRead(cam_bien_tay_trai);
  int cb_tay_phai = digitalRead(cam_bien_tay_phai);
  if (cb_tay_trai == 0) {
    nang_tay_encoder(nang_tay_trai, 10);  //=> nâng tay trái 50%
  }
  if (cb_tay_phai == 0) {
    nang_tay_encoder(nang_tay_phai, 10);  //=> nâng tay phải 50%
  }
}