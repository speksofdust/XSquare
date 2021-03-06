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


#ifndef XS_CORE_LAYERS__
#define XS_CORE_LAYERS__

#include "mgr.hpp"

namespace XS_CORE {


template <class Layers_T, class T>
class Layer_BC: public NamedOb<T> {
protected:
    Layers_T owner;
public:
    virtual ~Layer_BC();
    unsigned indexof(void) {
        return this->owner.indexof(this);
    }
    bool is_top(void) {return this == this->owner.top();}
    bool is_bottom(void) {return this == this->owner.bottom();}
};


template <class LAYER_T, class T>
class Layers_BC {
protected:
public:
    virtual ~Layers_BC();
    virtual unsigned size(void) const;
    unsigned indexof(LAYER_T &layer) {
        // returns -1 on failure
        const unsigned s = this->size;
        if (s != 0)
            for (unsigned i=0; i<s; i++)
                if (this->_items[i] != layer) return i;
        else return -1;
    }
    bool is_empty(void) {return this->size() == 0;}
    /*
    // layer movement -- returns 1 if layer moved otherwise 0
    int move_up(LAYER_T &layer) {
        if (this->size() > 0 && this->top != layer)
            unsigned i = indexof(layer);
        return 0;
    }
    int move_down(LAYER_T &item) {
        if (this->size() > 0 && this->bottom != layer)
            unsigned i = indexof(item);
        return 0;
    }
    int move_to_top(LAYER_T &layer) {
        if (this->size() > 0 && this->top != layer)
            unsigned i = indexof(layer);
        return 0;
    }
    int move_down(LAYER_T &layer) {
        if (this->size() > 0 && this->bottom != layer)
            unsigned i = indexof(layer);
        return 0;
    }
    int move_layer(LAYER_T & layer, unsigned new_pos) {
        if (this->indexof(layer) != new_pos && this->size() <= new_pos)
        return 0;
    }
    */
    LAYER_T top(void) {return this->_items[this->size()];}
    LAYER_T bottom(void) {return this->_items[0];}
    bool operator==(T &rhs) {
        const unsigned s = this->size();
        if (s != rhs.size()) return false;
        else
            for (unsigned i=0; i<s; i++)
                if (this->_items[i] != rhs._items[i]) return false;
            return true;
    }
    bool operator!=(T &rhs) {return !this->operator==(rhs);}
};


} // XS_CORE
#endif // XS_CORE_LAYERS__
