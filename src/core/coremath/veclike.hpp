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

#ifndef VECLIKE__
#define VECLIKE__

#include "../include/basic_ops.hpp" // for basic math (+ - / * etc.)
//#include <utility> // std::swap so we dont have to include it each time

template <class NUM_T, class VT>
class _VecLikeVT { // for any vector like ie: RGB, RGBA, Vec2x, Vec3x, Vec4x
public:
    virtual const unsigned size(void);
    virtual VT abs(void);
    virtual bool is_flat(void); // true if all axises are equal values
    virtual void set();     // set each individual axis
    virtual void fill(NUM_T n);     // set all axis to n
    void jitterfill(NUM_T amt) {
        // same as randfill but takes a single arg
        // fills each axis with a random NUM_T from -amt to amt
        this->randfill(-amt, amt);
    }
    virtual void randfill(NUM_T min, NUM_T max);
        // if ((0 == min) == max)
        //  VT v;
        //  v->fill(0);
        // else
        // return v;
        // }
    void jitter(NUM_T amt) {
        // add this with a vector where all axises are a
        //  random amt between -amt and amt
        VT r;
        r->randfill(amt)
        *this += r;
    };
    VT jittered(NUM_T amt) {
        VT r;
        r->randfill(-amt, amt);
        return this + r;
    }
    virtual void clamp(VT lo, VT hi);
    virtual void clamp_lo(VT lo);
    virtual void clamp_hi(VT hi);
    virtual void invert(void);
    virtual void reverse(void);
    virtual void swizzle(void);
    void lerp(VT other, float factor) {
        this = other.lerped(this, factor);
    }
    VT lerped(VT other, float factor) {
        VT t;
        t->fill(1-factor);
        return (t * other) + (t * this);
    }
    VT clamped(VT lo, VT hi) {
        VT v = this;
        return v->clamp(lo, hi);
    }
    VT clamped_lo(VT lo) {
        VT v = this;
        return v->clamp_lo(lo);
    }
    VT clamped_hi(VT hi) {
        VT v = this;
        return v->clamp_hi(hi);
    }
    VT swizzled(void) {
        VT v = this;
        return v->swizzle();
    }
    VT reversed(void) {
        VT v = this;
        return v->reverse();
    }
    VT inverted(void) {
        VT v = this;
        return v->invert();
    }
    VT avg_of_two(const VT &other) { // average of this and other
        VT v;
        v = this->operator+(other);
        v /= 2;
        return v;
    };
    VT avg_of(const VT* &ary, unsigned ary_size) { //average of all items in array
        if (ary_size == 1) return this->avg_of_two(ary[0]);
        else if (ary_size >= 2) {
            VT v;
            v = this;
            for (unsigned i=1; i<ary_size; i++)
                v += ary[i];
            v /= ary_size;
            return v;
        }
    }
    inline bool operator==(const VT &rhs);
    inline bool operator!=(const VT &rhs) {return !this->operator==(rhs);}
    inline const VT operator^(const VT &other);
    inline VT operator^=(const VT &other) {
        VT v = this;
        return v ^= other;
    }
};


#endif
