#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 7

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration * 0.034) / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance <= 15) {
        for (int i = 0; i < 5; i++) {  //beeps in multipls of 5
            tone(BUZZER_PIN, 2000); //2khz sounds like 'peee peee' and 500 more like 'poo poo'
            delay(100);
            noTone(BUZZER_PIN);
            delay(100);
        }
    } else {
        noTone(BUZZER_PIN);
    }

    delay(200);
}
