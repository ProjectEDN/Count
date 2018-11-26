const int anode_a = 13;
const int anode_b = 14;
const int anode_c = 15;
const int anode_d = 16;
const int anode_e = 17;
const int anode_f = 18;
const int anode_g = 19;
const int buttonPin = 27;
int buttonState = 0;

void display_0() {
  digitalWrite(anode_a, HIGH);
  digitalWrite(anode_b, HIGH);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, HIGH);
  digitalWrite(anode_e, HIGH);
  digitalWrite(anode_f, HIGH);
  digitalWrite(anode_g, LOW);
}
 
void display_1() {
  digitalWrite(anode_a, LOW);
  digitalWrite(anode_b, HIGH);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, LOW);
  digitalWrite(anode_e, LOW);
  digitalWrite(anode_f, LOW);
  digitalWrite(anode_g, LOW);
}
 
void display_2() {
  digitalWrite(anode_a, HIGH);
  digitalWrite(anode_b, HIGH);
  digitalWrite(anode_c, LOW);
  digitalWrite(anode_d, HIGH);
  digitalWrite(anode_e, HIGH);
  digitalWrite(anode_f, LOW);
  digitalWrite(anode_g, HIGH);
}
 
void display_3() {
  digitalWrite(anode_a, HIGH);
  digitalWrite(anode_b, HIGH);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, HIGH);
  digitalWrite(anode_e, LOW);
  digitalWrite(anode_f, LOW);
  digitalWrite(anode_g, HIGH);
}
 
void display_4() {
  digitalWrite(anode_a, LOW);
  digitalWrite(anode_b, HIGH);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, LOW);
  digitalWrite(anode_e, LOW);
  digitalWrite(anode_f, HIGH);
  digitalWrite(anode_g, HIGH);
}
 
void display_5() {
  digitalWrite(anode_a, HIGH);
  digitalWrite(anode_b, LOW);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, HIGH);
  digitalWrite(anode_e, LOW);
  digitalWrite(anode_f, HIGH);
  digitalWrite(anode_g, HIGH);
}
 
void display_6() {
  digitalWrite(anode_a, HIGH);
  digitalWrite(anode_b, LOW);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, HIGH);
  digitalWrite(anode_e, HIGH);
  digitalWrite(anode_f, HIGH);
  digitalWrite(anode_g, HIGH);
}
 
void display_7() {
  digitalWrite(anode_a, HIGH);
  digitalWrite(anode_b, HIGH);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, LOW);
  digitalWrite(anode_e, LOW);
  digitalWrite(anode_f, HIGH);
  digitalWrite(anode_g, LOW);
}
void display_8() {
  digitalWrite(anode_a, HIGH);
  digitalWrite(anode_b, HIGH);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, HIGH);
  digitalWrite(anode_e, HIGH);
  digitalWrite(anode_f, HIGH);
  digitalWrite(anode_g, HIGH);
}
 
void display_9() {
  digitalWrite(anode_a, HIGH);
  digitalWrite(anode_b, HIGH);
  digitalWrite(anode_c, HIGH);
  digitalWrite(anode_d, HIGH);
  digitalWrite(anode_e, LOW);
  digitalWrite(anode_f, HIGH);
  digitalWrite(anode_g, HIGH);
}
/*
int display_x(int x) {
  switch(x) {
    case 0: display_0();
    case 1: display_1();
    case 2: display_2();
    case 3: display_3();
    case 4: display_4();
    case 5: display_5();
    case 6: display_6();
    case 7: display_7();
    case 8: display_8();
    case 9: display_9();
    default:display_0();
  }
}
*/
int x=1;

// setup()　は、最初に一度だけ実行される
void setup () {
  // ピンを出力モードに設定する
  pinMode(anode_a, OUTPUT);
  pinMode(anode_b, OUTPUT);
  pinMode(anode_c, OUTPUT);
  pinMode(anode_d, OUTPUT);
  pinMode(anode_e, OUTPUT);
  pinMode(anode_f, OUTPUT);
  pinMode(anode_g, OUTPUT);
  pinMode(buttonPin, INPUT);
}
 
// loop() は、setup ()実行後、無限に実行される
void loop() {
  buttonState = digitalRead(buttonPin);
  //display_x(x);
  switch(x) {
    case 0: display_0();break;
    case 1: display_1();break;
    case 2: display_2();break;
    case 3: display_3();break;
    case 4: display_4();break;
    case 5: display_5();break;
    case 6: display_6();break;
    case 7: display_7();break;
    case 8: display_8();break;
    case 9: display_9();break;
    default:display_0();break;
  }
  if (buttonState == LOW) {     
    x = x+1;
    delay(500);
  }
}
