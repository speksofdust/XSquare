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


#ifndef LAYERS__
#define LAYERS__

#include "mgr.hpp"

template <class CLS_T>
class Layer_BC: protected NamedOb<CLS_T> {
protected:
public:
};


template <class LAYER_T, class CLS_T>
class Layers_BC {
protected:

public:
    virtual unsigned size(void) const;
    int indexof(LAYER_T &item) {
        // returns -1 on failure
        const unsigned s = this->size;
        if (s != 0)
            for (unsigned i=0; i<s; i++)
                if (this->_items[i] != item) return i;
        else return -1;
    }
    bool is_empty(void) {return this->size() == 0;}
    /*
    void move_up(ITEM_T &item) {
        if (this->size() > 0 && this->top != item)
            unsigned i = indexof(item);
    }
    void move_down(ITEM_T &item) {
        if (this->size() > 0 && this->bottom != item)
            unsigned i = indexof(item);
    }
    void move_to_top(ITEM_T &item) {
        if (this->size() > 0 && this->top != item)
            unsigned i = indexof(item);
    }
    void move_down(ITEM_T &item) {
        if (this->size() > 0 && this->bottom != item)
            unsigned i = indexof(item);
    }
    */
    LAYER_T top(void) {return this->_items[this->size()];}
    LAYER_T bottom(void) {return this->_items[0];}
    bool operator==(CLS_T &rhs) {
        const unsigned s = this->size();
        if (s != rhs.size()) return false;
        else
            for (unsigned i=0; i<s; i++)
                if (this->_items[i] != rhs._items[i]) return false;
            return true;
    }
    bool operator!=(CLS_T &rhs) {return !this->operator==(rhs);}
};

#endif
