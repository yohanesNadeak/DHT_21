#include <SD.h>                //Library Micro SD
#include <FS.h>                //Library Micro SD
#include <Wire.h>              //Library komunikasi I2C
#include "RTClib.h"            //library RTC
#include "variabel.h"          //Variabel data tanggal
#include <Adafruit_GFX.h>      //Library mengelolah tampilan Oled
#include <Adafruit_SSD1306.h>  //Library mengelolah tampilan Oled
#include "DHT.h"               //Library sensor Dht 22

#define uS_TO_S_FACTOR 1000000ULL  //mengonversi waktu dari mikrodetik ke detik.
#define TIME_TO_SLEEP 100            //waktu dalam detik (5 detik) esp akan tidur
RTC_DATA_ATTR int bootCount = 0;   //menghitung jumlah kali perangkat telah booting.

#define SCREEN_WIDTH 128                                                   //Panjang Oled
#define SCREEN_HEIGHT 64                                                   //Lebar Oled
#define OLED_RESET -1                                                      //pin reset untuk layar OLED
#define DHT21_PIN 33                                                       //Pin DHT 21
#define SCREEN_ADDRESS 0x3C                                                //Alamat komunikasi I2C
#define LOGO_HEIGHT 128                                                    //Ukuran panjang logo pada oled
#define LOGO_WIDTH 64                                                      //Ukuran Lebar logo pada oled
RTC_DS3231 rtc;                                                            //Objek RTC
File myFile;                                                               //Objek MICRO SD
DHT dht21(DHT21_PIN, DHT21);                                               //Inisiasi Objek DHT 21
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);  // mendefinisikan dimensi layar OLED (128x64 piksel)

void print_wakeup_reason();

void setup() {
  Serial.begin(115200);  //Memulai komunikasi Serial
 // espmauBobo();
 logoo();
  intOled();             //Menghubungkan ke oled
  logo();                //Menampilkan Logo pada oled
  intRtc();              //Menghubungkan ke RTC
  intMicroSD();          //Menghubungkan Ke MicroSD

  display.clearDisplay();               //Bersihkan Layar Oled
  display.setTextSize(1);               //Ukuran teks Pada Oled
  display.setTextColor(SSD1306_WHITE);  //Warna Pada Teks Oled

  ambilWaktu();                //Mengambil waktu
  tampilWaktu();               //Menampilkan waktu
  display.setCursor(0, 20);    //Atur posisi teks pada oled
  display.println(F("Suhu"));  //menampilkan SUHU
  display.setCursor(30, 20);   //Atur posisi teks pada oled
  display.println(F("="));     //menampilkan =
  display.setCursor(90, 20);   //Atur posisi Teks pada Oled
  display.println(F("°C"));    //menampilkan °C pada oled

  //display.setCursor(60, 20);
  //display.print(F(humi));

  display.setCursor(0, 40);     //Atur posisi teks pada oled
  display.println(F("Humid"));  //menampilkan Humid
  display.setCursor(35, 40);    //Atur posisi teks pada oled
  display.println(F("="));      //menampilkan =
  display.setCursor(90, 40);    //Atur posisi teks pada oled
  display.println(F("%"));      //menampilkan %
  display.display();            //Tampilkan semuanya
// espBobo();
}

void loop() {
  // ambilWaktu();
  
  // ambilDatawaktu();
  espmauBobo();
  sensorDHT();    //Membaca sensor DHT
  tampilWaktu();  //Menampilkan waktu
  tampilkanSuhu();
   simpanDatawaktu();
  delay(800);  //jeda 0,2 detik
  espBobo();
}