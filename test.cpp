#include "./src/Penyimpanan/Penyimpanan.hpp"
#include "./src/Penyimpanan/PetiRahasia.hpp"
#include "./src/Penyimpanan/PetiRahasia.cpp"
#include "./src/Penyimpanan/Ladang.hpp"
#include "./src/Penyimpanan/Ladang.cpp"
#include "./src/Penyimpanan/Ternak.hpp"
#include "./src/Penyimpanan/Ternak.cpp"
#include "./src/Item/Item.hpp"
#include "./src/Item/Item.cpp"
#include "./src/Item/Plant.hpp"
#include "./src/Item/Plant.cpp"
#include "./src/Item/Animal.hpp"
#include "./src/Item/Animal.cpp"
#include "./src/Toko/Toko.hpp"
#include "./src/Toko/Toko.cpp"
#include "./src/Player/Player.hpp"
#include "./src/Player/Player.cpp"
#include "./src/Player/Petani.hpp"
#include "./src/Player/Petani.cpp"
#include "./src/Player/Peternak.hpp"
#include "./src/Player/Peternak.cpp"
#include "./src/Item/Produk.hpp"
#include "./src/Item/Produk.cpp"
#include "./src/GameObject/GameObject.hpp"
#include "./src/GameObject/GameObject.cpp"
#include "./src/Item/Bangunan.hpp"
#include "./src/Item/Bangunan.cpp"

int main() {
  GameObject game_object = GameObject();

  try{
      game_object.muatTanaman("Config/plant.txt");
      game_object.muatHewan("Config/animal.txt");
      game_object.muatProduk("Config/product.txt");
      game_object.muatBangunan("Config/recipe.txt");
      game_object.muatMisc("Config/misc.txt");
  }
  catch (const FileNotFoundError &e){
      cout << e.what() << endl;
  }

  /* Peternak */
  Peternak P;
  P.setUsername("Albert");
  P.setBeratBadan(60);

  P.dataTernak.setElement(new Animal("COW", "COW", "HERBIVORE", 20, 6), 2, 2);
  P.dataTernak.setElement(new Animal("SHP", "SHEEP", "HERBIVORE", 15, 5), 3, 2);
  P.dataTernak.getElement(3, 2)->setBerat(25);
  P.dataTernak.setElement(new Animal("CHK", "CHICKEN", "OMNIVORE", 12, 3), 2, 5);
  P.dataTernak.getElement(2, 5)->setBerat(25);
  P.dataTernak.setElement(new Animal("SHP", "SHEEP", "HERBIVORE", 15, 5), 4, 4);

  P.data.setElement(new Produk("APP", "APPLE", "PRODUCT_FRUIT_PLANT", "APPLE_TREE", 4, 8), 2, 2);

  P.panenTernak(game_object);

  P.data.cetakPeti("Penyimpanan");
  P.dataTernak.cetakTernak("Peternakan");

  // Petani P;

  // P.setUsername("Petani");
  // P.setBeratBadan(50);

  // P.dataLadang.setElement(new Plant("APL", "APPLE_TREE", "FRUIT_PLANT", 13, 4), 1, 1);
  // P.dataLadang.setElement(new Plant("APL", "APPLE_TREE", "FRUIT_PLANT", 13, 4), 1, 3);
  // P.dataLadang.setElement(new Plant("APL", "APPLE_TREE", "FRUIT_PLANT", 13, 4), 1, 5);
  // P.dataLadang.setElement(new Plant("ALT", "ALOE_TREE", "MATERIAL_PLANT", 11, 5), 3, 3);

  // P.tambahUmurTanaman(15, 1, 1);
  // P.tambahUmurTanaman(15, 1, 3);
  // P.tambahUmurTanaman(15, 3, 3);

  // P.panenTanaman(game_object);

  // P.dataLadang.cetakLadang("Ladang");
  // P.data.cetakPeti("Penyimpanan");

  return 0;
}