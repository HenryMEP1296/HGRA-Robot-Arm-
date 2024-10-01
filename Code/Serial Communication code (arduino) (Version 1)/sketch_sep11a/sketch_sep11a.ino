String val;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = Serial.readStringUntil("a");
  int valI = val.toInt();

 if(valI == 12) {
   digitalWrite(LED_BUILTIN, HIGH);
 } else if(val == 0) {
  digitalWrite(LED_BUILTIN, LOW);
 }


}
