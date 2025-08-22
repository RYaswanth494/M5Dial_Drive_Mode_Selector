#include <M5Dial.h>
#include"Class_Dial.hpp"
Vayve_Dial M5Dial_class;
#define DEBUG
#ifdef DEBUG
int prev_Reg=0,prev_Gear=NEUTRAL_MODE;
M5Dial_Display_Upddate_Regen Display_Structure_Regen={90,190,3,0xffff,0};
M5Dial_Display_Upddate_GearMode Display_Structure_Gear_Mode={97,65,'N',NEUTRAL_MODE,2,0xd841,0,0 };
void setup() {
    M5Dial_class.Dial_Init();
    M5Dial_class.Display_Image(0);
    delay(1000);
    M5Dial.Display.fillScreen(TFT_BLACK);
    M5Dial_class.Update_outer_and_inner_radius(WHITE);
    M5Dial_class.Display_update_structure_Regen(Display_Structure_Regen);
    M5Dial_class.Display_update_structure_GearMode(Display_Structure_Gear_Mode);
    Serial.println("M5Dial UART Example Started");
}
void loop() {
  M5.update();  // Always call this in loop to keep encoder & touch working
  M5Dial_class.Check_Update_Regen_Values(Display_Structure_Regen);
  M5Dial_class.Check_Update_Rotary_Encoder_Values(Display_Structure_Gear_Mode);
  if((prev_Reg!=Display_Structure_Regen.regen_mode)||(prev_Gear!=Display_Structure_Gear_Mode.gear_mode)){
    M5Dial.Speaker.tone(10000, 50);
    M5Dial_class.Display_update_structure_Regen(Display_Structure_Regen);
    M5Dial_class.Display_update_structure_GearMode(Display_Structure_Gear_Mode);
    prev_Reg=Display_Structure_Regen.regen_mode;
    prev_Gear=Display_Structure_Gear_Mode.gear_mode;
  }
}
#endif






#ifdef TESTING

void setup(){
    M5Dial_class.Dial_Init();
  Serial.begin(115200);        // Serial Monitor baudrate
}
void loop(){
      M5.update();  // Always call this in loop to keep encoder & touch working

}
#endif 