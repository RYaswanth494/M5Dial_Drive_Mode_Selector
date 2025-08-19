#include "M5Dial.h"
extern const uint16_t* Images_array[];
void setup() {
    auto cfg = M5.config();
    M5Dial.begin(cfg, false, false);
    M5Dial.Display.drawBitmap(0, 0, 240, 240, Images_array[0]);
}
void loop() {
  M5.update();  // Always call this in loop to keep encoder & touch working
}