//****bố trí bánh xe****//
//bánh 1 -------- bánh 2
//bánh 3 -------- bánh 4
//****bố trí cảm biến****//
//trước:  A12-A13-A14-A15-49-48
//sau:    35-34-33-32-31-30
//phải:   47-46-45-44-43-42
//trái:   41-40-39-38-37-36
#include <Servo.h>

Servo servo_trai_truoc;
Servo servo_trai_sau;
Servo servo_phai_truoc;
Servo servo_phai_sau;

#define nut_do A8
#define nut_xa A9

#define pwm1_lui 7
#define pwm1_toi 6
#define pwm2_lui 5
#define pwm2_toi 4
#define pwm3_lui 11
#define pwm3_toi 10
#define pwm4_lui 9
#define pwm4_toi 8

#define cb_0 42
#define cb_1 43
#define cb_2 44
#define cb_3 45
#define cb_4 46
#define cb_5 47

#define cam_bien_tay_phai A11
#define cam_bien_tay_trai A10

#define encoder1 2  //pwm4
#define encoder2 3  //pwm3
// #define encoder3     18
// #define encoder4     19

#define cb_truoc 1

#define chay_toi 1
#define chay_trai 2
#define chay_phai 3
#define chay_lui 4
#define chay_cheo_trai 5
#define chay_cheo_phai 6
#define chay_xoay_phai 7
#define chay_xoay_trai 8
#define dung_dong_co_chay 9

#define quay_trai 1
#define quay_phai 2

int cho_phep = 0;
int sensor[6] = { 0, 0, 0, 0, 0, 0 };

int error, previous_error;
float P, I, D, kp = 25, ki = 0.0001, kd = 250;
int PID_value, PID_phai, PID_trai;
float P1, I1, D1;
int error1, previous_error1;
int PID_value_1, PID_phai_1, PID_trai_1;
int gia_tri_dau_phai = 180;
int gia_tri_dau_trai = 180;
float goc_dat = 281;
volatile int xung_encoder1, xung_encoder2, xung_encoder3, xung_encoder4;

void doc_encoder1()  //ngắt 0, chân 2
{
  xung_encoder1++;
}
void doc_encoder2()  //ngắt 1, chân 3
{
  xung_encoder2++;
}
void doc_encoder3()  //ngắt 4, chân 19
{
  xung_encoder3++;
}
void doc_encoder4()  //ngắt 5, chân 18
{
  xung_encoder4++;
}
void setup() {
  Serial.begin(9600);
  pinMode(encoder1, INPUT);
  pinMode(encoder2, INPUT);
  digitalWrite(encoder1, HIGH);
  digitalWrite(encoder2, HIGH);
  attachInterrupt(0, doc_encoder1, RISING);  //ngắt 0, chân 2
  attachInterrupt(1, doc_encoder2, RISING);  //ngắt 1, chân 3
  //  attachInterrupt(4, doc_encoder3, RISING);  //ngắt 4, chân 19
  // attachInterrupt(5, doc_encoder4, RISING);  //ngắt 5, chân 18
  pinMode(nut_do, INPUT);
  pinMode(nut_xa, INPUT);

  for (int i = 4; i < 14; i++) { pinMode(i, OUTPUT); }
  for (int i = 30; i < 50; i++) { pinMode(i, INPUT); }
  // pinMode(A12, INPUT);
  // pinMode(A13, INPUT);
  // pinMode(A14, INPUT);
  // pinMode(A15, INPUT);

  for (int i = 4; i < 14; i++) { analogWrite(i, 0); }
  analogWrite(pwm1_toi, 0);
  analogWrite(pwm2_toi, 0);
  analogWrite(pwm3_toi, 0);
  analogWrite(pwm4_toi, 0);
  // delay(500);
  servo_trai_truoc.attach(A15);
  servo_trai_sau.attach(A14);
  servo_phai_truoc.attach(A13);
  servo_phai_sau.attach(A12);
  // servo5.attach(A1);
  // servo6.attach(A2);
  // khoi_dong_servo();
  // delay(2000);
}
/*
 CÁC ĐỊNH NGHĨA:

 CÁC CHƯƠNG TRÌNH CON:

 */

void loop() {
  // doi_do();
  servo_phai_truoc.write(83);
}

