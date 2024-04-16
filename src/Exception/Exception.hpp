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
        return "Belum ada player yang terdaftar! ";
    }
};
class NoPetaniException : public Exception{
    public:
    const char* what() const throw(){
        return "Belum ada petani yang terdaftar!";
    }
};
class NoPeternakException : public Exception{
    public:
    const char* what() const throw(){
        return "Belum ada petani yang terdaftar!";
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
class PenyimpananSudahTerisi : public Exception{
    public:
    const char* what() const throw(){
        return "Penyimpanan Anda Sudah Terisi!";
    }
};
class PenympananSudahPenuh : public Exception {
    public:
    const char* what() const throw() {
        return "Penyimpanan Anda sudah penuh, tidak ada petak kosong yang tersisa!";
    }
};
class IndexOutOfBound : public Exception {
    public:
    const char* what() const throw(){
        return "Index yang dimasukkan melebihi batas penyimpanan!";
    }
};
class PlayerAlreadyExist : public Exception {
    public:
    const char* what() const throw(){
        return "Username Pemain sudah Terdaftar!";
    }
};
class PeranTidakValid : public Exception {
    public:
    const char* what() const throw(){
        return "Peran Tidak Valid!";
    }
};
class PeranTidakSesuai : public Exception {
    public:
    const char* what() const throw(){
        return "Perintah tidak dapat diakses karena peran tidak sesuai!";
    }
};
class UangTidakCukup : public Exception {
    public:
    const char* what() const throw(){
        return "Uang Pemain Tidak Cukup!";
    }
};
class WalikotaSurrend : public Exception {
    public:
    const char* what() const throw(){
        return "YTH Walikota, jangan surrend ! (T_T) ";
    }
};
class OpsiTidakValid : public Exception {
    public:
    const char* what() const throw(){
        return "Opsi tidak valid! ";
    }
};
#endif