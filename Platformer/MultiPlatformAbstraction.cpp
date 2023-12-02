/*
Its is under the MIT license, to encourage reuse by cut-and-paste.

The original files are hosted here: https://github.com/sago007/PlatformFolders

Copyright (c) 2015 Poul Sander

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation files
(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "MultiPlatformAbstraction.hpp"
#include "Libs/platform_folders.h"
#include "physfs.h"
#include <memory>
#include <iostream>

/**
 * Returns the path to where all settings must be saved.
 * On unix-like systems this is the home-folder under: ~/.local/share/GAMENAME
 * In Windows it is a special save games folder
 */
std::string getPathToSaveFiles(const char* gamename) {
	return sago::getSaveGamesFolder2()+"/"+gamename;
}

void ReadBytesFromFile(const char* filename, std::unique_ptr<char[]>& dest, unsigned int& bytes) {
	bytes = 0;
	if (!PHYSFS_exists(filename)) {
		std::cerr << "ReadBytesFromFile - File does not exists: " << filename << "\n";
		return;
	}
	PHYSFS_file* myfile = PHYSFS_openRead(filename);
	unsigned int m_size = PHYSFS_fileLength(myfile);
	std::unique_ptr<char[]> m_data(new char[m_size]);
	int length_read = PHYSFS_readBytes (myfile, m_data.get(), m_size);
	if (length_read != (int)m_size) {
		PHYSFS_close(myfile);
		std::cerr << "Error: Curropt data file: " << filename << "\n";
		return;
	}
	PHYSFS_close(myfile);
	std::swap(m_data, dest);
	bytes = m_size;
}

std::string GetFileContent(const char* filename) {
	std::string ret;
	if (!PHYSFS_exists(filename)) {
		std::cerr << "GetFileContent - File does not exists: " << filename << "\n";
		return ret;
	}
	unsigned int m_size = 0;
	std::unique_ptr<char[]> m_data;
	ReadBytesFromFile(filename, m_data, m_size);
	//Now create a std::string
	ret = std::string(m_data.get(), m_data.get()+m_size);
	return ret;
}

static void CreatePathToFile(const std::string& path) {
	size_t end_of_path = path.find_last_of("/");
	if (end_of_path == std::string::npos) {
		//No path
		return;
	}
	std::string path2dir = path.substr(0, end_of_path);
	PHYSFS_mkdir(path2dir.c_str());
}

void WriteFileContent(const char* filename, const std::string& content) {
	CreatePathToFile(filename);
	PHYSFS_file* myfile = PHYSFS_openWrite(filename);
	if (!myfile) {
		PHYSFS_ErrorCode code = PHYSFS_getLastErrorCode();
		std::cerr << "Failed to open file for writing, " << PHYSFS_getErrorByCode(code) << " (" << code << ")\n";
		return;
	}
	PHYSFS_writeBytes(myfile, content.c_str(), sizeof(char)*content.length());
	PHYSFS_close(myfile);
}