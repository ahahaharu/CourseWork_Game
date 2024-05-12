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

    int silence;
    int stan;
    int periodic;
    int periodicFor;
};

class Hero {
private:
    QString name;
    QDir image;

    int health;
    int mana;

    Ability* abilities = new Ability[3];

    int currentHP = health;
    int currentMana = mana;
    int currentGold = 500;

    int isSilenced = 0;
    int isStanned = 0;
    int isPereodic = 0;
    int pereodicDamage = 0;

public:
    Hero(QString name, QDir image, int health, int mana, Ability* abilities);

    QString getName();
    QDir getImage();
    int getHealth();
    int getMana();
    Ability* getAbilities();
    int getGold();

    virtual void castSkill(int);
    void getDamage(int);
    void useItem();
    void addGold(int);
    void removeGold(int);

    std::vector<int>items;
};



#endif // HERO_H
