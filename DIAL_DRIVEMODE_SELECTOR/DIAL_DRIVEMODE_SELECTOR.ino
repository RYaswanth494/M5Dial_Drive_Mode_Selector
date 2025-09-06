#include <M5Dial.h>
#include "Class_Dial.hpp"
Vayve_Dial M5Dial_class;
#define DEBUG
#ifdef DEBUG

uint8_t crc8(uint8_t data) {
    uint8_t crc = 0x00; // initial value
    for (uint8_t i = 0; i < 8; i++) {
        if ((crc ^ data) & 0x80)
            crc = (crc << 1) ^ 0x07; // polynomial 0x07
        else
            crc <<= 1;
        data <<= 1;
    }
    return crc;
}


int prev_Reg = 0, prev_Gear = NEUTRAL_MODE;
M5Dial_Display_Upddate_Regen Display_Structure_Regen = { 90, 190, 3, 0xffff, 0 };
M5Dial_Display_Upddate_GearMode Display_Structure_Gear_Mode = { 97, 65, 'N', NEUTRAL_MODE, 2, 0xd841, 0, 0 };
void I2C_SEND(uint8_t address,char data){
  uint8_t buf[2];
  buf[0]={data};
  buf[1]=crc8(data);
    Wire.beginTransmission(address);
    Wire.write(buf,2);
    // Wire.print(crc8(data));
    uint8_t error = Wire.endTransmission(true);
    Serial.printf("endTransmission: %u\n", error);
}
void setup() {
  M5Dial_class.Dial_Init();
  M5Dial_class.Display_Image(0);
  delay(1000);
  M5Dial.Display.fillScreen(TFT_BLACK);
  M5Dial_class.Update_outer_and_inner_radius(WHITE);
  M5Dial_class.Display_update_structure_Regen(Display_Structure_Regen);
  M5Dial_class.Display_update_structure_GearMode(Display_Structure_Gear_Mode);
  I2C_SEND(0x55,Display_Structure_Gear_Mode.gear_mode_character);
}
void loop() {
  M5.update();  // Always call this in loop to keep encoder & touch working
  M5Dial_class.Check_Update_Regen_Values(Display_Structure_Regen);
  M5Dial_class.Check_Update_Rotary_Encoder_Values(Display_Structure_Gear_Mode);
  if ((prev_Reg != Display_Structure_Regen.regen_mode) || (prev_Gear != Display_Structure_Gear_Mode.gear_mode)) {
    M5Dial.Speaker.tone(10000, 50);
    M5Dial_class.Display_update_structure_Regen(Display_Structure_Regen);
    M5Dial_class.Display_update_structure_GearMode(Display_Structure_Gear_Mode);
  I2C_SEND(0x55,Display_Structure_Gear_Mode.gear_mode_character);
    prev_Reg = Display_Structure_Regen.regen_mode;
    prev_Gear = Display_Structure_Gear_Mode.gear_mode;
  }
}
#endif






#ifdef TESTING
#include "Wire.h"

#define I2C_DEV_ADDR 0x55

uint32_t i = 0;

void setup() {
  auto cfg = M5.config();
  cfg.output_power = true;
  M5Dial.begin(cfg, true, true);
  M5.Display.setTextSize(2);
  M5.Display.drawString("I2C master", 30, 20, &fonts::efontCN_16_b);

  Wire.begin(15, 13, 400000);
  //Write message to the slave
  Wire.beginTransmission(I2C_DEV_ADDR);
  Wire.printf("S", i++);
  uint8_t error = Wire.endTransmission(true);
  Serial.printf("endTransmission: %u\n", error);
}

long oldPosition = -999;
long newPosition = 0;

void loop() {

  M5Dial.update();
  newPosition = M5Dial.Encoder.read()/4;

  if (newPosition != oldPosition) {
    oldPosition = newPosition;

    Wire.beginTransmission(I2C_DEV_ADDR);
    Wire.print(newPosition);
    M5.Display.setCursor(100, 100);
    M5.Display.printf("%d   ", newPosition);
    uint8_t error = Wire.endTransmission(true);
    Serial.printf("endTransmission: %u\n", error);
  }
  
}
#endif