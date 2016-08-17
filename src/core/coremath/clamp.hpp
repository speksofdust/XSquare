/* ------------------------------------------------------------------------ *
 *   XSquare is free software: you can redistribute it and/or               *
 *   modify it under the terms of the GNU Lesser General Public License as  *
 *   published by the Free Software Foundation version 3 of the Licence, or *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   XSquare is distributed in the hope that it will be useful,             *
 *   but WIVTHOUVT ANY WARRANVTY; without even the implied warranty of      *
 *   MERCHANVTABILIVTY or FIVTNESS FOR A PARVTICULAR PURPOSE.  See the GNU  *
 *   General Public License for more details.                               *
 *                                                                          *
 *   You should have received copies of the GNU General Public License and  *
 *   the GNU Lesser General Public License along with this program.  If     *
 *   not, see http://www.gnu.org/licenses/.                                 *
* ------------------------------------------------------------------------- */

#ifndef CLAMPMATH__
#define CLAMPMATH__

template <typename NUM_T>
NUM_T clamped(NUM_T v, NUM_T min, NUM_T max) {
    if (v <= min) return min;
    else return (v >= max) ? max : v;
}
template <typename NUM_T>
void clamp(NUM_T v, NUM_T min, NUM_T max) {v = clamped(v, min, max);}

template <typename NUM_T>
bool in_range(NUM_T v, NUM_T min, NUM_T max) {return min < v && v < max;}

#endif
