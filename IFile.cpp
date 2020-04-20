#include "IFile.h"

IFile::IFile(const std::string filePath, const std::string mode) : filePath(filePath), openMode(0), length(0)
{
	if (mode.find("r") != std::string::npos) openMode |= std::fstream::in;
	if (mode.find("w") != std::string::npos) openMode |= std::fstream::out;
	if (mode.find("a") != std::string::npos) openMode |= std::fstream::app;
	if (mode.find("t") != std::string::npos) openMode |= std::fstream::trunc;
	if (mode.find("e") != std::string::npos) openMode |= std::fstream::ate;
	if (mode.find("b") != std::string::npos) openMode |= std::fstream::binary;
	
	file.open(filePath, openMode);
	if (file.is_open())
	{
		file.seekg(0, std::fstream::end);
		length = file.tellg();
		file.seekg(0, std::fstream::beg);
	}
}

IFile::~IFile()
{
	file.close();
}

virtual Error IFile::Write(const std::vector<Point>& v)
{
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & std::fstream::out)
	{
		file.write((const char *)v.data(), v.size() * sizeof(Point));
		retVal = FileError(SUCCESS);
	}

	return retVal;
}

virtual Error IFile::Read(std::vector<Point>& v)
{
	if (!file.is_open())
	{
	}
	else if (openMode & std::fstream::in)
	{
		v.clear();
		v.resize(length / sizeof(Point));
		file.seekg(0, std::fstream::beg);
		file.read((char *)v.data(), length);
	}
}

virtual Error IFile::Read(Point & p, const unsigned long idx)
{

	if (!file.is_open())
	{
	}
	else if (idx * sizeof(Point) > length)
	{
	}
	else if (openMode & std::fstream::in)
	{
		file.seekg(idx * sizeof(Point));
		file.read((char*)(&p), sizeof(Point));
	}

	
}
