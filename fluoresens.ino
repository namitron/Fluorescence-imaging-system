int p_out = 4;
int p_in = 10;
int uv_out = 7;
int uv_in = 12;
int potensio = A3;
int p_lcd = 8;
int led = 11;

int state = 0;
void setup() {
  Serial.begin(9600);
  pinMode(p_out, OUTPUT);
  pinMode(p_in, INPUT_PULLUP);
  pinMode(uv_out, OUTPUT);
  pinMode(uv_in, INPUT_PULLUP);
  pinMode(p_lcd, OUTPUT);
  pinMode(led, OUTPUT);



  
}

void loop() {
 p_in = digitalRead(p_in);
uv_in = digitalRead(uv_in);
 Serial.println(uv_in); 
 
 if (uv_in == LOW){
  digitalWrite(p_out, HIGH);
  Serial.println("hidup"); 
  state=1;
 }
 else {
    digitalWrite(p_out, LOW);
      Serial.println("mati"); 
 }
}
