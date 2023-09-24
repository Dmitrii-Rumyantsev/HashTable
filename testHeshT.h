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

int hashFuncForRehash(int key, int M)
{
	return (key % M);
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


void deleteInHashTable(int key, HashTable & hashtable)
{
	int id = hashFunc(key, hashtable.M);
	while (hashtable.Keys[id].Key != key && id < hashtable.M)
	{
		id++;
	}
	cout << "DELETE: " << hashtable.Keys[id].airopotOut << " " << hashtable.Keys[id].numberFligth << " " << hashtable.Keys [id] .dataIn << " " << hashtable.Keys[id].timeIn << " " << hashtable.Keys[id].hoursDelay << "\n";
	hashtable.Keys[id].Key = DELETE;
	hashtable.N = hashtable.N - 1;
	hashtable.Keys[id].delKey = true;
	hashtable.Keys[id].openKey = true;

}

int findInHashTable(HashTable &hashtable, int key)
{
	int id = hashFunc(key, hashtable.M);
	while (hashtable.Keys[id].Key != key && id < hashtable.M)
	{
		id++;
	}
	if(hashtable.Keys[id].delKey && !hashtable.Keys[id].openKey)
	{
		return -1;
	}
	else
	{
		return id;
	}
}

void rehashTable(HashTable& hashtable)
{
	int newM = hashtable.M * 2;
	HashTable reHash(newM, hashtable.N);
	for (int i = 0; i < hashtable.M; i++)
	{
		if (hashtable.Keys[i].Key >= 0)
		{
			int newId = hashFuncForRehash(hashtable.Keys[i].Key, newM);
			while (!reHash.Keys[newId].openKey)
			{
				newId++;
				if (newId >= newM)
				{
					return; // Нет свободных ячеек для вставки
				}
			}
			reHash.Keys[newId] = hashtable.Keys[i];
			reHash.Keys[newId].openKey = false;
		}
	}
	hashtable = reHash;
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
}