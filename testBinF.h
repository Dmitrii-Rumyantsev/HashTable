#pragma once
#include "ToBinary.h"
#include "testHeshT.h"

void binaryToHashTable(ifstream& bin, HashTable &hashtable)
{
    AiropotBin air;
    bin.read((char*)&air, sizeof(AiropotBin));
    while (bin.read((char*)&air, sizeof(AiropotBin)))
    {
        Airopot toHash(air.airopotOut, air.numberFligth, air.dataIn, air.timeIn, air.hoursDelay);
        insertInHashTable(toHash, hashtable);
    }

    if (!bin.eof() && bin.good())
    {
        cout << "Error reading from binary file." << endl;
    }
}

void deleteBinaryAndHash(int n, fstream& bin, HashTable& hashtable, Airopot air) {
    cout << "�������� �� ����� � ���-������� :";
    deleteInHashTable(air, hashtable);
    cout << "\n�������� �� ����� � �������� ����� :";
    delete_bin(bin, n);
    cout << endl;
    if (!bin.eof() && bin.fail())
    {
        cout << "Error reading from binary file." << endl;
    }
    bin.close();
}

void findKey(int key, HashTable &hashtable, ifstream &bin)
{
    cout << "����� �� ����� � ���-������� :";
    findInHashTable(hashtable, key);
    cout << "\n����� �� ����� � �������� ����� :";
    key_bin(bin, key);
    cout << endl;
    if (!bin.eof() && bin.fail())
    {
        cout << "Error reading from binary file." << endl;
    }
    bin.close();
}