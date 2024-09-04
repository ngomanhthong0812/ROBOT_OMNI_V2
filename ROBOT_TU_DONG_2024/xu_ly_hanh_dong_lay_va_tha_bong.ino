void xu_ly_hanh_dong_lay_bong() {
  kiem_tra_co_bong();
  delay(7000);
  quay_robo_90_phai(150);
  nang_tay_phai_doc_CTHT();
  kep_tay_trai();
  delay(300);
  nang_50_tay_trai();
  quay_robo_180_phai(150);
  nang_tay_trai_doc_CTHT();
  kep_tay_phai();
  delay(300);
}
void xu_ly_hanh_dong_chay_tha_bong(int silo_can_tha_bong) {
  chay_toi_bat_cam_bien_dau();
  quay_robo_90_phai(150);
  delay(300);
  mo_tay_trai();
  delay(300);
  quay_robo_90_trai(150);
  chay_toi_bat_cam_bien_dau();
  if (silo_can_tha_bong == silo_3 || silo_can_tha_bong == silo_2_3) {
    nang_tay_trai_doc_CTHT();  //
  } else {
    nang_70_tay_trai();
  }
  if (silo_can_tha_bong == silo_1_2 || silo_can_tha_bong == silo_2_3) {
    chay_do_encoder(chay_phai, 200, 1, 100, 103);                 //=> chạy qua khỏi line 2
    chay_bat_line_doc_cam_bien(chay_phai, 100, 100, cb_2, cb_3);  //=> di chuyển sang silo tiếp theo
  }
  if (silo_can_tha_bong == silo_3_1) {
    chay_do_encoder(chay_trai, 1200, 1, 100, 103);  //=> chạy qua khỏi line 3
    chay_bat_line_doc_cam_bien(chay_trai, 100, 103, cb_2, cb_3);
    chay_do_encoder(chay_trai, 350, 1, 100, 103);  //=> chạy qua khỏi line 2
    chay_bat_line_doc_cam_bien(chay_trai, 100, 103, cb_2, cb_3);
  }
  if (silo_can_tha_bong == silo_2_1) {
    chay_do_encoder(chay_trai, 350, 1, 100, 103);  //=> chạy qua khỏi line 2
    chay_bat_line_doc_cam_bien(chay_trai, 100, 103, cb_2, cb_3);
  }

  quay_robo_90_trai(150);
  delay(300);
  mo_tay_phai();
  delay(300);
  quay_robo_90_phai(150);
  chay_toi_bat_cam_bien_dau();
}

void xu_ly_hanh_dong_lay_bong_doi_xanh() {
  kiem_tra_co_bong();
  delay(7000);
  quay_robo_90_trai(150);
  nang_tay_trai_doc_CTHT();
  kep_tay_phai();
  delay(300);
  nang_50_tay_phai();
  quay_robo_180_trai(150);
  nang_tay_phai_doc_CTHT();
  kep_tay_trai();
  delay(300);
}

void xu_ly_hanh_dong_chay_tha_bong_doi_xanh(int silo_can_tha_bong) {
  chay_toi_bat_cam_bien_dau();
  quay_robo_90_trai(150);
  delay(300);
  mo_tay_phai();
  delay(300);
  quay_robo_90_phai(150);
  chay_toi_bat_cam_bien_dau();
  if (silo_can_tha_bong == silo_3 || silo_can_tha_bong == silo_2_3) {
    nang_tay_trai_doc_CTHT();  //
  } else {
    nang_70_tay_trai();
  }
  if (silo_can_tha_bong == silo_1_2 || silo_can_tha_bong == silo_2_3) {
    chay_do_encoder(chay_trai, 200, 1, 100, 103);                 //=> chạy qua khỏi line 2
    chay_bat_line_doc_cam_bien(chay_trai, 100, 100, cb_2, cb_3);  //=> di chuyển sang silo tiếp theo
  }
  if (silo_can_tha_bong == silo_3_1) {
    chay_do_encoder(chay_phai, 1200, 1, 100, 103);  //=> chạy qua khỏi line 3
    chay_bat_line_doc_cam_bien(chay_phai, 100, 103, cb_2, cb_3);
    chay_do_encoder(chay_phai, 350, 1, 100, 103);  //=> chạy qua khỏi line 2
    chay_bat_line_doc_cam_bien(chay_phai, 100, 103, cb_2, cb_3);
  }
  if (silo_can_tha_bong == silo_2_1) {
    chay_do_encoder(chay_phai, 350, 1, 100, 103);  //=> chạy qua khỏi line 2
    chay_bat_line_doc_cam_bien(chay_phai, 100, 103, cb_2, cb_3);
  }
  quay_robo_90_phai(150);
  delay(300);
  mo_tay_trai();
  delay(300);
  quay_robo_90_trai(150);
  chay_toi_bat_cam_bien_dau();
}
