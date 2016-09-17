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


#ifndef STATEPROPS__
#define STATEPROPS__

#include "stateops_T.hpp"

template <typename NUM_T, class T>
class state_switch_T: public _T_state_ops<NUM_T, T> {
protected:
    NUM_T min, max;
public:
    virtual ~state_switch_T();
    const NUM_T get(void) const {return this->state;}
    NUM_T get(void) {return this->state;}
    int set(const NUM_T state) {
        if (state == this->state) return 0;
        else if (state <= min) this->state = this->min;
        else if (state >= this->max) this->state = this->max;
        else this->state = state;
        return 1;
    }
    inline void operator++(void) {
        if (this->state < this->max) this->state++;
    }
    inline void operator--(void) {
        if (this->state > this->min) this->state--;
    }
};

template <typename NUM_T, class T>
class looping_state_switch_T: public _T_state_ops<NUM_T, T> {
protected:
    NUM_T max;
public:
    virtual ~looping_state_switch_T();
    const unsigned get(void) const {return this->state;}
    NUM_T get(void) {return this->state;}
    int set(const NUM_T state) {
        if (state == this->state) return 0;
        else if (state >= this->max) this->state = this->max;
        else if (state <= 0) this->state = 0;
        return 1;
    }
    inline void operator++(void) {
        if (this->state == this->max) this->state = 0;
        else this->state++;
    }
    inline void operator--(void) {
        if (this->state == 0) this->state = this->max;
        else this->state--;
    }
};

#endif // STATEPROPS__
