#include <fstream>
#include <sstream>
#include <vector>
#include "Point.h"
//#include "FileError.h"
#include "IFile.h"
using namespace std;
class CSVFile : public IFile
{
private:
	IFile::Error WriteLine(const Point&);
	vector<string> Split(string, char);
public:
	CSVFile(const string, const string);
	~CSVFile();

	IFile::Error Write(const vector<Point>&);
	IFile::Error Read(vector<Point>&);
	IFile::Error Read(Point&, const unsigned long);

};