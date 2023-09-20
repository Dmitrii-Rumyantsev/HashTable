#pragma once
#include "ToBinary.h"
#include "testHeshT.h"

void binaryToHashTable(ifstream& bin, HashTable &hashtable)
{
    AiropotBin air;
    bin.read((char*)&air, sizeof(AiropotBin));
    while (!bin.eof())
    {
        Airopot toHash(air.airopotOut, air.numberFligth, air.dataIn, air.timeIn, air.hoursDelay);
        insertInHashTable(toHash, hashtable);
        bin.read((char*)&air, sizeof(AiropotBin));
    }

    if (!bin.eof() && bin.good())
    {
        cout << "Error reading from binary file." << endl;
    }
    bin.close();
}

void deleteBinaryAndHash(int n, fstream& bin, HashTable& hashtable, Airopot air) {
    deleteInHashTable(n, hashtable);
    cout << endl;
    if (!bin.eof() && bin.fail())
    {
        cout << "Error reading from binary file." << endl;
    }
    bin.close();
}

void findKey(int key, HashTable &hashtable, ifstream &bin)
{

    cout << "\nHash :\n";
    key_bin(bin, key);
    cout << endl;
    if (!bin.eof() && bin.fail())
    {
        cout << "Error reading from binary file." << endl;
    }
    bin.close();
}