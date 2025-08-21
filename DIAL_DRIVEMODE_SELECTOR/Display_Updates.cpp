#include"Class_Dial.hpp"
#include"Images_Array.hpp"
int radius_of_cursor = 5;
        #define X_COORDINATE_CUR_MODE_CHAR  103
        #define Y_COORDINATE_CUR_MODE_CHAR  100

        // coordinates of mode character and their corresponding cursor position on dial
        // character coordinates 
        #define X_COORDINATE_REV_MODE_CHAR  33
        #define Y_COORDINATE_REV_MODE_CHAR  60

        #define X_COORDINATE_NEUTRAL_MODE_CHAR  77
        #define Y_COORDINATE_NEUTRAL_MODE_CHAR  24

        #define X_COORDINATE_UNSWAP_DRIVE_MODE_CHAR  137
        #define Y_COORDINATE_UNSWAP_DRIVE_MODE_CHAR  24

        #define X_COORDINATE_SWAP_DRIVE_MODE_CHAR  180
        #define Y_COORDINATE_SWAP_DRIVE_MODE_CHAR  60

        #define X_COORDINATE_UNSWAP_SPORT_MODE_CHAR  180
        #define Y_COORDINATE_UNSWAP_SPORT_MODE_CHAR  60

        #define X_COORDINATE_SWAP_SPORT_MODE_CHAR  137
        #define Y_COORDINATE_SWAP_SPORT_MODE_CHAR  24

        //cursor coordinates 
        int x_crdnt_of_reverse_cursor =66;
        int y_crdnt_of_reverse_cursor =92;

        int x_crdnt_of_sport_cursor =171;
        int y_crdnt_of_sport_cursor =92;
        
        int x_crdnt_of_neutral_cursor =97;
        int y_crdnt_of_neutral_cursor =65;
        
        int x_crdnt_of_drive_cursor =144;
        int y_crdnt_of_drive_cursor =65; 
