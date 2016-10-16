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

// TODOs (as needed)
// 1 -- make Mgrs more universaly compatable with other std container types
// 2 -- Thread safety?

template <class ITEM_T, class CLS_T>
class Mgr: public VC<ITEM_T, CLS_T> {
protected:
public:
    virtual ~Mgr();
    void _add_item(ITEM_T &item) {
        this->items.push_back(*item);
    }
};


template <class ITEM_T, class CLS_T>
class MgrWithRID: public Mgr<ITEM_T, CLS_T> {
// Only the manager (CLS_T) uses an rid
// - Comparisons are done using rids for speed
protected:
    MgrRawID rid;
    const unsigned ID(void) const {return this->rid.ID();}
public:
    virtual ~MgrWithRID();
    inline bool operator==(CLS_T& rhs) {return this->rid == rhs.rid;}
};


template <class ITEM_T, class CLS_T> // ITEM_T must inherit from ObWithRID
class ObWithRID_MgrWithRID: public MgrWithRID<ITEM_T, CLS_T> {
// Both the manager (CLS_T) and the items it manages (ITEM_T) use rids
protected:
    void _add_item(ITEM_T &item) {
        item.rid = this->rid.new_RawID();
        this->items.push_back(*item);
    }
public:
    virtual ~ObWithRID_MgrWithRID();
    inline bool operator==(CLS_T& rhs) {return this->rid == rhs.rid;}
};


template <class ITEM_T, class CLS_T>
class MgrMgr: public Mgr<ITEM_T, CLS_T> {
// manager to manage 'managers'
// the item ('manager') to be managed (ITEM_T) MUST inherit from
//      MgrWithRID or one of its derived classes
//      OR use utilize an rid in the same manner as MgrWithRID
// - Comparisons are done using RIDS for speed
protected:
public:
    virtual ~MgrMgr();
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
    virtual ~_Ob_BC();
    CLS_T& operator=(const CLS_T &other) { //copy
        if (this != &other) return *this;
    }
    CLS_T& operator=(CLS_T &other) { // move
        if (this != &other) return *this;
    }
    virtual bool operator==(CLS_T &rhs);
    bool operator!=(CLS_T &rhs) {return !this->operator==(rhs);}

};


template <class CLS_T>
class NamedOb: public _Ob_BC<CLS_T> {
public:
    StrProp name;
    virtual ~NamedOb();
};


template <class CLS_T>
class ObWithRID: public _Ob_BC<CLS_T> {
protected:
    RawID rid;
    const unsigned ID(void) {return this->rid.ID();}
public:
    virtual ~ObWithRID();
    CLS_T& operator=(const CLS_T &other) { // copy
        if (this != &other) {// must increment rid
            CLS_T x = *this;
            x.rid = this->rid.new_RawID();
            return x;
        } else return *this;
    }
    bool operator==(const CLS_T &rhs) {return this->rid == rhs.rid;}
};


template <class CLS_T>
class NamedObWithRID: public ObWithRID<CLS_T> {
public:
    StrProp name;
    virtual ~NamedObWithRID();
};


#endif
