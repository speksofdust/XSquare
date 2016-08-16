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


#ifndef VC__
#define VC__

#include <iostream>
#include <vector>

template <class ITEM_T, class CLS_T>
class VC { // Vector container class
protected:
    std::vector<ITEM_T> items;
    void _del_item_safe(ITEM_T item) {
        this._del_item_by_idx(this->indexof_safe(item));
    }
    void _del_item(ITEM_T item) { this._del_item_by_idx(this->indexof(item)); }
    void _del_item_by_idx(const unsigned i) {
        if (i == 0 || i <= this->size())
            this->items.erase(this->items.begin()+i);
    }
    void _add_item(ITEM_T &item) {this->items.push_back;}
public:
    unsigned size(void) const {return this->items.size();}
    unsigned indexof(ITEM_T item) {
        // should only be called when item is guarenteed to exist in items
        for (unsigned i=0; i<this->items.size(); i++)
            if (this->items[i] == item) return i;
    }
    unsigned indexof_safe(ITEM_T item) {
        // same as indexof but throws error if item does not exist
        try { return indexof(item); }
        catch(const std::exception& e) {
            std::cout << "item: '" << e.what() << "' does not exist in this "
                "vector array.\n";
        }
    }
    bool has_item(ITEM_T item) {
        for (unsigned i=0; i<this->items.size(); i++)
            if (this->items[i] == item) return true;
        return false;
    }
    bool operator==(const CLS_T &rhs) {return this->items->operator==(rhs);}
    bool operator!=(const CLS_T &rhs) {return !this->operator==(rhs);}
    ITEM_T& operator[](size_t pos) {return this->items[pos];}
    const ITEM_T& operator[](size_t pos) const {return this->items[pos];}

};

#endif
