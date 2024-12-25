void sensorDHT() {
  dht21.begin();                          // menginisialisasi sensor DHT21
  float humi = dht21.readHumidity();      // membaca nilai kelembapan dari sensor
  float tempC = dht21.readTemperature();  // membaca suhu dari sensor dalam derajat Celsius
  //memeriksa apakah pembacaan kelembapan atau suhu menghasilkan nilai
  if (isnan(humi) || isnan(tempC)) { 
    Serial.println("Failed to read from DHT21 sensor!");  //satu dari pembacaan gagal maka akan mencetak di serial monitor
  } else {
    Serial.print("DHT21# Humidity: "); //Menampilkan kelembapan pada serial monitor
    Serial.print(humi);                //Menampilkan nilai dari kelembapan
    Serial.print("%");                 //Menampilkan persen 
    Serial.print("  |  ");             //memberi garis tengah atau pemisah
    Serial.print("Temperature: ");     //Menampilkan suhu pada serial monitor
    Serial.print(tempC);               //Menampilkan nilai dari suhu 
    Serial.print("°C");                //Menampilkan derajat dan celcius
  }
}