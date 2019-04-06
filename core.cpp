//
// Created by Nguyen Duc Dung on 2019-02-15.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
/// Prototype declaration
void Initialization();
void Finalization();
void LoadConfiguration();
void LoadMenu();
void DisplayMenu();
void DisplayMenuInside();
void ProcessUserChoice();

///--------------------------------------------------------------------

bool __coreInitialized = false;  /// an example of global variable
std::string  __userChoice;               /// a global variable to store user choice
bool __isExiting = false;        /// this variable should be turn on when the program exits
std::string menu1;
std::string menu2;
std::string menu3;
std::string menu4;
std::string menu5;
std::string line1;
std::string line2;
std::string line3;
std::string line4;
std::string line5;
std::string line6;
std::string line7;
std::string line8;
std::string line9;
// TODO: add more global variables to complete tasks

///--------------------------------------------------------------------
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */
void Initialization() {
	LoadConfiguration();
	LoadMenu();
	// TODO: write the code to initialize the program
	__coreInitialized = true;
}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization() {
	// TODO: write the code to clean up when the program exits
	__coreInitialized = false;
}
//---------------------------------------------------------------------
void LoadConfiguration() {
	// TODO: write code to load data from the configuration 

	std::string temp; //variable to save every line in file temporarily
	int countLine{ 0 };
	int countWelcome{ 0 };

	std::ifstream conf("conf.json");
	//Print WelcomeText will begin here
	//the code include the reading file and print 
	while (std::getline(conf, temp)) {
		countLine++;
		//Check the line begin welcome text
		if (temp.find("WelcomeText") != std::string::npos)
			countWelcome = countLine;
		//Start to print welcome text
		if (temp.find("line") != std::string::npos && countLine > countWelcome) {
			int countC{ 0 };
			int beginCharacter{ 0 };
			int endCharacter{ 0 };
			//Find the right thing to print
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i] == '\"') {
					countC++;
					if (countC == 3) beginCharacter = i + 1;
					if (countC == 4) endCharacter = i - 1;
				}
			}
			// adjust welcome text to become right position
			// Assign each line to be the right line
			if (temp.find("line1") != std::string::npos) 
					line1.assign(temp, beginCharacter, endCharacter-beginCharacter+1);
			
			if (temp.find("line2") != std::string::npos) 
					line2.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			
			if (temp.find("line3") != std::string::npos) 
					line3.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
		
			if (temp.find("line4") != std::string::npos) 
					line4.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			
			if (temp.find("line5") != std::string::npos) 
				for (int i = beginCharacter; i <= endCharacter; i++)
					line5.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			
			if (temp.find("line6") != std::string::npos) 
					line6.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			
			if (temp.find("line7") != std::string::npos) 
					line7.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			
			if (temp.find("line8") != std::string::npos) 
					line8.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			
			if (temp.find("line9") != std::string::npos) 
					line9.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			
		}

	}
	//Print the welcome text 
 
	std::cout <<line1<<'\n'<<line2<<'\n'<<line3<<'\n'<<line4<<'\n'<<line5
		<<'\n'<<line6<<'\n'<<line7<<'\n'<<line8<<'\n'<<line9<<'\n';
	conf.close();
	////Print the menu
}
//-------------------------------------------------------
void LoadMenu() {
	// TODO: write code to load menu from the configuration file
	std::string temp; //variable to save each line in file temporarily
	int countLine{ 0 };
	int countMenu{ 0 };
	std::ifstream conf("conf.json");

	while (std::getline(conf, temp)) {
		countLine++;//Use to count the line of text
		if (temp.find("Menu") != std::string::npos)
			countMenu = countLine;

		if (temp.find("opt") != std::string::npos && countLine > countMenu) {
			int countC{ 0 };
			int beginCharacter{ 0 };
			int endCharacter{ 0 };
			//Find the right thing to print that is inside the third and forth "
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i] == '\"') {
					countC++;
					if (countC == 3) beginCharacter = i + 1;
					if (countC == 4) endCharacter = i - 1;
				}
			}
			//Save every line in menu
			if (temp.find("opt1") != std::string::npos) menu1.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			if (temp.find("opt2") != std::string::npos) menu2.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			if (temp.find("opt3") != std::string::npos) menu3.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			if (temp.find("opt4") != std::string::npos) menu4.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
			if (temp.find("opt5") != std::string::npos) menu5.assign(temp, beginCharacter, endCharacter - beginCharacter + 1);
		}
	}
	//Display the menu loaded from configuration file
	std::cout << "1. " << menu1 << '\n';
	std::cout << "2. " << menu2 << '\n';
	std::cout << "3. " << menu3 << '\n';
	std::cout << "4. " << menu4 << '\n';
	std::cout << "5. " << menu5 << '\n';
	conf.close();
}

//------------------------------------------------------------
void DisplayMenu() {};
//------------------------------------------------------------
void DisplayMenuInside() {
	// TODO: Display the menu loaded from configuration file
	std::cout << "1. " << menu1 << '\n';
	std::cout << "2. " << menu2 << '\n';
	std::cout << "3. " << menu3 << '\n';
	std::cout << "4. " << menu4 << '\n';
	std::cout << "5. " << menu5 << '\n';

}
//----------------------------------------------------
void ProcessUserChoice() {
	// TODO: Read user input and process
	//Check input is integer
	int value;
	bool canCheck = true;

	std::cout << "Please select: ";

	std::getline(std::cin, __userChoice);

	//NOW, PROGRAME WILL ANALISICS THE VALUE FROM USER:
	// Check whether the input only has space:
	int sum = 0;
	for (int i = 0; i < __userChoice.size(); i++) {
		sum += (int)__userChoice[i];
	}
	if (sum == __userChoice.size() * 32) {
		std::cout << "Invalid input , please input an interge number.\n";
		//End the program
	}
	else {
		// IF the input not only has space:
		// delete 0 or ++ character in front of and in the end of input value
		while (__userChoice[0] == ' ')
		{
			__userChoice.assign(__userChoice, 1, __userChoice.size() - 1);
		}
		while (__userChoice[__userChoice.size() - 1] == ' ')
		{
			__userChoice.assign(__userChoice, 0, __userChoice.size() - 1);
		}

		//
		// Convert string to integer
		std::istringstream iss(__userChoice);
		iss >> value;

		//Check is there any other character representing number 
		for (int i = 0; i < __userChoice.size(); i++) {
			if (((int)__userChoice[i] < 47 || (int)__userChoice[i] > 58) && __userChoice[i] != '+' && __userChoice[i] != '-') {
				canCheck = false;
				break;
			}
		}
		if (!iss.good() && canCheck) {
			if (value == 1 || value == 2 || value == 3 || value == 4) {
				std::cout << "You select menu item " << value << ". Processing... Done\n";
				DisplayMenuInside();
			}
			else if (value == 5) {
				std::cout << "Exiting...";
				__isExiting = true;
			}
			else if(value<=2147483647 && value >-2147483647){
                std::cout << "Please select number from 1 to 5\n";
			}
			else std::cout << "Invalid input , please input an interge number.\n";
		}
		else std::cout << "Invalid input , please input an interge number.\n";
	}
}
