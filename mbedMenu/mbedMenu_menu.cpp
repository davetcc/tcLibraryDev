/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
*/

#include <mbed.h>
#include <tcMenu.h>
#include <graphics/MenuTouchScreenEncoder.h>
#include "mbedMenu_menu.h"

#include "FreeSans12pt7b.h"

// Global variable declarations

const PROGMEM ConnectorLocalInfo applicationInfo = { "MBed Test", "98ea360b-fe08-444a-996b-2e94dda7a2eb" };
StChromaArtDrawable bspDrawable;
GraphicsDeviceRenderer renderer(30, applicationInfo.name, &bspDrawable);

StBspTouchInterrogator touchInterrogator(240, 320);
MenuTouchScreenManager touchScreen(&touchInterrogator, &renderer, iotouch::TouchInterrogator::PORTRAIT);

// Global Menu Item declarations

const AnyMenuInfo minfoShowDialog = { "Show dialog", 11, 0xFFFF, 0, NO_CALLBACK };
ActionMenuItem menuShowDialog(&minfoShowDialog, NULL);
const char enumStrSubMenuFoods_0[]  = "Pizza";
const char enumStrSubMenuFoods_1[]  = "Pasta";
const char enumStrSubMenuFoods_2[]  = "Salad";
const char enumStrSubMenuFoods_3[]  = "Beef";
const char enumStrSubMenuFoods_4[]  = "Falafel";
const char* const enumStrSubMenuFoods[]  = { enumStrSubMenuFoods_0, enumStrSubMenuFoods_1, enumStrSubMenuFoods_2, enumStrSubMenuFoods_3, enumStrSubMenuFoods_4 };
const EnumMenuInfo minfoSubMenuFoods = { "Foods", 10, 0xFFFF, 4, NO_CALLBACK, enumStrSubMenuFoods };
EnumMenuItem menuSubMenuFoods(&minfoSubMenuFoods, 0, NULL);
RENDERING_CALLBACK_NAME_INVOKE(fnSubMenuEditIPRtCall, ipAddressRenderFn, "Edit IP", -1, NO_CALLBACK)
IpAddressMenuItem menuSubMenuEditIP(fnSubMenuEditIPRtCall, 9, &menuSubMenuFoods);
RENDERING_CALLBACK_NAME_INVOKE(fnSubMenuIPAddressRtCall, ipAddressRenderFn, "IP Address", -1, NO_CALLBACK)
IpAddressMenuItem menuSubMenuIPAddress(fnSubMenuIPAddressRtCall, 8, &menuSubMenuEditIP);
RENDERING_CALLBACK_NAME_INVOKE(fnSubMenuLargeNumRtCall, largeNumItemRenderFn, "Large Num", -1, NO_CALLBACK)
EditableLargeNumberMenuItem menuSubMenuLargeNum(fnSubMenuLargeNumRtCall, 7, 7, 3, &menuSubMenuIPAddress);
const SubMenuInfo minfoSubMenu = { "Sub Menu", 6, 0xFFFF, 0, NO_CALLBACK };
RENDERING_CALLBACK_NAME_INVOKE(fnSubMenuRtCall, backSubItemRenderFn, "Sub Menu", -1, NO_CALLBACK)
BackMenuItem menuBackSubMenu(fnSubMenuRtCall, &menuSubMenuLargeNum);
SubMenuItem menuSubMenu(&minfoSubMenu, &menuBackSubMenu, &menuShowDialog);
const FloatMenuInfo minfoA0Value = { "A0 Value", 5, 0xFFFF, 3, NO_CALLBACK };
FloatMenuItem menuA0Value(&minfoA0Value, &menuSubMenu);
const BooleanMenuInfo minfoABoolean = { "A Boolean", 4, 0xFFFF, 1, onUserButton, NAMING_TRUE_FALSE };
BooleanMenuItem menuABoolean(&minfoABoolean, false, &menuA0Value);
const AnalogMenuInfo minfoAnalogValue = { "Analog Value", 2, 0xFFFF, 100, onAnalogChange, 0, 1, "" };
AnalogMenuItem menuAnalogValue(&minfoAnalogValue, 0, &menuABoolean);


// Set up code

void setupMenu() {
    menuSubMenuIPAddress.setReadOnly(true);

    renderer.setUpdatesPerSecond(10);
    renderer.prepareDisplay(false, &FreeSans12pt7b, 1, &FreeSans12pt7b, 1, true);
    touchScreen.start();
    menuMgr.initWithoutInput(&renderer, &menuAnalogValue);
}
