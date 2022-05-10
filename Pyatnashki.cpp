#include <iostream>
#include <Windows.h>
#include "Header.h"
#include <ctime>

using namespace std;
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Ru");
    int size1, size2, time;
    char direction;
    position zero;
    cout << "Введите размерность игры" << endl;
    cin >> size1 >> size2;
    int** tab = new int* [size1];
    int** playtab = new int* [size1];
    for (int i = 0; i < size1; i++) {
        tab[i] = new int[size2];
        playtab[i] = new int[size2];
    }
    CreateTab(tab, size1, size2);
    CreatePlayTab(playtab, size1, size2, zero);
    ShowTab(playtab, size1, size2);
    int start = clock();
    int step = 0;
    do {
        cout << endl;
        cout << "1 - Сдвиг влево" << endl;
        cout << "3 - Сдвиг вправо" << endl;
        cout << "5 - Сдвиг вверх" << endl;
        cout << "2 - Сдвиг вниз" << endl;
        cout << "0 - Выход" << endl;
        cin >> direction;
        switch (direction)
        {
        case '1':
            left(playtab, size2, zero.x, zero.y);
            step++;
            ShowTab(playtab, size1, size2);            
            break;
        case '3':
            right(playtab, zero.x, zero.y);
            step++;
            ShowTab(playtab, size1, size2);            
            break;
        case '5':
            up(playtab, size1, zero.x, zero.y);
            step++;
            ShowTab(playtab, size1, size2);            
            break;
        case '2':
            down(playtab, zero.x, zero.y);
            step++;
            ShowTab(playtab, size1, size2);           
            break;
        case '0':
            cout << "Пока!" << endl;
            exit;
            break;
        default:
            cout << "Набрана неправильная команда" << endl;
            Sleep(2000);
            break;
        }
    } while (!Win(tab, playtab, size1, size2)&&direction!='0');
    int end = clock();
    time = (end - start) / CLOCKS_PER_SEC;
    cout << "Игра закончена!!!" << endl;
    cout << "Затраченное время: " << time / 3600 << " часов, " << time % 3600 / 60 << " минут, " << time % 3600 % 60 << " секунд" << endl;
    cout << "Кол-во ходов: " << step << endl;
    DelTab(tab, size1);
    DelTab(playtab, size1);
}

