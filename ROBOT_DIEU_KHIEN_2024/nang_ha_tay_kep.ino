void nang_ha_tay_kep(int action) {
  switch (action) {
    case nang_tay_kep:
       digitalWrite(NANGTK, LOW);
      digitalWrite(HATK, HIGH);
      break;
    case ha_tay_kep:
         digitalWrite(NANGTK, HIGH);
      digitalWrite(HATK, LOW);
      break;
    case dung_nang_ha_tay_kep:
      digitalWrite(NANGTK, LOW);
      digitalWrite(HATK, LOW);
      break;

    default:
      break;
  }
}