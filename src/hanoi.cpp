/**
 * Implementation of Tower and Hanoi
 */
 
#include <algorithm>
#include <stack>
#include <deque>
#include "hanoi.h"

std::string& Tower::getName()
{
    return this->name;
}

std::vector<size_t>& Tower::getTower()
{
    return this->tower;
}

Tower::Tower() {}

Tower::Tower(const std::string& name): name(name), tower(std::vector<size_t>()) {}

Tower::Tower(const std::string& name, std::vector<size_t>& v) : name(name), tower(v) {}

Hanoi::Hanoi(size_t height)
{
    this->towerA = Tower("TowerA");    
    for(size_t i=height; i>0; --i)
        this->towerA.getTower().push_back(i);
    this->towerB = Tower("TowerB");
    this->towerC = Tower("TowerC");
    this->solveHanoiStart(std::cout, this->towerA, this->towerB, this->towerC);
}

void Hanoi::moveTopPlate(Tower& origin, Tower& target, 
     const std::function<void (const std::string&, const std::string&)> &preMovePrint, 
     const std::function<void ()> &postMovePrint)
{
    // TODO: Implement
    if (origin.getTower().size() == 0)
        return;
    if (target.getTower().size() > 0) {
        if (origin.getTower().back() < target.getTower().back()) {
            preMovePrint(origin.getName(), target.getName());
            target.getTower().push_back(origin.getTower().back());
            origin.getTower().pop_back();
            postMovePrint();
        }
    }
    else {
        preMovePrint(origin.getName(), target.getName());
        target.getTower().push_back(origin.getTower().back());
        origin.getTower().pop_back();
        postMovePrint();
    }
}

void Hanoi::solveHanoi(size_t towersize, Tower& source, Tower& destination, Tower& spare, 
    const std::function<void (const std::string&, const std::string&)> &preMovePrint, 
    const std::function<void ()> &postMovePrint)
{
    // TODO: Implement
    if (towersize == 1) {
        this->moveTopPlate(source, destination, preMovePrint, postMovePrint);
        return;
    }
    this->solveHanoi(towersize - 1, source, spare, destination, preMovePrint, postMovePrint);
    this->moveTopPlate(source, destination, preMovePrint, postMovePrint);
    this->solveHanoi(towersize - 1, spare, destination, source, preMovePrint, postMovePrint);
}

void Hanoi::solveHanoiStart(std::ostream& os, Tower& source, Tower& destination, Tower& spare)
{
    // TODO: Implement
    size_t h = source.getTower().size();
    auto preMovePrint = [&os](const std::string& a, const std::string& b)
        {os << "Move from " << a << " to " << b << std::endl;};
    auto postMovePrint = [this, &h, &os]()
        {
            for (size_t i=h; i>0; --i) {
                size_t plate = 0;
                if (this->towerA.getTower().size() >= i) {
                    plate = this->towerA.getTower()[i-1];
                }

                os << std::string((2*h-2*plate)/2, ' ') << std::string(2*plate, '#') << std::string((2*h-2*plate)/2, ' ');
                os << ' ';

                if (this->towerB.getTower().size() >= i) {
                    plate = this->towerB.getTower()[i-1];
                } else {
                    plate = 0;
                }

                os << std::string((2*h-2*plate)/2, ' ') << std::string(2*plate, '#') << std::string((2*h-2*plate)/2, ' ');
                os << ' ';

                if (this->towerC.getTower().size() >= i) {
                    plate = this->towerC.getTower()[i-1];
                } else {
                    plate = 0;
                }

                os << std::string((2*h-2*plate)/2, ' ') << std::string(2*plate, '#') << std::string((2*h-2*plate)/2, ' ');
                os << std::endl;
            }
            os << std::string(6*h+2, '_') << "\n\n";
        };
    this->solveHanoi(h, source, destination, spare, preMovePrint, postMovePrint);
}



