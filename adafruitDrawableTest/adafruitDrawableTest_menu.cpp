/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "adafruitDrawableTest_menu.h"
#include "ThemeCoolBlueModern.h"
#include <Fonts/OpenSansCyrillicLatin18.h>
#include <Fonts/RobotoMedium24.h>

// Global variable declarations
const PROGMEM  ConnectorLocalInfo applicationInfo = { "adafruitDrawableTest", "0ad4bdde-34a4-4507-912e-b495b0eac2c1" };

Adafruit_ILI9341 gfx(20, 18, 19);
AdafruitDrawable gfxDrawable(&gfx, 40);
GraphicsDeviceRenderer renderer(30, applicationInfo.name, &gfxDrawable);

// Global Menu Item declarations
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsRGBRtCall, rgbAlphaItemRenderFn, "RGB", -1, NO_CALLBACK)
Rgb32MenuItem menuSettingsRGB(fnSettingsRGBRtCall, RgbColor32(0, 0, 0), 7, false, NULL);
const PROGMEM AnyMenuInfo minfoSettingsAction = { "Action", 6, 0xffff, 0, NO_CALLBACK };
ActionMenuItem menuSettingsAction(&minfoSettingsAction, &menuSettingsRGB);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsRtCall, backSubItemRenderFn, "Settings", -1, NO_CALLBACK)
const PROGMEM SubMenuInfo minfoSettings = { "Settings", 5, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackSettings(fnSettingsRtCall, &menuSettingsAction);
SubMenuItem menuSettings(&minfoSettings, &menuBackSettings, NULL);
const PROGMEM BooleanMenuInfo minfoPower = { "Power", 4, 0xffff, 1, NO_CALLBACK, NAMING_ON_OFF };
BooleanMenuItem menuPower(&minfoPower, false, &menuSettings);
const char enumStrEnum_0[] PROGMEM = "Item1";
const char enumStrEnum_1[] PROGMEM = "Item2";
const char* const enumStrEnum[] PROGMEM  = { enumStrEnum_0, enumStrEnum_1 };
const PROGMEM EnumMenuInfo minfoEnum = { "Enum", 3, 0xffff, 1, NO_CALLBACK, enumStrEnum };
EnumMenuItem menuEnum(&minfoEnum, 0, &menuPower);
const PROGMEM FloatMenuInfo minfoFloat = { "Float", 2, 0xffff, 3, NO_CALLBACK };
FloatMenuItem menuFloat(&minfoFloat, 33.123, &menuEnum);
const PROGMEM AnalogMenuInfo minfoAnalog = { "Analog", 1, 0xffff, 1000, NO_CALLBACK, 0, 10, "V" };
AnalogMenuItem menuAnalog(&minfoAnalog, 222, &menuFloat);

void setupMenu() {
    // First we set up eeprom and authentication (if needed).

    // Code generated by plugins.
    gfx.begin();
    gfx.setRotation(1);
    renderer.setUpdatesPerSecond(5);
    switches.init(internalDigitalIo(), SWITCHES_POLL_EVERYTHING, true);
    menuMgr.initForEncoder(&renderer, &menuAnalog, 16, 17, 21);
    renderer.setTitleMode(BaseGraphicalRenderer::TITLE_FIRST_ROW);
    renderer.setUseSliderForAnalog(true);
    renderer.enableTcUnicode();
    installCoolBlueModernTheme(renderer, MenuFontDef(&OpenSansCyrillicLatin18, 0), MenuFontDef(&RobotoMedium24, 1), false);
}

