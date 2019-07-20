#include <iostream>
#include "item.hpp"

using namespace game;

Item::Item(float x, float y, float width, float height) {
    
    // std::cout << "Called the item ctor" << std::endl;

    this->m_dimension = std::make_pair(width, height);
    this->m_position = std::make_pair(x,y);
}