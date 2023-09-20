#pragma once
#include "iostream"
#include "fstream"
#include <string>
#include "string"
using namespace std;
typedef int TKey;

const TKey DELETE = -1;

struct Airopot
{
	TKey Key;
	string airopotOut;
	int numberFligth, dataIn, timeIn, hoursDelay;
	bool openKey, delKey;
	Airopot(){
		this->openKey = true;
		this->delKey = false;

	}
	Airopot(string airopotOut, int numberFligth, int dataIn, int timeIn, int hoursDelay)
	{
		this->Key = numberFligth;
		this->airopotOut = airopotOut;
		this->numberFligth = numberFligth;
		this->dataIn = dataIn;
		this->timeIn = timeIn;
		this->hoursDelay = hoursDelay;
		this->openKey = true;
		this->delKey = false;
	}
};

struct HashTable
{
	int M, N;
	Airopot* Keys;
	HashTable(int M, int N)
	{
		this->M = M;
		this->N = N;
		this->Keys = new Airopot[M];
	}
};


int hashFunc(int key, int M)
{
	return ((key << 1) % M );
}

void insertInHashTable(Airopot air, HashTable &hashTable)
{
    int id = hashFunc(air.Key, hashTable.M);
    while (!hashTable.Keys[id].openKey)
    {
        id++;
        if (id >= hashTable.M)
        {
            return; // Нет свободных ячеек для вставки
        }
    }
    hashTable.Keys[id] = air;
    hashTable.N = hashTable.N + 1;
    hashTable.Keys[id].openKey = false;
}


void deleteInHashTable(int key, HashTable &hashTable)
{
	int id = hashFunc(key, hashTable.M);
	while (hashTable.Keys[id].Key != key)
	{
		id++;
		if(id >= hashTable.M)
		{
			return;
		}
	}
	hashTable.Keys[id].Key = DELETE;
	hashTable.N = hashTable.N - 1;
	hashTable.Keys[id].delKey = true;
	hashTable.Keys[id].openKey = true;

}

int findInHashTable(HashTable &hashtable, int key)
{
	int id = hashFunc(key, hashtable.M);
	while (!hashtable.Keys[id].delKey && !hashtable.Keys[id].openKey && (hashtable.Keys[id].Key != key))
	{
		id++;
	}
	if(hashtable.Keys[id].delKey && hashtable.Keys[id].openKey)
	{
		return -1;
	}
	else
	{
		return id;
	}
}

void rehashTable(HashTable &hashtable)
{
	int newM = hashtable.M * 2;
	Airopot* reHash = new Airopot[newM];
	for (int i = 0; i < hashtable.M; i++)
	{
		if(hashtable.Keys[i].Key != 0)
		{
			int newId = hashFunc(hashtable.Keys[i].Key, hashtable.M);
			while (reHash[newId].Key != 0)
			{
				newId = newId + 1;
			}
			reHash[newId] = hashtable.Keys[i];
		}
	}
	delete[] hashtable.Keys;
	hashtable.Keys = reHash;
	hashtable.M = newM;
}
void printHashTable(const HashTable &hashtable)
{
    cout << "Hash Table Contents:" << endl;
    for (int i = 0; i < hashtable.M; i++)
    {
        if (!hashtable.Keys[i].openKey && !hashtable.Keys[i].delKey)
        {
            cout << "Index " << i << ": Key=" << hashtable.Keys[i].Key << ", AirportOut=" << hashtable.Keys[i].airopotOut << ", NumberFlight=" << hashtable.Keys[i].numberFligth << ", DataIn=" << hashtable.Keys[i].dataIn << ", TimeIn=" << hashtable.Keys[i].timeIn << ", HoursDelay=" << hashtable.Keys[i].hoursDelay << endl;
        }
        else if (hashtable.Keys[i].delKey)
        {
            cout << "Index " << i << ": DELETED" << endl;
        }
        else
        {
            cout << "Index " << i << ": EMPTY" << endl;
        }
    }
    cout << "Total Entries: " << hashtable.N << endl;
}