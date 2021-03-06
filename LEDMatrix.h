#ifndef _LEDMATRIX_H_
#define _LEDMATRIX_H_
/*******************************************************************************
* \file    LEDMatrix.h
********************************************************************************
* \author  Jascha Haldemann jh@oxon.ch
* \date    01.02.2017
* \version 1.0
*
* \brief   LED matrix class with basic functions to draw something
*
* \license LGPL-V2.1
* Copyright (c) 2017 OXON AG. All rights reserved.
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, see 'http://www.gnu.org/licenses/'
********************************************************************************
* LEDMatrix Library
*******************************************************************************/

/* ============================== Global imports ============================ */
#include <Arduino.h>
#include <avr/pgmspace.h>

/* ==================== Global module constant declaration ================== */

/* ========================= Global macro declaration ======================= */

/* ============================ Class declaration =========================== */
class LEDMatrix
{
public:
  /* Constructor(s) and  Destructor */
  LEDMatrix(uint8_t x, uint8_t y) : x_(x), y_(y) {};
  ~LEDMatrix() {};

  /* Public member functions */
  void movePixel(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
  void animatePixel(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint16_t stepSpeed);

  void drawHLine(uint8_t x, uint8_t y, uint8_t l, uint8_t b);
  void drawVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t b);
  void drawRectangle(uint8_t x, uint8_t y, uint8_t l, uint8_t h, uint8_t b);
  void drawFilledRectangle(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  void drawCircle(uint8_t x0, uint8_t y0, uint8_t r, uint8_t b);
  void drawFilledCircle(uint8_t x0, uint8_t y0, uint8_t r, uint8_t b);
  void drawTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t b);
  void drawFilledTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t b);

  void drawPicture(uint8_t x0, uint8_t y0, uint8_t l, uint8_t h, const uint8_t *image);

  void drawChar(uint8_t x, uint8_t y, char c, uint8_t b);
  void drawString(uint8_t x, uint8_t y, const char *str, uint8_t b);
  void runningText(uint8_t x, uint8_t y, const char* str, uint8_t b, uint16_t stepSpeed);

  void rotateContentCW();
  void rotateContentACW();

  /* Public virtual functions */
  // MUST be defined by the subclass
  virtual void drawPixel(uint8_t x, uint8_t y, uint8_t brightness);
  virtual uint8_t getPixel(uint8_t x, uint8_t y);

  // CAN be defined by the subclass
  virtual void fillScreen(uint8_t b);
  virtual void clear();
  virtual void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t b);

protected:
  /* Protected constant declerations (static) */
  static const uint8_t MAX_BRIGHTNESS_VALUE = 255;
  static const uint8_t CHAR_SPACING_OFFSET = 1;
  static const uint8_t ASCII_FIRST_CHARACTER_OFFSET = 32;

  /* Protected member data */
  uint8_t x_;
  uint8_t y_;

  /* Protected member functions */
  void setPixel(uint8_t x, uint8_t y, uint8_t brightness) {drawPixel(x, y, brightness);}
  void clearPixel(uint8_t x, uint8_t y) {drawPixel(x, y, 0);}

  /* Protected class functions (static) */
  static void swap(uint8_t *a, uint8_t *b) {uint8_t temp = *a; *a = *b; *b = temp;}
  static int8_t sgn(int16_t a) {if (a > 0) return 1; if (a < 0) return -1; return 0;}
};

/* Pictures ----------------------------------------------------------------- */
#define LED_MATRIX_PICTURE_X             8
#define LED_MATRIX_PICTURE_Y             8
#define LED_MATRIX_FONTSIZE              5
#define LED_MATRIX_FONTWIDTH             3
#define NUMBER_OF_DIFFERENT_CHARACTERS   97

/* happy smile */
PROGMEM const uint8_t picture0[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // row 0
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00,  // row 1
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00,  // row 2
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // row 3
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 4
  0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,  // row 5
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 6
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   // row 7
};

/* sad smile */
PROGMEM const uint8_t picture1[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // row 0
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00,  // row 1
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00,  // row 2
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // row 3
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 4
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // row 5
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 6
  0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00   // row 7
};

/* tick mark */
PROGMEM const uint8_t picture2[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 0
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,  // row 1
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,  // row 2
  0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF,  // row 3
  0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF,  // row 4
  0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF,  // row 5
  0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,  // row 6
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF   // row 7
};

