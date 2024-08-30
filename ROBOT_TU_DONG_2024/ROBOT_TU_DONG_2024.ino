//****bố trí bánh xe****//
//bánh 1 -------- bánh 2
//bánh 3 -------- bánh 4
//****bố trí cảm biến****//
//trước:  A12-A13-A14-A15-49-48
//sau:    35-34-33-32-31-30
//phải:   47-46-45-44-43-42
//trái:   41-40-39-38-37-36
#include <Servo.h>

Servo servo_trai_sau;
Servo servo_trai_truoc;
Servo servo_phai_truoc;
Servo servo_phai_sau;

#define cam_bien_tay_phai A11
#define cam_bien_tay_trai A10

#define nut_do 24
#define nut_xanh 22

#define ct_trai 28
#define ct_phai 26

#define pwm1_lui 7
#define pwm1_toi 6
#define pwm2_lui 5
#define pwm2_toi 4
#define pwm3_lui 11
#define pwm3_toi 10
#define pwm4_lui 9
#define pwm4_toi 8

#define pwm_nang_tay_lui 12
#define pwm_nang_tay_toi 13

#define cb_0 42
#define cb_1 43
#define cb_2 44
#define cb_3 45
#define cb_4 46
#define cb_5 47

#define cb_phat_hien_bong A3
#define cb_dau_phai A1
#define cb_dau_trai A2



#define encoder1 2           //pwm4
#define encoder2 3           //pwm3
#define encoder_nang_tay 18  //pwm_nang_tay
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

#define nang_tay_trai 10
#define nang_tay_phai 11

#define quay_trai 1
#define quay_phai 2

#define san_do 30
#define san_xanh 31

int silo_1_2 = 12;
int silo_2_3 = 23;
int silo_3 = 3;
int silo_2 = 2;
int silo_3_1 = 31;
int silo_2_1 = 21;


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
volatile int xung_encoder1, xung_encoder2, xung_encoder3, xung_encoder4, xung_encoder_nang_tay;

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
void doc_encoder_nang_tay()  //ngắt 5, chân 18
{
  xung_encoder_nang_tay++;
}
void setup() {
  Serial.begin(9600);
  pinMode(encoder1, INPUT);
  pinMode(encoder2, INPUT);
  pinMode(encoder_nang_tay, INPUT);

  digitalWrite(encoder1, HIGH);
  digitalWrite(encoder2, HIGH);
  //  digitalWrite(encoder3,   HIGH);
  // digitalWrite(encoder4,   HIGH);
  attachInterrupt(0, doc_encoder1, RISING);          //ngắt 0, chân 2
  attachInterrupt(1, doc_encoder2, RISING);          //ngắt 1, chân 3
  attachInterrupt(5, doc_encoder_nang_tay, RISING);  //ngắt 1, chân 3
  //  attachInterrupt(4, doc_encoder3, RISING);  //ngắt 4, chân 19
  // attachInterrupt(5, doc_encoder4, RISING);  //ngắt 5, chân 18
  pinMode(nut_do, INPUT_PULLUP);
  pinMode(nut_xanh, INPUT_PULLUP);
  pinMode(cam_bien_tay_trai, INPUT_PULLUP);
  pinMode(cam_bien_tay_phai, INPUT_PULLUP);
  pinMode(cb_phat_hien_bong, INPUT_PULLUP);

  pinMode(ct_trai, INPUT_PULLUP);
  pinMode(ct_phai, INPUT_PULLUP);

  for (int i = 4; i < 14; i++) { pinMode(i, OUTPUT); }
  for (int i = 30; i < 50; i++) { pinMode(i, INPUT); }

  for (int i = 4; i < 14; i++) { analogWrite(i, 0); }
  analogWrite(pwm1_toi, 0);
  analogWrite(pwm2_toi, 0);
  analogWrite(pwm3_toi, 0);
  analogWrite(pwm4_toi, 0);
  // delay(500);
  servo_trai_truoc.attach(38);
  servo_trai_sau.attach(39);
  servo_phai_truoc.attach(40);
  servo_phai_sau.attach(41);
  // delay(2000);

  kep_tay_phai();
  kep_tay_trai();
  delay(100);
  mo_tay_trai();
  mo_tay_phai();

  khoi_dong_nang_tay();

  pinMode(cb_dau_phai, INPUT_PULLUP);
  pinMode(cb_dau_trai, INPUT_PULLUP);
}
/*
 CÁC ĐỊNH NGHĨA:
 xu_ly_hanh_dong_chay_tha_bong(silo cần bỏ bóng);
 CÁC CHƯƠNG TRÌNH CON:

 */

void xu_ly_chien_thuat(int ten_san) {
  int cb_trai = digitalRead(ct_trai);
  int cb_phai = digitalRead(ct_phai);
  switch (ten_san) {
    case san_do:
      if (cb_trai == 0 && cb_phai == 1) {  // Xử lý khi cb_trai tắt và cb_phai bật
        ct_1_doi_do();
      } else if (cb_trai == 1 && cb_phai == 0) {  // Xử lý khi cb_trai bật và cb_phai tắt
        ct_2_doi_do();
      } else if (cb_trai == 0 && cb_phai == 0) {  // Xử lý khi cả cb_trai và cb_phai đều tắt
        doi_do();
      } else {
        // Xử lý khi cả cb_trai và cb_phai đều bật
      }
      break;
    case san_xanh:
      if (cb_trai == 0 && cb_phai == 1) {  // Xử lý khi cb_trai tắt và cb_phai bật
        ct_1_doi_xanh();
      } else if (cb_trai == 1 && cb_phai == 0) {  // Xử lý khi cb_trai bật và cb_phai tắt
        ct_2_doi_xanh();
      } else if (cb_trai == 0 && cb_phai == 0) {  // Xử lý khi cả cb_trai và cb_phai đều tắt
        doi_xanh();
      } else {
        // Xử lý khi cả cb_trai và cb_phai đều bật
      }
      break;
  }
}

void loop() {
  int cb_do = digitalRead(nut_do);
  int cb_xanh = digitalRead(nut_xanh);
  if (cb_do == 1) xu_ly_chien_thuat(san_do);
  if (cb_xanh == 1) xu_ly_chien_thuat(san_xanh);
}
