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

#ifndef STATEOPS_T__
#define STATEOPS_T__

template <typename NUM_T, class T>
class _T_state_ops {
// Basic state machine comparison operators;
protected:
    NUM_T state = 0;
    void _set_state(const char state) {this->state = state;}
public:
    virtual ~_T_state_ops();
    bool operator==(T &rhs) {return this->state == rhs.state;}
    bool operator!=(T &rhs) {return !this->operator==(rhs);}
    bool operator<(T &rhs) {return this->state < rhs.state;}
    bool operator>(T &rhs) {return this->state > rhs.state;}
    bool operator<=(T &rhs) {return this->state <= rhs.state;}
    bool operator>=(T &rhs) {return this->state >= rhs.state;}

    bool operator==(NUM_T rhs) {return this->state == rhs;}
    bool operator!=(NUM_T rhs) {return !this->operator==(rhs);}
    bool operator<(NUM_T rhs) {return this->state < rhs;}
    bool operator>(NUM_T rhs) {return this->state > rhs;}
    bool operator<=(NUM_T rhs) {return this->state <= rhs;}
    bool operator>=(NUM_T rhs) {return this->state >= rhs;}
};

#endif // STATEOPS_T__