/* cross */
PROGMEM const uint8_t picture3[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 0
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,  // row 1
  0xFF, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF,  // row 2
  0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF,  // row 3
  0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF,  // row 4
  0xFF, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF,  // row 5
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,  // row 6
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF   // row 7
};

/* ! */
PROGMEM const uint8_t picture4[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 0
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 1
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 2
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 3
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 4
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // row 5
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 6
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00   // row 7
};

/* ? */
PROGMEM const uint8_t picture5[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 0
  0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00,  // row 1
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,  // row 2
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 3
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 4
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // row 5
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 6
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00   // row 7
};

/* heart */
PROGMEM const uint8_t picture6[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
    // row 0
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00,  // row 0
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 1
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 2
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 3
  0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,  // row 4
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 5
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 6
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00   // row 7
};

/* star */
PROGMEM const uint8_t picture7[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,  // row 0
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 1
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 2
  0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,  // row 3
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 4
  0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 5
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00,  // row 6
  0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF   // row 7
};

/* sun */
PROGMEM const uint8_t picture8[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF,  // row 0
  0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00,  // row 1
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 2
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 3
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 4
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,  // row 5
  0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00,  // row 6
  0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF   // row 7
};

/* couvert */
PROGMEM const uint8_t picture9[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // row 0
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 1
  0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,  // row 2
  0xFF, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF,  // row 3
  0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF,  // row 4
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,  // row 5
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 6
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   // row 7
};

/* couvert */
PROGMEM const uint8_t picture10[LED_MATRIX_PICTURE_X*LED_MATRIX_PICTURE_Y] =
{ /*columns:
      0     1     2     3     4     5     6     7 */
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,  // row 0
  0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00,  // row 1
  0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,  // row 2
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // row 3
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,  // row 4
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,  // row 5
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,  // row 6
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF   // row 7
};

