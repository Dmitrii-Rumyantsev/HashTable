#include <iostream>
#include <fstream>
#include "testBinF.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    const char* txt_name = "AiroportInText.txt";
    const char* binary_name = "AiroportInBin.dat";
    ifstream txt(txt_name, ios::out);
    ofstream bin(binary_name, ios::binary | ios::in | ios::trunc);
    HashTable hash(100, 10);
    int x = 1;
    txt_to_binary(txt, bin);
    bin.close();
    while (x != 0)
    {
        cout << "Выберите операцию\n1 - Из бинарного в хэш-таблицу\n2 - Поиск по ключу\n3 - Удалить по ключу\n4 - Произвести реъеширование\n5 - Вывести хэш-таблицу\n";
        cin >> x;
        switch (x)
        {
            case 1: {
                ifstream bn(binary_name, ios::binary);
                binaryToHashTable(bn, hash);
                bn.close();
                break;
            }
            case 2: {
                cout << "Введите ключ\n";
                int key;
                cin >> key;
                ifstream bn(binary_name, ios::binary | ios::in);
                findKey(key, hash, bn);
                bn.close();
                break;
            }
            case 3: {
                cout << "Введите ключ\n";
                int key;
                cin >> key;
                deleteBinaryAndHash(key, hash);
                break;
            }
            case 4: {
                rehashTable(hash);
                break;
            }
            case 5: {
                printHashTable(hash);
                break;
            }
            case 0:
                cout << "Выход из цикла\n";
                break;
            default:
                cout << "Введенные данные не верный!\n";
        }
    }
    return 0;
}