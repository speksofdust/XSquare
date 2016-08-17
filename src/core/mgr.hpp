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


#ifndef MGR__
#define MGR__

#include "include/vc.hpp"
#include "include/rawid.hpp"
#include "prop.hpp"


template <class ITEM_T, class CLS_T>
class Mgr: protected VC<ITEM_T, CLS_T> {
protected:
public:
};


template <class ITEM_T, class CLS_T> // T must inherit from ObWithRID
class MgrWithRID: protected Mgr<ITEM_T, CLS_T> {
protected:
    MgrRawID rid;

    void _add_item(ITEM_T &item) {
        item.rid = this->rid.new_RawID();
        this->items.push_back;
    }

public:
    const unsigned ID(void) {return this->rid.ID();}
};


template <class ITEM_T, class CLS_T>
class MgrMgr: protected Mgr<ITEM_T, CLS_T> {
// manager to manage managers
protected:
public:
    const CLS_T get_mgr_by_MGRID(const unsigned id) {
        for (unsigned i=0; i<this->size; i++)
            if (this->items[i].rid == id) return this->items[i];
    }
    const CLS_T get_mgr(const ITEM_T &item) {
        return this->get_mgr_by_MGRID(item._mgrid);
    }
};


/* ---- Primative Object types ---------------------------------------------- */
template <class CLS_T>
class _Ob_BC { // Base class
public:
    CLS_T& operator=(const CLS_T &other) { //copy
        if (this != &other) return *this;
    }
    CLS_T& operator=(CLS_T &other) { // move
        if (this != &other) return *this;
    }
    bool operator==(const CLS_T &rhs);
    bool operator!=(const CLS_T &rhs) {return !this->operator==(rhs);}

};

template <class CLS_T>
class NamedOb: protected _Ob_BC<CLS_T> {
public:
    StrProp name;
};

template <class CLS_T>
class ObWithRID: protected _Ob_BC<CLS_T> {
protected:
    RawID rid;
public:
    const unsigned ID(void) {return this->rid.ID();}
    CLS_T& operator=(const CLS_T &other) { // copy
        if (this != &other)
            this->rid++;    // must increment rid
            return *this;
    }
    bool operator==(const CLS_T &rhs) {return this->rid == rhs.rid;}
};

template <class CLS_T>
class NamedObWithRID: protected ObWithRID<CLS_T> {
public:
    StrProp name;
};


#endif
