#include"Class_Dial.hpp"




void Vayve_Dial::Dial_Init(){
   auto cfg = M5.config();
    M5Dial.begin(cfg, true, false);
}