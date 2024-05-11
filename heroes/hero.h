#ifndef HERO_H
#define HERO_H

#include <QString>
#include <QFileDialog>
#include <QPixmap>

struct Ability {
    QString name;
    QPixmap image;
    int cooldown;
    int manaCost;
    int damage;
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

    virtual void castSkill(int);
    void getDamage(int);
    void useItem();
};



#endif // HERO_H
