#ifndef FAN_MODE_HPP
#define FAN_MODE_HPP

#include <map>
#include <string>
#include "FanMode.hpp"

using std::map;
using std::string;

class FanController {
   private:
    map<FanMode, string> modeNames = {
        {FanMode::OFF, "OFF"},
        {FanMode::LOW, "LOW"},
        {FanMode::MEDIUM, "MEDIUM"},
        {FanMode::HIGH, "HIGH"},
        {FanMode::AUTO, "AUTO"}
    };

    FanMode currentMode = FanMode::OFF;

   public:
    FanController(FanMode startingMode = FanMode::OFF);
    void setMode(FanMode newMode);
    void nextMode();
    void previousMode();
    FanMode getCurrentMode();
    string getCurrentModeName();
};

#endif  // FAN_MODE_HPP