#include <iostream>
#include <time.h>

using namespace std;

bool game = true;
short c; // Yes, No, Instructions in function choic()

void start();
void choic();
void gams();
void again();

void choic(){
	switch(c)
	{
	case 1: // if c == 1 then start game
		gams();
		break;
	case 0: // if c == 0 then exit
		cout << "Goodbay!" << endl;
		break;
	case 9: // if c == 9 then instructions
		cout << "Instructions" << endl;
		cout << "Two players take turns naming numbers from 1 to 10 and summing them. The first to name the number 100 wins. You will play against the computer." << endl << endl;
		start();
		break;
	default: // if c != 1, 0, 9 then start page
		start();
		break;
	}
}
void gams() {
	short z;
	z = 0; // sum of numbers
	do {
		while (z != 100) {
			short b; // number entered by the player
			cout << "Your turn: ";
			cin >> b;
			if (b > 10 || b < 1)
			{
				cout << "You entered an invalid number" << endl;
				continue;
			}
			z += b;
			cout << "Sum of numbers:" << z << endl << endl;
			if (z >= 100)
			{
				cout << "You won!" << endl << endl;
				break;
			}
			short a; // number entered by the computer
			a = rand() % 10 + 1;
			if (z >= 79) {
				a = 89 - z;
				if (a < 1 || a > 10)
				{
					a = 1;
				}
			}
			if (z >= 90)
			{
				a = 100 - z;
			}
			z += a;
			cout << "Computer named the number: " << a << endl;
			cout << "Sum of numbers: " << z << endl << endl;
			if (z >= 100)
			{
				cout << "Computer won!" << endl << endl;
				break;
			}
		}
	} while (z != 100);
	again();
}

void start() {
	cout << "Do you want to start the game? (1 - yes, 0 - no, 9 - instructions)" << endl;
	cin >> c;
	cout << endl;
	choic();
}
void again() {
	cout << "Do you want to play again? (1 - yes, 0 - no, 9 - instructions , other - to start page)" << endl;
	cin >> c;
	cout << endl;
	choic();
}

int main() {
	srand(time(NULL));
	start();
	return 0;
}