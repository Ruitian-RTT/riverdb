#pragma once

#include <string>

#include "ifile_writer.h"

namespace RiverDB {

class NormalFileWriter : public IFileWriter {
public:
	NormalFileWriter(const std::string& file, int mode = FileOpenModeWrite) : _file(file) {
        if (mode == FileOpenModeAppend) {
	        _out.open(_file, std::ofstream::app | std::ofstream::binary);
        } else {
	        _out.open(_file, std::ofstream::out | std::ofstream::binary);
        }
	}

	~NormalFileWriter() {
		flush();
		_out.close();
	}

	void writeline(const std::string& line) {
		_out.write(line.c_str(), line.size());
		write_char('\n');
	}

	void write(const char* str, unsigned int size) {
		_out.write(str, size);
	}
	void write_char(char c) {
		_out.put(c);
	}
    void flush() {
        _out.flush();
    }


private:
	std::string _file;
	std::ofstream _out;
};

} // namespace RiverDB