void Vayve_Dial::Display_Image(uint8_t index){
  if(index< (sizeof(Images_array)/sizeof(Images_array[0]))){
      M5Dial.Display.drawBitmap(0, 0, 240, 240, Images_array[index]);
  }
}
void Display_background(int mode_color) {
    //M5Dial.Display.fillCircle(120,120,50, mode_color);  
    for(int i=1;i<5;i++){    
      M5Dial.Display.drawCircle(120,120,45+i, mode_color);  
    }
}
void drawCircleDots(int cx, int cy, int radius, int dotSize, uint16_t color) {
  for (int angle = 0; angle < 360; angle += 5) {  // 5° step for spacing
    float rad = angle * 3.14159 / 180.0;          // convert to radians
    int x = cx + radius * cos(rad);
    int y = cy + radius * sin(rad);
    M5Dial.Display.fillCircle(x, y, dotSize, color);
  }
}
void Vayve_Dial::Update_outer_and_inner_radius(uint16_t in_out_rad_color){
    M5Dial.Display.fillScreen(TFT_BLACK);
    drawCircleDots(120,120,120,2,in_out_rad_color);
    Display_background(in_out_rad_color);
}
void Vayve_Dial::Display_update_structure_Regen(M5Dial_Display_Upddate_Regen &Display_Structure){
        switch(Display_Structure.regen_mode){
          case 0:
                  M5Dial.Display.setTextSize(Display_Structure.character_size);
                  M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);
                  M5Dial.Display.setTextColor(BLACK);
                  M5Dial.Display.println("R_Hi"); 
                   M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);
                  M5Dial.Display.setTextColor(BLACK);                 
                  M5Dial.Display.println("R_Med");
                  M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);
                  M5Dial.Display.setTextColor(GREEN);
                  M5Dial.Display.println("R_Lo");
                  break;
          case 1:
                  M5Dial.Display.setTextSize(Display_Structure.character_size);
                  M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);       
                  M5Dial.Display.setTextColor(BLACK);
                  M5Dial.Display.println("R_Lo"); 
                  M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);
                  M5Dial.Display.setTextColor(BLACK);                  
                  M5Dial.Display.println("R_Hi"); 
                  M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);
                  M5Dial.Display.setTextColor(GREEN);
                  M5Dial.Display.println("R_Med");
                  break;
          case 2:
                  M5Dial.Display.setTextSize(Display_Structure.character_size);
                  M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);  
                  M5Dial.Display.setTextColor(BLACK);
                  M5Dial.Display.println("R_Lo"); 
                  M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);
                  M5Dial.Display.setTextColor(BLACK);                  
                  M5Dial.Display.println("R_Med"); 
                  M5Dial.Display.setCursor(Display_Structure.x_cordinate,Display_Structure.y_cordinate);
                  M5Dial.Display.setTextColor(GREEN);
                  M5Dial.Display.println("R_Hi");
                  break;                    
        }
}
void remove_cursor_from_prev_position(){
    M5Dial.Display.setColor(BLACK);
    M5Dial.Display.fillCircle(x_crdnt_of_reverse_cursor,y_crdnt_of_reverse_cursor,radius_of_cursor);//R
    M5Dial.Display.fillCircle(x_crdnt_of_sport_cursor,y_crdnt_of_sport_cursor,radius_of_cursor);//S
    M5Dial.Display.fillCircle(x_crdnt_of_neutral_cursor,y_crdnt_of_neutral_cursor,radius_of_cursor);//N
    M5Dial.Display.fillCircle(x_crdnt_of_drive_cursor,y_crdnt_of_drive_cursor,radius_of_cursor);//D
}
void update_gear_charactor_color(uint8_t x,uint8_t y,char c,uint16_t colour){
        M5Dial.Display.setTextColor(colour);
        M5Dial.Display.setTextSize(4);
        M5Dial.Display.setCursor(x,y);
        M5Dial.Display.println(c);
}
void Vayve_Dial::Display_update_structure_GearMode(M5Dial_Display_Upddate_GearMode &Display_Structure){

        switch(Display_Structure.gear_mode_character){
          case 'N':
          case 'n':update_gear_charactor_color(X_COORDINATE_NEUTRAL_MODE_CHAR,Y_COORDINATE_NEUTRAL_MODE_CHAR,'N',RED);
                   update_gear_charactor_color(X_COORDINATE_REV_MODE_CHAR,Y_COORDINATE_REV_MODE_CHAR,'R',WHITE);
                   update_gear_charactor_color(X_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,Y_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,'D',WHITE);
                   update_gear_charactor_color(X_COORDINATE_UNSWAP_SPORT_MODE_CHAR,Y_COORDINATE_UNSWAP_SPORT_MODE_CHAR,'S',WHITE);
                   break;
          case 'R':
          case 'r':update_gear_charactor_color(X_COORDINATE_NEUTRAL_MODE_CHAR,Y_COORDINATE_NEUTRAL_MODE_CHAR,'N',WHITE);
                   update_gear_charactor_color(X_COORDINATE_REV_MODE_CHAR,Y_COORDINATE_REV_MODE_CHAR,'R',RED);
                   update_gear_charactor_color(X_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,Y_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,'D',WHITE);
                   update_gear_charactor_color(X_COORDINATE_UNSWAP_SPORT_MODE_CHAR,Y_COORDINATE_UNSWAP_SPORT_MODE_CHAR,'S',WHITE);
                   break;
          case 'd':
          case 'D':
                   update_gear_charactor_color(X_COORDINATE_NEUTRAL_MODE_CHAR,Y_COORDINATE_NEUTRAL_MODE_CHAR,'N',WHITE);
                   update_gear_charactor_color(X_COORDINATE_REV_MODE_CHAR,Y_COORDINATE_REV_MODE_CHAR,'R',WHITE);
                   switch(Display_Structure.swap_D_S){
                    case 0:
                           update_gear_charactor_color(X_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,Y_COORDINATE_SWAP_DRIVE_MODE_CHAR,'D',BLACK);
                           update_gear_charactor_color(X_COORDINATE_UNSWAP_SPORT_MODE_CHAR,Y_COORDINATE_SWAP_SPORT_MODE_CHAR,'S',BLACK);                     
                           update_gear_charactor_color(X_COORDINATE_SWAP_DRIVE_MODE_CHAR,Y_COORDINATE_SWAP_DRIVE_MODE_CHAR,'D',RED);
                           update_gear_charactor_color(X_COORDINATE_SWAP_SPORT_MODE_CHAR,Y_COORDINATE_SWAP_SPORT_MODE_CHAR,'S',WHITE);                    
                           break;
                    case 1:
                           update_gear_charactor_color(X_COORDINATE_SWAP_DRIVE_MODE_CHAR,Y_COORDINATE_SWAP_DRIVE_MODE_CHAR,'D',BLACK);
                           update_gear_charactor_color(X_COORDINATE_SWAP_SPORT_MODE_CHAR,Y_COORDINATE_SWAP_SPORT_MODE_CHAR,'S',BLACK);                    
                           update_gear_charactor_color(X_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,Y_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,'D',WHITE);
                           update_gear_charactor_color(X_COORDINATE_UNSWAP_SPORT_MODE_CHAR,Y_COORDINATE_UNSWAP_SPORT_MODE_CHAR,'S',RED);                   
                           break;
                   }          
          case 's':
          case 'S':         
                   update_gear_charactor_color(X_COORDINATE_NEUTRAL_MODE_CHAR,Y_COORDINATE_NEUTRAL_MODE_CHAR,'N',WHITE);
                   update_gear_charactor_color(X_COORDINATE_REV_MODE_CHAR,Y_COORDINATE_REV_MODE_CHAR,'R',WHITE);
                   switch(Display_Structure.swap_D_S){
                    case 0:
                           update_gear_charactor_color(X_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,Y_COORDINATE_SWAP_DRIVE_MODE_CHAR,'D',BLACK);
                           update_gear_charactor_color(X_COORDINATE_UNSWAP_SPORT_MODE_CHAR,Y_COORDINATE_SWAP_SPORT_MODE_CHAR,'S',BLACK);                                       
                           update_gear_charactor_color(X_COORDINATE_SWAP_DRIVE_MODE_CHAR,Y_COORDINATE_SWAP_DRIVE_MODE_CHAR,'D',WHITE);
                           update_gear_charactor_color(X_COORDINATE_SWAP_SPORT_MODE_CHAR,Y_COORDINATE_SWAP_SPORT_MODE_CHAR,'S',RED);                    
                           break;
                    case 1:
                           update_gear_charactor_color(X_COORDINATE_SWAP_DRIVE_MODE_CHAR,Y_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,'D',BLACK);
                           update_gear_charactor_color(X_COORDINATE_SWAP_SPORT_MODE_CHAR,Y_COORDINATE_UNSWAP_SPORT_MODE_CHAR,'S',BLACK);                    
                           update_gear_charactor_color(X_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,Y_COORDINATE_UNSWAP_DRIVE_MODE_CHAR,'D',RED);
                           update_gear_charactor_color(X_COORDINATE_UNSWAP_SPORT_MODE_CHAR,Y_COORDINATE_UNSWAP_SPORT_MODE_CHAR,'S',WHITE);                   
                           break;
                   }
                                  
        }
        remove_cursor_from_prev_position();
        M5Dial.Display.setColor(GREEN);
        M5Dial.Display.fillCircle(Display_Structure.x_cordinate, Display_Structure.y_cordinate,radius_of_cursor);
        M5Dial.Display.fillCircle(120,120,40, BLACK);
        M5Dial.Display.setCursor(X_COORDINATE_CUR_MODE_CHAR,Y_COORDINATE_CUR_MODE_CHAR);  
        M5Dial.Display.setTextSize(5);
        M5Dial.Display.setTextColor(RED);
        M5Dial.Display.println(Display_Structure.gear_mode_character);
}