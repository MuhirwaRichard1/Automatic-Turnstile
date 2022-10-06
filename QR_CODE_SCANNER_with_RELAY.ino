
int relaypin=3;
int relay1 =11;
int relay2=12;

int val;
boolean buttonState = LOW;

void setup(){
  Serial.begin(9600);
  pinMode(relaypin, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  }
  
void loop(){
Serial.println(buttonState);
//Serial.println(relaypin);
  if( debounceButton(buttonState) == 1 ){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    delay(420);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    delay(6000);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    delay(450);
    }
    else{digitalWrite(relay1, LOW);
         digitalWrite(relay2, LOW);
    }

  delay(100);
  }
    boolean debounceButton(boolean state){
      boolean stateNow = digitalRead(relaypin);
      if(state != stateNow){
        delay(10);
        stateNow = digitalRead(relaypin);
        }
        return stateNow;
      }
  
