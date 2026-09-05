#pragma once

#if defined(ST7796)

// Data specific to the ST7796 controller
#define DISPLAY_SET_CURSOR_X 0x2A
#define DISPLAY_SET_CURSOR_Y 0x2B
#define DISPLAY_WRITE_PIXELS 0x2C

// Physical panel targeted here is a 320x240 (landscape-native) ST7796-based SPI TFT,
// as used e.g. as the stock LCD in Anycubic Kobra Neo/Go 3D printers.
#define DISPLAY_NATIVE_WIDTH 320
#define DISPLAY_NATIVE_HEIGHT 240

#define InitSPIDisplay InitST7796
void InitST7796(void);

#endif

