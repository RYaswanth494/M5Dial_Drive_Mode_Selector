#include <M5Dial.h>
#include"Class_Dial.hpp"
Vayve_Dial M5Dial_class;
int prev_geg=0;
M5Dial_Display_Upddate Display_Structure={97,65,'N',0xffff,0,0};
void setup() {
    M5Dial_class.Dial_Init();
    M5Dial_class.Display_Image(0);
    delay(1000);
    M5Dial.Display.fillScreen(TFT_BLACK);
    M5Dial_class.Display_update_structure(Display_Structure);
}
void loop() {
  M5.update();  // Always call this in loop to keep encoder & touch working
  M5Dial_class.Check_Update_Regen_Values(Display_Structure);
  if(prev_geg!=Display_Structure.regen_mode){
    M5Dial_class.Display_update_structure(Display_Structure);
    prev_geg=Display_Structure.regen_mode;
  }
}