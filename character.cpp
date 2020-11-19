//
// Created by Emmmer Shirakami on 2020/11/18.
//
#include <string>
#include <utility>
#include "random.cpp"

class person {
public:
    int hp = 0;
    int mp = 0;
    int armor = 50;
    int spell_resistance = 0;
    std::string name;


protected:
    int max_hp = 100;
    int max_mp = 0;

    int attack_power = 10;
    double attack_up_rate = 0.00;

    double vulnerable = 0.00;

    int piercing = 0;
    int mana_piercing = 0;

    double critical_rate = 0.05;
    double critical_damage = 0.50;


/*
 * 物理攻击
 * 如果暴击，返回暴击伤害
 * 如果没有暴击，返回普通伤害
 *
 * 判断 伤害 - (护甲 - 穿甲) 是否小于等于 保底伤害
 * 若小于，就返回 保底伤害+易伤效果
 * 若大于，就返回 穿甲伤害+易伤效果
 *
 * */

    virtual int physical_attack(person *be_attacked) {
        int damage = if_critical(critical_rate)
                     ? attack_power * (1 + attack_up_rate) * (1 + critical_damage)
                     : attack_power * (1 + attack_up_rate);
        int actually_damage = damage - ((be_attacked->armor) - piercing) <= damage * 0.05
                              ? damage * 0.05 * (1 + vulnerable)
                              : (damage - (be_attacked->armor - piercing)) * (1 + vulnerable);
        be_attacked->hp -= actually_damage;
        return actually_damage;
    }

/*
 * 法术
 * 法术不存在暴击机制
 * 伤害 = 攻击力 * (1+攻击力加成) * (法抗-无视法抗) * 0.6 + 易伤效果/2
 *
 * */
    virtual int mana(person *be_attacked) {
        int damage = attack_power
                     * (1 + attack_up_rate)
                     * (be_attacked->spell_resistance - mana_piercing)
                     * 0.6 * (1 + vulnerable / 2);
        be_attacked->hp -= damage;
        return damage;
    }
};

class player : public person {
public:
    explicit player(std::string input) {
        name = std::move(input);
        max_hp = 1000;
        max_mp = 100;
        hp = 1000;
        mp = 100;
    }


};

class npc : public person {
public:
    explicit npc(std::string input) {
        name = std::move(input);
        max_hp = 100;
        hp = 100;
    }

    int physical_attack(person *be_attacked) override {
        return 0;
    }

    int mana(person *be_attacked) override {
        return 0;
    }
};

int main() {
    player me("Emmmer");
    npc sb("mhy");

    me.physical_attack(&sb);
    printf("");


}