#pragma once

#include <string>

namespace RiverDB {



class IOInterface {
public:
    IOInterface () = default;
    virtual ~IOInterface() {}

    virtual int readline(std::string& line) = 0;

    virtual int read_col(std::string& val, bool is_scan = false) = 0; 

    virtual unsigned long long get_cur() = 0; 

    virtual void set_cur(unsigned long long cur) = 0; 

    virtual void set_data_start(unsigned long long data_start) = 0; 

    virtual unsigned long long get_data_start() = 0; 

    virtual void append() ;

};

} // namespace RiverDB
