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

template <typename NUM>
NUM clamped(const NUM v, const NUM min, const NUM max) {
    if (v <= min) return min;
    else return (v >= max) ? max : v;
}
template <typename NUM>
void clamp(const NUM v, const NUM min, const NUM max) {
    v = clamped(v, min, max);
}

template <typename NUM>
bool in_range(const NUM v, const NUM min, const NUM max) {
    return min < v && v < max;
}

#endif