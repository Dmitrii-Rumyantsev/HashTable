#pragma once
#include "ToBinary.h"
#include "testHeshT.h"

void binaryToHashTable(ifstream& bin, HashTable &hashtable)
{
    AiropotBin air;
    while (bin.read((char*)&air, sizeof(AiropotBin)))
    {
        Airopot toHash(air.airopotOut, air.numberFligth, air.dataIn, air.timeIn, air.hoursDelay);
        insertInHashTable(toHash, hashtable);
    }
}

void deleteBinaryAndHash(int n, HashTable& hashtable) {
    deleteInHashTable(n, hashtable);
    cout << endl;
}

void findKey(int key, HashTable &hashtable, ifstream &bin)
{

    cout << "\nHash :\n";
    if (findInHashTable(hashtable,key) != -1) {
        cout << hashtable.Keys[findInHashTable(hashtable, key)].airopotOut << " " << hashtable.Keys[findInHashTable(hashtable, key)].numberFligth << " " << hashtable.Keys[findInHashTable(hashtable, key)].dataIn << " " << hashtable.Keys[findInHashTable(hashtable, key)].timeIn << " " << hashtable.Keys[findInHashTable(hashtable, key)].hoursDelay << "\n";
    }
}