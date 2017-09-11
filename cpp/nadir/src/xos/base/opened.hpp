///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: opened.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_OPENED_HPP
#define _XOS_BASE_OPENED_HPP

#include "xos/base/attached.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  enum: open_status
///////////////////////////////////////////////////////////////////////
enum open_status {
    close_success,
    open_success = close_success,
    open_failed,
    close_failed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* open_status_to_chars(open_status status) {
    switch (status) {
    case open_success: return "open_success";
    case open_failed: return "open_failed";
    case close_failed: return "close_failed";
    }
    return "unknown";
}

typedef exceptiont_implements open_exceptiont_implements;
typedef exceptiont<open_status> open_exceptiont_extends;
///////////////////////////////////////////////////////////////////////
///  class: open_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = open_exceptiont_implements,
 class TExtends = open_exceptiont_extends>

class _EXPORT_CLASS open_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typename extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    open_exceptiont(open_status status): extends(status) {}
    open_exceptiont(const open_exceptiont& copy): extends(copy.status()) {}
    virtual ~open_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* status_to_chars() const {
        return open_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef open_exceptiont<> open_exception;

typedef implement_base opent_implements;
///////////////////////////////////////////////////////////////////////
///  class: opent
///////////////////////////////////////////////////////////////////////
template
<class TException = open_exception, class TImplements = opent_implements>
class _EXPORT_CLASS opent: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef TException open_exception;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open() { return false; }
    virtual bool close() { return false; }
    virtual bool opened() {
        if (!(this->is_open())) {
            return this->open();
        }
        return true; }
    virtual bool closed() {
        if ((this->is_open())) {
            return this->close();
        }
        return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_open(bool to = true) { return this->is_open(); }
    virtual bool is_open() const { return false; }
    virtual bool is_closed() const { return !this->is_open(); }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef opent<> open;

typedef open openedt_implements;
typedef base openedt_extends;
///////////////////////////////////////////////////////////////////////
///  class: openedt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = open_exception,
 class TImplements = attacht
  <TAttached, TUnattached, VUnattached, openedt_implements>,
 class TExtends = attachedt
 <TAttached, TUnattached, VUnattached, TImplements, openedt_extends> >

class _EXPORT_CLASS openedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TException open_exception;
    typedef TAttached attached;
    typedef TUnattached unattached_t;
    static const unattached_t unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    openedt(attached attached_to, bool is_open)
    : extends(attached_to), m_is_open(is_open) {
    }
    openedt(attached attached_to)
    : extends(attached_to), m_is_open(false) {
    }
    openedt(const openedt& copy)
    : extends(copy.attached_to()), m_is_open(false) {
    }
    openedt()
    : extends(((attached)unattached)), m_is_open(false) {
    }
    virtual ~openedt() {
        if (!(this->closed())) {
            open_exception e(close_failed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open() {
        attached detached = ((attached)unattached);
        if (((attached)unattached) != (detached = open_attached())) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    virtual bool close() {
        attached detached = ((attached)unattached);
        if (((attached)unattached) != (detached = this->detach())) {
            if ((close_detached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached open_attached() {
        attached detached = ((attached)unattached);
        if ((detached = open_detached())) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached open_detached() const {
        attached detached = ((attached)unattached);
        return detached;
    }
    virtual bool close_detached(attached detached) const {
        if (((attached)unattached) != (detached)) {
            bool success = false;
            return success;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached attach_opened
    (attached attached_to, bool is_open = true) {
        attached_to = this->attach(attached_to);
        this->set_is_open(is_open);
        return attached_to;
    }
    virtual attached detach_opened(bool& is_open){
        attached detached = this->detach();
        is_open = this->is_open();
        this->set_is_open(false);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached attach(attached attached_to) {
        attached_to = extends::attach(attached_to);
        this->set_is_open(false);
        return attached_to;
    }
    virtual attached detach(){
        attached detached = extends::detach();
        this->set_is_open(false);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_open(bool to = true) {
        m_is_open = to;
        return m_is_open;
    }
    virtual bool is_open() const {
        return m_is_open;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_is_open;
};

} // namespace xos

#endif // _XOS_BASE_OPENED_HPP 
