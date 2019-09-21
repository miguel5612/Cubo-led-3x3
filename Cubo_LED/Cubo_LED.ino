#include <LedCube.h>
#define SIZE 3
#define COLS (SIZE*SIZE)
byte levelPins[SIZE] = {10,11,12};
byte colPins[COLS] = {2,3,4,5,6,7,8,9,13};
byte level = 0;
byte col = 0;
LedCube cube(SIZE, levelPins, colPins);
void setup ()
{
}
void loop () {
  cube.enableBuffer(false);
  NewsEffects();
  TestLevels();
  RandColDrop();
  SingleRand();
  CircleRand();
  CycleDown();
  RandCol();
  ColInOut();
  SinglSeq();
  LineSeq();
  PlaneSeq();
  FaceToFace();
  CircleNonRandHS();
  ExtInt();
  explosion();
  for(int b=0;b<5;b++)
  {  diag();
  diag1();}
  for(int b=0;b<5;b++)
  {  slide1();
  slide2();}
  Helicopter3x3x3();
  Helicopter();
  Swiming();
  CircleNonRand(); 
  NewsEffects();
  HorizBarrel();
  HorizBarrel2();
  NE6();
  NE0();
  NE02();
  NW2();
  N0();
  N1();
  N2();
  BK0();
  BK3();
  BK6();
  OneAtTimeOff();
}
void OneAtTimeOff(){
  cube.enableBuffer();
  cube.fillBuffer();
  cube.drawBuffer(20);
    for(byte w=0, l, c, max = cube.getNumLights(); w<max; ){
      // lower bound is inclusive, upper is exclusive
      l = random(0, cube.getLevels());
      c = random(0, cube.getCols());
      if(cube.getBufferAt(l,c) == HIGH){
        cube.lightOff(l,c);
        cube.drawBuffer(4);
        w++;
      }
    }
    cube.enableBuffer(false);
}
void Swiming(){
  byte topSeq1[8] = {0,1,2,1,0,1,2,1};
  byte botSeq1[8] = {8,7,6,7,8,7,6,7};
    for(int i=0; i<3; i++){
      for(byte loops = 0, delay = 50; loops<=8; loops++){
        for(byte s=0; s<8; s++){
          byte seq[] = {i,topSeq1[s], i,4, i,botSeq1[s]};
          cube.lightSequence(seq, sizeof(seq), delay);
        } 
        if(loops < 5) delay-=10;  else delay += 10;
      }
    }
  }
