/*
 * Comment the Code!
 * ===================================
 * 
 * Welcome to your second Git assignment!
 * 
 * Task: Below is a working program with NO comments. Your job is to add comments that explain what the code does and WHY each part exists.
 * This is a real-world skill—you'll often inherit uncommented code from teammates or past projects.
 *  Rules:
•	Add a file header block comment at the top
•	Add section headers (like // ===== HARDWARE OBJECTS =====)
•	Add inline comments explaining non-obvious lines
•	Add a block comment before each function explaining its purpose
  * Save this file (Ctrl+S on PC, Cmd+S on Mac)
  * Commit your changes using VS Code's Source Control panel
  * 4. Push your changes to GitHub
*/

//The Uncommented Code:

// ============================================
// YOUR NAME AND DATE GO HERE (uncomment and edit the line below):
// 
// Author: Preston Zhang
// Date:  12/5/2025
// AI:  Yes / No I used AI to help me with this assignment.
// ============================================

// ======Hardware Objects=======
#include <Zumo32U4.h> 
 
Zumo32U4ButtonA buttonA;  //Create Button A object
Zumo32U4ButtonB buttonB;  //Create Button B object
Zumo32U4ButtonC buttonC;  //Create Button C object
Zumo32U4OLED display;     //Create display object
 
int mode = 0;
 
void showMode() {   //Original screen display
    display.clear();
    display.setLayout21x8();
    display.gotoXY(0, 0);
    display.print(F("Mode: "));
    display.print(mode);
    
    display.gotoXY(0, 2);   //Alternate Screen Displays after pressing buttons A through C
    if (mode == 0) {
        display.print(F("IDLE"));
    } else if (mode == 1) {
        display.print(F("READY"));
    } else if (mode == 2) {
        display.print(F("RUNNING"));
    }
    
    display.gotoXY(0, 7);
    display.print(F("A:- B:+ C:Reset"));
}
 
void setup() {     //Done Once
    Serial.begin(115200);    
    Serial.println(F("Mode Selector"));
    showMode();
}
 
void loop() {       //Repeats Infinitely
    if (buttonA.getSingleDebouncedPress()) {   //Waits for Button A to be pressed, then proceeds with the following code
        if (mode > 0) {
            mode--;
        }
        ledYellow(1); delay(50); ledYellow(0); //Turns on the Yellow LED, then turns it off after 50 milliseconds
        showMode();
        Serial.print(F("Mode: ")); Serial.println(mode); //Displays Mode Change
    }
    
    if (buttonB.getSingleDebouncedPress()) {   //B is pressed, changes mode to display RUNNING
        if (mode < 2) {
            mode++;
        }
        ledYellow(1); delay(50); ledYellow(0); //Flashes Yellow LED
        showMode();
        Serial.print(F("Mode: ")); Serial.println(mode); //Displays Mode Change
    }
    
    if (buttonC.getSingleDebouncedPress()) { //C is pressed, changes mode to Display IDLE
        mode = 0;
        ledYellow(1); delay(50); ledYellow(0); //Flashes Yellow LED
        showMode();
        Serial.println(F("Mode reset to 0")); //Displays Mode Change
    }
    
    delay(10);
}
