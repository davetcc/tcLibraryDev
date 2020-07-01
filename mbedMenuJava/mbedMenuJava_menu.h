/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#ifndef MENU_GENERATED_CODE_H
#define MENU_GENERATED_CODE_H

#include <mbed.h>
#include <tcMenu.h>

#include <LiquidCrystalIO.h>
#include <IoAbstractionWire.h>
#include "MBedEthernetTransport.h"
#include <RemoteConnector.h>
#include <RuntimeMenuItem.h>
#include <EditableLargeNumberMenuItem.h>
#include "tcMenuLiquidCrystal.h"

// all define statements needed
#define LCD_WIDTH 20
#define LCD_HEIGHT 4
#define I2C_ADDRESS 0x40
#define PIN_LAYOUT RS_RW_EN
#define WIRE_VARIABLE i2c
#define PULLUP_LOGIC true
#define INTERRUPT_SWITCHES false
#define SWITCH_IODEVICE 
#define ENCODER_PIN_A PA_6
#define ENCODER_PIN_B PD_14
#define ENCODER_PIN_OK PA_5
#define LISTEN_PORT 3333

// all variables that need exporting
extern I2C i2c;
extern LiquidCrystal lcd;
extern LiquidCrystalRenderer renderer;

// all menu item forward references.
extern EnumMenuItem menuSubMenuFoods;
extern IpAddressMenuItem menuSubMenuEditIP;
extern IpAddressMenuItem menuSubMenuIPAddress;
extern EditableLargeNumberMenuItem menuSubMenuLargeNum;
extern BackMenuItem menuBackSubMenu;
extern SubMenuItem menuSubMenu;
extern FloatMenuItem menuA0Value;
extern BooleanMenuItem menuABoolean;
extern AnalogMenuItem menuAnalogValue;
extern DateFormattedMenuItem menuRTCDate;
extern TimeFormattedMenuItem menuRTCTime;
extern const ConnectorLocalInfo applicationInfo;

// Callback functions must always include CALLBACK_FUNCTION after the return type
#define CALLBACK_FUNCTION

void CALLBACK_FUNCTION onUserButton(int id);

void setupMenu();

#endif // MENU_GENERATED_CODE_H