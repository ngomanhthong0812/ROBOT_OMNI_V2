#include <Arduino.h>
#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial SerialBT;

int M1A = 26;  // PWM TRAI TRUOC
int M1B = 27;  // DIR TRAI TRUOC
int M2A = 25;  // PWM TRAI SAU
int M2B = 33;  // DIR TRAI SAU
int M3A = 2;   // PWM PHAI TRUOC
int M3B = 4;   // DIR PHAI TRUOC
int M4A = 17;  // PWM PHAI SAU
int M4B = 16;  // DIR PHAI SAU

int NANGTK = 19;
int HATK = 18;

Servo KEPT;
Servo KEPP;

int toc_do = 100;


#define nang_tay_kep 0
#define ha_tay_kep 1
#define dung_nang_ha_tay_kep 2
#define tay_kep_trai 3
#define tay_kep_phai 4

#define chay_toi 5
#define chay_lui 6
#define chay_trai 7
#define chay_phai 8
#define quay_trai 9
#define quay_phai 10
#define dung_dong_co 11

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ROBOT_CNTT");  // Đặt tên Bluetooth cho ESP32

  // Khởi tạo các chân
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(M3A, OUTPUT);
  pinMode(M3B, OUTPUT);
  pinMode(M4A, OUTPUT);
  pinMode(M4B, OUTPUT);

  pinMode(NANGTK, OUTPUT);
  pinMode(HATK, OUTPUT);

  KEPT.attach(21);
  KEPP.attach(22);

  KEPT.write(350);
  KEPP.write(210);
}

void loop() {
  if (SerialBT.available()) {        // Kiểm tra có dữ liệu từ kết nối Bluetooth không
    char command = SerialBT.read();  // Đọc một ký tự từ kết nối Bluetooth
    bluetooth_comand(command);       // Xử lý lệnh đọc được
  }
}
