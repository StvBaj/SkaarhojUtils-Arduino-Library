/*****************
 * Foot Pedal Test
 * (Arduino Mega Extended Breakout Shield)
 * 
 * - kasper
 */
 
int tipPin = 33;
int ringPin = 34;


// no-cost stream operator as described at 
// http://arduiniana.org/libraries/streaming/
template<class T>
inline Print &operator <<(Print &obj, T arg)
{  
  obj.print(arg); 
  return obj; 
}

bool tipDefaultState = false;
bool ringDefaultState = false;

void setup() { 
    
  // Start the Ethernet, Serial (debugging) and UDP:
  Serial.begin(9600);
  Serial << F("\n- - - - - - - -\nSerial Started\n");  
  
  // make the pushbutton's pin an input:
  pinMode(tipPin, INPUT_PULLUP);
  pinMode(ringPin, INPUT_PULLUP);
  delay(2);
  tipDefaultState = digitalRead(tipPin);
  ringDefaultState = digitalRead(ringPin);

  Serial << "FootSwitch Default State: " 
        << "Tip: " << (tipDefaultState ? "Open" : " Closed to GND")
        << " - Ring: " << (ringDefaultState ? "Open" : "Closed to GND")
        << "\n----\n\n";
  delay(2000);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial << "FootSwitch State: " 
        << "Tip: " << (tipDefaultState != digitalRead(tipPin) ? "ON!" : "OFF")
        << " - Ring: " << (ringDefaultState != digitalRead(ringPin) ? "ON!" : "OFF")
        << "\n";
  delay(10);        // delay in between reads for stability
}


