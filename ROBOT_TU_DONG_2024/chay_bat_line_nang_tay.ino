void chay_bat_line_nang_tay_phai_70(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  bool tay_phai_dang_nang = true;
  bool line_dang_doc = true;

  unsigned long bat_dau_nang_tay = millis();  // Lấy thời gian bắt đầu
  unsigned long thoi_gian_nang_tay = 12000;    // Thời gian nâng tay là 6,8 giây (6800ms)

  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;

  do {
    // Đọc trạng thái cảm biến line
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);

    // Điều khiển robot chạy đọc line
    if (tt_cam_bien0 == 0 || tt_cam_bien1 == 0) {
      dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
      Serial.println("chay");
    } else {
      line_dang_doc = false;
      dung_dong_co();  // Dừng động cơ khi hoàn thành đọc line
    }

    // Nâng tay phải nếu chưa hết 6,8 giây
    if (millis() - bat_dau_nang_tay <= thoi_gian_nang_tay) {
      dk_nang_tay_phai();
      Serial.println("nang");
    } else {
      tay_phai_dang_nang = false;
      dk_dung_dong_co_nang();  // Dừng động cơ nâng tay khi hết thời gian
    }

    delay(10);
  } while (line_dang_doc == true || tay_phai_dang_nang == true);
}
void chay_bat_line_nang_tay_phai_100(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  bool tay_phai_dang_nang = true;
  bool line_dang_doc = true;

  int cb_tay_trai = 1;  // Đọc giá trị từ cảm biến tay trái
  int cb_tay_phai = 1;  // Đọc giá trị từ cảm biến tay phải

  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;
  dk_nang_tay_phai();
  delay(500);
  do {
    // Đọc trạng thái cảm biến line
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);

    cb_tay_trai = digitalRead(cam_bien_tay_trai);
    cb_tay_phai = digitalRead(cam_bien_tay_phai);

    // Điều khiển robot chạy đọc line
    if (tt_cam_bien0 == 0 || tt_cam_bien1 == 0) {
      dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
    } else {
      line_dang_doc = false;
      dung_dong_co();  // Dừng động cơ khi hoàn thành đọc line
    }

    if (cb_tay_trai == 1 && cb_tay_phai == 1) {
      dk_nang_tay_phai();
    } else {
      tay_phai_dang_nang = false;
      dk_dung_dong_co_nang();  // Dừng động cơ nâng tay khi hết thời gian
    }

    delay(10);
  } while (line_dang_doc == true || tay_phai_dang_nang == true);
}


void chay_bat_line_nang_tay_trai_50(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  bool tay_trai_dang_nang = true;
  bool line_dang_doc = true;

  unsigned long bat_dau_nang_tay = millis();  // Lấy thời gian bắt đầu
  unsigned long thoi_gian_nang_tay = 6800;    // Thời gian nâng tay là 6,8 giây (6800ms)

  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;

  do {
    // Đọc trạng thái cảm biến line
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);

    // Điều khiển robot chạy đọc line
    if (tt_cam_bien0 == 0 || tt_cam_bien1 == 0) {
      dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
    } else {
      line_dang_doc = false;
      dung_dong_co();  // Dừng động cơ khi hoàn thành đọc line
    }

    // Nâng tay phải nếu chưa hết 6,8 giây
    if (millis() - bat_dau_nang_tay <= thoi_gian_nang_tay) {
      dk_nang_tay_trai();
    } else {
      tay_trai_dang_nang = false;
      dk_dung_dong_co_nang();  // Dừng động cơ nâng tay khi hết thời gian
    }

    delay(10);
  } while (line_dang_doc == true || tay_trai_dang_nang == true);
}

