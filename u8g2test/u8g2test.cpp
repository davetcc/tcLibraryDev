/****************************************************************************************************************************
  Async_HelloServer.h - Dead simple AsyncWebServer for STM32 LAN8720 or built-in LAN8742A Ethernet

  For STM32 with LAN8720 (STM32F4/F7) or built-in LAN8742A Ethernet (Nucleo-144, DISCOVERY, etc)

  AsyncWebServer_STM32 is a library for the STM32 with LAN8720 or built-in LAN8742A Ethernet WebServer

  Based on and modified from ESPAsyncWebServer (https://github.com/me-no-dev/ESPAsyncWebServer)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncWebServer_STM32
  Licensed under MIT license
 *****************************************************************************************************************************/


#if defined(STM32F0)
#warning STM32F0 board selected
  #define BOARD_TYPE  "STM32F0"
#elif defined(STM32F1)
#warning STM32F1 board selected
  #define BOARD_TYPE  "STM32F1"
#elif defined(STM32F2)
#warning STM32F2 board selected
  #define BOARD_TYPE  "STM32F2"
#elif defined(STM32F3)
#warning STM32F3 board selected
  #define BOARD_TYPE  "STM32F3"
#elif defined(STM32F4)
#warning STM32F4 board selected
  #define BOARD_TYPE  "STM32F4"
#elif defined(STM32F7)
#warning STM32F7 board selected
  #define BOARD_TYPE  "STM32F7"
#elif defined(STM32L0)
#warning STM32L0 board selected
  #define BOARD_TYPE  "STM32L0"
#elif defined(STM32L1)
#warning STM32L1 board selected
  #define BOARD_TYPE  "STM32L1"
#elif defined(STM32L4)
#warning STM32L4 board selected
  #define BOARD_TYPE  "STM32L4"
#elif defined(STM32H7)
#warning STM32H7 board selected
  #define BOARD_TYPE  "STM32H7"
#elif defined(STM32G0)
#warning STM32G0 board selected
  #define BOARD_TYPE  "STM32G0"
#elif defined(STM32G4)
#warning STM32G4 board selected
  #define BOARD_TYPE  "STM32G4"
#elif defined(STM32WB)
#warning STM32WB board selected
  #define BOARD_TYPE  "STM32WB"
#elif defined(STM32MP1)
#warning STM32MP1 board selected
  #define BOARD_TYPE  "STM32MP1"
#else
#warning STM32 unknown board selected
#define BOARD_TYPE  "STM32 Unknown"
#endif

#ifndef BOARD_NAME
#define BOARD_NAME    BOARD_TYPE
#endif

#define SHIELD_TYPE     "LAN8742A built-in Ethernet"

#include <SPI.h>
#include <LwIP.h>
#include <STM32Ethernet.h>
#include <AsyncWebServer_STM32.h>

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
        {
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x01 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x02 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x03 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x04 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x05 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x06 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x07 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x08 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x09 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0A },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0B },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0C },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0D },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0E },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0F },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x10 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x11 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x12 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x13 },
                { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x14 },
        };
// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 232);

AsyncWebServer    server(80);

const int led = 13;

void handleRoot(AsyncWebServerRequest *request)
{
    digitalWrite(led, 1);
    request->send(200, "text/plain", String("Hello from AsyncWebServer_STM32 on ") + BOARD_NAME );
    digitalWrite(led, 0);
}

void handleNotFound(AsyncWebServerRequest *request)
{
    digitalWrite(led, 1);
    String message = "File Not Found\n\n";

    message += "URI: ";
    //message += server.uri();
    message += request->url();
    message += "\nMethod: ";
    message += (request->method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += request->args();
    message += "\n";

    for (uint8_t i = 0; i < request->args(); i++)
    {
        message += " " + request->argName(i) + ": " + request->arg(i) + "\n";
    }

    request->send(404, "text/plain", message);
    digitalWrite(led, 0);
}

void setup(void)
{
    pinMode(led, OUTPUT);
    digitalWrite(led, 0);

    Serial.begin(115200);
    while (!Serial);

    delay(200);

    Serial.print("\nStart Async_HelloServer on "); Serial.print(BOARD_NAME);
    Serial.print(" with "); Serial.println(SHIELD_TYPE);
    Serial.println(ASYNC_WEBSERVER_STM32_VERSION);

    // start the ethernet connection and the server
    // Use random mac
    uint16_t index = millis() % NUMBER_OF_MAC;

    // Use Static IP
    //Ethernet.begin(mac[index], ip);
    // Use DHCP dynamic IP and random mac
    Ethernet.begin(mac[index]);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest * request)
    {
        handleRoot(request);
    });

    server.on("/inline", [](AsyncWebServerRequest * request)
    {
        request->send(200, "text/plain", "This works as well");
    });

    server.onNotFound(handleNotFound);

    server.begin();

    Serial.print(F("HTTP EthernetWebServer is @ IP : "));
    Serial.println(Ethernet.localIP());
}

void loop(void)
{
}