#include <iostream>
#include <fstream>
#include "testBinF.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    const char* txt_name = "AiroportInText.txt";
    const char* binary_name = "AiroportInBin.dat";
    std::ifstream txt("AiroportInText.txt");
    std::ofstream bin("AiroportInBin.dat");
    HashTable hash(100, 10);
    Airopot airs;
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
            printHashTable(hash);
            break;
        }
        case 3: {
            ifstream bn(binary_name, ios::binary | ios::in);
            findKey(2, hash,bn);
            break;
        }
        case 4: {
            fstream bn(binary_name, ios::binary | ios::in);
            deleteBinaryAndHash(1, bn, hash,airs);
            break;
        }
        case 5: {
            rehashTable(hash);
            break;
        }
        }
    }
    return 0;
}