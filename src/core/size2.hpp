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


#ifndef SIZE2__
#define SIZE2__

#include <iostream>

template <typename NUM_T, class CLS_T>
class Size2 {
protected:
    NUM_T *_size[2];
    NUM_T *_sizemin[2];
    NUM_T *_sizemax[2];

    bool _set_wh(NUM_T *v, float *i) {
        if (this->_size[i] == v) return false; // no change
        else if (v <= this->_sizemin[i]) {
            if (this->_size[i] != this->_sizemin[i]) {
                this->_size[i] = this->_sizemin[i];
                return true;
            } else return false;
        }else if (v >= this->_sizemax[i]) {
            if (this->_size[i] != this->_sizemax[i]) {
                this->_size[i] = this->_sizemax[i];
                return true;
            } else return false;
        }else
            this->size[i] = v;
            return true;
    }
    void _qs(const NUM_T *size[2], const NUM_T *min[2], const NUM_T *max[2]) {
        // quick set size for fast init where we dont need validation
        this->_size = size;
        this->_sizemin = min;
        this->_sizemax = max;
    }
public:
    bool operator==(const CLS_T &rhs) {
        return (this->_size[0] == rhs->_size[0] &&
            this->_size[1] == rhs->_size[1]);
    }
    bool operator!=(const CLS_T &rhs) {return !(this->operator==(rhs));}
    void _validate_size(const NUM_T &size, const NUM_T &min,
        const NUM_T& max) {
        if (min[0] < 1 || min[1] == NULL) this->_sizemin[0] = 1;
        if (min[1] < 1 || min[1] == NULL) this->_sizemin[0] = 1;
        if (size[0] < min[0]) this->_size[0] = min[0];
        if (size[1] < min[1]) this->_size[1] = min[1];
        if (max[0] < this->_size || max[0] == NULL)
            this->_sizemax[0] = this->_size[0];
        if (max[1] < this->_size || max[0] == NULL)
            this->_sizemax[1] = this->_size[1];
    }
    NUM_T* get_size(void) { return this->_size; }
    void set_size(const NUM_T &size) {
        bool *a, *b;
        if (size[0] != this->_size[0])
            a = this._set_wh(size[0], 0);
        if (size[1] != this->_size[1])
            b = this._set_wh(size[1], 1);
        if (a || b) // Check if height or width was modified
            this->on_resize(this->_size[0], this->_size[1]);
    }
    NUM_T get_height(void) { return this->_size[1]; }
    void set_height(const NUM_T &h) {
        if (_set_wh(h, 0)) this->on_resize(h, this->_size[0]);
    }
    NUM_T get_width(void) { return this->_size[0]; }
    void set_width(const NUM_T &w) {
        if (this._set_wh(w, 0)) this->on_resize(w, this->_size[0]);
    }
    float* center(void) {
        float *x;
        x[0] = this->_size[0] * 0.5;
        x[1] = this->_size[1] * 0.5;
        return x;
    }

    /* -- events -- */
    bool on_resize(NUM_T w, NUM_T h) {return false;}
};

#endif
