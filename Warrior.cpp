#include "Warrior.h"
#include "header.h"

void Warrior::swingWeapon(Player* opponent) {
    cout << Warrior::getName() << " attacked " << opponent->getName() << " with a " << _weapon << endl; 
    opponent->takeDamage(Warrior::getDamge());
}

Warrior::Warrior(string name, int health, int damage, string weapon) {
    _weapon = weapon;
    Warrior::setName(name);
    Warrior::setHealth(health);
    Warrior::setDamage(damage);
}   