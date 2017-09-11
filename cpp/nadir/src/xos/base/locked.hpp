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
///   File: locked.hpp
///
/// Author: $author$
///   Date: 9/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LOCKED_HPP
#define _XOS_BASE_LOCKED_HPP

#include "xos/base/exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum lock_status {
    unlock_success,
    lock_success = unlock_success,

    lock_failed,
    lock_busy,
    lock_interrupted,
    lock_invalid,

    unlock_failed,
    unlock_busy,
    unlock_interrupted,
    unlock_invalid
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* lock_status_to_chars(lock_status status) {
    switch (status) {
    case lock_success: return "lock_success";
    case lock_failed: return "lock_failed";
    case lock_busy: return "lock_busy";
    case lock_interrupted: return "lock_interrupted";
    case lock_invalid: return "lock_invalid";

    case unlock_failed: return "unlock_failed";
    case unlock_busy: return "unlock_busy";
    case unlock_interrupted: return "unlock_interrupted";
    case unlock_invalid: return "fork_invalid";
    }
    return "unknown";
}

typedef exceptiont_implements lock_exception_implements;
typedef exceptiont<lock_status> lock_exception_extends;
///////////////////////////////////////////////////////////////////////
///  Class: lock_exceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = lock_exception_implements,
 class TExtends = lock_exception_extends>

class _EXPORT_CLASS lock_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    lock_exceptiont(lock_status status): Extends(status) {}
    virtual ~lock_exceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* status_to_chars() const {
        return lock_status_to_chars(this->status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef lock_exceptiont<> lock_exception;

typedef implement_base lockedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: lockedt
///////////////////////////////////////////////////////////////////////
template
<class TLockException = lock_exception,
 class TImplements = lockedt_implements>

class _EXPORT_CLASS lockedt: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TLockException lock_exception;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() { return false; }
    virtual lock_status try_lock() { return lock_failed; }
    virtual lock_status untimed_lock() { return lock_failed; }
    virtual lock_status timed_lock(mseconds_t milliseconds) { return lock_failed; }
    virtual bool unlock() { return false; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef lockedt<> locked;

typedef locked unlockedt_implements;
typedef base unlockedt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: unlockedt
///////////////////////////////////////////////////////////////////////
template
<class TLocked = locked,
 class TLockException = lock_exception,
 class TImplements = unlockedt_implements,
 class TExtends = unlockedt_extends>

class _EXPORT_CLASS unlockedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TLocked locked;
    typedef TLockException lock_exception;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    unlockedt() {
    }
    virtual ~unlockedt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() { return true; }
    virtual lock_status try_lock() { return lock_success; }
    virtual lock_status untimed_lock() { return lock_success; }
    virtual lock_status timed_lock(mseconds_t milliseconds) { return lock_success; }
    virtual bool unlock() { return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef unlockedt<> unlocked;

typedef implement_base lockt_implements;
typedef base lockt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: lockt
///////////////////////////////////////////////////////////////////////
template
<class TLocked = locked,
 class TLockException = lock_exception,
 class TImplements = lockt_implements,
 class TExtends = lockt_extends>

class _EXPORT_CLASS lockt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TLocked locked;
    typedef TLockException lock_exception;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    lockt(locked& _locked): locked_(_locked) {
        if (!(locked_.lock())) {
            lock_exception e(lock_failed);
            throw (e);
        }
    }
    virtual ~lockt() {
        if (!(locked_.unlock())) {
            lock_exception e(unlock_failed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    locked& locked_;
};
typedef lockt<> lock;

} // namespace xos

#endif // _XOS_BASE_LOCKED_HPP 
