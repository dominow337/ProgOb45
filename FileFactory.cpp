#include "FileFactory.h"

IFile* FileFactory::Open(const string filePath, const string mode)
{
	IFile * file = nullptr;

	if (filePath.substr(filePath.find_last_of(".") + 1) == "bin")
	{
		file = new BinaryFile(filePath, mode);
	}
	else if (filePath.substr(filePath.find_last_of(".") + 1) == "csv")
	{
		file = new CSVFile(filePath, mode);
	}


	return file;
}
