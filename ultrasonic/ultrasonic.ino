const int trigPin = 9; // Пин Trig
const int echoPin = 10; // Пин Echo
const int red = 11;
const int green = 6;
const int blue =5;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(trigPin, OUTPUT); // Trig как выход
  pinMode(echoPin, INPUT);  // Echo как вход
  Serial.begin(9600);       // Открываем Serial Monitor
}

void loop() {
  long duration; // Время полёта сигнала
  int distance;  // Расстояние до объекта

  // Посылаем ультразвуковой импульс
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Измеряем длительность сигнала, вернувшегося на Echo
  duration = pulseIn(echoPin, HIGH);

  // Рассчитываем расстояние (см)
  distance = duration * 0.0343 / 2;

  // Выводим результат
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(10); // Задержка между измерениями

  if(distance <= 30){
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    delay(500);
  } else{
    for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(red, brightness);
    analogWrite(green, 255 - brightness);
    analogWrite(blue, brightness / 2); // Синий увеличивается медленно
    delay(7);
    }

    // digitalWrite(red, LOW);
    // digitalWrite(green, HIGH);
    // delay(500);
  }
}