#ifndef MYMYNU_H
#define MYMYNU_H
#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "enums.h"

#define _LCD_COLS_ 20
#define _LCD_ROWS_ 4

class myMenu
{
private:
    LiquidCrystal_I2C *lcd;
    byte *BT_ST;
    uint8_t *AppMode;

    uint8_t lastCursor[3] = {0, 0, 0};
    uint8_t lastScroll[3] = {0, 0, 0};
    uint8_t lastMenuNb[3] = {0, 0, 0};

    uint8_t curMenu, child, scroll, cursor, menuOffset, menuLevel;
    bool menuIsOn, scrollMenu;

    int *value_p, *v_p;
    uint8_t *enu_p, *e_p;

public:
    myMenu(LiquidCrystal_I2C *lcd, int *value_p, uint8_t *enu_p, byte *BT_ST, uint8_t *AppMode);
    void MenuStart();
    void DrawMenu();
    void MoveUp();
    void MoveDown();
    void UpdateCursor();
    bool ChceckBtn(uint8_t btn);
    void SetButton(uint8_t btn);
    void ClearButton(uint8_t btn);
    bool CheckAnyBtn();
    void ClearAllBtn();
    void IncData();
    void DecData();
    void GetMenu(uint8_t menuNumber);
    void GetValueLine(char *bufOut, uint8_t _id, uint8_t call);
    void GetMenuItemLine(char *bufOut, uint8_t _id);
    void GetEnumValLine(char *bufOut, uint8_t id, uint8_t call);
    void GetCallBackLine(char *bufOut, uint8_t _id);
    void GetEnumLine(char *bufOut, uint8_t id, uint8_t call);
    void UpdateMenu();
    void PrintLine(uint8_t line);
};

#endif // !1