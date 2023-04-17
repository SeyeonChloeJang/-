// 사용할 음계를 정의해준다.
#define B3 247
#define C4 262
#define CS4 277
#define D4 294
#define DS4 311
#define E4 330
#define F4 349
#define FS4 370
#define G4 392
#define GS4 415
#define A4 440
#define AS4 466
#define B4 494

// 사용할 핀은 8번이다.
int piezoPin = 8;

// 음계를 설정한다.
int notes[] = {
  C4, B4, B4, FS4, E4, E4, B3, E4, E4, FS4, E4, 0,
  C4, B4, B4, FS4, E4, E4, B3, E4, E4, FS4, E4, 0,
  E4, B4, A4, E4, FS4, D4, D4, A4, G4, C4, 0, 0,
  B3, C4, D4, E4, FS4, G4, A4, B4, A4, DS4, 0, 0
}; 

// 핀 아웃풋을 적어준다.
void setup() {
  pinMode(piezoPin, OUTPUT);
} 

// 아래의 함수를 반복한다. 총 48개의 음이 있어 i<49로 설정
void loop() {
  for (int i = 0; i < 49; i++) {
    
    int Durations = 250; // 음의 길이는 전부 250으로 맞춰진다.
    tone(piezoPin, notes[i], Durations);   // tone 함수를 사용하여 각 음을 해당 시간동안 출력한다. 
    int pauseBetweenNotes = Durations *1.3 ; // 빠르기를 지정한다.
    delay(pauseBetweenNotes);
    noTone(piezoPin); // 한 번 연주 이후 쉬는 시간을 가진다.
  }

}