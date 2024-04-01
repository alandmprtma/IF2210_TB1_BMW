#include "Player.hpp"

int Player::jumlahPlayer = 0;

Player::Player() {
  this->uang = 50;
  this->berat_badan = 40;
}

void Player::setUsername(string username) {
  this->username = username;
}