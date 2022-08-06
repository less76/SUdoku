// Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <time.h>
using namespace std;

#define underline "\033[4m"
#define deunderline "\033[0m"

char **game;

void Display() {
	cout << underline <<  "   0  1  2   3  4  5   6  7  8  \n" << deunderline <<"";
	for (int i = 1; i < 10; i++) {

		if (i % 3 == 0) {
			cout << underline;
		}

		else {
			cout << deunderline;
		}

		cout << (i - 1);

		for (int j = 0; j < 9; j++) {
			if (j % 3 == 0) {
				cout << "|";
			}
			cout << " " << game[j][i] << " ";
		}
		
		cout << "|" << endl;
	}
	cout << deunderline;
}

int main()
{
	char row, column, number;

	game = new char*[10];

	for (int i = 0; i < 10; i++) {
		game[i] = new char[10];
	}

	//system("C:\Users\monst\Desktop\funny.PNG");

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			game[i][j] = 0;
		}
	}

	

	cout << "Welcome to sudoku." << endl;
	cout << "This is your board" << endl;
	//cout << underline << "this text should be underlined" << deunderline << endl;
	random_device rd;
	mt19937 gen(rd());


	int k = 0;
	while (k < 140) {

		//Display();

		//int same = 0;
		int same1 = 0;
		int x = gen() % 9;
		int y = gen() % 9 + 1;
		int value = gen() % 9 + 1;

		try {
			if (game[x][y] != NULL) {
				throw "skip";
			}

			else {
				try {
					for (int j = 1; j < 10; j++) {
						if (game[x][j + 1] == value + 0x30 || game[j - 1][y] == value + 0x30) {
							same1 = 1;
							int ll = 0;
							throw "skip";
						}

						else {
							int mm = 0;
						}
					}

					try {
						int same = 0;
						int x_placement = x / 3;
						int y_placement = y / 3;

						for (int i = x_placement * 3; i < x_placement * 3 + 3; i++) {
							for (int j = y_placement * 3; j < y_placement * 3 + 3; j++) {
								//int ff = 0;
								if (game[i][j] == value + 0x30) {
									throw "skip";
									same = 1;
									//int pp = 0;
									//int c = 0;
									//break;
								}

								if (same == 0 && i == x_placement * 3 + 3 - 1 && same1 == 0) {
									game[x][y] = value + 0x30;
									k++;
									//int ff = 0;
								}
							}
						}

					}

					catch (const char *e) {
						game[x][y] = NULL;
					}

				}

				catch (const char *e) {
					game[x][y] = NULL;
				}
			}
		}

		catch (const char *e) {
			game[x][y] = NULL;
		}

	}
	


	while (1) {
		//system("color 4F");
		Display();

		cout << "type in the row" << endl;
		row = _getch();
		cout << row << endl;
		cout << "type in the column " << endl;
		column = _getch();
		cout << column << endl;
		cout << "type in the number or press d to erase" << endl;
		number = _getch();
		cout << number << endl;
		cout << "\033[2J\033[H";
		
		bool blocked = 0;

		if (number == 'd') {
			game[row - 0x30][column - 0x30 + 1] = 0;
			blocked = 1;
		}

		if (game[row - 0x30][column - 0x30 + 1] != NULL) {
			cout << "Oops occupied" << endl;
		}

		for (int i = 1; i < 10; i++) {
			if (game[row - 0x30][i + 1] == number || game[i-1][column - 0x30 + 1] == number) {

				blocked = 1;
				cout << "blocked" << endl;
				
				break;
			}
		}

		int row_placement = ((row - 0x30) / 3);
		int column_placment = ((column - 0x30) / 3);

		if (blocked == 0) {
			for (int i = row_placement * 3; i < row_placement * 3 + 3; i++) {
				for (int j = column_placment * 3; j < column_placment * 3 + 3; j++) {

					if (game[i][j+1] == number) {
						blocked = 1;
						cout << "blocked" << endl;
						break;
					}

				}
			}
		}

		if(blocked == 0) {
			game[row - 0x30][column - 0x30 + 1] = number;
		}

		int checker = 0;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {

				checker *= game[i][j + 1] - 0x30;
			}
		}

		if (checker != 0) {
			cout << "Board solved" << endl;
			break;
		}
		
	}

	return 0;
}