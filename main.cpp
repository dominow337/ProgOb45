#include "BinaryFile.h"
#include "CSVFile.h"
#include "FileFactory.h"
#include "IFile.h"

int main()
{
	string filePath;
	cin >> filePath;
	string mode;
	cin >> mode;
	IFile* FileFactory::Open(filePath, mode);
}