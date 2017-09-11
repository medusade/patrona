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
///   File: created.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_CREATED_HPP
#define _XOS_BASE_CREATED_HPP

#include "xos/base/attached.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  enum: create_status
///////////////////////////////////////////////////////////////////////
enum create_status {
    destroy_success,
    create_success = destroy_success,
    create_failed,
    destroy_failed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* create_status_to_chars(create_status status) {
    switch (status) {
    case create_success: return "create_success";
    case create_failed: return "create_failed";
    case destroy_failed: return "destroy_failed";
    }
    return "unknown";
}

typedef exceptiont_implements create_exceptiont_implements;
typedef exceptiont<create_status> create_exceptiont_extends;
///////////////////////////////////////////////////////////////////////
///  class: create_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = create_exceptiont_implements,
 class TExtends = create_exceptiont_extends>

class _EXPORT_CLASS create_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typename extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    create_exceptiont(create_status status): extends(status) {}
    create_exceptiont(const create_exceptiont& copy): extends(copy.status()) {}
    virtual ~create_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* status_to_chars() const {
        return create_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef create_exceptiont<> create_exception;

typedef implement_base createt_implements;
///////////////////////////////////////////////////////////////////////
///  class: createt
///////////////////////////////////////////////////////////////////////
template
<class TException = create_exception, class TImplements = createt_implements>
class _EXPORT_CLASS createt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef TException create_exception;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() { return false; }
    virtual bool destroy() { return false; }
    virtual bool created() {
        if (!(is_created())) {
            return create();
        }
        return true; }
    virtual bool destroyed() {
        if ((is_created())) {
            return destroy();
        }
        return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_created(bool is_true = true) { return false; }
    virtual bool is_created() const { return false; }
    virtual bool is_destroyed() const { return !is_created(); }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef createt<> create;

typedef create createdt_implements;
typedef base createdt_extends;
///////////////////////////////////////////////////////////////////////
///  class: createdt
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = create_exception,
 class TImplements = attacht
  <TAttached, TUnattached, VUnattached, createdt_implements>,
 class TExtends = attachedt
 <TAttached, TUnattached, VUnattached, TImplements, createdt_extends> >

class _EXPORT_CLASS createdt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TException create_exception;
    typedef TAttached attached;
    static const TUnattached unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    createdt(attached attached_to, bool is_created)
    : extends(attached_to), m_is_created(is_created) {
    }
    createdt(const createdt& copy)
    : extends(copy.attached_to()), m_is_created(false) {
    }
    createdt()
    : extends(((attached)unattached)), m_is_created(false) {
    }
    virtual ~createdt() {
        if (!(this->destroyed())) {
            create_exception e(destroy_failed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create() {
        attached detached = ((attached)unattached);
        if (((attached)unattached) != (detached = create_attached())) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        attached detached = ((attached)unattached);
        if (((attached)unattached) != (detached = this->detach())) {
            if ((destroy_detached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached create_attached() {
        attached detached = ((attached)unattached);
        if ((detached = create_detached())) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached create_detached() const {
        attached detached = ((attached)unattached);
        return detached;
    }
    virtual bool destroy_detached(attached detached) const {
        if (((attached)unattached) != (detached)) {
            bool success = false;
            return success;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached attach_created
    (attached attached_to, bool is_created = true) {
        attached_to = this->attach(attached_to);
        this->set_is_created(is_created);
        return attached_to;
    }
    virtual attached detach_created(bool& is_created){
        attached detached = this->detach();
        is_created = this->is_created();
        this->set_is_created(false);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached attach(attached attached_to) {
        attached_to = extends::attach(attached_to);
        this->set_is_created(false);
        return attached_to;
    }
    virtual attached detach(){
        attached detached = extends::detach();
        this->set_is_created(false);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_created(bool is_true = true) {
        m_is_created = is_true;
        return m_is_created;
    }
    virtual bool is_created() const {
        return m_is_created;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_is_created;
};

} // namespace xos 

#endif // _XOS_BASE_CREATED_HPP 
