#include<stdint.h>
#include<M5Dial.h>
#pragma pack(1)
enum BUTTON_STATE{
  BUTTON_NOT_PRESSED,
  BUTTON_PRESSED
};
enum REGEN{
  LOW_REGEN,
  MEDIUM_REGEN,
  HIGH_REGEN
};
enum GEAR_MODE{
  REVERSE_MODE,
  NEUTRAL_MODE,
  DRIVE_MODE,
  SPORT_MODE
};
enum ENCODER_DIRECTION{
  IGNORE,
  CLOCK_WISE,
  COUNTER_CLOCK_WISE
};
typedef struct M5Dial_Display_Upddate_Regen{
  uint8_t x_cordinate;
  uint8_t y_cordinate;
  uint8_t character_size;
  uint16_t Regen_char_colour;
  uint8_t regen_mode:2;
};
typedef struct M5Dial_Display_Upddate_GearMode{
  uint8_t x_cordinate;
  uint8_t y_cordinate;
  char gear_mode_character;
  uint8_t gear_mode;
  uint8_t character_size;
  uint16_t Regen_char_colour;
  uint8_t swap_D_S:2;
  uint8_t encoder_direction:2;
};
class Vayve_Dial{
public:
void Dial_Init();
void Display_Image(uint8_t index);
void Update_outer_and_inner_radius(uint16_t in_out_rad_colour);
void Display_update_structure_Regen(M5Dial_Display_Upddate_Regen &Display_Structure);
void Check_Update_Regen_Values(M5Dial_Display_Upddate_Regen &Display_Structure);
void Display_update_structure_GearMode(M5Dial_Display_Upddate_GearMode &Display_Structure);
void Check_Update_Rotary_Encoder_Values(M5Dial_Display_Upddate_GearMode &Display_Structure);
};