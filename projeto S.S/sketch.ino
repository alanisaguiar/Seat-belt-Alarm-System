const int trocadorCinto = 14;     //pino do slide
const int potenciometroPin = 25;  //pino do potenciometro  
const int ledPin = 12;            //pino do LED

void setup() {
  pinMode(trocadorCinto, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int trocarCinto = digitalRead(trocadorCinto);  //le o estado do pino de slide
  int velocidade = analogRead(potenciometroPin); //le a velocidade simulada           

  Serial.print("Velocidade: ");
  Serial.println(map(velocidade, 0, 1023, 0, 100)); //mapeia a leitura do potenciometro para 0-100km/h

  //verifica se o passageiro nao esta usando o cinto e se a velocidade é maior que 10km/h
  if (trocarCinto == LOW && map(velocidade, 0, 1023, 0, 100) > 10) {
    digitalWrite(ledPin, HIGH); //ativa o LED (aciona o alarme)
    Serial.println("Atenção: Passageiro sem cinto de segurança e com a velocidade acima de 10 km/h!");
  } else {
    digitalWrite(ledPin, LOW);  //desativa o LED (desativa o alarme)
  }

  delay(1000); //espera 1 segundo antes de verificar novamente
}
