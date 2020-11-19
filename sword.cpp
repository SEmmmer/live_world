//
// Created by Emmmer Shirakami on 2020/11/18.
//
#include <string>

class sword {
protected:
    int damage = 0;
    int speed = 2;
    int level = 1;
    int experience = 0;
    int max_set_count = 0;
    std::string name;

    virtual int level_up() = 0;

    virtual int strengthen() = 0;

};

//wood sword
class wood_sword : public sword {
public:
    wood_sword() {
        name = "木剑";
        damage = 1;
    }
};

int main() {

};