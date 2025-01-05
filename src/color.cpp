#include "color.h"

namespace Axle
{
    Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    Color::Color(unsigned char r, unsigned char g, unsigned char b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = 255;
    }

    Color::Color()
    {
        this->r = 0;
        this->g = 0;
        this->b = 0;
        this->a = 0;
    }

    Color::Color(ColorPreset preset)
    {
        this->setColor(preset);
    }

    void Color::setR(unsigned char r)
    {
        this->r = r;
    }

    void Color::setG(unsigned char g)
    {
        this->g = g;
    }

    void Color::setB(unsigned char b)
    {
        this->b = b;
    }

    void Color::setA(unsigned char a)
    {
        this->a = a;
    }

    void Color::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    void Color::setColor(ColorPreset preset)
    {
        switch (preset)
        {
        case ColorPreset::LIGHTGRAY:
            this->r = 200;
            this->g = 200;
            this->b = 200;
            this->a = 255;
            break;
        case ColorPreset::GRAY:
            this->r = 130;
            this->g = 130;
            this->b = 130;
            this->a = 255;
            break;
        case ColorPreset::DARKGRAY:
            this->r = 80;
            this->g = 80;
            this->b = 80;
            this->a = 255;
            break;
        case ColorPreset::YELLOW:
            this->r = 253;
            this->g = 249;
            this->b = 0;
            this->a = 255;
            break;
        case ColorPreset::GOLD:
            this->r = 255;
            this->g = 203;
            this->b = 0;
            this->a = 255;
            break;
        case ColorPreset::ORANGE:
            this->r = 255;
            this->g = 161;
            this->b = 0;
            this->a = 255;
            break;
        case ColorPreset::PINK:
            this->r = 255;
            this->g = 109;
            this->b = 194;
            this->a = 255;
            break;
        case ColorPreset::RED:
            this->r = 230;
            this->g = 41;
            this->b = 55;
            this->a = 255;
            break;
        case ColorPreset::MAROON:
            this->r = 190;
            this->g = 33;
            this->b = 55;
            this->a = 255;
            break;
        case ColorPreset::GREEN:
            this->r = 0;
            this->g = 228;
            this->b = 48;
            this->a = 255;
            break;
        case ColorPreset::LIME:
            this->r = 0;
            this->g = 158;
            this->b = 47;
            this->a = 255;
            break;
        case ColorPreset::DARKGREEN:
            this->r = 0;
            this->g = 117;
            this->b = 44;
            this->a = 255;
            break;
        case ColorPreset::SKYBLUE:
            this->r = 102;
            this->g = 191;
            this->b = 255;
            this->a = 255;
            break;
        case ColorPreset::BLUE:
            this->r = 0;
            this->g = 121;
            this->b = 241;
            this->a = 255;
            break;
        case ColorPreset::DARKBLUE:
            this->r = 0;
            this->g = 82;
            this->b = 172;
            this->a = 255;
            break;
        case ColorPreset::PURPLE:
            this->r = 200;
            this->g = 122;
            this->b = 255;
            this->a = 255;
            break;
        case ColorPreset::VIOLET:
            this->r = 135;
            this->g = 60;
            this->b = 190;
            this->a = 255;
            break;
        case ColorPreset::DARKPURPLE:
            this->r = 112;
            this->g = 31;
            this->b = 126;
            this->a = 255;
            break;
        case ColorPreset::BEIGE:
            this->r = 211;
            this->g = 176;
            this->b = 131;
            this->a = 255;
            break;
        case ColorPreset::BROWN:
            this->r = 127;
            this->g = 106;
            this->b = 79;
            this->a = 255;
            break;
        case ColorPreset::DARKBROWN:
            this->r = 76;
            this->g = 63;
            this->b = 47;
            this->a = 255;
            break;
        case ColorPreset::WHITE:
            this->r = 255;
            this->g = 255;
            this->b = 255;
            this->a = 255;
            break;
        case ColorPreset::BLACK:
            this->r = 0;
            this->g = 0;
            this->b = 0;
            this->a = 255;
            break;
        case ColorPreset::BLANK:
            this->r = 0;
            this->g = 0;
            this->b = 0;
            this->a = 0;
            break;
        case ColorPreset::MAGENTA:
            this->r = 255;
            this->g = 0;
            this->b = 255;
            this->a = 255;
            break;
        }
    }

    unsigned char Color::getR() const
    {
        return r;
    }

    unsigned char Color::getG() const
    {
        return g;
    }

    unsigned char Color::getB() const
    {
        return b;
    }

    unsigned char Color::getA() const
    {
        return a;
    }
}
