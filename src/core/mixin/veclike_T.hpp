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

#ifndef VECLIKE_T__
#define VECLIKE_T__

#include "clamp_T.hpp"
#include "mm/veclikebase_T.hpp"

template <typename NUM_T, class CLS_T>
class T_veclike: CLS_T_clamping<CLS_T>, T_veclikebase<NUM_T, CLS_T> {
// advanced vector functions
public:
    virtual ~T_veclike();
    void jitterfill(NUM_T amt) {
        // same as randfill but takes a single arg
        // fills each axis with a random NUM_T from -amt to amt
        this->randfill(-amt, amt);
    }
    virtual void randfill(NUM_T min, NUM_T max);
        // if ((0 == min) == max)
        //  CLS_T v;
        //  v->fill(0);
        // else
        // return v;
        // }
    void jitter(NUM_T amt) {
        // add this with a vector where all axises are a
        //  random amt between -amt and amt
        CLS_T r;
        r->randfill(amt)
        *this += r;
    };
    CLS_T jittered(NUM_T amt) {
        CLS_T r;
        r->randfill(-amt, amt);
        return this + r;
    }
    void lerp(CLS_T other, float factor) {
        this = other.lerped(this, factor);
    }
    CLS_T lerped(CLS_T other, float factor) {
        CLS_T t;
        t->fill(1-factor);
        return (t * other) + (t * this);
    }
    CLS_T avg_of(CLS_T &other) { // average of this and other
        CLS_T v;
        v = this->operator+(other);
        v /= 2;
        return v;
    }
    CLS_T avg_of(CLS_T* &ary, const unsigned ary_size) {
        //average of all items in array
        if (ary_size == 1) return this->avg_of_two(ary[0]);
        else if (ary_size >= 2) {
            CLS_T v;
            v = this;
            for (unsigned i=1; i<ary_size; i++)
                v += ary[i];
            v /= ary_size;
            return v;
        }
    }
};

#endif // VECLIKE_T__
