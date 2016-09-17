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

#ifndef CLAMP_T__
#define CLAMP_T__

template <class T, class CLS_T>
class T_clamping {
    virtual ~T_clamping();
    virtual bool in_range(T min, T max);
    virtual void clamp(T lo, T hi);
    CLS_T clamped(T lo, T hi) {
        T v = this;
        return v->clamp(lo, hi);
    }
    virtual void clamp_lo(T lo);
    CLS_T clamped_lo(T lo) {
        T v = this;
        return v->clamp_lo(lo);
    }
    virtual void clamp_hi(T hi);
    CLS_T clamped_hi(T hi) {
        T v = this;
        return v->clamp_hi(hi);
    }
};

template <class CLS_T>
class CLS_T_clamping {
    virtual ~CLS_T_clamping();
    virtual bool in_range(CLS_T min, CLS_T max);
    virtual void clamp(CLS_T lo, CLS_T hi);
    CLS_T clamped(CLS_T lo, CLS_T hi) {
        CLS_T v = this;
        return v->clamp(lo, hi);
    }
    virtual void clamp_lo(CLS_T lo);
    CLS_T clamped_lo(CLS_T lo) {
        CLS_T v = this;
        return v->clamp_lo(lo);
    }
    virtual void clamp_hi(CLS_T hi);
    CLS_T clamped_hi(CLS_T hi) {
        CLS_T v = this;
        return v->clamp_hi(hi);
    }
};

#endif // CLAMP_T__
