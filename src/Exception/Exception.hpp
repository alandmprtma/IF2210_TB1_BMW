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

class NoPLayerException : public Exception{
    public:
    const char* what() const throw(){
        return "[ERROR]: No Player Assigned yet";
    }
};
class NoPetaniException : public Exception{
    public:
    const char* what() const throw(){
        return "[ERROR]: No Petani Assigned yet";
    }
};
class NoPeternakException : public Exception{
    public:
    const char* what() const throw(){
        return "[ERROR]: No Peternak Assigned yet";
    }
};

class RecipeNotFoundException : public Exception{
    public:
    const char* what() const throw(){
        return  "Kamu tidak punya resep bangunan tersebut!";
    }
};

class PenyimpananKosong : public Exception{
    public:
    const char* what() const throw(){
        return "Penyimpanan Anda kosong!";
    }
};

class HarapanKosong : public Exception{
    public:
    const char* what() const throw(){
        return "Anda mengambil harapan kosong dari penyimpanan.";
    }
};

#endif