﻿/*#include <iostream>
#include <fstream>
#include "testBinF.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    const char* txt_name = "AiroportInText.txt";
    const char* binary_name = "AiroportInBin.dat";
    std::ofstream bon("AiroportInBin.dat");
    HashTable hash(100, 10);
    int x = 1;
    txt_to_binary(txt, binary_name);
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
}*/