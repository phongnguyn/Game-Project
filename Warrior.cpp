#include "Warrior.h"
#include "header.h"

void Warrior::swingWeapon(Player* opponent) {
    cout << " with a " << _weapon << endl; 
    opponent->takeDamage(Warrior::getDamge());
}

Warrior::Warrior(float health, float damage, string weapon, float stamina) {
    _weapon = weapon;
    Warrior::setHealth(health);
    Warrior::setDamage(damage);
    Warrior::setStamina(stamina);
}   