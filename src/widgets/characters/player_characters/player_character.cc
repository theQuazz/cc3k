#include "player_character.h"
#include "../../items/gold/gold.h"

PlayerCharacter::PlayerCharacter(int health, int max_health, int atk, int def) :
  Character(health, max_health, atk, def),
  merchant_attacker(false) {}

void PlayerCharacter::take_turn() {
  Character::take_turn();
}

bool PlayerCharacter::is_pathable(terrain_t t) const {
  return t == TILE || t == PATHWAY || t == DOOR || t == STAIR;
}

char PlayerCharacter::to_char() const {
  return '@';
}

bool PlayerCharacter::has_reached_stair() const {
  return get_pos()->get_terrain() == STAIR;
}

bool PlayerCharacter::move(direction_t dir) {
  Cell *neighbour = get_pos()->get_neighbour(dir);

  if (neighbour && neighbour->get_widget()) {
    if (Gold *gold = dynamic_cast<Gold*>(neighbour->get_widget())) {
      gold->use(this);
    }
  }

  return Character::move(dir);
}

int PlayerCharacter::attack(Character &other) {
  int dmg = Character::attack(other);
  if (!other.is_alive()) did_kill(other);
  return dmg;
}

int PlayerCharacter::attack(Merchant &other) {
  merchant_attacker = true;
  return attack(static_cast<Hostile&>(other));
}

void PlayerCharacter::did_kill(Character &other) {
  set_gold(get_gold() + other.get_gold());
}

bool PlayerCharacter::attacks_merchants() {
  return merchant_attacker;
}

int PlayerCharacter::score() {
  return get_gold();
}
