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
    FanController(FanMode starting_mode = FanMode::OFF) {
        currentMode = starting_mode;
    }

    void setMode(FanMode new_mode) {
        currentMode = new_mode;
    }

    void nextMode() {
        switch (currentMode) {
            case FanMode::OFF:
                currentMode = FanMode::LOW;
                break;
            case FanMode::LOW:
                currentMode = FanMode::MEDIUM;
                break;
            case FanMode::MEDIUM:
                currentMode = FanMode::HIGH;
                break;
            case FanMode::HIGH:
                currentMode = FanMode::AUTO;
                break;
            case FanMode::AUTO:
                currentMode = FanMode::OFF;
                break;

            default:
                break;
        }
    }

    void previousMode() {
        currentMode = static_cast<FanMode>((static_cast<int>(currentMode) - 1) % 5);
    }

    FanMode getCurrentMode() {
        return currentMode;
    }

    string getCurrentModeName() {
        if (currentMode == FanMode::OFF) return modeNames[FanMode::OFF];
        else if (currentMode == FanMode::LOW) return modeNames[FanMode::LOW];
        else if (currentMode == FanMode::MEDIUM) return modeNames[FanMode::MEDIUM];
        else if (currentMode == FanMode::HIGH) return modeNames[FanMode::HIGH];
        else if (currentMode == FanMode::AUTO) return modeNames[FanMode::AUTO];
        throw "Invalid mode";
    }
};