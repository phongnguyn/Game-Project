#include "Wizard.h" 

void Wizard::castSpell(Player* opponent) {
    cout << Wizard::getName() << " attacked " << opponent->getName() << " with a spell of " << _mana << " mana" << endl; 
    opponent->takeDamage(Wizard::getDamge());
}

Wizard::Wizard(string name, int health, int damage, int mana) {
    _mana = mana;
    Wizard::setName(name);
    Wizard::setHealth(health);
    Wizard::setDamage(damage);
}   
