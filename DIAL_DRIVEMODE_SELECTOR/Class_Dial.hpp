#include<stdint.h>
#include<M5Dial.h>
//#include<bool.h>

//  Display_dial(x_crdnt_of_cursor, y_crdnt_of_cursor, character_value_of_gear_mode, mode_color, swap, regen_mode);
enum REGEN{
  LOW_REGEN,
  MEDIUM_REGEN,
  HIGH_REGEN
};

typedef struct M5Dial_Display_Upddate{
  uint8_t xcordinate;
  uint8_t ycordinate;
  uint8_t gear_mode;
  int mode_colour;
  uint8_t swap:1;
  uint8_t regen_mode:2;
};
class Vayve_Dial{
public:
void Dial_Init();
void Display_Image(uint8_t index);
void Display_update_structure(M5Dial_Display_Upddate &Display_Structure);
void Check_Update_Regen_Values(M5Dial_Display_Upddate &Display_Structure);
};