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


#ifndef XSAPP__
#define XSAPP__

#include "core/rstate/rstate_bc.hpp"
#include "console.hpp"


class AppState: public RState {
protected:
    char state;
    bool paused = false;
    unsigned locked = 0;
    void _set_state(const char state) {this->state = state;}
public:
    friend class App;
    AppState() {}
    ~AppState() {}
};


class AppEvent {
protected:
    char etid;
    bool handled = false;
public:
    friend class AppState;
    AppEvent() {}
    AppEvent(const char& etid) {
        this->etid = etid;
    }
    ~AppEvent() {}
    inline const char ETID(void) {return this->etid;}
    inline const char eventtype_id(void) {return this->etid;} // alias for ETID
    void handle(void) {
        if (!this->handled) this->handled = true;
    }
    inline bool is_handled(void) {return this->handled;}
    inline bool operator==(const AppEvent &rhs) {
        return this->etid == rhs.etid;
    }
    inline bool operator!=(const AppEvent &rhs) {
        return !this->operator==(rhs);
    }
};


class AppEvents {
public:
    AppEvent evt;
    AppEvents() {}
    ~AppEvents() {}
};


class App {
protected:
    AppState rs;
    void _spawn_evt();
    void _set_state(const char s) {this->rs._set_state(s);}
    Console console;
    // TODO add profiling stuff
public:
    App() {
        Console *c = new Console();
        this->console = *c;
        delete c;
    }
    AppEvents events;
    const AppState runstate(void) const {return this->rs;}
    inline char get_runstate(void) {return this->rs.get_state();}
    const char* runstate_name(void) {
        return get_rsname(this->rs.get_state());
    }
    void start(void);
    void app_init(void);
    void end(void);
};


App app = App();


#endif // XSAPP__
