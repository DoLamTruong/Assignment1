//
// Created by Nguyen Duc Dung on 2019-02-15.
//
#include<string>
#ifndef A01_CORE_H
#define A01_CORE_H

/*TODO: If you are using some global variables and you intent to let other
 * users access it, you better declare it here.
 * Hint: use extern as shown in the below
 */
extern bool __coreInitialized;
extern std::string  __userChoice;
extern bool __isExiting;
extern std::string menu1;
extern std::string menu2;
extern std::string menu3;
extern std::string menu4;
extern std::string menu5;
extern std::string line1;
extern std::string line2;
extern std::string line3;
extern std::string line4;
extern std::string line5;
extern std::string line6;
extern std::string line7;
extern std::string line8;
extern std::string line9;
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */
void Initialization();
/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization();

void LoadConfiguration();
void LoadMenu();
void DisplayMenu();
void DisplayMenuInside();
void ProcessUserChoice();



#endif //A01_CORE_H
