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
#include "mixin/base_T.hpp"
#include "mixin/dataprop_T.hpp"

#ifndef PROP__
#define PROP__


class BoolProp: T_basecmp_dataprop<bool, BoolProp>{ // bool property
public:
    inline operator const int() {return (this->data)? 1 : 0;}
    inline operator int() {return (this->data)? 1 : 0;}
    inline operator const unsigned() {return (this->data)? 1 : 0;}
    inline operator unsigned() {return (this->data)? 1 : 0;}
    inline operator const char() {return (this->data)? 1 : 0;}
    inline operator char() {return (this->data)? 1 : 0;}
    inline operator const bool() {return this->data;}
    inline operator bool() {return this->data;}
    void set(bool v) {this->data = v;}
    void toggle(void) { // invert current state
        this->data = ~this->data;
    }
    bool toggled(void) { // invert current state and return it
        this->toggle();
        return this->data;
    }
    /*BoolProp& operator=(const BoolProp &rhs) {
        if (rhs.enabled != this->enabled && *this != &rhs) {
            this->toggle();}
        return *this;
    }*/
};


class CharArrProp: T_basecmp<char*> { // char array property
protected:
    char* _ca;
public:
    operator const char*() const {return this->_ca;}
    operator char*() {return this->_ca;}
    char* get(void) {return this->_ca;}
    void set(char* t) { if (this->_ca != t) this->_ca = t;}
    bool operator==(CharArrProp &rhs) { return this->_ca == rhs._ca; }
    bool operator!=(CharArrProp &rhs) {return !this->operator==(rhs);}
    bool operator==(char* rhs) {return this->_ca == rhs;}

    //char& operator[](size_t pos) {return this->_ca[pos];}
    //const char& operator[](size_t pos) const {return this->_ca[pos];}
};


class StrProp: T_basecmp_dataprop<std::string, StrProp> {
public:
    unsigned size(void) const {return this->data.size();}
    void set(std::string v) {this->data = v;}
    operator const char*() const {
        const char* c = this->data.c_str();
        return c;
    }
    operator std::string() {return this->data;}
    inline bool operator==(StrProp &rhs) {
        const size_t s = this->size();
        if (!rhs.size() == s) return false;
        else
            for (size_t i=0; i<s; i++)
                if (!this->data[i] == rhs.data[i]) return false;
        return true;
    }
    inline bool operator==(std::string &rhs) {
        const size_t s = this->size();
        if (!rhs.size() == s) return false;
        else
            for (size_t i=0; i<s; i++)
                if (!this->data[i] == rhs[i]) return false;
        return true;
    }
    inline bool operator!=(std::string &rhs) {return !this->operator==(rhs);}
    char& operator[](size_t pos) {return this->data[pos];}
    const char& operator[](size_t pos) const {return this->data[pos];}
};


#endif
