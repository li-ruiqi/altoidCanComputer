// Include application, user and local libraries
#include "SPI.h"
#include "TFT_22_ILI9225.h"

#define TFT_RST 9
#define TFT_RS  10
#define TFT_CS  8
#define TFT_SDI 11
#define TFT_CLK 13
#define TFT_LED 0

#define TFT_BRIGHTNESS 200

#define BUTTON_UP 4
#define BUTTON_DOWN 5
#define BUTTON_RIGHT 6
#define BUTTON_LEFT 3
#define BUTTON_ENTER 2

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);

const uint8_t ARROW_BACK[] PROGMEM = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xFF, 0x0F, 0x60, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x84, 0x97, 0x01, 0x48, 0xCA, 0xD0, 0x00, 0x48, 0x51, 0x70, 0x00, 0x38, 0x5F, 0x30, 0x00, 0x48, 0x51, 0x70, 0x00, 0x48, 0xD1, 0xD0, 0x00, 0x38, 0x91, 0x97, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char "
};
const uint8_t ARROW_NEXT[] PROGMEM = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x06, 0xF0, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0xBE, 0xE8, 0x03, 0x98, 0x82, 0x8D, 0x00, 0x98, 0x02, 0x87, 0x00, 0xA8, 0x1E, 0x82, 0x00, 0xC8, 0x02, 0x87, 0x00, 0xC8, 0x82, 0x8D, 0x00, 0x88, 0xBE, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char #
};

const uint8_t ARROW_CLEAR[] PROGMEM = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char )
};

void drawArrowBitmap(const uint8_t *ARROW, int color, int x, int y, bool isBold)
{
  tft.drawXBitmap(x, y, ARROW, 32, 32, color);
  if(isBold)
    tft.drawRectangle(x, y, x + 31, y + 31, color);
  else
    tft.drawRectangle(x, y, x + 31, y + 31, 0x0000);
}
void screenClear()
{
  tft.clear();
  tft.drawRectangle(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_WHITE);
  drawArrowBitmap(ARROW_BACK, 0xFFFF, 5, tft.maxY() - 38, false);
  drawArrowBitmap(ARROW_NEXT, 0xFFFF, tft.maxX() - 38, tft.maxY() - 38, false);
}

