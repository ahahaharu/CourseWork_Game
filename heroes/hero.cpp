#include "hero.h"

Hero::Hero(QString name, QDir image, int health, int mana, Ability* abilities) {
    this->name = name;
    this->image = image;
    this->health = health;
    this->mana = mana;
    this->abilities = abilities;
}

QString Hero::getName() {
    return this->name;
}

QDir Hero::getImage() {
    return this->image;
}

int Hero::getHealth() {
    return this->health;
}

int Hero::getMana() {
    return this->mana;
}

Ability* Hero::getAbilities() {
    return this->abilities;
}

void Hero::castSkill() {

}

void Hero::getDamage(int damage) {
    health -= damage;
}

void Hero::useItem() {

}
