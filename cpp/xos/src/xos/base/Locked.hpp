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
///   File: Locked.hpp
///
/// Author: $author$
///   Date: 8/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LOCKED_HPP
#define _XOS_BASE_LOCKED_HPP

#include "xos/base/Exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
/// Enum: LockStatus
///////////////////////////////////////////////////////////////////////
enum LockStatus {
    UnlockSuccess,
    LockSuccess = UnlockSuccess,

    LockFailed,
    LockBusy,
    LockInterrupted,
    LockInvalid,

    UnlockFailed,
    UnlockBusy,
    UnlockInterrupted,
    UnlockInvalid
};

///////////////////////////////////////////////////////////////////////
/// Function: LockStatusToChars
///////////////////////////////////////////////////////////////////////
inline const char* LockStatusToChars(LockStatus status) {
    switch (status) {
    case LockSuccess: return "LockSuccess";
    case LockFailed: return "LockFailed";
    case LockBusy: return "LockBusy";
    case LockInterrupted: return "LockInterrupted";
    case LockInvalid: return "LockInvalid";

    case UnlockFailed: return "UnlockFailed";
    case UnlockBusy: return "UnlockBusy";
    case UnlockInterrupted: return "UnlockInterrupted";
    case UnlockInvalid: return "UnlockInvalid";
    }
    return "Unknown";
}

typedef ExceptionTImplements LockExceptionTImplements;
typedef ExceptionT<LockStatus> LockExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LockExceptionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = LockExceptionTImplements,
 class TExtends = LockExceptionTExtends>

class _EXPORT_CLASS LockExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LockExceptionT(LockStatus status): Extends(status) {}
    virtual ~LockExceptionT() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* StatusToChars() const {
        return LockStatusToChars(this->Status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef LockExceptionT<> LockException;

typedef ImplementBase LockedTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LockedT
///////////////////////////////////////////////////////////////////////
template
<class TLockException = LockException,
 class TImplements = LockedTImplements>

class _EXPORT_CLASS LockedT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TLockException LockException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() { return false; }
    virtual LockStatus TryLock() { return LockFailed; }
    virtual LockStatus TimedLock(mseconds_t milliseconds) { return LockFailed; }
    virtual LockStatus UntimedLock() { return LockFailed; }
    virtual bool Unlock() { return false; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef LockedT<> Locked;

typedef ImplementBase LockTImplements;
typedef Base LockTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LockT
///////////////////////////////////////////////////////////////////////
template
<class TLocked = Locked,
 class TLockException = LockException,
 class TImplements = LockTImplements,
 class TExtends = LockTExtends>

class _EXPORT_CLASS LockT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TLocked Locked;
    typedef TLockException LockException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LockT(Locked& locked): m_locked(locked) {
        if (!(m_locked.Lock())) {
            LockException e(LockFailed);
            throw (e);
        }
    }
    virtual ~LockT() {
        if (!(m_locked.Unlock())) {
            LockException e(UnlockFailed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Locked& m_locked;
};
typedef LockT<> Lock;

} // namespace xos

#endif // _XOS_BASE_LOCKED_HPP 
