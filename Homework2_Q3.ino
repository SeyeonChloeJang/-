void setup() {
  for (int i = 2; i < 10; i++) { //2~9번 핀을 사용함
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int count = 0; // 카운트 변수 초기화
  
  while (count < 3) { // 세번 반복
    // 왼쪽에서 오른쪽으로 점등
    for (int i = 2; i < 10; i++) {
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
    }
    
    // 오른쪽에서 왼쪽으로 점등
    for (int i = 9; i >= 2; i--) {
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
    }
    
    count++; // 카운트 변수 증가
  }


  // 전구 밝기 서서히 높이기
  // ***일부 전구의 밝기가 서서히 조절되지 않았습니다. 접지를 바꾸고 전선을 바꾸거나 꽂는 위치 등을 모두 시도했으나 해결하지 못했습니다. 죄송합니다.
  for (int brightness = 0; brightness <= 255; brightness++) { // 밝기 단계 2^6 단계로 조절
    for (int i = 2; i <= 9; i++) {
      analogWrite(i, brightness);
    }
    delay(10);
  }

  // 전구 밝기 서서히 낮추기
  for (int brightness = 255; brightness >= 0; brightness--) { // 밝기 단계 2^6 단계로 조절
    for (int i = 2; i <= 9; i++) {
      analogWrite(i, brightness);
    }
    delay(10);
  }

  // 왼쪽에서 하나씩 전구 밝히기
  for (int i = 9; i > 1; i -= 1) {
    digitalWrite(i, HIGH);
    delay(200);
  }

  // 오른쪽에서 두 개씩 전구 끄기
  for (int i = 9; i > 1; i -= 2) {
    digitalWrite(i, LOW);
    digitalWrite(i - 1, LOW);
    delay(400);
  }

  // 모든 전구가 켜질 때까지 무작위 순서로 전구 켜기
  for (int i = 0; i < 8; i++) {
    int randLed = random(2, 10);
    digitalWrite(randLed, HIGH);
    delay(200);
  }

  // 모든 전구 켜지게 한 뒤 다섯 번 깜빡이기
  for (int i = 0; i < 6; i++) {
    for (int j = 2; j <= 9; j++) {
      digitalWrite(j, HIGH);
    }
    delay(500);
    for (int j = 2; j <= 9; j++) {
      digitalWrite(j, LOW);
    }
    delay(500);
  }
}