#include"Class_Dial.hpp"

static int current=0,previous=0;;
bool Get_Rotary_Enc_Dir(){
  current=(M5Dial.Encoder.read()/4);
   //Serial.println(current);
  if(current!=previous){
    M5Dial.Speaker.tone(10000, 50);
    if(current>previous){
       Serial.println("clock ");
      previous=current;
      return CLOCK_WISE;
    }else if(current<previous){
      previous=current;
       Serial.println("anticlock ");
      return COUNTER_CLOCK_WISE;
    }
  }
  return IGNORE;
}

void Vayve_Dial::Check_Update_Rotary_Encoder_Values(M5Dial_Display_Upddate_GearMode &Display_Structure_Gear_Mode){
    uint8_t Direction_check=Get_Rotary_Enc_Dir();
    switch(Direction_check){
        case CLOCK_WISE:switch(Display_Structure_Gear_Mode.gear_mode){
                            case NEUTRAL_MODE:Display_Structure_Gear_Mode.gear_mode_character='D';
                                              Display_Structure_Gear_Mode.x_cordinate=144;
                                              Display_Structure_Gear_Mode.y_cordinate=65;
                                              Display_Structure_Gear_Mode.gear_mode=DRIVE_MODE;
                                              break;
                            case DRIVE_MODE:   Display_Structure_Gear_Mode.swap_D_S=1;
                                               Display_Structure_Gear_Mode.gear_mode_character='S';
                                               Display_Structure_Gear_Mode.gear_mode=SPORT_MODE;
                                               Display_Structure_Gear_Mode.x_cordinate=144;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                              
                                               break;
                            case SPORT_MODE:   Display_Structure_Gear_Mode.swap_D_S=0;
                                               Display_Structure_Gear_Mode.gear_mode_character='D';
                                               Display_Structure_Gear_Mode.gear_mode=DRIVE_MODE;
                                              Display_Structure_Gear_Mode.x_cordinate=144;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                               
                                               break; 
                            case REVERSE_MODE:Display_Structure_Gear_Mode.gear_mode_character='N';
                                               Display_Structure_Gear_Mode.gear_mode=NEUTRAL_MODE;
                                              Display_Structure_Gear_Mode.x_cordinate=97;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                               
                                               break;                                                                                                                 
                        }
                        break;
        case COUNTER_CLOCK_WISE:switch(Display_Structure_Gear_Mode.gear_mode){
                            case NEUTRAL_MODE:Display_Structure_Gear_Mode.gear_mode_character='R';
                                              Display_Structure_Gear_Mode.x_cordinate=66;
                                              Display_Structure_Gear_Mode.y_cordinate=92;
                                              Display_Structure_Gear_Mode.gear_mode=REVERSE_MODE;
                                              break;
                            case DRIVE_MODE:
                                               Display_Structure_Gear_Mode.gear_mode_character='N';
                                               Display_Structure_Gear_Mode.gear_mode=NEUTRAL_MODE;
                                               Display_Structure_Gear_Mode.x_cordinate=97;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                              
                                               break;
                            case SPORT_MODE:   Display_Structure_Gear_Mode.swap_D_S=0;
                                               Display_Structure_Gear_Mode.gear_mode_character='D';
                                               Display_Structure_Gear_Mode.gear_mode=DRIVE_MODE;
                                              Display_Structure_Gear_Mode.x_cordinate=144;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                               
                                               break; 
                            case REVERSE_MODE:Display_Structure_Gear_Mode.gear_mode_character='R';
                                               Display_Structure_Gear_Mode.gear_mode=REVERSE_MODE;
                                              Display_Structure_Gear_Mode.x_cordinate=97;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                               
                                               break;                                                                                                                 
                        }
                        break;                        
    }
}