#include "TextBox.h"
#include <iostream>

TextBox::TextBox(
        std::string text,
        float x,
        float y,
        void* font,
        float r,
        float g,
        float b,
        int width
    ):

    Shape(),
    text(text),
    x(x),
    y(y),
    font(font),
    r(r),
    g(g),
    b(b),
    width(width)
    {}

void TextBox::draw() const {
    glColor3f(r, g, b);
    glRasterPos2d(x, y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, reinterpret_cast<const unsigned char *>(text.c_str()));
}

void TextBox::setText(std::string text){
    this->text = text;
}
