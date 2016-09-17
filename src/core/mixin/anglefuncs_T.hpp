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

#ifndef ANGLEFUNCS_T__
#define ANGLEFUNCS_T__

#include "../coremath/pi_const.hpp"

template <class CLS_T>
class T_cvt_deg_rads {
public:
    virtual ~T_cvt_deg_rads();
    // conversion to radians
    void deg_to_rads(void) {this->operator*PI_OVER_180;}
    CLS_T get_deg_to_rads(void) {
        CLS_T v = this;
        v->deg_to_rads();
        return v;
    }
    void clamp_deg_to_rads(void); // -180 to 180
    CLS_T clamped_deg_to_rads(void) {
        CLS_T v = this;
        v->clamp_deg_to_rads();
        return v;
    }

    // conversion to degrees
    void rads_to_deg(void) {this->operator*PI_UNDER_180;}
    CLS_T get_rads_to_deg(void) {
        CLS_T v = this;
        v->rads_to_deg();
        return v;
    }
    void clamp_rads_to_deg(void); // 0 - 360
    CLS_T clamped_rads_to_deg_clamped(void) {
        CLS_T v = this;
        v->clamp_rads_to_deg();
        return v;
    }

};


template <typename NUM_T, class CLS_T>
class T_anglefuncs {
public:
    // get angle between this and other
    inline NUM_T angle_degrees(CLS_T other);
    inline NUM_T angle_degrees_clamped(CLS_T other) {
        NUM_T t = this->angle_degrees(other);
        // TODO
        return t;
    }
    inline NUM_T angle_radians(CLS_T other);
    inline NUM_T angle_radians_clamped(CLS_T other) {
        NUM_T t = this->angle_radians();
        // TODO
        return t;
    }
};


template <typename NUM_T, class CLS_T>
class T_angle_and_cvt_deg_rads: T_anglefuncs<NUM_T, CLS_T>,
        T_cvt_deg_rads<CLS_T> {
};

#endif
