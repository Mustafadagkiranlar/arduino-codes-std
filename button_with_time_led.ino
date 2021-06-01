
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  3; // the number of the LED pin
const int ledYellow = 4;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
bool ledState = false;
bool ledState_y = true;
unsigned long t0, t1, t, tmP;
const float potM = 0.0048875855327468f;

const unsigned long maxTime = 500UL;

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  //Serial.println(buttonState);

  int potValue = analogRead(A0);
  float vx = potValue * potM;

  if (buttonState == HIGH)
  {

    Serial.println("Button pressed");
    t0 = millis();
    while (digitalRead(buttonPin) == HIGH)
    {
      delay(10);
    }
    t1 = millis();

    t = t1 - t0;

    if (t > maxTime)
    {
      ledState_y = !ledState_y;
      Serial.print("Button released for yellow State:");
      Serial.println(ledState_y ? "ON" : "OFF");
    }
    else
    {
      ledState = !ledState;
      Serial.print("Button released for red State:");
      Serial.println(ledState ? "ON" : "OFF");
    }

  }
  digitalWrite(ledPin, ledState ? HIGH : LOW);
  digitalWrite(ledYellow, ledState_y ? HIGH : LOW);
}
