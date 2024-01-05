#include "FastLED.h"
// Fastled constants
#define DATA_PIN 2
#define COLOR_ORDER GRB
#define NUM_LEDS 64
#define LED_TYPE WS2812B
#define BRIGHTNESS 64
CRGB leds[NUM_LEDS];

#define LED_PIN 1 // Built in LED

void setup()
{
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  pinMode(LED_PIN, OUTPUT);
}

void anim1()
{
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
  digitalWrite(LED_PIN, LOW); //  Turn the LED on
  delay(200);
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  delay(200);
  fill_solid(leds, NUM_LEDS, CRGB::Green);
  FastLED.show();
  digitalWrite(LED_PIN, HIGH); //  Turn the LED off
  delay(200);
  fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  delay(200);
}

void loop()
{
  anim1();
}