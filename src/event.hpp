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


#ifndef EVENT__
#define EVENT__

#include "core/mgr.hpp"


class Event;

class EventMgr: protected MgrWithRID<Event, EventMgr> {
protected:
    void _add_item(Event &evt);
public:
    friend class Event;
    EventMgr() {}
    ~EventMgr() {}
    Event new_evt(void);
    void cleanup(void);
    inline bool operator==(EventMgr& rhs) {
        return this->rid == rhs.rid;}
};


class Event: public NamedOb<Event> {
// Note: only mgr class uses rawids
protected:
    EventMgr _mgr;
    bool handled = false;
public:
    Event(EventMgr& mgr) {
        mgr._add_item(*this);
    }
    ~Event() {}
    unsigned handle(void) {
        if (!this->handled) this->handled = true;
        return 1;
    }
    bool is_handled(void) {return this->handled;}
    inline bool operator==(Event& rhs) {
        return (this->_mgr == rhs._mgr &&
                this->handled == rhs.handled &&
                this->name == rhs.name);
    }
};


static MgrMgr<Event, EventMgr> eventmanagers = MgrMgr<Event, EventMgr>();

#endif
