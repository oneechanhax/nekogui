
/*
 * Nekogui: Dumb ways to do existing things
 * Copyright (C) 2018 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "checkbox.hpp"

namespace neko::gui {

CheckBox::CheckBox(Element* _parent, bool* _value, std::function<void()> _callback) 
	: Element(_parent), value(_value), callback(_callback) {}
	
CheckBox::~CheckBox() {}

void CheckBox::Draw(const Vec2d& abs) const {
    Vec2d size = this->GetSize();
    this->draw_api->RectFilled(abs, size, this->draw_api->background);
    this->draw_api->RectOutline(abs, size, this->draw_api->outline);
    if (this->hovered && this->pressed) {
        this->draw_api->RectFilled(abs - 1, size - 1, this->draw_api->foreground);
    } else if (*this->value)
        this->draw_api->RectFilled(abs + 3, size - 3, this->draw_api->foreground);
}

void CheckBox::OnMouseEnter() { this->hovered = true; }
void CheckBox::OnMouseLeave() { this->hovered = false; }
void CheckBox::OnMousePress() { this->pressed = true; }
void CheckBox::OnMouseRelease() {
    if (this->hovered) {
        *this->value = !*this->value;
        this->callback();
    }
}

}