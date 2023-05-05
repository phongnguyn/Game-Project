#include "Player.h"

void Player::takeDamage(int _damage) {
    cout << _damage << " damage\n";
    health -= _damage;
}

void Player::setHealth(int _health) {health = _health;}

float Player::getHealth() {return health;}

void Player::setDamage(int _damage) {damage = _damage;}

float Player::getDamge() {return damage;}

void Player::setStamina(float _stamina) {stamina = _stamina;}

float Player::getStamina() {return stamina;}

