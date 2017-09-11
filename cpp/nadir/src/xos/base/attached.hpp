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
///   File: attached.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ATTACHED_HPP
#define _XOS_BASE_ATTACHED_HPP

#include "xos/base/exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  enum: attach_status
///////////////////////////////////////////////////////////////////////
enum attach_status {
    detach_success,
    attach_success = detach_success,
    attach_failed,
    detach_failed
};

///////////////////////////////////////////////////////////////////////
/// function: attach_status_to_chars
///////////////////////////////////////////////////////////////////////
inline const char* attach_status_to_chars(attach_status status) {
    switch (status) {
    case attach_success: return "attach_success";
    case attach_failed: return "attach_failed";
    case detach_failed: return "detach_failed";
    }
    return "unknown";
}

typedef exceptiont_implements attach_exceptiont_implements;
typedef exceptiont<attach_status> attach_exceptiont_extends;
///////////////////////////////////////////////////////////////////////
///  class: attach_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = attach_exceptiont_implements,
 class TExtends = attach_exceptiont_extends>

class _EXPORT_CLASS attach_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typename extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    attach_exceptiont(attach_status status): extends(status) {}
    virtual ~attach_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* status_to_chars() const {
        return attach_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef attach_exceptiont<> attach_exception;

typedef implement_base attacht_implements;
///////////////////////////////////////////////////////////////////////
///  class: attacht
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = attach_exception,
 class TImplements = attacht_implements>

class _EXPORT_CLASS attacht: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef TException attach_exception;
    typedef TAttached attached;
    typedef TUnattached unattached_t;
    static const unattached_t unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached attach(attached attached_to) {
        return ((attached)unattached);
    }
    virtual attached detach() {
        return ((attached)unattached);
    }
    virtual bool detached() {
        if (((attached)unattached) != (this->attached_to())) {
            if (((attached)unattached) == (this->detach())) {
                return false;
            }
        }
        return true;
    }
    virtual attached attached_to() const {
        return ((attached)unattached);
    }
    virtual operator attached() const {
        return attached_to();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef base attachedt_extends;
///////////////////////////////////////////////////////////////////////
///  class: attachedt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = attach_exception,
 class TImplements = attacht
 <TAttached, TUnattached, VUnattached, attacht_implements>,
 class TExtends = attachedt_extends>

class _EXPORT_CLASS attachedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TException attach_exception;
    typedef TAttached attached;
    static const TUnattached unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    attachedt(attached attached_to): m_attached_to(attached_to) {
    }
    attachedt(const attachedt& copy): m_attached_to(copy.m_attached_to) {
    }
    attachedt(): m_attached_to(((attached)unattached)) {
    }
    virtual ~attachedt() {
        if (!(this->detached())) {
            attach_exception e(detach_failed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached attach(attached attached_to) {
        return m_attached_to = attached_to;
    }
    virtual attached detach() {
        attached detached = m_attached_to;
        m_attached_to = ((attached)unattached);
        return detached;
    }
    virtual attached attached_to() const {
        return m_attached_to;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    attached m_attached_to;
};

} // namespace xos

#endif // _XOS_BASE_ATTACHED_HPP 
