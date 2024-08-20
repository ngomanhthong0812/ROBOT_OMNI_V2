void chay_bat_line_doc_cam_bien(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;

  dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
  do {
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);
  } while (tt_cam_bien0 == 0 || tt_cam_bien1 == 0);
  dung_dong_co();
}
void chay_bo_qua_2_line(int huong_robot, int toc_do_trai, int toc_do_phai, int cam_bien0, int cam_bien1) {
  int dem_so_line = 0;
  int tt_cam_bien0 = 0;
  int tt_cam_bien1 = 0;

  dieu_khien_dong_co(huong_robot, toc_do_trai, toc_do_phai);
  do {
    tt_cam_bien0 = digitalRead(cam_bien0);
    tt_cam_bien1 = digitalRead(cam_bien1);
    if (tt_cam_bien0 == 1 && tt_cam_bien1 == 1) {
      dem_so_line++;
    }
  } while (dem_so_line < 3);
  dung_dong_co();
}
