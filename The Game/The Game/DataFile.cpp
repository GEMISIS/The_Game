#include "DataFile.h"

ifstream DataFile::fileReader;
ofstream DataFile::fileWriter;

void DataFile::SaveData(string filename, char* &dataStruct, unsigned int dataSize){
	DataFile::fileWriter = ofstream(filename.c_str(), ofstream::binary);
	DataFile::fileWriter.write(dataStruct, dataSize);
	DataFile::fileWriter.close();
}
void DataFile::LoadData(string filename, char* &dataStruct){
	DataFile::fileReader = ifstream(filename.c_str(), ifstream::binary);
	DataFile::fileReader.seekg(0, DataFile::fileReader.end);
	long length = DataFile::fileReader.tellg();
	DataFile::fileReader.seekg(0);

	dataStruct = new char[length];
	DataFile::fileReader.read(dataStruct, length);
	DataFile::fileReader.close();
}
