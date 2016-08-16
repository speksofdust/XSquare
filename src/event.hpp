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


//Event class & manager using rawids for really fast !/!=/== comparisons


#ifndef EVENT__
#define EVENT__

#include "core/mgr.hpp"


class Event: protected NamedObWithRID<Event> {
protected:
    unsigned _mgrid;
    bool handled = false;
public:
    Event() {}
    Event(unsigned RID) {
        this->_mgrid = RID;
    }
    ~Event() {}
    unsigned handle(void) {
        if (!this->handled) this->handled = true;
        return 1;
    }
    bool is_handled(void) {return this->handled;}
};


class EventMgr: protected MgrWithRID<Event, EventMgr> {
protected:
public:
    friend class Event;
    EventMgr() {}
    ~EventMgr() {}
    Event new_evt(void) {
        Event e = Event(this->ID());
        return e;
    }
    void cleanup(void) {
        for (unsigned i=0; i<=this->size(); i++) {
            if (!this->items[i].is_handled())
                this->_del_item_by_idx(i);
        }
    }
};


static MgrMgr<Event, EventMgr> eventmanagers = MgrMgr<Event, EventMgr>();

#endif
