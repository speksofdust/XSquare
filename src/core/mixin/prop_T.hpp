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

#ifndef PROP_T__
#define PROP_T__

#include "base_T.hpp"

/* Note all prop types must allow at least == and != comparison for both
    DATA_T and CLS_T types as args. (CLS_T ==/!= DATA_T)
*/

template <class DATA_T, class CLS_T>
class T_prop_bc {
public:
    virtual DATA_T get(void);
    virtual const DATA_T get(void) const;
    virtual void set(DATA_T value);

    virtual bool operator==(DATA_T rhs);
    bool operator!=(DATA_T rhs) {return !this->operator==(rhs);}
};


template <class DATA_T, class CLS_T>
class T_prop_basecmp: Dual_basecmp<DATA_T, CLS_T> {}; // with == and !=


template <class DATA_T, class CLS_T>
class T_mathprop: T_prop_bc<DATA_T, CLS_T>,
        Dual_math_w_basecmp<DATA_T, CLS_T> {
// with basic math operators and ==,!=
};

template <class DATA_T, class CLS_T>
class T_fullmathprop: T_prop_bc<DATA_T, CLS_T>,
        Dual_math_w_fullcmp<DATA_T, CLS_T> {
// with basic math operators and comparison
};







#endif
