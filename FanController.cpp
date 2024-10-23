#include "FanController.hpp"

class FanController {
   private:
    map<FanMode, string> modeNames = {
        {FanMode::OFF, "OFF"},
        {FanMode::LOW, "LOW"},
        {FanMode::MEDIUM, "MEDIUM"},
        {FanMode::HIGH, "HIGH"},
        {FanMode::AUTO, "AUTO"}};

    FanMode currentMode = FanMode::OFF;

   public:
    FanController(FanMode newMode = FanMode::OFF) {
        currentMode = newMode;
    }

    void setMode(FanMode newMode) {
        currentMode = newMode;
    }

    void nextMode() {
        currentMode = static_cast<FanMode>((static_cast<int>(currentMode) + 1) % 5);
    }

    void previousMode() {
        currentMode = static_cast<FanMode>((static_cast<int>(currentMode) - 1) % 5);
    }

    FanMode getCurrentMode() {
        return currentMode;
    }

    string getCurrentModeName() {
        return modeNames[currentMode];
    }
};