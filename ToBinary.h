
#include "iostream"
#include "fstream"
#include <string>
#include "string"

using namespace std;

struct AiropotBin
{
    string airopotOut;
    int numberFligth, dataIn, timeIn, hoursDelay;
};

void txt_to_binary(ifstream& txt, ofstream& bin)
{
    AiropotBin air;
    while (!txt.eof())
    {
        getline(txt, air.airopotOut);
        txt >> air.numberFligth;
        txt.get();
        txt >> air.dataIn;
        txt.get();
        txt >> air.timeIn;
        txt.get();
        txt >> air.hoursDelay;
        txt.get();
        bin.write((char*)&air, sizeof(AiropotBin));
    }
    txt.close();
    bin.close();
}

void binary_to_txt(ifstream& bin, ofstream& txt)
{
    AiropotBin air;
    bin.read((char*)&air, sizeof(AiropotBin));
    while (bin.read((char*)&air, sizeof(AiropotBin)))
    {
        txt << air.airopotOut << endl << air.numberFligth << endl << air.dataIn << endl << air.timeIn << endl << air.hoursDelay << endl;
    }

    if (!bin.eof() && bin.fail())
    {
        // ����������� ������ ������ �� �����
        cout << "Error reading from binary file." << endl;
    }
}

void print_binnary(ifstream& bin)
{
    AiropotBin air;
    int lineNumber = 0;
    while (bin.read((char*)&air, sizeof(AiropotBin)))
    {
        lineNumber++;
        cout << "Line " << lineNumber << ":" << endl;
        cout << air.airopotOut << endl << air.numberFligth << endl << air.dataIn << endl << air.timeIn << endl << air.hoursDelay << endl;
    }

    if (bin.fail() && !bin.eof())
    {
        cout << "Error reading from binary file at line " << lineNumber << "." << endl;
    }
    bin.close();
    return;
}


void key_bin(ifstream& bin, int n)
{
    AiropotBin airs;
    bin.seekg(n * sizeof(AiropotBin));
    if (bin.read((char*)&airs, sizeof(AiropotBin))) {
        cout << airs.airopotOut << endl << airs.numberFligth << endl << airs.dataIn << endl << airs.timeIn << endl << airs.hoursDelay;
    }
    else {
        cout << "������ ������ ������ �� ��������� �����." << endl;
    }
}


void delete_bin(fstream& bin, int n)
{
    AiropotBin air;
    int key = 0;
    while (!bin.eof())
    {
        bin.read((char*)&air, sizeof(AiropotBin));
        if (key == n) {
            bin.seekp(0, ios::end);
        }
        if (key > n)
        {
            bin.seekg(key - 2, ios::beg);
        }
    }
    bin.close();
}

