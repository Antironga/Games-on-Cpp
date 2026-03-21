#include <iostream>
#include <time.h>
#include <string>

int main(){
    srand(time(NULL));
    short b;
	short sum = 0;
	short randomNumber; // number entered by the computer
	while(true){
        std::cout << "Do you want to start the game? (1 - yes, 0 - no, 9 - instructions)" << std::endl;
		std::string start;
		std::cin >> start;
		try{
			b = std::stoi(start);
		}catch(...){
			b = 0;
		}
		std::cout << std::endl;

		switch(b){
			case 1: // if b == 1 then start game
				do {
					while (sum != 100) {
						std::cout << "Your turn: ";
						std::string yourTurn;
						std::cin >> yourTurn;
						try{
							b = std::stoi(yourTurn);
						}catch(...){
							b = 0;
						}
						if (b > 10 || b < 1){
							std::cout << "You entered an invalid number" << std::endl;
							continue;
						}
						sum += b;
						std::cout << "Sum of numbers:" << sum << std::endl << std::endl;
						if (sum >= 100){
							std::cout << "You won!" << std::endl << std::endl;
							break;
						}
						randomNumber = rand() % 10 + 1;
						if(sum >= 90){
							randomNumber = 100 - sum;
						}
						else if(sum >= 79){
							randomNumber = 89 - sum;
							if (randomNumber < 1 || randomNumber > 10){
								randomNumber = 1;
							}
						}
						sum += randomNumber;
						std::cout << "Computer named the number: " << randomNumber << std::endl;
						std::cout << "Sum of numbers: " << sum << std::endl << std::endl;
						if (sum >= 100){
							std::cout << "Computer won!" << std::endl << std::endl;
							break;
						}
					}
				} while (sum != 100);
				sum = 0;
				break;
			case 0: // if b == 0 then exit
				std::cout << "Goodbay!" << std::endl;
				return 0;
				break;
			case 9: // if b == 9 then instructions
				std::cout << "Instructions" << std::endl;
				std::cout << "Two players take turns naming numbers from 1 to 10 and summing them. The first to name the number 100 wins. You will play against the computer." << std::endl << std::endl;
				break;
			default: // if b != 1, 0, 9 then start page
				break;
		}
	}
}
