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


#include <string>
#include "include/basic_ops.hpp"

#ifndef PROP__
#define PROP__


class BoolProp: BasicBoolOps<BoolProp>{ // bool property
protected:
    bool enabled;
public:
    bool get_enabled(void) {return this->enabled; }
    void set_enabled(bool t) {if (this->enabled != t) this->enabled = t;}
    void toggle(void) { // invert current state
        if (this->enabled == true) this->enabled = false;
        else this->enabled = true;
    }
    bool toggled(void) { // invert current state and return it
        this->toggle();
        return this->enabled;
    }
    /*BoolProp& operator=(const BoolProp &rhs) {
        if (rhs.enabled != this->enabled && *this != &rhs) {
            this->toggle();}
        return *this;
    }*/
    bool operator==(const BoolProp &rhs) {
        return this->enabled == rhs.enabled;
    }
    bool operator!=(const BoolProp &rhs) {
        return (!this->operator==(rhs));
    }
};


class CharArrProp { // char array property
protected:
    char* _ca;
public:
    char* get(void) { return this->_ca; }
    void set(char* t) { if (this->_ca != t) this->_ca = t;}
    bool operator==(const CharArrProp &rhs) { return this->_ca == rhs._ca; }
    bool operator!=(const CharArrProp &rhs) {
        return (!this->operator==(rhs));
    }
    //char& operator[](size_t pos) {return this->_ca[pos];}
    //const char& operator[](size_t pos) const {return this->_ca[pos];}
};


class StrProp {
protected:
    std::string _str;
public:
    void set(char* t);
    unsigned size(void) const {return this->_str.size();}
    bool operator==(const StrProp &rhs) {
        const unsigned s = this->size();
        if (!rhs.size() == s) return false;
        else
            for (size_t i=0; i<s; i++)
                if (!this->_str[i] == rhs._str[i]) return false;
        return true;
    }
    bool operator!=(const StrProp &rhs) {return !this->operator==(rhs);}
    char& operator[](size_t pos) {return this->_str[pos];}
    const char& operator[](size_t pos) const {return this->_str[pos];}
    // std::string x StrProp comparison
    /*
    bool operator==(const &rhs) {
        const unsigned s = this->size();
        if (!rhs.size() == s) return false;
        else
            for (size_t i=0; i<s; i++)
                if (!this->_str[i] == rhs[i]) return false;
        return true;
    }
    bool operator!=(const &rhs) {return !this->operator==(rhs);}
    */
};


#endif
