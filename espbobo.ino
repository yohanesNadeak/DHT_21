
void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;      //menyimpan jenis penyebab bangun dari tidur.
  wakeup_reason = esp_sleep_get_wakeup_cause();//penyebab bangun terakhir dan menyimpannya dalam variabel
//untuk menentukan tindakan berdasarkan penyebab bangun.
  switch(wakeup_reason)                        
  {
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;  //jika ada sinyal eksternal pada pin RTC_IO
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;//jika ada sinyal eksternal pada pin RTC_CNTL
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;              //Jika penyebabnya adalah timer
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;        //jika terjadi interaksi dengan touchpad(sentuhan)
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;          // jika penyebabnya program ULP (Ultra Low Power)
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;  //Jika penyebab bangun tidak termasuk dalam kategori 
  }
}

void espmauBobo(){
   ++bootCount;        //Meningkatkan nilai bootCount setiap kali perangkat dinyalakan.
  Serial.println("Boot number: " + String(bootCount)); //Mencetak nomor boot saat ini ke Serial Monitor.
  print_wakeup_reason();      //untuk menampilkan alasan bangun terakhir.
//Mengatur timer untuk membangunkan ESP32 setelah periode waktu yang ditentukan
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR); 
//Mencetak informasi bahwa ESP32 diatur untuk tidur selama periode tertentu.
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) +" Seconds");

  Serial.println("Going to sleep now"); //Mencetak pesan bahwa perangkat akan segera masuk ke mode tidur.

}
void espBobo(){
      display.clearDisplay();                     //Membersihkan Layar OLED
  display.setTextSize(2);                     //Ukuran Teks pada OLED
  display.setTextColor(SSD1306_WHITE);        //Warna text pada OLED
  display.setCursor(20, 20);                    //Posisi Teks pada OLED
  display.println(F("ESP BOBO")); 
  delay(1000);
  display.display();
  Serial.flush();                       //Menunggu hingga semua data dalam buffer serial terkirim sebelum melanjutkan.
  esp_deep_sleep_start();               //memulai mode deep sleep


}