void Helicopter(){
  byte topSeq2[8] = {0,3,6,7,8,5,2,1};
  byte botSeq2[8] = {8,5,2,1,0,3,6,7};
  for(int i=0; i<3; i++){
    for(byte loops = 0, delay = 50; loops<=8; loops++){
      for(byte s=0; s<8; s++){
        byte seq[] = {i,topSeq2[s], i,4, i,botSeq2[s]};
        cube.lightSequence(seq, sizeof(seq), delay);
      }
      if(loops < 5) delay-=10;  else delay += 10;
    }
  }
}
void Helicopter3x3x3(){
  byte topSeq[8] = {0,3,6,7,8,5,2,1};
  byte botSeq[8] = {8,5,2,1,0,3,6,7};
  for(byte loops = 0, delay = 50; loops<=8; loops++){
    for(byte s=0; s<8; s++){
      byte seq[] = {2,topSeq[s], 1,4, 0,botSeq[s]};
      cube.lightSequence(seq, sizeof(seq), delay);
    }
    if(loops < 5) delay-=10;  else delay += 10;
  }
}
void explosion(){
  byte diamond[] = {0,4,1,1,1,3,1,5, 1,7,2,4};
  byte middle[] = {1,4};
  byte box[] = {
        2,0, 2,1, 2,2, 2,3, 2,5, 2,6, 2,7, 2,8,
        1,0, 1,2, 1,6, 1,8,
        0,0, 0,1, 0,2, 0,3, 0,5, 0,6, 0,7, 0,8
  };
  for(byte s=0; s<8; s++){
  cube.lightSequence(middle, sizeof(middle),200);
  cube.lightSequence(diamond, sizeof(diamond),30);
  cube.lightSequence(box, sizeof(box),30);
}
}
void slide1(){
  byte prvi[] = {0,8,1,8,2,8};
  byte drugi[] = {0,7,1,7,2,7,0,5,1,5,2,5};
  byte treci[] = {0,6,1,6,2,6,0,4,1,4,2,4,0,2,1,2,2,2};
  byte cetvrti[] = {0,3,1,3,2,3,0,1,1,1,2,1};
  byte peti[] = {0,0,1,0,2,0};
  cube.lightSequence(prvi, sizeof(prvi),50);
  cube.lightSequence(drugi, sizeof(drugi),30);
  cube.lightSequence(treci, sizeof(treci),25);
  cube.lightSequence(cetvrti, sizeof(cetvrti),30);
  cube.lightSequence(peti, sizeof(peti),50);
}
void slide2(){
  byte prvi[] = {0,8,1,8,2,8};
  byte drugi[] = {0,7,1,7,2,7,0,5,1,5,2,5};
  byte treci[] = {0,6,1,6,2,6,0,4,1,4,2,4,0,2,1,2,2,2};
  byte cetvrti[] = {0,3,1,3,2,3,0,1,1,1,2,1};
  byte peti[] = {0,0,1,0,2,0};
  cube.lightSequence(peti, sizeof(peti),50);
  cube.lightSequence(cetvrti, sizeof(cetvrti),30);
  cube.lightSequence(treci, sizeof(treci),25);
  cube.lightSequence(drugi, sizeof(drugi),30);
  cube.lightSequence(prvi, sizeof(prvi),50);
}
void diag(){
  byte prvi[] = {0,8};
  byte drugi[] = {0,7,0,5,0,4,1,7,1,5,1,4,1,8};
  byte treci[] = {2,5,2,4,2,8,2,7,0,0,0,1,0,2,1,1,1,2,1
  ,3,2,0,2,1,2,2,0,3,1,3,2,3,0,6,1,6,2,6,1,0};
  byte cetvrti[] = {1,0,1,1,1,4,1,3,2,0,2,1,2,4,2,3};
  byte peti[] = {2,0};
  cube.lightSequence(prvi, sizeof(prvi),50);
  cube.lightSequence(drugi, sizeof(drugi),30);
  cube.lightSequence(treci, sizeof(treci),10);
  cube.lightSequence(cetvrti, sizeof(cetvrti),25);
  cube.lightSequence(peti, sizeof(peti),300);
}
void diag1(){
  byte prvi[] = {0,8};
  byte drugi[] = {0,7,0,5,0,4,1,7,1,5,1,4,1,8};
  byte treci[] = {2,5,2,4,2,8,2,7,0,0,0,1,0,2,1,1,1,2,1
  ,3,2,0,2,1,2,2,0,3,1,3,2,3,0,6,1,6,2,6,1,0};
  byte cetvrti[] = {1,0,1,1,1,4,1,3,2,0,2,1,2,4,2,3};
  byte peti[] = {2,0};
  cube.lightSequence(peti, sizeof(peti),50);
  cube.lightSequence(cetvrti, sizeof(cetvrti),30);
  cube.lightSequence(treci, sizeof(treci),10);
  cube.lightSequence(drugi, sizeof(drugi),25);
  cube.lightSequence(prvi, sizeof(prvi),300);
}
void ExtInt(){
  for(byte c=1, d=0; c<=10; c++){
    if(c%2 == 0){
      for(d=0; d<20; d++){
        cube.lightColumn(2,1);
        cube.lightColumn(4,1);
        cube.lightColumn(6,1);
        cube.lightColumn(8,1);
      }
    }
    else if(c%4 == 1){
      for(d=0; d<30; d++){
        cube.lightColumn(1,1);
        cube.lightColumn(3,1);
        cube.lightColumn(7,1);
        cube.lightColumn(9,1);
      }
    }
    else{
      for(d=0; d<70; d++){
        cube.lightColumn(5,1);
      }
    }
  }
}
void FaceToFace(){
  byte planes[] = {cube.getLevels()+1,cube.getLevels(),cube.getLevels()*2,1};
  for(byte i=5; i; i--){
    for(byte p=0; p<sizeof(planes); p++){
      cube.lightPlane(planes[p], 5*i);
    }
  }
}
void PlaneSeq(){
  for(byte i=3; i; i--){
    for(byte row=1; row<=cube.getLevels()*2; row++){
      cube.lightPlane(row, 10*i);
      }
    }
}
void SinglSeq(){
  for(byte level=0; level<cube.getLevels(); level++){
    for(byte col=0; col<cube.getCols(); col++){
      cube.lightPulse(level, col, 100);
    }
  }
}
void LineSeq(){
  for(byte level=1; level<=cube.getLevels(); level++){
    for(byte row=1; row<=cube.getLevels()*2; row++){
      cube.lightRow(row, level);
    }
  }
}
void CycleDown(){
  int level = 0; 
  while (level < SIZE ) {
    for(col = 0; col < COLS; col++){
      cube.lightOn(level, col);
      delay(100);
      cube.lightOff(level, col);
      delay(20);
    }
    level++;
  }
}
void TestLevels(){
  for (byte t=35; t>2; t-=2) {
    cube.lightLevel(0,t);
    cube.lightLevel(1,t);
    cube.lightLevel(2,t);
    cube.lightLevel(3,t);
  }
}
void SingleRand(){
  // single random light at a time
  while(1){
    for(int i=0; i<10; i++){
      cube.randomLight(10,66); 
    }
    break;
  }   
}
void RandColDrop(){
  // random column drop  -- spund adjusted in LedCube4x4.cpp
  for(int i=0; i<18; i++){
    cube.lightDrop((random(0,COLS)), random(20,100));          
  }
}
void CircleRand(){ 
  // circle around cube at a random level
  byte x=0;
    while (x < COLS) {
      cube.lightPerimeter(random(0,SIZE), random(1,5), random(25,100)); 
      x++;
    } 
  }
