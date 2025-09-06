#include"Class_Dial.hpp"




void Vayve_Dial::Dial_Init(){
  auto cfg = M5.config();
  cfg.output_power = true;
  M5Dial.begin(cfg, true, false);
   Wire.begin(15, 13, 400000);
   Serial.begin(115200);

}