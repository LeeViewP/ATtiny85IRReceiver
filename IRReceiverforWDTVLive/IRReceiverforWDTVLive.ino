/*************************************
* This code is written by Laurens Wuyts
* For questions: laurens.wuyts@gmail.com
* 
* 
* Microcontroller: ATtiny85
* Dev board:       Digispark 
* 
*************************************/

/**** Define Remote control keys ****/ 
/****   Western Digital WD TV Live Remote****/
#define IR_power     72

#define IR_1         24
#define IR_2         152
#define IR_3         112
#define IR_4         56
#define IR_5         184
#define IR_6         122
#define IR_7         186
#define IR_8         58
#define IR_9         250
#define IR_0         136

// #define IR_vol_up    255
// #define IR_vol_down  255
#define IR_vol_mute      178

//#define ch_up     72
//#define ch_down   200
#define IR_m_playpause 80
#define IR_m_stop      32
#define IR_m_next      128
#define IR_m_prev      64
#define IR_m_ff        120
#define IR_m_rev       248

#define IR_up        160
#define IR_down      0
#define IR_left      224
#define IR_right     144
#define IR_select    16
#define IR_back      50

#define IR_menu      96
#define IR_exit      216
#define IR_red       168
#define IR_green     40
#define IR_yellow    104
#define IR_blue      232

/************************************/
#include "TrinketHidCombo.h"


uint8_t situation = 0;
uint8_t START = 0;
uint8_t x = 0;
uint8_t BIT = 0;
uint8_t Id = 0;
uint8_t Id_inv = 0;
uint8_t Data = 0;
uint8_t Data_back = 0;
uint8_t Data_inv = 0;
uint8_t Repeat = 0;
uint8_t sended = 0;

uint16_t Time_old = 0;
uint16_t Time = 0;
uint16_t TimeDelta = 0;
 
void setup(void) {
  /* Use INT0(P2) on the Digispark */
  attachInterrupt(0, IR_Read, FALLING);
  
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);

  TrinketHidCombo.begin();
}
 
void loop(void) {
  if(sended == 1) {
       /* Assign functions to the buttons */
    if(Data_back == IR_up) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_UP);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_down) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_DOWN);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_left) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_LEFT);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_right) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_RIGHT);
      TrinketHidCombo.pressKey(0, 0);
    }else if(Data_back == IR_select) {
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
	    TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_back) {
      TrinketHidCombo.pressKey(0, KEYCODE_BACKSPACE);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_exit) {
      TrinketHidCombo.pressKey(0, KEYCODE_ESC);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_menu) {
        TrinketHidCombo.pressKey(0,KEYCODE_C);
        TrinketHidCombo.pressKey(0, 0);
        //TrinketHidCombo.pressMultimediaKey(MMKEY_KB_MENU); //KEYCODE_RIGHT_ALT
    // } else if(Data_back == vol_up) {
    //   TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
    // } else if(Data_back == vol_down) {
    //   TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    } else if(Data_back == IR_m_next || Data_back == IR_m_ff) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_SCAN_NEXT_TRACK);
    } else if(Data_back == IR_m_prev || Data_back == IR_m_rev) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_SCAN_PREV_TRACK);
    } else if(Data_back == IR_m_stop) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_STOP);
    } else if(Data_back == IR_m_playpause) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_PLAYPAUSE);
    } else if(Data_back == IR_vol_mute) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_MUTE);
    } else if(Data_back == IR_power) {
      //TrinketHidCombo.pressSystemCtrlKey(SYSCTRLKEY_SLEEP);
      TrinketHidCombo.pressSystemCtrlKey(SYSCTRLKEY_WAKE);
      TrinketHidCombo.pressSystemCtrlKey(SYSCTRLKEY_POWER);
    } else if(Data_back == IR_0) {
      TrinketHidCombo.pressKey(0, KEYCODE_0);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_1) {
      TrinketHidCombo.pressKey(0, KEYCODE_1);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_2) {
      TrinketHidCombo.pressKey(0, KEYCODE_2);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_3) {
      TrinketHidCombo.pressKey(0, KEYCODE_3);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_4) {
      TrinketHidCombo.pressKey(0, KEYCODE_4);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_5) {
      TrinketHidCombo.pressKey(0, KEYCODE_5);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_6) {
      TrinketHidCombo.pressKey(0, KEYCODE_6);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_7) {
      TrinketHidCombo.pressKey(0, KEYCODE_7);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_8) {
      TrinketHidCombo.pressKey(0, KEYCODE_8);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_9) {
      TrinketHidCombo.pressKey(0, KEYCODE_9);
      TrinketHidCombo.pressKey(0, 0);
    }  else if(Data_back == IR_red) {
      //TrinketHidCombo.pressKey(0, KEYCODE_9);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_green) {
      //TrinketHidCombo.pressKey(0, KEYCODE_9);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_blue) {
     // TrinketHidCombo.pressKey(0, KEYCODE_9);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == IR_yellow) {
      //TrinketHidCombo.pressKey(0, KEYCODE_9);
      TrinketHidCombo.pressKey(0, 0);
    }
    sended = 0;
    Data_back = 0;
  } 
  else 
  {
      TrinketHidCombo.poll();
  }
  
  //delay(300);  //delay 300 ms
}

/* Read the IR code */
void IR_Read(void) {
  digitalWrite(1,HIGH);
  Time = micros();
  if (Time_old != 0) {
    TimeDelta = Time - Time_old;
    if ((TimeDelta > 12000)&&(TimeDelta < 14000)) {
      START = 1;
      x = 0;
      situation = 1;
      Id = 0;
      Id_inv = 0;
      Data = 0;
      Data_inv = 0;
    } else if ((TimeDelta > 10000)&&(TimeDelta < 12000)) {
      situation = 2; // repeat
      Data_back = 0;
    } else if ((TimeDelta > 1500)&&(TimeDelta < 2500)) {
      situation = 3; //"1"
      BIT = 1;
      Data_back = 0;
    } else if ((TimeDelta > 1000)&&(TimeDelta < 1500)) {
      situation = 3; //"0"
      BIT = 0;
      Data_back = 0;
    } else situation = 5; 
    if (situation == 3) {
      if (x < 8) {
        Id |= BIT;
        if (x < 7) Id <<= 1;  
        x++;
      } else if (x < 16) {
        Id_inv |= BIT;
        if (x < 15) Id_inv <<= 1;
        x++;
      } else if (x < 24) {
        Data |= BIT;
        if (x < 23) Data <<= 1;
        x++;
      } else if (x < 32) {
        Data_inv |= BIT;
        if (x < 31) {
          Data_inv <<= 1;
        } else {
          
          /* DO SOMETHING HERE */
          sended = 1;
          
          Data_back = Data;
          Repeat = 0;
        }
        x++;
      }
    } else if (situation == 2) {
      if(Repeat == 1) {
        
        /* DO SOMETHING HERE */
        sended = 1;
        Data_back = Data;
      } else {
        Repeat = 1;
        Data_back = Data;
      }
    }
  }
  Time_old = Time;
  digitalWrite(1,LOW);
}