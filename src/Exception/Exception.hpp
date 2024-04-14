#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

class Exception{

public:
    virtual const char* what() const throw(){
        return "[ERROR] : Undefined Exception";
    }
};

class FileNotFoundError : public Exception{

public:
    const char* what() const throw(){
        return "[ERROR]: Given Input File Cannot be Found";
    }

};

class UndefinedSymbolError : public Exception{

public:
    const char* what() const throw(){
        return "[ERROR]: Undefined Symbol Detected";
    }
};

class MaterialTidakCukupException : public Exception{
    public:
    const char* what() const throw(){
        return "Kamu tidak punya sumber daya yang cukup!";
    }
};

class RecipeNotFoundException : public Exception{
    public:
    const char* what() const throw(){
        return  "Kamu tidak punya resep bangunan tersebut!";
    }
};

#endif