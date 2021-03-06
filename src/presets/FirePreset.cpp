#include "Presets.hpp"
#include "handlers/LedHandler.hpp"


#ifndef FIRE_CPP
#define FIRE_CPP

DEFINE_GRADIENT_PALETTE(fire_gradient){
    0,   191, 0,  0, //red
    64,  255, 0,  0, //red
    255, 255, 75, 0, //orange
};

FirePreset::FirePreset() {}

void FirePreset::start() {}

void FirePreset::loop() {
    for(int i = 0; i < LED_COUNT; i++) {
        int palette_index = inoise8(i * 100, y_offset);
        LED::leds[i] = Util::fixValue(ColorFromPalette(firePalette, palette_index), LED::value);
    }

    EVERY_N_MILLIS((int)round(100.00)) {
        y_offset += 30;
        LED::show();
    }
}

#endif