void doi_xanh() {
  // => Chiến thắng tuyệt đối
  //Xuất phát gắp bóng bỏ 2 bóng vào silo3
  chay_do_encoder(chay_toi, 5850, 1, 103, 100);
  delay(100);
  chay_bat_line_doc_cam_bien(chay_cheo_phai, 100, 100, cb_2, cb_3);

  delay(500);
  quay_robo_90_trai(150);
  delay(500);
  quay_robo_180_trai(150);
  delay(500);
  chay_do_encoder(chay_toi, 3750, 1, 100, 100);
  delay(500);
  chay_bat_line_doc_cam_bien(chay_phai, 100, 100, cb_2, cb_3);
  delay(500);

  quay_robo_90_trai(150);
  delay(500);
  quay_robo_180_trai(150);

  //Chạy về gắp bóng bỏ 1 bóng vào slio3 và 1 bóng vào silo2
  delay(500);
  quay_robo_180_trai(150);
  delay(50);
  chay_do_encoder(chay_toi, 100, 1, 125, 125);
  delay(50);
  chay_bat_line_doc_cam_bien(chay_trai, 100, 100, cb_2, cb_3);

  delay(500);
  quay_robo_90_trai(150);
  delay(500);
  quay_robo_180_trai(150);
  delay(500);
  chay_do_encoder(chay_toi, 3750, 1, 100, 100);
  delay(500);
  chay_bat_line_doc_cam_bien(chay_phai, 100, 100, cb_2, cb_3);
  delay(500);

  quay_robo_90_trai(150);
  delay(500);
  quay_robo_90_phai(150);
  delay(500);
  chay_do_encoder(chay_phai, 100, 1, 125, 125);
  chay_bat_line_doc_cam_bien(chay_phai, 100, 100, cb_2, cb_3);
  delay(500);
  quay_robo_90_phai(150);

  //Chạy về gắp 1 bóng bỏ bóng vào slio1
  delay(500);
  quay_robo_90_trai(150);
  delay(500);
  chay_do_encoder(chay_trai, 100, 1, 125, 125);
  chay_bat_line_doc_cam_bien(chay_trai, 100, 100, cb_2, cb_3);
  delay(500);
  quay_robo_90_trai(150);
  delay(500);
  chay_do_encoder(chay_toi, 100, 1, 125, 125);
  delay(50);
  chay_bat_line_doc_cam_bien(chay_trai, 100, 100, cb_2, cb_3);

  delay(500);
  quay_robo_90_trai(150);
  delay(500);
  quay_robo_180_trai(150);
  delay(500);
  chay_do_encoder(chay_toi, 3750, 1, 100, 100);
  delay(500);
  chay_bo_qua_2_line(chay_phai, 100, 100, cb_2, cb_3);
  delay(500);

  quay_robo_90_trai(150);
  delay(500);
  quay_robo_180_trai(150);

  while (1)
    ;
}
void doi_do() {
  //Xuất phát gắp bóng bỏ 2 bóng vào silo3
  //*******
  chay_do_encoder(chay_toi, 5850, 1, 103, 100);
  delay(100);
  chay_bat_line_doc_cam_bien(chay_cheo_trai, 100, 100, cb_2, cb_3);

  delay(500);
  quay_robo_90_phai(150);
  // => mở cánh tay và phải
  //tay trái //  => hạ cạnh tay => kẹp bóng => nâng tay lên 50%
  delay(500);
  quay_robo_180_phai(150);
  //tay phải
  //  => hạ cạnh tay => kẹp bóng => nâng tay lên 50%
  delay(500);
  chay_do_encoder(chay_toi, 3900, 1, 103, 100);
  delay(500);
  chay_bat_line_doc_cam_bien(chay_trai, 103, 100, cb_2, cb_3);
  delay(500);

  quay_robo_90_phai(150);
  delay(500);
  quay_robo_180_phai(150);
  //*******


  //Chạy về gắp bóng bỏ 1 bóng vào slio3 và 1 bóng vào silo2
  //*******
  delay(500);
  quay_robo_phai(150, 2200);
  delay(500);
  chay_do_encoder(chay_toi, 50, 1, 125, 125);
  delay(500);
  chay_bat_line_doc_cam_bien(chay_phai, 108, 100, cb_3, cb_3);

  delay(500);
  quay_robo_90_phai(150);
  delay(500);
  quay_robo_180_phai(150);
  delay(500);
  chay_do_encoder(chay_toi, 4100, 1, 108, 100);
  delay(500);
  chay_bat_line_doc_cam_bien(chay_trai, 103, 100, cb_2, cb_3);
  delay(500);

  quay_robo_90_phai(150);
  delay(500);
  quay_robo_90_trai(150);
  delay(500);
  chay_do_encoder(chay_trai, 100, 1, 125, 125);
  chay_bat_line_doc_cam_bien(chay_trai, 103, 100, cb_2, cb_3);
  delay(500);
  quay_robo_90_trai(150);
  //*******

  //Chạy về gắp 1 bóng bỏ bóng vào slio1
  //*******
  delay(500);
  quay_robo_90_phai(150);
  delay(500);
  chay_do_encoder(chay_phai, 300, 1, 125, 125);
  chay_bat_line_doc_cam_bien(chay_phai, 100, 103, cb_2, cb_3);
  delay(500);
  quay_robo_phai(150, 1220);
  delay(500);
  chay_do_encoder(chay_toi, 50, 1, 125, 125);
  delay(50);
  chay_bat_line_doc_cam_bien(chay_phai, 108, 100, cb_2, cb_3);

  delay(500);
  quay_robo_90_phai(150);
  delay(500);
  quay_robo_180_phai(150);
  delay(500);
  chay_do_encoder(chay_toi, 4000, 1, 103, 100);
  delay(500);
  chay_bat_line_doc_cam_bien(chay_trai, 100, 103, cb_2, cb_3);
  delay(100);
  chay_do_encoder(chay_trai, 3000, 1, 100, 103);
  chay_bat_line_doc_cam_bien(chay_trai, 100, 103, cb_2, cb_3);
  delay(500);

  quay_robo_90_phai(150);
  delay(500);
  quay_robo_180_phai(150);
  //*******

  while (1)
    ;
}