void chay_bat_line_nang_tay_trai_100(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  bool tay_trai_dang_nang = true;
  bool line_dang_doc = true;

  int cb_tay_trai = 1;  // Đọc giá trị từ cảm biến tay trái
  int cb_tay_phai = 1;  // Đọc giá trị từ cảm biến tay phải

  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;
  dk_nang_tay_trai();
  delay(500);
  do {
    // Đọc trạng thái cảm biến line
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);

    cb_tay_trai = digitalRead(cam_bien_tay_trai);
    cb_tay_phai = digitalRead(cam_bien_tay_phai);

    // Điều khiển robot chạy đọc line
    if (tt_cam_bien0 == 0 || tt_cam_bien1 == 0) {
      dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
    } else {
      line_dang_doc = false;
      dung_dong_co();  // Dừng động cơ khi hoàn thành đọc line
    }

    if (cb_tay_trai == 1 && cb_tay_phai == 1) {
      dk_nang_tay_trai();
    } else {
      tay_trai_dang_nang = false;
      dk_dung_dong_co_nang();  // Dừng động cơ nâng tay khi hết thời gian
    }

    delay(10);
  } while (line_dang_doc == true || tay_trai_dang_nang == true);
}

void chay_ve_bat_line_nang_tay_trai_20(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  bool tay_trai_dang_nang = true;
  bool line_dang_doc = true;

  unsigned long bat_dau_nang_tay = millis();  // Lấy thời gian bắt đầu
  unsigned long thoi_gian_nang_tay = 2000;    // Thời gian nâng tay là 6,8 giây (6800ms)

  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;

  do {
    // Đọc trạng thái cảm biến line
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);

    // Điều khiển robot chạy đọc line
    if (tt_cam_bien0 == 0 || tt_cam_bien1 == 0) {
      dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
    } else {
      line_dang_doc = false;
      dung_dong_co();  // Dừng động cơ khi hoàn thành đọc line
    }

    // Nâng tay phải nếu chưa hết 2 giây
    if (millis() - bat_dau_nang_tay <= thoi_gian_nang_tay) {
      dk_nang_tay_trai();
    } else {
      tay_trai_dang_nang = false;
      dk_dung_dong_co_nang();  // Dừng động cơ nâng tay khi hết thời gian
    }

    delay(10);
  } while (line_dang_doc == true || tay_trai_dang_nang == true);
}

void chay_ve_bat_line_nang_tay_phai_20(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  bool tay_phai_dang_nang = true;
  bool line_dang_doc = true;

  unsigned long bat_dau_nang_tay = millis();  // Lấy thời gian bắt đầu
  unsigned long thoi_gian_nang_tay = 2000;    // Thời gian nâng tay là 6,8 giây (6800ms)

  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;

  do {
    // Đọc trạng thái cảm biến line
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);

    // Điều khiển robot chạy đọc line
    if (tt_cam_bien0 == 0 || tt_cam_bien1 == 0) {
      dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
    } else {
      line_dang_doc = false;
      dung_dong_co();  // Dừng động cơ khi hoàn thành đọc line
    }

    // Nâng tay phải nếu chưa hết 2 giây
    if (millis() - bat_dau_nang_tay <= thoi_gian_nang_tay) {
      dk_nang_tay_phai();
    } else {
      tay_phai_dang_nang = false;
      dk_dung_dong_co_nang();  // Dừng động cơ nâng tay khi hết thời gian
    }

    delay(10);
  } while (line_dang_doc == true || tay_phai_dang_nang == true);
}


void chay_bat_line_nang_tay_trai_30(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  bool tay_trai_dang_nang = true;
  bool line_dang_doc = true;

  unsigned long bat_dau_nang_tay = millis();  // Lấy thời gian bắt đầu
  unsigned long thoi_gian_nang_tay = 7000;    // Thời gian nâng tay là 6,8 giây (6800ms)

  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;

  do {
    // Đọc trạng thái cảm biến line
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);

    // Điều khiển robot chạy đọc line
    if (tt_cam_bien0 == 0 || tt_cam_bien1 == 0) {
      dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
    } else {
      line_dang_doc = false;
      dung_dong_co();  // Dừng động cơ khi hoàn thành đọc line
    }

    // Nâng tay phải nếu chưa hết 6,8 giây
    if (millis() - bat_dau_nang_tay <= thoi_gian_nang_tay) {
      dk_nang_tay_trai();
    } else {
      tay_trai_dang_nang = false;
      dk_dung_dong_co_nang();  // Dừng động cơ nâng tay khi hết thời gian
    }

    delay(10);
  } while (line_dang_doc == true || tay_trai_dang_nang == true);
}
