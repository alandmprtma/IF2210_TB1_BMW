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
class PenyimpananSudahTerisi : public Exception{
    public:
    const char* what() const throw(){
        return "Penyimpanan Anda Sudah Terisi!";
    }
};

class IndexOutOfBound : public Exception {
    public:
    const char* what() const throw(){
        return "Index yang dimasukkan melebihi batas penyimpanan!";
    }
};

class InvalidPlayer : public Exception {
    public:
    const char* what() const throw(){
        return "Anda tidak memiliki akses untuk melakukan aksi ini!";
    }
};

class ElementNotFound : public Exception {
    public:
    const char* what() const throw(){
        return "Kamu mengambil harapan kosong dari penyimpanan.\nSilahkan masukan slot yang berisi makanan.";
    }
};

class ElementNotConsumable : public Exception {
    public:
    const char* what() const throw(){
        return "Apa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!\nSilahkan masukan slot yang berisi makanan.";
    }
};

class PenyimpananDontHaveProduct : public Exception {
    public:
    const char* what() const throw(){
        return "Penyimpanan Anda tidak memiliki produk! Anda tidak bisa makan!";
    }
};

#endif