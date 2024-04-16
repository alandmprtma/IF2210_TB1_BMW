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
class PenyimpananSudahPenuh : public Exception {
    public:
    const char* what() const throw() {
        return "Penyimpanan Anda sudah penuh, tidak ada petak kosong yang tersisa!";
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

class PenyimpananDontHavePlant : public Exception {
    public:
    const char* what() const throw(){
        return "Penyimpanan Anda tidak memiliki plant! Anda tidak bisa tanam!";
    }
};

class ElementNotPlant : public Exception {
    public:
    const char* what() const throw(){
        return "Itu bukan tanaman! ambil yang lain!";
    }
};

class PetaniNotFoundException : public Exception {
    public:
    const char* what() const throw(){
        return "Petani tidak ditemukan!";
    }
};

class PeternakNotFoundException : public Exception {
    public:
    const char* what() const throw(){
        return "Peternak tidak ditemukan!";
    }
};

class SlotSudahTerisi : public Exception {
    public:
    const char* what() const throw(){
        return "Slot yang dipilih sudah terisi!";
    }
};

class SlotTidakValid : public Exception {
    public:
    const char* what() const throw(){
        return "Slot tidak valid!";
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
class HarapanKosong : public Exception{
    public:
    const char* what() const throw(){
        return "Anda mengambil harapan kosong dari penyimpanan.";
    }
};
class PenyimpananPenuh : public Exception{
    public:
    const char* what() const throw(){
        return "Penyimpanan Anda Penuh!";
    }
};
class GuldenTidakCukupException : public Exception{
    public:
    const char* what() const throw(){
        return "Gulden Anda tidak cukup!";
    }
};

class BarangTidakCukup : public Exception{
    public:
    const char* what() const throw(){
        return "Kuantitas barang tidak cukup untuk dibeli!";
    }
};

class LadangDontHaveAnimal : public Exception {
    public:
    const char* what() const throw() {
        return "Ladang Anda tidak memiliki Animal! Anda tidak bisa panen!";
    }
};

#endif