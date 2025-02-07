#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2  // Pino do sensor de temperatura DS18B20
#define PH_PIN A0        // Pino do sensor de pH
#define MQ2_PIN A1       // Pino do sensor de gás MQ-2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
    Serial.begin(9600);
    sensors.begin();
}

void loop() {
    // Leitura do sensor de temperatura
    sensors.requestTemperatures();
    float temperatura = sensors.getTempCByIndex(0);
    
    // Leitura do sensor de pH
    int leituraPh = analogRead(PH_PIN);
    float phValue = (leituraPh * 5.0 / 1023.0) * 3.5; // Conversão simplificada
    
    // Leitura do sensor MQ-2
    int leituraMq2 = analogRead(MQ2_PIN);
    float gasValue = (leituraMq2 * 5.0) / 1023.0; // Conversão simplificada
    
    // Exibir valores no Monitor Serial
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");
    
    Serial.print("pH: ");
    Serial.println(phValue);
    
    Serial.print("Gás MQ-2: ");
    Serial.println(gasValue);
    
    Serial.println("------------------------");
    
    delay(2000); // Aguarda 2 segundos antes de nova leitura
}