void text_presentation(int SCREEN_val)
{
  tft.setFont(Terminal6x8);
  tft.drawText(5,5,String(SCREEN_val), 0x07E0);
  
  if(SCREEN_val == 1)
  {
    tft.drawText(43, 5, "Hi! Welcome to the", COLOR_WHITE);
    tft.drawText(43, 14, "AltoidTinComputer", COLOR_YELLOW);
    tft.drawText(43, 23, "(TM)! This was progr-", COLOR_WHITE);
    tft.drawText(43, 32, "amed by ", COLOR_WHITE);
    tft.drawText(92, 32, "Ruiqi Li", COLOR_YELLOW);
  }
  else if(SCREEN_val == 2)
  {
    tft.drawText(43, 5, "Materials are bought", COLOR_WHITE);
    tft.drawText(43, 14, "from amazon/adafru-", COLOR_WHITE);
    tft.drawText(43, 23, "it. Materials:", COLOR_WHITE);
    tft.drawRectangle(65, 35, 66, 36, COLOR_WHITE);
    
    tft.drawText(69, 32, "Arduino Nano", COLOR_WHITE);
    tft.drawRectangle(65, 35, 66, 36, COLOR_BLUE);
    
    tft.drawText(69, 41, "Li-Ion battery", COLOR_WHITE);
    tft.drawRectangle(65, 44, 66, 45, COLOR_BLUE);
    
    tft.drawText(69, 50, "Buttons (5)", COLOR_WHITE);
    tft.drawRectangle(65, 53, 66, 54, COLOR_BLUE);
    
    tft.drawText(69, 50, "Powerboost 500", COLOR_WHITE);
    tft.drawText(69, 59, "charger (Adafruit)", COLOR_WHITE);
    tft.drawRectangle(65, 53, 66, 54, COLOR_BLUE);

    tft.drawText(69, 68, "3.5\" TFT screen", COLOR_WHITE);
    tft.drawRectangle(65, 71, 66, 72, COLOR_BLUE);

    tft.drawText(69, 77, "An Altoid Tin.", COLOR_WHITE);
    tft.drawRectangle(65, 80, 66, 81, COLOR_BLUE);
  }
  else if(SCREEN_val == 3)
  {
    tft.drawText(43, 5, "Code for this is on", COLOR_WHITE);
    tft.drawText(43, 14, "GitHub. GitHub is a", COLOR_WHITE);
    tft.drawText(43, 23, "very useful version", COLOR_WHITE);
    tft.drawText(43, 32, "contorl site. Whee!", COLOR_WHITE);
    tft.drawText(43, 41, "I use it a lot. -_-", COLOR_WHITE);
  }
  else if(SCREEN_val == 4)
  {
    tft.drawText(43, 5, "The code that displays", COLOR_WHITE);
    tft.drawText(43, 14, "thing on the TFT LCD", COLOR_WHITE);
    tft.drawText(43, 23, "screen is from the", COLOR_WHITE);
    tft.drawText(43, 32, "libary:", COLOR_WHITE);
    tft.drawText(43, 41, "TFT_22_ILI9225.h", COLOR_CYAN);
    tft.drawText(43, 50, "from GitHub.", COLOR_WHITE);
  }
  else if(SCREEN_val == 5)
  {
    tft.drawText(43, 5, "I want to thank my", COLOR_WHITE);
    tft.drawText(43, 14, "dad for buying stuff", COLOR_WHITE);
    tft.drawText(43, 23, "and supporting me.", COLOR_WHITE);
    tft.drawText(43, 32, "I enjoyed doing this", COLOR_WHITE);
    tft.drawText(43, 41, "project. It was cool", COLOR_WHITE);
    tft.drawText(43, 50, "BTW i was listening to", COLOR_WHITE);
    tft.drawText(43, 59, "UNDERTALE music while", COLOR_WHITE);
    tft.drawText(43, 68, "coding this", COLOR_WHITE);
  }
  else if(SCREEN_val == 6)
  {
    tft.drawText(43, 5, "The NEXT and BACK", COLOR_WHITE);
    tft.drawText(43, 14, "buttons on the screen", COLOR_WHITE);
    tft.drawText(43, 23, "(bitmaps) are made in", COLOR_WHITE);
    tft.drawText(43, 32, "a font maker(don't ask)", COLOR_WHITE);
  }
  else if(SCREEN_val == 7)
  {
    tft.drawText(43, 5, "Cool stuff I can do:", COLOR_WHITE);
    tft.drawText(43, 14, "Color text:", COLOR_WHITE);
    tft.drawText(43, 23, "Red", COLOR_RED);
    tft.drawText(43, 32, "Orange", COLOR_ORANGE);
    tft.drawText(43, 41, "Yellow", COLOR_YELLOW);
    tft.drawText(43, 50, "Green", COLOR_GREEN);
    tft.drawText(43, 59, "Blue", COLOR_BLUE);
    tft.drawText(43, 68, "Indigo", COLOR_INDIGO);
    tft.drawText(43, 77, "Purple", COLOR_VIOLET);
  }
}

int SCREEN_val = 0;

void setup() {
  tft.begin();
  Serial.begin(9600);

  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_ENTER, INPUT_PULLUP);
  
  tft.setOrientation(1);
  screenClear();
}

int button = -1;
void loop(){
  temmie:

  tft.setFont(Terminal6x8);
  
    if(!digitalRead(BUTTON_UP)) 
    {
      button = 0;
    }
    if(!digitalRead(BUTTON_DOWN))
    {
      button = 1;
    }
    if(!digitalRead(BUTTON_RIGHT)) 
    { 
      button = 2;
      drawArrowBitmap(ARROW_BACK, 0xFFFF, 5, tft.maxY() - 38, false);
      drawArrowBitmap(ARROW_NEXT, 0xFFFF, tft.maxX() - 38, tft.maxY() - 38, true);
    }
    if(!digitalRead(BUTTON_LEFT))
    {
      button = 3;
      drawArrowBitmap(ARROW_NEXT, 0xFFFF, tft.maxX() - 38, tft.maxY() - 38, false);
      drawArrowBitmap(ARROW_BACK, 0xFFFF, 5, tft.maxY() - 38, true);
    }
    if(!digitalRead(BUTTON_ENTER))
    {
      if(button == 0)
      {
      // do whatever
      }
      else if(button == 1)
      {
      // do whatever
      }
      else if(button == 2)
      {
        screenClear();
        SCREEN_val ++;
        button = -1;
        text_presentation(SCREEN_val);
      }
      else if(button == 3)
      {
        screenClear();
        if(SCREEN_val > 1)
          SCREEN_val --;
        button = -1;
        text_presentation(SCREEN_val);
      }
      
    }
}
