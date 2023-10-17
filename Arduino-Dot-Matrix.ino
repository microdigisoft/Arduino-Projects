//import libraries
#include < MD_MAX72xx.h>
//#include < SPI.h>
#define  DEBUG  1
#if  DEBUG
#define PRINT(s, x) { Serial.print(F(s)); Serial.print(x); }
#define PRINTS(x) Serial.print(F(x))
#define PRINTD(x) Serial.println(x, DEC)
#else
#define PRINT(s, x)
#define PRINTS(x)
#define PRINTD(x)

#endif

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES  11

#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

// SPI hardware interface
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary pins
//MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// We always wait a bit between updates of the display
#define  DELAYTIME  100  // in milliseconds

void scrollText(const char *p)
{
  uint8_t charWidth;
  uint8_t cBuf[8];  // this should be ok for all built-in fonts

  PRINTS("\nScrolling text");
  mx.clear();

  while (*p != '\0')
  {
    charWidth = mx.getChar(*p++, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);

    for (uint8_t i=0; i<=charWidth; i++)  // allow space between characters
    {
      mx.transform(MD_MAX72XX::TSL);
      if (i < charWidth)
        mx.setColumn(0, cBuf[i]);
      delay(DELAYTIME);
    }
  }
}

void zeroPointSet()
// Demonstrates the use of setPoint and
// show where the zero point is in the display
{
  PRINTS("\nZero point highlight");
  mx.clear();

  if (MAX_DEVICES > 1)
    mx.setChar((2*COL_SIZE)-1, '0');

  for (uint8_t i=0; i7");
  mx.clear();

  for (uint8_t row=0; row rmin) && (cmax > cmin))
  {
    // do row
    for (int i=cmin; i<=cmax; i++)
    {
      mx.setPoint(rmin, i, true);
      delay(DELAYTIME/MAX_DEVICES);
    }
    rmin++;

    // do column
    for (uint8_t i=rmin; i<=rmax; i++)
    {
      mx.setPoint(i, cmax, true);
      delay(DELAYTIME/MAX_DEVICES);
    }
    cmax--;

    // do row
    for (int i=cmax; i>=cmin; i--)
    {
      mx.setPoint(rmax, i, true);
      delay(DELAYTIME/MAX_DEVICES);
    }
    rmax--;

    // do column
    for (uint8_t i=rmax; i>=rmin; i--)
    {
      mx.setPoint(i, cmin, true);
      delay(DELAYTIME/MAX_DEVICES);
    }
    cmin++;
  }
}

void blinking()
// Uses the test function of the MAX72xx to blink the display on and off.
{
  int  nDelay = 1000;

  PRINTS("\nBlinking");
  mx.clear();

  while (nDelay > 0)
  {
    mx.control(MD_MAX72XX::TEST, MD_MAX72XX::ON);
    delay(nDelay);
    mx.control(MD_MAX72XX::TEST, MD_MAX72XX::OFF);
    delay(nDelay);

    nDelay -= DELAYTIME;
  }
}

void scanLimit(void)
// Uses scan limit function to restrict the number of rows displayed.
{
  PRINTS("\nScan Limit");
  mx.clear();

  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
  for (uint8_t row=0; row=0; s--)
  {
    mx.control(MD_MAX72XX::SCANLIMIT, s);
    delay(DELAYTIME*5);
  }
  mx.control(MD_MAX72XX::SCANLIMIT, MAX_SCANLIMIT);
}

void setup()
{
  mx.begin();

#if  DEBUG
  Serial.begin(57600);
#endif
  PRINTS("\n[MD_MAX72XX Test & Demo]");
//  scrollText("MD_MAX72xx Test  ");
}

void loop()
{
#if 1
  scrollText("Graphics");
  zeroPointSet();
  rows();
  columns();
  cross();
  stripe();
  checkboard();
  bullseye();
  bounce();
  spiral();
#endif

#if 1
  scrollText("Control");
  intensity();
  scanLimit();
  blinking();
#endif

#if 1
  scrollText("Transform");
  transformation1();
  transformation2();
#endif

#if 1
