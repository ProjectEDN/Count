const int anode_a = 13;
const int anode_b = 14;
const int anode_c = 15;
const int anode_d = 16;
const int anode_e = 17;
const int anode_f = 18;
const int anode_g = 19;
const int buttonPin = 27;

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

int x=0;

#include <WiFi.h>

const char* ssid     = "BlackCat";
const char* password = "01234567";

WiFiServer server(80);

// setup()　は、最初に一度だけ実行される
void setup () {
    Serial.begin(115200);
        pinMode(anode_a, OUTPUT);
        pinMode(anode_b, OUTPUT);
        pinMode(anode_c, OUTPUT);
        pinMode(anode_d, OUTPUT);
        pinMode(anode_e, OUTPUT);
        pinMode(anode_f, OUTPUT);
        pinMode(anode_g, OUTPUT);
        pinMode(buttonPin, INPUT);

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();
}
 
// loop() は、setup ()実行後、無限に実行される
void loop() {
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
  if (digitalRead(buttonPin) == LOW) {     
    x = x-1;
    while(digitalRead(buttonPin) == LOW){}
    delay(20);
  }
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            
            client.println("<!DOCTYPE html>");
            client.println("<html>");
            client.println("<head>");
            client.println("<meta name='viewport' content='initial-scale=1.5'>");
            client.println("</head>");
            client.println("<body>");
            client.println("<form method='get'>");
            client.println("<font size='4'>ESP-WROOM-32<br>");
            client.println("Wi-Fi  LED  Switch</font><br>");
            client.println("<br>");
            client.println("<font size='2'>Current value = ");
            client.print(x);
            client.println("<br>");
            client.println("<input type='submit' name=1 value='ON' style='background-color:#88ff88; color:red;'>");
            client.println("<input type='submit' name=2 value='OFF' style='background-color:black; color:white;'>");
            client.println("</form>");
            client.println("</body>");
            client.println("</html>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
        // Check
        if (currentLine.endsWith("GET /?1=ON")) {
          x = x+1;
        }
        if (currentLine.endsWith("GET /?2=OFF")) {
          x = x-1;
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
