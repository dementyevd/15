#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

void CreateTab(int**& a, int size1, int size2) {
	int value = 1;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			a[i][j] = value++;
		}
	}
	a[size1 - 1][size2 - 1] = 0;
}

void UpdateTemp(int*& a, int& limit, int value) {
	int index = 0;
	for (int i = 0; i < limit; i++) {
		if (a[i] == value) index = i;
	}
	for (int i = 0; i < limit; i++) {
		if (i >= index) a[i] = a[i + 1];
	}
	limit--;
}

bool CheckTemp(int*& a, int limit, int value) {
	int count = 0;
	for (int i = 0; i < limit; i++) {
		if (a[i] == value) count++;
	}
	if (count > 0) return true;
	else {
		cout << "Введен уже выбранный элемент!" << endl;
		return false;
	}
}

void CreatePlayTab(int**& a, int size1, int size2, position &zero) {
	int limit = size1 * size2;
	int value=0;
	char choice;
	int* temp = new int[limit];
	for (int i = 0; i < limit; i++) {
		temp[i] = i;
	}
	cout << "1 - Ручное заполнение" << endl;
	cout << "2 - Автозаполнение" << endl;
	cin >> choice;
	switch (choice)
	{
	case '1':
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				do
				{
					cout << "Введите элемент " << i + 1 << " строки " << j + 1 << " столбца:" << endl;
					cin >> value;
					if (value == 0) {
						a[i][j] = value;
						zero.x = i;
						zero.y = j;
					}
					else {
						a[i][j] = value;
					}
				} while (!CheckTemp(temp, limit, value));
				UpdateTemp(temp, limit, value);
			}
		}
		break;
	case '2':
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				value = temp[rand() % limit];
				if (value == 0) {
					a[i][j] = value;
					zero.x = i;
					zero.y = j;
				}
				else {
					a[i][j] = value;
				}
				UpdateTemp(temp, limit, value);
			}
		}
		break;
	}
	delete[] temp;
}

void ShowTab(int** a, int size1, int size2) {
	system("cls");
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (a[i][j] == 0) cout << "\t";
			else cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

bool Win(int** tab, int** playtab, int size1, int size2) {
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (tab[i][j] != playtab[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void down(int**& a, int& x, int y) {
	if (x > 0) {
		a[x][y] = a[x - 1][y];
		a[x - 1][y] = 0;
		x--;
	}		
}
void up(int**& a, int size1, int& x, int y) {
	if (x < size1 - 1) {
		a[x][y] = a[x + 1][y];
		a[x + 1][y] = 0;
		x++;
	}	
}
void left(int**& a, int size2, int x, int& y) {
	if (y < size2 - 1) {
		a[x][y] = a[x][y + 1];
		a[x][y + 1] = 0;
		y++;
	}		
}
void right(int**& a, int x, int& y) {
	if (y > 0) {
		a[x][y] = a[x][y - 1];
		a[x][y - 1] = 0;
		y--;
	}	
}

void DelTab(int**& a, int size) {
	for (int i = 0; i < size; i++) {
		delete[] a[i];
	}
	delete[] a;
}