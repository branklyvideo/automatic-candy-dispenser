// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 400;
const int button = 4;
const int sensors = 5;
const int enable = 10;
const int audio = 6;
const int bowl = 7;
int back = 0;

void setup()
{
  Serial.begin(115200);
  // Declare pins as InOutputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(button, INPUT);
  pinMode(sensors, INPUT);
  pinMode(enable, OUTPUT);
  pinMode(audio, OUTPUT);
  pinMode(bowl, OUTPUT);
  digitalWrite(enable, HIGH);
  digitalWrite(audio, HIGH);
  digitalWrite(bowl, LOW);
}
void loop()
{
  
  if (digitalRead(button) == 1) {
    Serial.print("Button: ");
    Serial.println(digitalRead(button));
    Serial.print("Sensors: ");
    Serial.println(digitalRead(sensors));

    digitalWrite(dirPin, LOW);
    digitalWrite(enable, LOW);

    digitalWrite(audio, LOW);
    delay(1000);
    digitalWrite(audio, HIGH);
    delay(4000);
    while (digitalRead(sensors) == 1) {
      spinMotor();
      Serial.println("Spin");
    }
    digitalWrite(bowl, HIGH);
    delay(500);
    digitalWrite(dirPin, HIGH);
    back = 300;
    while (back > 0) {
      spinMotor();
      Serial.println("Spin back");
      back--;
    }

    
    digitalWrite(enable, HIGH);
    delay(20000);
    digitalWrite(bowl, LOW);
  }
  
  // Spin motor quickly

  
  
}

void spinMotor() {

    digitalWrite(stepPin, HIGH);
    delayMicroseconds(3000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(3000);
}
