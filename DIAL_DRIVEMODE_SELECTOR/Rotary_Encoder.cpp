#include"Class_Dial.hpp"

static int current=0,previous=0;
static int state=IGNORE;

ENCODER_DIRECTION Get_Rotary_Enc_Dir(){
  current=(M5Dial.Encoder.read()/4);
  if(current!=previous){
    M5Dial.Speaker.tone(10000, 50);
    if(current>previous){
      // if(state!=CLOCK_WISE){
      //  state= CLOCK_WISE;
       previous=current;
      //  Serial.println("CW");
      return CLOCK_WISE;
      // }
      // previous=current;
      //  return IGNORE;
    }else if(current<previous){
         previous=current;
      return COUNTER_CLOCK_WISE;
    }
  }
  return IGNORE;
}

void Vayve_Dial::Check_Update_Rotary_Encoder_Values(M5Dial_Display_Upddate_GearMode &Display_Structure_Gear_Mode){
    uint8_t Direction_check=Get_Rotary_Enc_Dir();
    switch(Direction_check){
        case ENCODER_DIRECTION::CLOCK_WISE:switch(Display_Structure_Gear_Mode.gear_mode){
                            case GEAR_MODE::NEUTRAL_MODE:
                            Serial.println("CLOCK_WISE_TO_DRIVE ");
                                              Display_Structure_Gear_Mode.gear_mode_character='D';
                                              Display_Structure_Gear_Mode.swap_D_S=0;
                                              Display_Structure_Gear_Mode.x_cordinate=144;
                                              Display_Structure_Gear_Mode.y_cordinate=65;
                                              Display_Structure_Gear_Mode.gear_mode=DRIVE_MODE;
                                              break;
                            case GEAR_MODE::DRIVE_MODE:
                            Serial.println("CLOCK_WISE_TOSPORT ");
                                              Display_Structure_Gear_Mode.swap_D_S=1;
                                               Display_Structure_Gear_Mode.gear_mode_character='S';
                                               Display_Structure_Gear_Mode.gear_mode=SPORT_MODE;
                                               Display_Structure_Gear_Mode.x_cordinate=144;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                              
                                               break;
                            case GEAR_MODE::SPORT_MODE:  
                            Serial.println("CLOCK_WISE_DRIVE");
                                               Display_Structure_Gear_Mode.swap_D_S=1;
                                               Display_Structure_Gear_Mode.gear_mode_character='D';
                                               Display_Structure_Gear_Mode.gear_mode=DRIVE_MODE;
                                              Display_Structure_Gear_Mode.x_cordinate=144;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                               
                                               break; 
                            case GEAR_MODE::REVERSE_MODE:
                                             Display_Structure_Gear_Mode.gear_mode_character='N';
                                              Serial.println("CLOCK_WISE_NEUTRAL");
                                               Display_Structure_Gear_Mode.gear_mode=NEUTRAL_MODE;
                                              Display_Structure_Gear_Mode.x_cordinate=97;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                               
                                               break;                                                                                                                 
                        }
                        break;
        case ENCODER_DIRECTION::COUNTER_CLOCK_WISE:switch(Display_Structure_Gear_Mode.gear_mode){
                            case GEAR_MODE::NEUTRAL_MODE:Display_Structure_Gear_Mode.gear_mode_character='R';
                                              Serial.println("CCCCLOCK_WISE");
                                              Display_Structure_Gear_Mode.x_cordinate=66;
                                              Display_Structure_Gear_Mode.y_cordinate=92;
                                              Display_Structure_Gear_Mode.gear_mode=REVERSE_MODE;
                                              break;
                            case GEAR_MODE::DRIVE_MODE:Display_Structure_Gear_Mode.swap_D_S=0;
                                               Display_Structure_Gear_Mode.gear_mode_character='N';
                                               Display_Structure_Gear_Mode.gear_mode=NEUTRAL_MODE;
                                               Serial.println("CCCCCCCCCLOCK_WISE");
                                               Display_Structure_Gear_Mode.x_cordinate=97;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                              
                                               break;
                            case GEAR_MODE::SPORT_MODE:   Display_Structure_Gear_Mode.swap_D_S=1;
                                               Display_Structure_Gear_Mode.gear_mode_character='N';
                                               Serial.println("CCCCCCCCCCCCCCCCCLOCK_WISE");
                                               Display_Structure_Gear_Mode.gear_mode=NEUTRAL_MODE;
                                              Display_Structure_Gear_Mode.x_cordinate=97;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                               
                                               break; 
                            case GEAR_MODE::REVERSE_MODE:Display_Structure_Gear_Mode.gear_mode_character='R';
                                               Display_Structure_Gear_Mode.gear_mode=REVERSE_MODE;
                                               Serial.println("CCCCLOCK_WISE");
                                              Display_Structure_Gear_Mode.x_cordinate=97;
                                              Display_Structure_Gear_Mode.y_cordinate=65;                                               
                                               break;                                                                                                                 
                        }
                        break;                                  
    }
}