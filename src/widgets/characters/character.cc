#include "character.h"
#include <algorithm>

Character::Character(int health, int max_health, int atk, int def) :
  health(health),
  max_health(max_health),
  atk(atk),
  def(def),
  gold(0),
  moved(false) {}

bool Character::move(direction_t dir) {
  return false;
}

void Character::attack(Character &other) {
  other.defend(*this);
}

bool Character::defend(Character &other) {
  return false;
}

bool Character::did_move() {
  return moved;
}

void Character::take_turn() {
  moved = false;
}

int Character::get_health() {
  return health;
}

void Character::set_health(int new_health) {
  health = new_health;
  if (health > max_health) health = max_health;
  if (health < 0) health = 0;
}

int  Character::get_atk() {
  return atk;
}

void Character::set_atk(int new_atk) {
  atk = std::max(new_atk, 0);
}

int  Character::get_def() {
  return def;
}

void Character::set_def(int new_def) {
  def = std::max(new_def, 0);
}

int Character::get_gold() {
  return gold;
}

void Character::set_gold(int new_gold) {
  gold = std::max(new_gold, 0);
}

bool Character::is_alive() {
  return health > 0;
}
