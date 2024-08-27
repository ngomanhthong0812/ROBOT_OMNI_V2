void dieu_khien_robot(int huong) {
  switch (huong) {
    case chay_toi:
      // Di chuyển tới
      analogWrite(M1A, toc_do);
      analogWrite(M1B, 0);
      analogWrite(M2A, toc_do);
      analogWrite(M2B, 0);
      analogWrite(M3A, toc_do);
      analogWrite(M3B, 0);
      analogWrite(M4A, toc_do);
      analogWrite(M4B, 0);
      break;
    case chay_lui:
      // Di chuyển lùi
      analogWrite(M1A, 0);
      analogWrite(M1B, toc_do);
      analogWrite(M2A, 0);
      analogWrite(M2B, toc_do);
      analogWrite(M3A, 0);
      analogWrite(M3B, toc_do);
      analogWrite(M4A, 0);
      analogWrite(M4B, toc_do);
      break;
    case chay_trai:
      // Di chuyển ngang trái
      analogWrite(M1A, toc_do);
      analogWrite(M1B, 0);
      analogWrite(M2A, 0);
      analogWrite(M2B, toc_do);
      analogWrite(M3A, 0);
      analogWrite(M3B, toc_do);
      analogWrite(M4A, toc_do);
      analogWrite(M4B, 0);
      break;
    case chay_phai:
      // Di chuyển ngang phải
      analogWrite(M1A, 0);
      analogWrite(M1B, toc_do);
      analogWrite(M2A, toc_do);
      analogWrite(M2B, 0);
      analogWrite(M3A, toc_do);
      analogWrite(M3B, 0);
      analogWrite(M4A, 0);
      analogWrite(M4B, toc_do);
      break;
    case quay_trai:
      // Quay trái
      analogWrite(M1A, toc_do);
      analogWrite(M1B, 0);
      analogWrite(M2A, toc_do);
      analogWrite(M2B, 0);
      analogWrite(M3A, 0);
      analogWrite(M3B, toc_do);
      analogWrite(M4A, 0);
      analogWrite(M4B, toc_do);
      break;
    case quay_phai:
      // Quay phải
      analogWrite(M1A, 0);
      analogWrite(M1B, toc_do);
      analogWrite(M2A, 0);
      analogWrite(M2B, toc_do);
      analogWrite(M3A, toc_do);
      analogWrite(M3B, 0);
      analogWrite(M4A, toc_do);
      analogWrite(M4B, 0);
      break;
    case dung_dong_co:
      // Dừng động cơ
      analogWrite(M1A, 0);
      analogWrite(M1B, 0);
      analogWrite(M2A, 0);
      analogWrite(M2B, 0);
      analogWrite(M3A, 0);
      analogWrite(M3B, 0);
      analogWrite(M4A, 0);
      analogWrite(M4B, 0);
      break;
    default:
      // Nếu giá trị không hợp lệ thì dừng động cơ
      analogWrite(M1A, 0);
      analogWrite(M1B, 0);
      analogWrite(M2A, 0);
      analogWrite(M2B, 0);
      analogWrite(M3A, 0);
      analogWrite(M3B, 0);
      analogWrite(M4A, 0);
      analogWrite(M4B, 0);
      break;
  }
}
