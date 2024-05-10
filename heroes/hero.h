#ifndef HERO_H
#define HERO_H

#include <QString>
#include <QFileDialog>

struct Ability {
    QString name;
    QDir image;
    int manaCost;
};

class Hero {
private:
    QString name;
    QDir image;

    int health;
    int mana;

    Ability* abilities = new Ability[3];

public:
    Hero(QString name, QDir image, int health, int mana, Ability* abilities);

    QString getName();
    QDir getImage();
    int getHealth();
    int getMana();
    Ability* getAbilities();

    void castSkill();
    void getDamage(int);
    void useItem();
};



#endif // HERO_H
