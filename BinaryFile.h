#pragma once
#include <fstream>
#include <vector>
#include "Point.h"
#include "FileError.h"
#include "CSVFile.h"
#include "IFile.h"
using namespace std;
class BinaryFile : public IFile
{	
public:
	BinaryFile(const string, const string);
	~BinaryFile();

	FileError Write(const vector<Point>&);
	FileError Read(vector<Point>&);
	FileError Read(Point&, const unsigned long);
};


