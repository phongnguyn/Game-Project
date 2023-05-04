#include "player.h"

void Player::takeDamage(int damage) {
    cout << _name << " take " << damage << " damage\n";
    _health -= damage;
}

void Player::setName(string name) {_name = name;}

string Player::getName() {return _name;}

void Player::setHealth(int health) {_health = health;}

int Player::getHealth() {return _health;}

void Player::setDamage(int damage) {_damage = damage;}

int Player::getDamge() {return _damage;}

