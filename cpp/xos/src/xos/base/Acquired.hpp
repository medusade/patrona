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
///   File: Acquired.hpp
///
/// Author: $author$
///   Date: 8/28/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ACQUIRED_HPP
#define _XOS_BASE_ACQUIRED_HPP

#include "xos/base/Exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
/// Enum: AcquireStatus
///////////////////////////////////////////////////////////////////////
enum AcquireStatus {
    ReleaseSuccess,
    AcquireSuccess = ReleaseSuccess,

    AcquireFailed,
    AcquireBusy,
    AcquireInterrupted,
    AcquireInvalid,

    ReleaseFailed,
    ReleaseBusy,
    ReleaseInterrupted,
    ReleaseInvalid
};

///////////////////////////////////////////////////////////////////////
/// Function: AcquireStatusToChars
///////////////////////////////////////////////////////////////////////
inline const char* AcquireStatusToChars(AcquireStatus status) {
    switch (status) {
    case AcquireSuccess: return "AcquireSuccess";
    case AcquireFailed: return "AcquireFailed";
    case AcquireBusy: return "AcquireBusy";
    case AcquireInterrupted: return "AcquireInterrupted";
    case AcquireInvalid: return "AcquireInvalid";

    case ReleaseFailed: return "ReleaseFailed";
    case ReleaseBusy: return "ReleaseBusy";
    case ReleaseInterrupted: return "ReleaseInterrupted";
    case ReleaseInvalid: return "ReleaseInvalid";
    }
    return "Unknown";
}

typedef ExceptionTImplements AcquireExceptionTImplements;
typedef ExceptionT<AcquireStatus> AcquireExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AcquireExceptionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = AcquireExceptionTImplements,
 class TExtends = AcquireExceptionTExtends>

class _EXPORT_CLASS AcquireExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AcquireExceptionT(AcquireStatus status): Extends(status) {}
    virtual ~AcquireExceptionT() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* StatusToChars() const {
        return AcquireStatusToChars(this->Status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AcquireExceptionT<> AcquireException;

typedef ImplementBase AcquiredTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: AcquiredT
///////////////////////////////////////////////////////////////////////
template
<class TAcquireException = AcquireException,
 class TImplements = AcquiredTImplements>

class _EXPORT_CLASS AcquiredT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TAcquireException AcquireException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Acquire() { return false; }
    virtual AcquireStatus TryAcquire() { return AcquireFailed; }
    virtual AcquireStatus TimedAcquire(mseconds_t milliseconds) { return AcquireFailed; }
    virtual AcquireStatus UntimedAcquire() { return AcquireFailed; }
    virtual bool Release() { return false; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AcquiredT<> Acquired;

typedef ImplementBase AcquireTImplements;
typedef Base AcquireTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AcquireT
///////////////////////////////////////////////////////////////////////
template
<class TAcquired = Acquired,
 class TAcquireException = AcquireException,
 class TImplements = AcquireTImplements,
 class TExtends = AcquireTExtends>

class _EXPORT_CLASS AcquireT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TAcquired Acquired;
    typedef TAcquireException AcquireException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AcquireT(Acquired& acquired, mseconds_t milliseconds): m_acquired(acquired) {
        AcquireStatus status = AcquireSuccess;
        if (AcquireSuccess != (status = m_acquired.TimedAcquire(milliseconds))) {
            AcquireException e(AcquireFailed);
            throw (e);
        }
    }
    AcquireT(Acquired& acquired): m_acquired(acquired) {
        if (!(m_acquired.Acquire())) {
            AcquireException e(AcquireFailed);
            throw (e);
        }
    }
    virtual ~AcquireT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Acquired& m_acquired;
};
typedef AcquireT<> Acquire;

typedef ImplementBase ReleaseTImplements;
typedef Base ReleaseTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ReleaseT
///////////////////////////////////////////////////////////////////////
template
<class TAcquired = Acquired,
 class TAcquireException = AcquireException,
 class TImplements = ReleaseTImplements,
 class TExtends = ReleaseTExtends>

class _EXPORT_CLASS ReleaseT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TAcquired Acquired;
    typedef TAcquireException AcquireException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ReleaseT(Acquired& acquired, mseconds_t milliseconds): m_acquired(acquired) {
        AcquireStatus status = AcquireSuccess;
        if (AcquireSuccess != (status = m_acquired.TimedRelease(milliseconds))) {
            AcquireException e(ReleaseFailed);
            throw (e);
        }
    }
    ReleaseT(Acquired& acquired): m_acquired(acquired) {
        if (!(m_acquired.Release())) {
            AcquireException e(ReleaseFailed);
            throw (e);
        }
    }
    virtual ~ReleaseT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Acquired& m_acquired;
};
typedef ReleaseT<> Release;

} // namespace xos

#endif // _XOS_BASE_ACQUIRED_HPP 
