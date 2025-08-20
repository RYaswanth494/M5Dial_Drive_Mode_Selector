#include"Class_Dial.hpp"
#include"Images_Array.hpp"
void Vayve_Dial::Display_Image(uint8_t index){
  if(index< (sizeof(Images_array)/sizeof(Images_array[0]))){
      M5Dial.Display.drawBitmap(0, 0, 240, 240, Images_array[index]);
  }
}
void Display_background(int mode_color) {
    //M5Dial.Display.fillCircle(120,120,50, mode_color);  
    for(int i=1;i<5;i++){    
      M5Dial.Display.drawCircle(120,120,50+i, mode_color);  
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
void Vayve_Dial::Display_update_structure(M5Dial_Display_Upddate &Display_Structure){
    M5Dial.Display.fillScreen(TFT_BLACK);
uint8_t numTriangles=1,triSize=10,radius=70,cx=120,cy=120;
drawCircleDots(120,120,120,2,Display_Structure.mode_colour);
Display_background(Display_Structure.mode_colour);

          int x = 90;
          int y = 190;
          int r = 30;  
        switch(Display_Structure.regen_mode){
          case 0:
                  M5Dial.Display.setTextSize(3.5);
                  M5Dial.Display.setCursor(x,y);       
                  M5Dial.Display.setTextColor(GREEN);
                  M5Dial.Display.println("R_Lo");
                  break;
          case 1:
                  M5Dial.Display.setTextSize(3);
                  M5Dial.Display.setCursor(x,y); 
                  M5Dial.Display.setTextColor(WHITE);
                  M5Dial.Display.println("R_Med");
                  break;
          case 2:
                  M5Dial.Display.setTextSize(3.5);
                  M5Dial.Display.setCursor(x,y);  
                  M5Dial.Display.setTextColor(ORANGE);
                  M5Dial.Display.println("R_Hi");
                  break;                    
        }
}