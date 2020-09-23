/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
*/

#ifndef MENU_GENERATED_CODE_H
#define MENU_GENERATED_CODE_H

#include <Arduino.h>
#include <tcMenu.h>
#include "tcMenuAdaFruitGfx.h"
#include "EthernetTransport.h"
#include <RemoteConnector.h>

void setupMenu();  // forward reference of the menu setup function.
extern const PROGMEM ConnectorLocalInfo applicationInfo;  // defines the app info to the linker.

// Global variables that need exporting

extern Adafruit_ILI9341 gfx;
extern AdaColorGfxMenuConfig gfxConfig;
extern AdaFruitGfxMenuRenderer renderer;
extern WiFiServer server;

// Callback functions must always include CALLBACK_FUNCTION after the return type
#define CALLBACK_FUNCTION

// Global Menu Item exports

extern AnalogMenuItem menuStatusHeatsinkTemp;
extern AnalogMenuItem menuStatusRightLevel;
extern AnalogMenuItem menuStatusLeftLevel;
extern SubMenuItem menuStatus;
void CALLBACK_FUNCTION onSave(int id);
extern ActionMenuItem menuSettingsSaveAll;
void CALLBACK_FUNCTION onTrimChange(int id);
extern AnalogMenuItem menuSettingsIn3Trim;
void CALLBACK_FUNCTION onTrimChange(int id);
extern AnalogMenuItem menuSettingsIn2Trim;
void CALLBACK_FUNCTION onTrimChange(int id);
extern AnalogMenuItem menuSettingsIn1Trim;
extern AnalogMenuItem menuSettingsMaxOnVol;
extern SubMenuItem menuSettings;
extern BooleanMenuItem menuMuteAll;
void CALLBACK_FUNCTION onChannelChanged(int id);
extern EnumMenuItem menuChannel;
void CALLBACK_FUNCTION onVolumeChanged(int id);
extern AnalogMenuItem menuVolume;

#endif // MENU_GENERATED_CODE_H
