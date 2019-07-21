#pragma once

#include <utility>

namespace game
{
    using TwoDim = std::pair<float, float>;

    class Item {

        // friend class Item;
        public:
        TwoDim m_dimension, m_position; // make this protected/private again
        // TODO: add color

        public:
        Item(float x, float y, float width, float height);
        const TwoDim getDimension();
    };
}