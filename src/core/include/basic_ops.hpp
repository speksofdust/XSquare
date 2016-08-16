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


#ifndef BASIC_OPS__
#define BASIC_OPS__

template <class CLS_T>
class BasicBoolOps {
public:
    inline bool operator==(const CLS_T &rhs);
    inline bool operator!=(const CLS_T &rhs) {return !this->operator==(rhs);}
};


template <class CLS_T>
class BasicMathOps {
public:
    inline bool operator==(const CLS_T &rhs);
    inline bool operator!=(const CLS_T &rhs) {return !this->operator==(rhs);}
    inline CLS_T operator+=(const CLS_T &other);
    inline CLS_T operator-=(const CLS_T &other);
    inline CLS_T operator/=(const CLS_T &other);
    inline CLS_T operator*=(const CLS_T &other);
    inline const CLS_T operator+(const CLS_T &other) {
        CLS_T v = this;
        return v += other;
    }
    inline const CLS_T operator-(const CLS_T &other) {
        CLS_T v = this;
        return v -= other;
    }
    inline const CLS_T operator/(const CLS_T &other) {
        CLS_T v = this;
        return v /= other;
    }
    inline const CLS_T operator*(const CLS_T &other) {
        CLS_T v = this;
        return v *= other;
    }
};

#endif
