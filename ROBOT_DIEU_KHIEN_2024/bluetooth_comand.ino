void bluetooth_comand(char command) {
  switch (command) {
    case 'T':
      // Di chuyển tới
      dieu_khien_robot(chay_toi);
      break;
    case 'L':
      // Di chuyển lùi
      dieu_khien_robot(chay_lui);
      break;
    case 'O':
      // Quay trái
      dieu_khien_robot(quay_trai);
      break;
    case 'R':
      // Quay phải
      dieu_khien_robot(quay_phai);
      break;
    case 'A':
      // Di chuyển ngang trái
      dieu_khien_robot(chay_trai);
      break;
    case 'P':
      // Di chuyển ngang phải
      dieu_khien_robot(chay_phai);
      break;
    case 'S':
      // Dừng động cơ
      dieu_khien_robot(dung_dong_co);

      // dừng nâng hoặc hạ tay kẹp
      nang_ha_tay_kep(dung_nang_ha_tay_kep);

      break;
    case 'N':
      // Mở kẹp phải
      mo_tay_kep(tay_kep_phai);
      break;
    case 'M':
      // Đóng kẹp phải
      dong_tay_kep(tay_kep_phai);
      break;
    case 'V':
      // Mở kẹp trái
      mo_tay_kep(tay_kep_trai);
      break;
    case 'B':
      // Đóng kẹp trái
      dong_tay_kep(tay_kep_trai);
      break;
    case 'X':
      // Nâng tay
      nang_ha_tay_kep(nang_tay_kep);
      break;
    case 'Z':
      // Hạ tay
      nang_ha_tay_kep(ha_tay_kep);
      break;
    case 'I':
      dong_tay_kep(tay_kep_trai);
      dong_tay_kep(tay_kep_phai);
    case 'U':
      mo_tay_kep(tay_kep_trai);
      mo_tay_kep(tay_kep_phai);
      break;
    case '0':
      toc_do = 100;
      break;
    case '1':
      toc_do = 150;
      break;
    case '2':
      toc_do = 200;
      break;
    case '3':
      toc_do = 250;
      break;
  }
  Serial.println(command);
}