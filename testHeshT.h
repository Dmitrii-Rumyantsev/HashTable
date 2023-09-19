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
	Airopot(){}
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


int hashFunc(int key)
{
	return (key << 1) % 10 ;
}

void insertInHashTable(Airopot air, HashTable &hashTable)
{
	int id = hashFunc(air.Key);
	while (hashTable.Keys[id].Key != DELETE)
	{
		id++;
		if (id < hashTable.M)
		{
			hashTable.Keys[id] = air;
			hashTable.N = hashTable.N + 1;
			hashTable.Keys[id].openKey = false;
		}
	}
}

void deleteInHashTable(Airopot air, HashTable &hashtable)
{
	int id = hashFunc(air.Key);
	while (hashtable.Keys[id].Key != air.Key)
	{
		id++;
		if(id >= hashtable.M)
		{
			return;
		}
	}
	hashtable.Keys[id].Key = DELETE;
	hashtable.N = hashtable.N - 1;
	hashtable.Keys[id].delKey = true;
	hashtable.Keys[id].openKey = true;

}

int findInHashTable(HashTable hashtable, int key)
{
	int id = hashFunc(key);
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
			int newId = hashFunc(hashtable.Keys[i].Key);
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