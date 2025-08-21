#include"Class_Dial.hpp"
bool Button_Status(){
  if(M5Dial.BtnA.wasPressed()){
    return BUTTON_PRESSED;
  }
  return BUTTON_NOT_PRESSED ;
}
void Vayve_Dial::Check_Update_Regen_Values(M5Dial_Display_Upddate_Regen &Display_Structure){
  static uint8_t button_count=0;
  if(Button_Status()){
    button_count++;
  }
  switch(button_count){
    case 0:Display_Structure.regen_mode=REGEN::LOW_REGEN;
            break;
    case 1:Display_Structure.regen_mode=REGEN::MEDIUM_REGEN;
            break;
    case 2:Display_Structure.regen_mode=REGEN::HIGH_REGEN;
            break;
    case 3:button_count=0;    
  }
}