void CircleNonRand(){
  // circle around cube at a non-random level
  byte rotns = 1;
  byte pausetime = 100;
  byte x=0;
    while (x < COLS){
     for(byte level=0; level <  SIZE; level++) {
        cube.lightPerimeter(level, rotns, pausetime);
      x++;
     } 
      }
    pausetime = pausetime - 33;  
    }    
void CircleNonRandHS(){
  // circle around cube at a non-random level (high speed)
  byte rotns = 1;
  byte pausetime = 40;
  byte level = 0;
  for(int i=0; i<6; i++){
    for(byte level=0; level <  SIZE; level++){
      cube.lightPerimeter(level, rotns, pausetime);
    }
  }
}      
void RandCol(){
  cube.randomColumn(32,100); // (number of columns, wait duration)
 }
void ColInOut(){
  // cols in and out -- works in 4x4x4 cube 
  byte c=0, d=0;
  while (c <=20){
    if(c < 5){
      for(d=0; d<5; d++) {
        cube.lightColumn(1,35);
        cube.lightColumn(9,35);
        cube.lightColumn(7,35);
        cube.lightColumn(3,35);
      }
    } 
    else if(c >= 5 && c < 10) {
      for(d=0; d<5; d++) {
        cube.lightColumn(2,35);
        cube.lightColumn(8,35);
        cube.lightColumn(4,35);
        cube.lightColumn(6,35);
      }
    } 
    else if(c >= 10 && c < 15){
      for(d=0; d<5; d++) {
        cube.lightColumn(1,20);
        cube.lightColumn(2,20);
        cube.lightColumn(3,20);
        cube.lightColumn(6,20);
        cube.lightColumn(9,20);
        cube.lightColumn(8,20);
        cube.lightColumn(7,20);
        cube.lightColumn(4,20);            
      }
    }
    else{
      for(d=0; d<5; d++) {
        cube.lightColumn(1,20);
        cube.lightColumn(4,20);
        cube.lightColumn(7,20);
        cube.lightColumn(8,20);
        cube.lightColumn(9,20);
        cube.lightColumn(6,20);
        cube.lightColumn(3,20);
        cube.lightColumn(2,20);            
      }
    }
    c++;
  } 
}  
void HorizBarrel() {
  byte pauseT=4, d=0;
  for (int i=0; i<3; i++){
    for( d=0; d<pauseT; d++) {
      cube.lightRow(1, 1, 25);
      cube.lightRow(2, 1, 25);
    }
    for(d=0; d<pauseT; d++) {
      cube.lightRow(3, 1, 25);
      cube.lightRow(3, 2, 25);
    } 
    for(d=0; d<pauseT; d++) { 
      cube.lightRow(3, 3 ,25);
      cube.lightRow(2, 3, 25);
    } 
    for(d=0; d<pauseT; d++) { 
      cube.lightRow(1, 3, 25);
      cube.lightRow(1, 2, 25);
    }                  
  }
}
void HorizBarrel2() {
  byte pauseT=4, d=0;
  for (int i=0; i<3; i++){
    for( d=0; d<pauseT; d++) {
      cube.lightRow(2, 1, 25);
      cube.lightRow(1, 2, 25);
    }
    for(d=0; d<pauseT; d++) {
      cube.lightRow(2, 1, 25);
      cube.lightRow(3, 2, 25);
    } 
    for(d=0; d<pauseT; d++) { 
      cube.lightRow(3, 2 ,25);
      cube.lightRow(2, 3, 25);
    } 
    for(d=0; d<pauseT; d++) { 
      cube.lightRow(2, 3, 25);
      cube.lightRow(1, 2, 25);
    }                  
  }
}
void NewsEffects(){
  cube.enableBuffer(false);
  //NOTE: byte x [] = {layer,column,}; they run in sequence starting at #0(lowest layer/first column)
   
// a through f draws the letter o
byte a [] = {0,0, };
byte b [] = {0,0, 1,0, };
byte c [] = {0,0, 1,0, 2,0, };
byte d [] = {0,0, 1,0, 2,0, 2,1, };
byte e [] = {0,0, 1,0, 2,0, 2,1, 2,2, };
byte ee [] ={0,0, 1,0, 2,0, 2,1, 2,2, 1,2, };
byte f [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, };
// pushes the letter around the cube
byte g [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, 0,1, };
byte h [] = {0,1, 0,2, 1,1, 2,1, 2,2, 0,5, 1,5, 2,5, };
byte i [] = {0,2, 1,2, 2,2, 0,5, 2,5, 0,8, 1,8, 2,8, };
byte j [] = {1,2, 1,5, 1,8, 2,2, 2,8, 2,1, 2,4, 2,7, };
byte k [] = {2,2, 2,5, 2,8, 2,1, 2,7, 2,0, 2,3, 2,6, };
byte l [] = {2,6, 2,7, 2,8, 1,3, 1,5, 1,0, 1,1, 1,2, };
byte m [] = {2,6, 2,7, 2,8, 1,3, 1,5, 0,0, 0,1, 0,2, };
byte n [] = {2,3, 2,4, 2,5, 1,3, 1,5, 0,3, 0,4, 0,5, };
// puts letter back at beginning
byte o [] = {2,0, 2,1, 2,2, 1,2, 1,5, 0,3, 0,4, 0,5, };
byte p [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, 0,1, };
// letter erases
byte q [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, };
byte r [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, };
byte s [] = {0,0, 1,0, 2,0, 2,1, 2,2, };
byte t [] = {0,0, 1,0, 2,0, 2,1, };
byte u [] = {0,0, 1,0, 2,0, };
byte v [] = {0,0, 1,0, };
byte w [] = {0,0, };
byte x [] = {};
byte y [] = {};
byte z [] = {};

//for weeble wobble
byte aa [] = {2,2, 2,5, 2,8, 2,1, 2,7, 2,0, 2,3, 2,6, };
byte bb [] = {2,0, 2,1, 2,2, 2,3, 2,6, 1,8, };
byte cc [] = {2,0, 2,1, 2,2, 2,5, 2,8, 1,6, };
byte dd [] = {2,8, 2,2, 2,5, 2,6, 2,7, 1,0, };
byte ff [] = {2,0, 2,8, 2,3, 2,6, 2,7, 1,2, };
byte gg [] = {};
byte hh [] = {2,0, 2,1, 2,2, 2,3, 2,6, 1,8, };
byte ii [] = {2,0, 2,1, 2,2, 2,5, 2,8, 1,6, };
byte jj [] = {2,8, 2,2, 2,5, 2,6, 2,7, 1,0, };
byte kk [] = {2,0, 2,8, 2,3, 2,6, 2,7, 1,2, };
byte ll [] = {};
byte mm [] = {2,0, 2,1, 2,2, 2,3, 2,6, 1,8, };
byte nn [] = {2,0, 2,1, 2,2, 2,5, 2,8, 1,6, };
byte oo [] = {2,8, 2,2, 2,5, 2,6, 2,7, 1,0, };
byte pp [] = {2,0, 2,8, 2,3, 2,6, 2,7, 1,2, };
byte qq [] = {};
byte rr [] = {2,0, 2,1, 2,2, 2,3, 2,7, 1,8, };
byte ss [] = {2,0, 2,1, 2,2, 2,5, 2,8, 1,6, };
byte tt [] = {2,8, 2,2, 2,5, 2,6, 2,7, 1,0, };
byte uu [] = {2,0, 2,8, 2,3, 2,6, 2,7, 1,2, };
byte vv [] = {2,2, 2,5, 2,8, 2,1, 2,7, 2,0, 2,3, 2,6, };
byte ww [] = {2,0, 2,1, 2,2, 1,2, 1,5, 0,3, 0,4, 0,5, };
byte xx [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, 0,1, };
byte yy [] = {};
byte zz [] = {};

         //NOTE: cube.lightSequence(*whichever byte you are referring to* sizeof(*that byte*), *how long you want to stay lit*);

         //for the letter sequence
         cube.lightSequence(a, sizeof(a), 20);
         cube.lightSequence(b, sizeof(b), 20);
         cube.lightSequence(c, sizeof(c), 20);
         cube.lightSequence(d, sizeof(d), 20);
         cube.lightSequence(e, sizeof(e), 20);
         cube.lightSequence(ee, sizeof(ee), 20);
         cube.lightSequence(f, sizeof(f), 20);
         cube.lightSequence(g, sizeof(g), 20);
         cube.lightSequence(h, sizeof(h), 20);
         cube.lightSequence(i, sizeof(i), 20);
         cube.lightSequence(j, sizeof(j), 20);
         cube.lightSequence(k, sizeof(k), 20);
         cube.lightSequence(l, sizeof(l), 20);
         cube.lightSequence(m, sizeof(m), 20);
         cube.lightSequence(n, sizeof(n), 20);
         cube.lightSequence(o, sizeof(o), 20);
         cube.lightSequence(p, sizeof(p), 20);
         cube.lightSequence(q, sizeof(q), 20);
         cube.lightSequence(r, sizeof(r), 20);
         cube.lightSequence(s, sizeof(s), 20);
         cube.lightSequence(t, sizeof(t), 20);
         cube.lightSequence(u, sizeof(u), 20);
         cube.lightSequence(v, sizeof(v), 20);
         cube.lightSequence(w, sizeof(w), 20);
         cube.lightSequence(x, sizeof(x), 100);
         cube.lightSequence(y, sizeof(y), 100);
         cube.lightSequence(z, sizeof(z), 100);
         //for weeble wobble sequence
         cube.lightSequence(aa, sizeof(aa), 20);
         cube.lightSequence(bb, sizeof(bb), 20);
         cube.lightSequence(cc, sizeof(cc), 20);
         cube.lightSequence(dd, sizeof(dd), 20);
         cube.lightSequence(ff, sizeof(ff), 20);
         cube.lightSequence(gg, sizeof(gg), 200);
         cube.lightSequence(hh, sizeof(hh), 20);
         cube.lightSequence(ii, sizeof(ii), 20);
         cube.lightSequence(jj, sizeof(jj), 20);
         cube.lightSequence(kk, sizeof(kk), 20);
         cube.lightSequence(ll, sizeof(ll), 200);
         cube.lightSequence(mm, sizeof(mm), 20);
         cube.lightSequence(nn, sizeof(nn), 20);
         cube.lightSequence(oo, sizeof(oo), 20);
         cube.lightSequence(pp, sizeof(pp), 20);
         cube.lightSequence(qq, sizeof(qq), 200);
         cube.lightSequence(rr, sizeof(rr), 20);
         cube.lightSequence(ss, sizeof(ss), 20);
         cube.lightSequence(tt, sizeof(tt), 20);
         cube.lightSequence(uu, sizeof(uu), 20);
         cube.lightSequence(aa, sizeof(aa), 20);
         cube.lightSequence(bb, sizeof(bb), 20);
         cube.lightSequence(cc, sizeof(cc), 20);
         cube.lightSequence(dd, sizeof(dd), 20);
         cube.lightSequence(ff, sizeof(ff), 20);
         cube.lightSequence(gg, sizeof(gg), 200);
         cube.lightSequence(hh, sizeof(hh), 20);
         cube.lightSequence(ii, sizeof(ii), 20);
         cube.lightSequence(jj, sizeof(jj), 20);
         cube.lightSequence(kk, sizeof(kk), 20);
         cube.lightSequence(ll, sizeof(ll), 200);
         cube.lightSequence(mm, sizeof(mm), 20);
         cube.lightSequence(nn, sizeof(nn), 20);
         cube.lightSequence(oo, sizeof(oo), 20);
         cube.lightSequence(pp, sizeof(pp), 20);
         cube.lightSequence(qq, sizeof(qq), 200);
         cube.lightSequence(rr, sizeof(rr), 20);
         cube.lightSequence(ss, sizeof(ss), 20);
         cube.lightSequence(tt, sizeof(tt), 20);
         cube.lightSequence(uu, sizeof(uu), 20);
         cube.lightSequence(vv, sizeof(vv), 20);
         cube.lightSequence(ww, sizeof(ww), 20);
         cube.lightSequence(xx, sizeof(xx), 20);
         cube.lightSequence(yy, sizeof(yy), 200);
         cube.lightSequence(zz, sizeof(zz), 200);
         
}


