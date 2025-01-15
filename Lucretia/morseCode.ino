const int dotDuration = 200;
const int dashDuration = 600;
const int gapDuration = 200;
const int letterGap = 600; 
const int wordGap = 1400; //delay after one repitition

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(wordGap*20);
  sendMorse("xkcd1362");  
  delay(wordGap);
}

void sendMorse(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    if (c == ' ') {
      delay(wordGap);
    } else {
      sendChar(c);
      delay(letterGap);
    }
  }
}

void sendChar(char c) {
  switch (toupper(c)) {
    case 'A': dot(); dash(); break;
    case 'B': dash(); dot(); dot(); dot(); break;
    case 'C': dash(); dot(); dash(); dot(); break;
    case 'D': dash(); dot(); dot(); break;
    case 'E': dot(); break;
    case 'F': dot(); dot(); dash(); dot(); break;
    case 'G': dash(); dash(); dot(); break;
    case 'H': dot(); dot(); dot(); dot(); break;
    case 'I': dot(); dot(); break;
    case 'J': dot(); dash(); dash(); dash(); break;
    case 'K': dash(); dot(); dash(); break;
    case 'L': dot(); dash(); dot(); dot(); break;
    case 'M': dash(); dash(); break;
    case 'N': dash(); dot(); break;
    case 'O': dash(); dash(); dash(); break;
    case 'P': dot(); dash(); dash(); dot(); break;
    case 'Q': dash(); dash(); dot(); dash(); break;
    case 'R': dot(); dash(); dot(); break;
    case 'S': dot(); dot(); dot(); break;
    case 'T': dash(); break;
    case 'U': dot(); dot(); dash(); break;
    case 'V': dot(); dot(); dot(); dash(); break;
    case 'W': dot(); dash(); dash(); break;
    case 'X': dash(); dot(); dot(); dash(); break;
    case 'Y': dash(); dot(); dash(); dash(); break;
    case 'Z': dash(); dash(); dot(); dot(); break;
    case '1': dot(); dash(); dash(); dash(); dash(); break;
    case '2': dot(); dot(); dash(); dash(); dash(); break;
    case '3': dot(); dot(); dot(); dash(); dash(); break;
    case '4': dot(); dot(); dot(); dot(); dash(); break;
    case '5': dot(); dot(); dot(); dot(); dot(); break;
    case '6': dash(); dot(); dot(); dot(); dot(); break;
    case '7': dash(); dash(); dot(); dot(); dot(); break;
    case '8': dash(); dash(); dash(); dot(); dot(); break;
    case '9': dash(); dash(); dash(); dash(); dot(); break;
    case '0': dash(); dash(); dash(); dash(); dash(); break;
  }
}

void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dotDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(gapDuration);
}

void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dashDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(gapDuration);
}
