#include "CSVFile.h"

CSVFile::CSVFile(const string filePath, const string mode) : IFile(filePath, mode)
{
}
FileError CSVFile::Write(const vector<Point>& points)
{
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & fstream::out)
	{
		for (auto p : points)
		{
			WriteLine(p);
		}
	}

	return retVal;
}

FileError CSVFile::Read(vector<Point>& p)
{
	//getline, stod

	FileError retVal = FileError(ACCESS_DENIED);
	string file;
	double x;
	double y;
	double z;
	vector<Point> v;
	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & fstream::in)
	{
		while (!p.eof())
		{
			getline(p, file);
			stod(file, new CSVFile);
			v = Split(file, ';');
			p.x = stod(v[0]);
			p.y = stod(v[1]);
			p.z = stod(v[2]);
		}
		retVal = FileError(SUCCESS);
	}

	return retVal;
}

FileError CSVFile::Read(Point& p, const unsigned long idx)
{
	FileError retVal = FileError(ACCESS_DENIED);
	string file;
	int j = 0;
	double x;
	double y;
	double z;
	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & fstream::in)
	{
		while(!p.eof()||j==idx)
		{
			p.ignore(MAX_LONG, '\n');
			j++;
		}
		if (j == idx)
		{
			getline(p, file);
			retVal = FileError(SUCCESS);
		}
		else if (p.eof())
		{
			retVal = FileError(OUT_OF_BOUNDS);
		}
	}
	vector<Point> v = Split(file, ';');
	p.x = stod(v[0]);
	p.y = stod(v[1]);
	p.z = stod(v[2]);
	return retVal;
}	//file.ignore(MAX_LONG, '\n');
	//file.eof();

IFile::Error CSVFile::WriteLine(const Point& p)
{
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & fstream::out)
	{
		file << p.x << ";" << p.y << ";" << p.z << "\n";
		retVal = FileError(SUCCESS);
	}

	return retVal;
}

vector<string> CSVFile::Split(string str, char delim)
{
	vector<string> result;
	stringstream ss(str);
	string item;
	while (getline(ss, item, delim))
	{
		result.push_back(item);
	}
	return result;
}

CSVFile::~CSVFile()
{
}