void NE6(){
  // northeast from pin 6
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0  };
  int horizontal[8] = {  
    6, 3, 0, 1, 2, 5, 8, 7  };  
   for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }
}

void NE0(){
  // northeast from pin 0
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0    };
  int horizontal[8] = {  
    0, 1, 2, 5, 8, 7, 6, 3    };
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }
}

void NE02(){
  // northeast from pin 0
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0      };
  int horizontal[8] = {  
    0, 3, 6, 7, 8, 5, 2, 1      };
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }
}

void NW2(){
  // northwest from pin 2
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    2, 1, 0, 3, 6, 7, 8, 5                                             }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    } 
}

void N0(){
  // north from pin 0
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    0, 0, 0, 3, 6, 6, 6, 3                                             }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }  
}

void N1(){
  // north from pin 1
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    1, 1, 1, 4, 7, 7, 7, 4                                             };
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }  
}

void N2(){
  // north from pin 2
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    2, 2, 2, 5, 8, 8, 8, 5                                             };
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    } 
}

void BK0(){
  // back from pin 0
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    0, 0, 0, 1, 2, 2, 2, 1                                             }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }  
}

void BK3(){
  // back from pin 3
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    3, 3, 3, 4, 5, 5, 5, 4                                             }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }
}

void BK6(){
  // back from pin 6
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0   };
  int horizontal[8] = {  
    6, 6, 6, 7, 8, 8, 8, 7   }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(150);
      cube.lightOff(vertical[iter],horizontal[iter]);
    } 
}
