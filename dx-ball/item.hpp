#pragma once

#include <utility>

namespace game
{
    using TwoDim = std::pair<float, float>;

    class Item {

        protected:
        TwoDim m_dimension, m_position;
        // TODO: add color

        public:
        Item(float x, float y, float width, float height);
        const TwoDim getDimension();
    };
}