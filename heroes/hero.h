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

    int health = 500;
    int mana = 300;

    Ability* abilities = new Ability[3];

    int currentHP = 500;
    int currentMana = 300;
    int currentGold = 500;

    int isSilenced = 0;
    int isStanned = 0;
    int isPeriodic = 0;
    int periodicDamage = 0;

public:
    Hero(QString name, QDir image, int health, int mana, Ability* abilities);

    QString getName();
    QDir getImage();
    int getHealth();
    int getMana();
    Ability* getAbilities();
    int getGold();
    int getCurrentHP();
    int getCurrentMana();
    int getIsSilenced();
    int getIsStanned();
    int getIsPeriodic();
    int getPeriodicDamage();

    virtual void castSkill(int);
    void getDamage(int);
    void useItem();
    void addGold(int);
    void addMaxHP(int);
    void addHP(int);
    void addMaxMana(int);
    void addMana(int);
    void removeGold(int);
    void removeMana(int);

    void setCurrentHP(int);
    void setCurrentMana(int);

    void setSilence(int);
    void setStanned(int);
    void setPeriodic(int);
    void addPeriodicDamage(int);

    void decreasePeriodic();

    std::vector<int>items;
};



#endif // HERO_H
