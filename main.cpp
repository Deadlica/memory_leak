#include <iostream>
#include <string>
#include <math.h>

void printMenu();
bool validateInput(std::string input);

int main() {
	uint64_t totalAllocatedMemory = 0;
	int counter = 0, GiB = pow(2, 30) / 8, KiB = pow(2, 10) / 8;
	std::string userInput;
	bool input_is_bad = true;
	while (true) {
		while (input_is_bad) {
			system("cls");
			printMenu();
			getline(std::cin, userInput);
			if (validateInput(userInput)) {
				break;
			}
		}
		if (userInput == "0") {
			std::cout << "Bye!" << std::endl;
			return 0;
		}
		else if (userInput == "1") {
			system("cls");
			std::cout << "Option 1: 1GiB" << std::endl;
			while (true) {
				try
				{
					new int64_t[GiB];
					totalAllocatedMemory += GiB * 8;
					std::cout << "Total allocated memory: " << totalAllocatedMemory << " bytes" << std::endl;
					//system("timeout /t 2 /nobreak");
				}
				catch (std::bad_alloc& exception)
				{
					std::cerr << "bad_alloc occured: " << exception.what();
				}
			}
		}
		else if (userInput == "2") {
			system("cls");
			std::cout << "Option 2: 1KiB" << std::endl;
			while (true) {
				try
				{
					new int64_t[KiB];
					totalAllocatedMemory += KiB * 8;
					counter++;
					if (counter == 1024) {
						std::cout << "Total allocated memory: " << totalAllocatedMemory << " bytes" << std::endl;
						counter = 0;
					}
				}
				catch (std::bad_alloc& exception)
				{
					std::cerr << "bad_alloc occured: " << exception.what();
				}
			}
		}
	}
	return 0;
}

void printMenu() {
	std::cout << "=====================================================" << std::endl <<
		"Memory Limit" << std::endl <<
		"=====================================================" << std::endl <<
		"1. Testcase 1: Allocate 1 GiB chunks" << std::endl <<
		"2. Testcase 2: Allocate 1 KiB chunks" << std::endl <<
		"0. Exit" << std::endl;
}

bool validateInput(std::string input) {
	if (input.length() == 1) {
		if (input >= "0" && input <= "2") {
			std::cout << input << std::endl;
			return true;
		}
	}
	std::cerr << "Invalid input!" << std::endl;
	return false;
}