#pragma once
struct position {
	int x, y;
};
void CreateTab(int**& a, int size1, int size2);
void CreatePlayTab(int**& a, int size1, int size2, position& zero);
void ShowTab(int** a, int size1, int size2);
void DelTab(int**& a, int size);
bool Win(int** tab, int** playtab, int size1, int size2);
bool CheckTemp(int*& a, int limit, int value);
void down(int**& a, int& x, int y);
void up(int**& a, int size1, int& x, int y);
void left(int**& a, int size2, int x, int& y);
void right(int**& a, int x, int& y);
