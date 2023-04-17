#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 9 // clock 핀 설정
#define DIO 8 // 데이터 핀 설정
TM1637Display display(CLK, DIO); // 화면 초기 설정

unsigned long startTime; // 시작 시간을 저장하기 위한 변수
unsigned long endTime; // 끝나는 시간을 저장하기 위한 변수
unsigned long offTime; // 정확도 측정을 위해, 시간차를 저장하기 위한 변수
unsigned long expectedTime = 10L * 60L * 1000L; // milliseconds로 제대로 흘러야 하는 시간을 계산함

void setup() {
  display.setBrightness(3); // 화면 밝기 설정
}

void loop() {
  startTime = millis(); // 시작한 시간을 millisecond 단위로 저장
  int minutes = 10; // 10분 설정
  int seconds = 0; // 0초 설정
  
  while (minutes >= 0) { // 10분 간 아래 내용을 루프
    display.showNumberDecEx(minutes * 100 + seconds, 0b01000000, true);
    // 시간은 100을 곱해 앞자리에 두고, hour과 minute 사이 : 를 표시하기 위해 binary로 64를 의미하는 0b01000000을 포함시킴
    delay(1000); // 1초 간 대기
    seconds--; // 초 단위 감소시키기
    
    if (seconds < 0) { // 초가 0이 되었을 때, 분 단위를 조정
      minutes--;
      seconds = 59; // 초는 다시 59초로 설정
    }
  }
  
  endTime = millis(); // 끝난 시간을 millisecond 단위로 저장
  offTime = expectedTime - (endTime - startTime); // 제대로 흘러야 하는 시간과, 실제 흐른 시간의 차이 계산
  display.showNumberDec(offTime); 
  delay(5000); // 화면에 보인 채 5초간 정지
}
