#ifndef DATA_FILE_H
#define DATA_FILE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataFile{
public:
	static void SaveData(string filename, char* &dataStruct, unsigned int dataSize);
	static void LoadData(string filename, char* &dataStruct);
private:
	static ifstream fileReader;
	static ofstream fileWriter;
};

#endif