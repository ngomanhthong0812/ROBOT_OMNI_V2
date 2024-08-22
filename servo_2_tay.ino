int vi_tri_servor_kep_trai_truoc = 110;
int vi_tri_servor_kep_trai_sau = 80;

int vi_tri_servor_kep_phai_truoc = 83;
int vi_tri_servor_kep_phai_sau = 100;

void kep_tay_trai() {
  servo_trai_truoc.write(110);
  servo_trai_sau.write(80);
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
void thuc_hien_kep_bong_tay_trai_va_kiem_tra() {
  int vi_tri_servor_trai_truoc_hien_tai;
  int vi_tri_servor_trai_sau_hien_tai;
  bool co_bong = false;
  bool lan_kep_dau_tien = true;  // Biến để theo dõi lần kẹp đầu tiên

  mo_tay_trai();
  nang_tay_phai_doc_CTHT();

  do {
    mo_tay_trai();
    if (!lan_kep_dau_tien) {  // Bỏ qua lần kẹp đầu tiên
      delay(5000);
    }
    kep_tay_trai();
    vi_tri_servor_trai_truoc_hien_tai = servo_trai_truoc.read();
    vi_tri_servor_trai_sau_hien_tai = servo_trai_sau.read();
    Serial.print(vi_tri_servor_trai_truoc_hien_tai);
    Serial.print(vi_tri_servor_trai_sau_hien_tai);
    if (vi_tri_servor_kep_trai_truoc != vi_tri_servor_trai_truoc_hien_tai && vi_tri_servor_kep_trai_sau == vi_tri_servor_trai_sau_hien_tai) {
      co_bong = true;
    }
    lan_kep_dau_tien = false;  // Gán lại false khi hoàn thành lần kẹp đầu tiên
  } while (!co_bong);
  servo_trai_truoc.write(vi_tri_servor_trai_truoc_hien_tai);
  servo_trai_sau.write(vi_tri_servor_trai_sau_hien_tai);
  nang_tay_encoder(nang_tay_trai, 1);  //=> nâng lên 50%
}

void thuc_hien_kep_bong_tay_phai_va_kiem_tra() {
  int vi_tri_servor_phai_truoc_hien_tai;
  int vi_tri_servor_phai_sau_hien_tai;
  bool co_bong = false;
  bool lan_kep_dau_tien = true;  // Biến để theo dõi lần kẹp đầu tiên

  mo_tay_phai();
  nang_tay_trai_doc_CTHT();

  do {
    mo_tay_phai();
    if (!lan_kep_dau_tien) {  // Bỏ qua lần kẹp đầu tiên
      delay(5000);
    }
    kep_tay_phai();
    vi_tri_servor_phai_truoc_hien_tai = servo_phai_truoc.read();
    vi_tri_servor_phai_sau_hien_tai = servo_phai_sau.read();
    Serial.print(vi_tri_servor_phai_truoc_hien_tai);
    Serial.print(vi_tri_servor_phai_sau_hien_tai);
    if (vi_tri_servor_kep_phai_truoc != vi_tri_servor_phai_truoc_hien_tai && vi_tri_servor_kep_phai_sau == vi_tri_servor_phai_sau_hien_tai) {
      co_bong = true;
    }
    lan_kep_dau_tien = false;  // Gán lại false khi hoàn thành lần kẹp đầu tiên
  } while (!co_bong);
  servo_phai_truoc.write(vi_tri_servor_phai_truoc_hien_tai);
  servo_phai_sau.write(vi_tri_servor_phai_sau_hien_tai);
  nang_tay_encoder(nang_tay_phai, 1);  //=> nâng lên 50%
}