/* Simple Font -------------------------------------------------------------- */
PROGMEM const uint8_t characters[NUMBER_OF_DIFFERENT_CHARACTERS][LED_MATRIX_FONTSIZE][LED_MATRIX_FONTWIDTH] =
{
  {  // ' '
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {  // '!'
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0}
  },
  {  // '"'
    {0, 1, 0},
    {0, 1, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {  // '#'
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1}
  },
  {  // '$'
    {1, 1, 1},
    {1, 1, 0},
    {1, 1, 1},
    {0, 1, 1},
    {1, 1, 1}
  },
  {  // '%'
    {1, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
    {0, 0, 1}
  },
  {  // '&'
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 1}
  },
  {  // '''
    {0, 1, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {  // '('
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 0, 1}
  },
  {  // ')'
    {1, 0, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {1, 0, 0}
  },
  {  // '*'
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1},
    {0, 0, 0}
  },
  {  // '+'
    {0, 0, 0},
    {0, 1, 0},
    {1, 1, 1},
    {0, 1, 0},
    {0, 0, 0}
  },
  {  // ','
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0}
  },
  {  // '-'
    {0, 0, 0},
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}
  },
  {  // '.'
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {1, 0, 0}
  },
  {  // '/'
    {0, 0, 1},
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
    {1, 0, 0}
  },
  {  // '0'
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {  // '1'
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {  // '2'
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1}
  },
  {  // '3'
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1}
  },
  {  // '4'
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {  // '5'
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1}
  },
  {  // '6'
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {  // '7'
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {  // '8'
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {  // '9'
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {1, 1, 1}
  },
  {  // ':'
    {0, 0, 0},
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0}
  },
  {  // ';'
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0}
  },
  {  // '<'
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
  },
  {  // '='
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  },
  {  // '>'
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0}
  },
  {  // '?'
    {1, 1, 0},
    {0, 0, 1},
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0}
  },
  {  // '@'
    {0, 1, 0},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 0},
    {0, 1, 1}
  },
  {  // 'A'
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1}
  },
  {  // 'B'
    {1, 1, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 0, 1},
    {1, 1, 0}
  },
  {  // 'C'
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0},
    {0, 1, 1}
  },
  {  // 'D'
    {1, 1, 0},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 0}
  },
  {  // 'E'
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1}
  },
  {  // 'F'
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 0},
    {1, 0, 0},
    {1, 0, 0}
  },
  {  // 'G'
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 0}
  },
  {  // 'H'
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1}
  },
  {  // 'I'
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {  // 'J'
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {1, 0, 1},
    {0, 1, 0}
  },
  {  // 'K'
    {1, 0, 1},
    {1, 1, 0},
    {1, 0, 0},
    {1, 1, 0},
    {1, 0, 1}
  },
  {  // 'L'
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0},
    {1, 1, 1}
  },
  {  // 'M'
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1}
  },
  {  // 'N'
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1}
  },
  {  // 'O'
    {0, 1, 0},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 0}
  },
  {  // 'P'
    {1, 1, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 0, 0},
    {1, 0, 0}
  },
  {  // 'Q'
    {0, 1, 0},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 1}
  },
  {  // 'R'
    {1, 1, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 0},
    {1, 0, 1}
  },
  {  // 'S'
    {0, 1, 1},
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 0}
  },
  {  // 'T'
    {1, 1, 1},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {  // 'U'
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {  // 'V'
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 0}
  },
  {  // 'W'
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1}
  },
  {  // 'X'
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1},
    {1, 0, 1}
  },
  {  // 'Y'
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {  // 'Z'
    {1, 1, 1},
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1}
  },
  {  // '['
    {0, 1, 1},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 1}
  },
  {  // '\'
    {1, 0, 0},
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {0, 0, 1}
  },
  {  // ']'
    {1, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {1, 1, 0}
  },
  {  // '^'
    {0, 1, 0},
    {1, 0, 1},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {  // '_'
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {1, 1, 1}
  },
  {  // '`'
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  },
  {  // 'a'
    {1, 1, 0},
    {0, 0, 1},
    {0, 1, 1},
    {1, 0, 1},
    {0, 1, 1}
  },
  {  // 'b'
    {1, 0, 0},
    {1, 0, 0},
    {1, 1, 0},
    {1, 0, 1},
    {1, 1, 0}
  },
  {  // 'c'
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 0},
    {0, 1, 1}
  },
  {  // 'd'
    {0, 0, 1},
    {0, 0, 1},
    {0, 1, 1},
    {1, 0, 1},
    {0, 1, 1}
  },
  {  // 'e'
    {0, 1, 0},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 0},
    {0, 1, 1}
  },
  {  // 'f'
    {0, 1, 1},
    {1, 0, 0},
    {1, 1, 0},
    {1, 0, 0},
    {1, 0, 0}
  },
  {  // 'g'
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 1},
    {0, 0, 1},
    {1, 1, 0}
  },
  {  // 'h'
    {1, 0, 0},
    {1, 0, 0},
    {1, 1, 0},
    {1, 0, 1},
    {1, 0, 1}
  },
  {  // 'i'
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {  // 'j'
    {0, 0, 1},
    {0, 0, 0},
    {0, 0, 1},
    {1, 0, 1},
    {0, 1, 0}
  },
  {  // 'k'
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 0, 1}
  },
  {  // 'l'
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0}
  },
  {  // 'm'
    {0, 0, 0},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1}
  },
  {  // 'n'
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1}
  },
  {  // 'o'
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 0}
  },
  {  // 'p'
    {0, 1, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 0, 0},
    {1, 0, 0}
  },
  {  // 'q'
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 1},
    {0, 0, 1},
    {0, 0, 1}
  },
  {  // 'r'
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 1},
    {1, 0, 0},
    {1, 0, 0}
  },
  {  // 's'
    {0, 1, 1},
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 0}
  },
  {  // 't'
    {0, 1, 0},
    {0, 1, 0},
    {1, 1, 1},
    {0, 1, 0},
    {0, 1, 0}
  },
  {  // 'u'
    {0, 0, 0},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1}
  },
  {  // 'v'
    {0, 0, 0},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 0}
  },
  {  // 'w'
    {0, 0, 0},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1}
  },
  {  // 'x'
    {0, 0, 0},
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1}
  },
  {  // 'y'
    {0, 0, 0},
    {1, 0, 1},
    {1, 0, 1},
    {0, 1, 0},
    {0, 1, 0}
  },
  {  // 'z'
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 1},
    {0, 1, 0},
    {1, 1, 1}
  },
  {  // '{'
    {0, 0, 1},
    {0, 1, 0},
    {1, 1, 0},
    {0, 1, 0},
    {0, 0, 1}
  },
  {  // '|'
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {  // '}'
    {1, 0, 0},
    {0, 1, 0},
    {0, 1, 1},
    {0, 1, 0},
    {1, 0, 0}
  },
  {  // '~'
    {0, 0, 0},
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 0},
    {0, 0, 0}
  }
};

#endif
