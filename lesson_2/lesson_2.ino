int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() { // плавная смена цвета

  // RED <<<
    for(int brightness = 0; brightness >= 255; brightness++){
      analogWrite(redPin, brightness);
      delay(7);
    }
    for(int brightness = 255; brightness >= 0; brightness--){
      analogWrite(redPin, brightness);
      delay(7);
    }
     
     // Blue
    for(int brightness = 0; brightness <= 200; brightness++){
      analogWrite(bluePin, brightness);
      delay(7);
    }

    for(int brightness = 200; brightness >= 0; brightness--){
      analogWrite(bluePin, brightness);
      delay(7);
    }

     // Green
    for(int brightness = 0; brightness <= 200; brightness++){
      analogWrite(greenPin, brightness);
      delay(7);
    }
    
    for(int brightness = 200; brightness >= 0; brightness--){
      analogWrite(greenPin, brightness);
      delay(7);
    }

}