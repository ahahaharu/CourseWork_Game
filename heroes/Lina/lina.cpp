#include "lina.h"

Lina::Lina()
    : Hero("Lina", QDir("../../Resources/images/Heroes/Lina/Lina.gif"), 500, 300, new Ability[3]{
    {"Dragon Slave", QPixmap("../../Resources/images/Heroes/Lina/lina_dragon_slave.png"), 0, 50, 75},
    {"Light Strike", QPixmap("../../Resources/images/Heroes/Lina/lina_light_strike.png"), 2, 100, 50},
    {"Laguna Blade", QPixmap("../../Resources/images/Heroes/Lina/lina_laguna_blade.png"), 4, 200, 300}
    }) {}

void Lina::castSkill(int ind) {

}
