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


#ifndef WINDOW__
#define WINDOW__

#include "core/size2.hpp"
#include "core/mgr.hpp"
#include "events.hpp"


class Window: protected Size2 <unsigned, Window>{
protected:
    bool _destroying = false;
public:
    friend class Size2<unsigned, Window>;

    StrProp title;
    BoolProp fullscreen;

    Window(const unsigned* size[2], const unsigned* min_size[2],
        const unsigned* max_size[2]);
    ~Window();
    Window& operator=(const Window &other) { // copy
        if (this != &other) return *this;
    }
    Window& operator=(Window&& other) { // move
        if (this != &other) return *this;
    }
    bool operator==(const Window &rhs);
    bool operator!=(const Window &rhs) {return !this->operator==(rhs);}

    void clear(void);   // GlClear
    bool is_visible(void) {
        return !(this->_destroying || this->get_iconified());
    }

    /* -- window state getters/setters -- */
    bool get_iconified(void);
    void set_iconified(const bool x);

    void update(const double dt);
    void draw(const double dt);

    /* ---- Events ---- */
    unsigned on_destroy(void) {return 1;}
    /*
    unsigned int on_create(void) {return 1;}
    unsigned int on_resize(uint w, uint h) {return 1;}
    unsigned int on_destroy(void) {return 1;}
    unsigned int on_draw(double dt) {return 1;}
    unsigned int on_update(double dt) {return1;}
    */
};


class WindowManager: Mgr<Window, WindowManager> {
protected:
public:
    friend class Mgr<Window, WindowManager>;
    friend class Window;
    WindowManager() {}
    ~WindowManager() {}
    bool has_window(void) {
        for (unsigned i=0; i<this->size(); i++)
            if (this->items[i].is_visible())
                return true;
        return false;
    }
    unsigned update(double dt) {
        if (this->size() >= 1)
            for (unsigned i=0; i<this->size(); i++)
                this->items[i].update(dt);
        return this->on_finish_update();
    }
    unsigned draw(double dt) {
        if (this->size() >= 1)
            for (unsigned i=0; i<this->size(); i++)
                this->items[i].draw(dt);
        return this->on_finish_draw();
    }
    /* ---- Events ---- */
    unsigned on_finish_draw(void) {return 1;}
    unsigned on_finish_update(void) {return 1;}
};

#endif
