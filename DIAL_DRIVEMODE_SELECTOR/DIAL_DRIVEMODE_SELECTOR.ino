#include <M5Dial.h>
#include"Class_Dial.hpp"
Vayve_Dial M5Dial_class;
#define DEBUG
#ifdef DEBUG
int prev_geg=0;
M5Dial_Display_Upddate_Regen Display_Structure_Regen={90,190,3,0xffff,0};
M5Dial_Display_Upddate_GearMode Display_Structure_Gear_Mode={97,65,'D',2,2,0xd841,0,0 };
void setup() {
    M5Dial_class.Dial_Init();
    M5Dial_class.Display_Image(0);
    delay(1000);
    M5Dial.Display.fillScreen(TFT_BLACK);
    M5Dial_class.Update_outer_and_inner_radius(WHITE);
    M5Dial_class.Display_update_structure_Regen(Display_Structure_Regen);
    M5Dial_class.Display_update_structure_GearMode(Display_Structure_Gear_Mode);
}
void loop() {
  M5.update();  // Always call this in loop to keep encoder & touch working
  M5Dial_class.Check_Update_Regen_Values(Display_Structure_Regen);
  // M5Dial_class.Check_Update_Rotary_Encoder_Values(Display_Structure_Gear_Mode);
  if(prev_geg!=Display_Structure_Regen.regen_mode){
    M5Dial_class.Display_update_structure_Regen(Display_Structure_Regen);
    M5Dial_class.Display_update_structure_GearMode(Display_Structure_Gear_Mode);
    prev_geg=Display_Structure_Regen.regen_mode;
  }
}
#endif





/*
#ifdef TESTING
int previous=0;
void setup(){
    M5Dial_class.Dial_Init();
    M5Dial.Display.fillScreen(TFT_BLACK);
    for(int i=0;i<3;i++){
    M5Dial.Display.drawCircle(120,120,50+i, WHITE);  
    }
     previous=(M5Dial.Encoder.read()/4);
}
void loop(){
      M5.update();  // Always call this in loop to keep encoder & touch working
      int current=(M5Dial.Encoder.read()/4);
      if(previous!=current){
                  M5Dial.Display.fillScreen(TFT_BLACK);
                  M5Dial.Display.setTextSize(4);
                  M5Dial.Display.setCursor(120,120);       
                  M5Dial.Display.setTextColor(GREEN);
                  M5Dial.Display.println(current);
                   M5Dial.Speaker.tone(10000, 50);
                   previous=current;
      }
}
#endif */