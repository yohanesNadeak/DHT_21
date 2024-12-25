void intMicroSD() {
  while (!Serial) {  //Tunggu hingga koneksi Serial Monitor
    ;
  }
  Serial.print("Initializing SD card...");     //Mencetak pesan ke Serial Monitor
  if (!SD.begin(5)) {                          //Mencoba menginisialisasi kartu SD pada pin 5
    Serial.println("initialization failed!");  //Jika inisialisasi gagal, cetak pesan kesalahan
    while (1)
      ;  //Masuk ke loop tak terhingga untuk menghentikan eksekusi program
  }
  Serial.println("initialization done.");  //Jika inisialisasi berhasil, cetak pesan bahwa inisialisasi selesai

  display.clearDisplay();               //Membersihkan Layar OLED
  display.setTextSize(1);               //Ukuran Teks pada OLED
  display.setTextColor(SSD1306_WHITE);  //Warna text pada OLED
  display.setCursor(0, 0);              //Posisi Teks pada OLED
  display.println(F("MICRO SD AMAN"));  //Menampilkan Micro sd aman pada OLED
  display.setTextSize(2);               //Ukuran Teks pada OLED
  display.setCursor(0, 20);              //Posisi Teks pada OLED
  display.println(F("NAMA"));
  display.setCursor(20, 40);              //Posisi Teks pada OLED
  display.println(F("KELOMPOK:"));
  delay(2000);
  display.display();  //Menampilkan pada oled
}

void simpanDatawaktu() {
  //nama dari microSD
  myFile = SD.open("/waktu.txt", FILE_APPEND);  //(tidak akan menimpa file yang sudah ada)
  if (myFile) {
    float humi = dht21.readHumidity();                 // membaca nilai kelembapan dari sensor
    float tempC = dht21.readTemperature();             // membaca suhu dari sensor dalam derajat Celsius
    DateTime now = rtc.now() + TimeSpan(0, 0, 0, 20);  //mengambil waktu secara realtime
    sprintf(tanggal, "%02d/%02d/%04d %02d:%02d:%02d",  //format tanggal (MM/DD/YYYY HH:MM:SS)
            now.day(), now.month(), now.year(),        // Nilai-nilai yang diambil dari objek datetime (now)
            now.hour(), now.minute(), now.second());
    myFile.print(tanggal);             //simpan tanggal yang sudah di set ke dalam micro sd
    myFile.print(", Suhu: ");          //simpan suhu ke dalam micro sd
    myFile.print(tempC);               //simpan nilai suhu yang sudah di dapatkan ke dalam micro sd
    myFile.print(" C, Kelembapan: ");  //simpan kelembapan ke dalam micro sd
    myFile.println(humi);              //simpan nilai kelembapan ke dalam micro sd
    myFile.close();                    // Mengakhiri proses penulisan ke file kartu SD
    } else {
    // if the file didn't open, print an error:
    Serial.println("gagal membuka waktu.txt");  //jika microsd gagal maka akan menampilkan
  }
}
