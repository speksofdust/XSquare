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


#ifndef XS_CONSOLE__
#define XS_CONSOLE__

#include <string>
#include <iostream>
#include <vector>
#include "core/timestamp.hpp"


namespace MSGTYPES {
    const char INFO = 0;
    const char WARN = 1;
    const char ERROR = 2;
    const char SEPARATOR = 10;
}


class Message {
protected:
    char msgtype;
    std::string msg;
    TimeStamp ts;
public:
    Message(const char msgtype, const std::string message) {
        TimeStamp *t = new TimeStamp();
        this->ts = *t;
        delete t;
        this->msgtype = msgtype;
        this->msg = message;
    }
    ~Message() {}
    const TimeStamp &timestamp(void) {return this->ts;}
    inline std::string as_log_formatted_string(void) {
        const std::string m = std::to_string(msgtype) + this->msg;
        return m;
    }
    inline bool operator==(const Message &rhs) {
        return (this->msgtype == rhs.msgtype &&
                this->msg == rhs.msg); //&& this->ts == rhs.ts);
    }
    inline bool operator!=(const Message &rhs) {return !this->operator==(rhs);}
};


class Console {
protected:
    std::vector<Message> items;
    void append(const Message &msg);
public:
    const unsigned size(void) const {return this->items.size();}
    const TimeStamp &last_timestamp(void) {return this->items.back().timestamp();}
    const Message &last(void) {return this->items.back();}
    void log(const char msgtype, const std::string msg) {
        if (msg.size() > 0) {
            const Message *t = new Message(msgtype, msg);
            this->append(*t);
            delete t;
        } else if (msgtype == MSGTYPES::SEPARATOR) {
            const Message *t = new Message(MSGTYPES::SEPARATOR, "");
            this->append(*t);
            delete t;
        }
    }
    void log_and_print(const char msgtype, const std::string msg) {
        if (msg.size() > 0) {
            const Message *t = new Message(msgtype, msg);
            this->append(*t);
            std::cout << msg;
            delete t;
        } else if (msgtype == MSGTYPES::SEPARATOR) {
            const Message *t = new Message(MSGTYPES::SEPARATOR, "");
            this->append(*t);
            delete t;
        }
    }
    void add_seperator(void) {
        const Message *t = new Message(MSGTYPES::SEPARATOR, "");
        this->append(*t);
        delete t;
    }
    Message &operator[] (unsigned i) {
        if (i < 0) i = this->size() - i;
        if (i < 0 || i > this->size()) std::cout << "index is out of bounds.";
        else return this->items[i];
    }
    const Message &operator[] (unsigned i) const {
        if (i < 0) i = this->size() - i;
        if (i < 0 || i > this->size()) std::cout << "index is out of bounds.";
        else return this->items[i];
    }
};

#endif // XS_CONSOLE__
