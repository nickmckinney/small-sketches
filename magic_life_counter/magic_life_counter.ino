#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306();
uint8_t lifeTotal;
bool btnA;
bool btnB;
bool btnC;

#define BUTTON_A 9
#define BUTTON_B 6
#define BUTTON_C 5

#define STARTING_LIFE_TOTAL 20

#define LIFE_TOTAL_TEXT_SIZE 3
#define LIFE_TOTAL_CHAR_WIDTH (6 * LIFE_TOTAL_TEXT_SIZE)
#define LIFE_TOTAL_CHAR_HEIGHT (8 * LIFE_TOTAL_TEXT_SIZE)
#define LIFE_TOTAL_START_Y 11

void printLifeTotal()
{
  int x, toShow;
  char digit;

  x = 128;
  toShow = lifeTotal;

  do
  {
    digit = '0' + (char)(toShow % 10);
    x -= LIFE_TOTAL_CHAR_WIDTH;
    display.drawChar(x, LIFE_TOTAL_START_Y, digit, WHITE, BLACK, LIFE_TOTAL_TEXT_SIZE);
    toShow /= 10;
  } while(toShow > 0);

  display.fillRect(0, LIFE_TOTAL_START_Y, x, LIFE_TOTAL_CHAR_HEIGHT, BLACK);
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Magic: the Gathering");

  lifeTotal = STARTING_LIFE_TOTAL;
  printLifeTotal();
  
  display.display();

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  btnA = btnB = btnC = false;
}

bool detectButtonPress(int pin, bool &state)
{
  bool oldState = state;
  state = !digitalRead(pin);
  
  return !oldState && state;
}

void loop() {
  bool needDisplay = false;
  
  if(detectButtonPress(BUTTON_A, btnA))
  {
    needDisplay = true;
    lifeTotal++;
  }
  else if(detectButtonPress(BUTTON_C, btnC))
  {
    needDisplay = true;
    lifeTotal = (lifeTotal == 0 ? 0 : lifeTotal - 1);
  }
  else if(detectButtonPress(BUTTON_B, btnB))
  {
    needDisplay = true;
    lifeTotal = STARTING_LIFE_TOTAL;
  }

  if(needDisplay)
  {
    printLifeTotal();
    display.display();
  }

  delay(20);
}
