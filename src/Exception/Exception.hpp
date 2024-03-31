#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

class Exception{

public:
    virtual const char* what() const throw(){
        return "[ERROR] : Undefined Exception";
    }
};

class FileNotFoundError{

public:
    const char* what() const throw(){
        return "[ERROR]: Given Input File Cannot be Found";
    }

};

class UndefinedSymbolError{

public:
    const char* what() const throw(){
        return "[ERROR]: Undefined Symbol Detected";
    }
};

#endif