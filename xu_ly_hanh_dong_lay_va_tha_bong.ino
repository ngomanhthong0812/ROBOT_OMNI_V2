void xu_ly_hanh_dong_lay_bong() {
  kiem_tra_co_bong();
  quay_robo_90_phai(150);
  nang_tay_phai_doc_CTHT();
  kep_tay_trai();
  nang_50_tay_trai();
  quay_robo_180_phai(150);
  nang_tay_trai_doc_CTHT();
  kep_tay_phai();
}
void xu_ly_hanh_dong_chay_tha_bong(int silo_can_tha_bong) {
  quay_robo_90_phai(150);
  mo_tay_trai();
  quay_robo_90_trai(150);
  nang_tay_phai_doc_CTHT();
  if (silo_can_tha_bong == silo_1_2 || silo_can_tha_bong == silo_2_3) {
    chay_bat_line_doc_cam_bien(chay_phai, 100, 100, cb_2, cb_3);  //=> di chuyển sang silo tiếp theo
  }
  quay_robo_90_trai(150);
  mo_tay_phai();
  quay_robo_90_phai(150);
}