#define PWMPIN 12                                                 // Третья ножка NE555
#define ZAPUSK 11                                                 // Вторая ножка NE555
#define SPEEDSERIAL 9600                                          // Скорость передачи Serial в Бодах

byte pinDISPLAYsigment[]{2,3,4,5,6,7,8,9};                        // A,B,C,D,E,F,G,DP
byte pinDISPLAYfrogment[]{A0,A1,A2,A3};                           // A0, A1, A2, A3
int ROm = 2200;                                                   // Сопротивление резистора R2

unsigned long timer = 0;                                          // Обьявление таймера для millis()
unsigned long Msek = 0;                                           // Обьявление целочисленной переменной для хранения длительности сигнала с NE555
float C = 0;                                                      // Обьявление переменной с плавующей точкой для хранения информации о ёмкости конденсатора
boolean flag,flag1 = 0;                                           // Обьявление вспомогательных флагов в ходе программы

byte sigmentsCODE[]{                                              //
  0b00000010, // 0                                                //
  0b10011110, // 1                                                //
  0b00100100, // 2                                                //
  0b00001100, // 3                                                //
  0b10011000, // 4                                                //
  0b01001000, // 5                                                //
  0b01000000, // 6                                                //
  0b00011110, // 7                                                //  Коды для отображения Цифр и Букв на индикаторе
  0b00000000, // 8                                                //
  0b00001000, // 9                                                //
  0b11111111, // Полностью отключенный индикатор                  //
  0b11100000, // t                                                //
  0b01100000, // e                                                //
  0b01001000, // s                                                //
  0b11110100  // r                                                //
};                                                                //
void setup() {
 Serial.begin(SPEEDSERIAL);                                       // Иннициализация Serial
 pinMode(PWMPIN, INPUT);                                          // Иннициализация пина считывающего сигнал с 3-ей ножки NE555
 pinMode(ZAPUSK, OUTPUT);                                         // Иннициализация пина запускающий NE555 (вторая ножка)
for(int i = 0;i<=8;i++)pinMode(pinDISPLAYsigment[i],OUTPUT);      // Иннициализация выходов сигментов
for(int i = 0;i<=3;i++)pinMode(pinDISPLAYfrogment[i],OUTPUT);     // Иннициализация выходов фрагментов
for(int i = 0;i<=8;i++)digitalWrite(pinDISPLAYsigment[i],1);      // Установка выходов дисплея в положение высокого сигнала

 zapuskNE();                                                      // Запуск NE555
}


void loop() {
 if(digitalRead(PWMPIN)){
  if ( millis() - timer >= 1){ 
   timer = millis();
   Msek++;
   if(!flag1)flag1=1;
   }
  vivodSlovo("test",'L');
  }
 else{
  if(!flag){
    
   C = (round(Msek*25500)/ROm);
   if (round(C)==0)Err1();
  else VivodQIFRA(round(C));
  } 
 } 
}
