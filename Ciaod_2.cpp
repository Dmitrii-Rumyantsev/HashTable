// Ciaod_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "testBinF.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    const char* txt_name = "AiroportInText.txt";
    const char* binary_name = "AiroportInBin.dat";
    ifstream txt(txt_name);
    ofstream bin(binary_name, ios::binary, ios::in);
    HashTable hash(100, 10);
    int x = 1;
    txt_to_binary(txt, bin);
    bin.close();
    while (x != 0)
    {
        cin >> x;
        switch (x)
        {
        case 1: {
            ifstream bn(binary_name, ios::binary | ios::in);
            binaryToHashTable(bn, hash);
            bn.close();
            break;
        }
        case 2: {
            ifstream bn(binary_name, ios::binary | ios::in);
            findKey(7, hash, bn);
            bn.close();
            break;
        }
        case 3: {
            ifstream bn(binary_name, ios::binary | ios::in);
            print_binnary(bn);
            break;
        }
        case 4: {
            ifstream bn(binary_name, ios::binary | ios::in);
            key_bin(bn, 2);
            break;
        }
        case 5: {
            fstream bg(binary_name, ios::binary | ios::in);
            delete_bin(bg, 1);
            break;
        }
        }
    }
    return 0;
}