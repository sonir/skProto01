const int ON = 66; //66
const int OFF = 0;

const int playPin = 11;
const int recPin = 10;

int count = 0;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);
  analogWrite(playPin, OFF);

  //rec once
  analogWrite(recPin, ON);
  delay(5000);
  analogWrite(recPin, OFF);
}

void loop() {

//rec by Serial message
  if (Serial.read() > 0) {

    analogWrite(recPin, ON);
    delay(5000);
    analogWrite(recPin, OFF);
  }


//play by

  if (analogRead(A0) > 0) {
    count++;
    Serial.println(count);
    analogWrite(playPin, ON);
    delay(10000);
    analogWrite(playPin, OFF);
  }



  /*if(Serial.read() > 0){

    analogWrite(playPin, ON);
    delay(1000);
    analogWrite(playPin, OFF);

  }*/

}
