#pragma once
#include <string>
#include "IFile.h"
#include "BinaryFile.h"
#include "CsvFile.h"

static class FileFactory
{
public:
	static IFile* Open(const string, const string);
};

