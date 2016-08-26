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

// Mixin classes to add operators for singular numeric classes

#ifndef BASE_T__
#define BASE_T__

template <class T>
class T_basecmp {
public:
    virtual inline bool operator==(T &rhs);
    inline bool operator!=(T &rhs) {return !this->operator==(rhs);}
};


template <class T>
class T_cmp {
public:
    virtual inline bool operator >(T rhs);
    virtual inline bool operator <(T rhs);
    inline bool operator >=(T rhs) {return !this->operator>(rhs);}
    inline bool operator <=(T rhs) {return !this->operator<(rhs);}
};


template <class T>
// <, <=, >=, >, ==, and != operators
class T_fullcmp: T_cmp<T>, T_basecmp<T> {};


template <class T, class CLS_T>
class T_math {
// math operators for T
public:
    virtual inline CLS_T operator+=(T other);
    virtual inline CLS_T operator-=(T other);
    virtual inline CLS_T operator/=(T other);
    virtual inline CLS_T operator*=(T other);
    inline const CLS_T operator+(T other) {
        CLS_T v = this;
        return v += other;
    }
    inline const CLS_T operator-(T other) {
        CLS_T v = this;
        return v -= other;
    }
    inline const CLS_T operator/(T other) {
        CLS_T v = this;
        return v /= other;
    }
    inline const CLS_T operator*(T other) {
        CLS_T v = this;
        return v *= other;
    }
};


template <class T, class CLS_T>
class T_math_w_basecmp: T_math<T, CLS_T>, T_basecmp<T> {};

template <class T, class CLS_T>
class T_math_w_fullcmp: T_math<T, CLS_T>, T_fullcmp<T> {};

/* ---- operators for dual case (can use T or CLS_T as arg) ----------------- */
template <class T, class CLS_T>
class Dual_basecmp: T_basecmp<T>, T_basecmp<CLS_T> {}; // base cmp only

template <class T, class CLS_T>
class Dual_cmp: T_cmp<T>, T_cmp<CLS_T> {};              // cmp only

template <class T, class CLS_T>
class Dual_fullcmp: T_fullcmp<T>, T_fullcmp<CLS_T> {}; // fullcmp only

template <class T, class CLS_T>
class Dual_math: T_math<T, CLS_T>, T_math<CLS_T, CLS_T> {}; // math only

template <class T, class CLS_T>
class Dual_math_w_basecmp: T_math_w_basecmp<T, CLS_T>,
    T_math_w_basecmp<CLS_T, CLS_T> {};

template <class T, class CLS_T>
class Dual_math_w_fullcmp: T_math_w_fullcmp<T, CLS_T>,
    T_math_w_fullcmp<CLS_T, CLS_T> {};

#endif
