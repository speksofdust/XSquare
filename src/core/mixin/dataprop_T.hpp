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

#ifndef DATAPROP_T__
#define DATAPROP_T__

#include "prop_T.hpp"

template <class DATA_T, class CLS_T>
class _T_dataprop: T_prop_bc<DATA_T, CLS_T> {
protected:
    DATA_T data;
public:
    virtual ~_T_dataprop();
    DATA_T get(void) {return this->data;}
    const DATA_T get(void) const {return this->data;}
    bool operator==(DATA_T rhs) {return this->data == rhs;}
    bool operator==(CLS_T rhs) {return this->data == rhs.data;}
};

template <class DATA_T, class CLS_T>
class T_basecmp_dataprop: protected _T_dataprop<DATA_T, CLS_T>,
        Dual_basecmp<DATA_T, CLS_T> {
public:
    virtual ~T_basecmp_dataprop();
};


template <class DATA_T, class CLS_T>
class T_math_dataprop: protected _T_dataprop<DATA_T, CLS_T>,
        Dual_math_w_basecmp<DATA_T, CLS_T> {
public:
    virtual ~T_math_dataprop();
    void set(DATA_T value) {if (!this->data == value) this->data == value;}
    inline CLS_T operator+=(DATA_T other) {
        this->data += other;
        return *this;
    }
    inline CLS_T operator-=(DATA_T other) {
        this->data -= other;
        return *this;
    }
    inline CLS_T operator/=(DATA_T other) {
        this->data /= other;
        return *this;
    }
    inline CLS_T operator*=(DATA_T other) {
        this->data *= other;
        return *this;
    }

    /* ---- CLS_T as arg ---- */
    inline CLS_T operator+=(CLS_T other) {
        this->data += other.data;
        return *this;
    }
    inline CLS_T operator-=(CLS_T other) {
        this->data -= other.data;
        return *this;
    }
    inline CLS_T operator/=(CLS_T other) {
        this->data /= other.data;
        return *this;
    }
    inline CLS_T operator*=(CLS_T other) {
        this->data *= other.data;
        return *this;
    }
};


template <class DATA_T, class CLS_T>
class T_fullmath_dataprop: protected T_math_dataprop<DATA_T, CLS_T>,
        Dual_fullcmp<DATA_T, CLS_T> {
public:
    virtual ~T_fullmath_dataprop();
    inline bool operator >(DATA_T rhs) {return this->data > rhs;}
    inline bool operator <(DATA_T rhs) {return this->data < rhs;}
    inline bool operator >(CLS_T rhs) {return this->data > rhs.data;}
    inline bool operator <(CLS_T rhs) {return this->data < rhs.data;}
};

#endif // DATAPROP_T__
