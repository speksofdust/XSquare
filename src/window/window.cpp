/* ------------------------------------------------------------------------ *
 *   XSquare is free software: you can redistribute it and/or               *
 *   modify it under the terms of the GNU Lesser General Public License as  *
 *   published by the Free Software Foundation version 3 of the Licence, or *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   XSquare is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 *   General Public License for more details.                               *
 *                                                                          *
 *   You should have received copies of the GNU General Public License and  *
 *   the GNU Lesser General Public License along with this program.  If     *
 *   not, see http://www.gnu.org/licenses/.                                 *
* ------------------------------------------------------------------------- */


#include "window.hpp"

WindowManager wm = WindowManager();


Window::Window(const unsigned int* size[2], const unsigned int* min_size[2],
    const unsigned int* max_size[2]) {
    Window *w;
    this->_validate_size(size, min_size, max_size);
    wm._add_item(w);
    return w;
}
Window::~Window() {
    this->_destroying = true;
    wm._del_item(this);
    this->on_destroy();
}
Window::Window(const Window &win) { //copy
    Window *w;
    w->_qs(win._size, win._sizemin, win._sizemax);
    w->title = win.title;
    wm._add_item(w);
    this->on_create();
    return *this;
}
Window::Window operator==(const Window &rhs) {
    return wm->indexof(this) == wm->indexof(rhs);
}


