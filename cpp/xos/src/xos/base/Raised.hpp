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
///   File: Raised.hpp
///
/// Author: $author$
///   Date: 11/12/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_RAISED_HPP
#define _XOS_BASE_RAISED_HPP

#include "xos/base/Exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
/// Enum: RaiseStatus
///////////////////////////////////////////////////////////////////////
enum RaiseStatus {
    LowerSuccess,
    RaiseSuccess = LowerSuccess,

    RaiseFailed,
    RaiseBusy,
    RaiseInterrupted,
    RaiseInvalid,

    LowerFailed,
    LowerBusy,
    LowerInterrupted,
    LowerInvalid
};

///////////////////////////////////////////////////////////////////////
/// Function: RaiseStatusToChars
///////////////////////////////////////////////////////////////////////
inline const char* RaiseStatusToChars(RaiseStatus status) {
    switch (status) {
    case RaiseSuccess: return "RaiseSuccess";
    case RaiseFailed: return "RaiseFailed";
    case RaiseBusy: return "RaiseBusy";
    case RaiseInterrupted: return "RaiseInterrupted";
    case RaiseInvalid: return "RaiseInvalid";

    case LowerFailed: return "LowerFailed";
    case LowerBusy: return "LowerBusy";
    case LowerInterrupted: return "LowerInterrupted";
    case LowerInvalid: return "LowerInvalid";
    }
    return "Unknown";
}

typedef ExceptionTImplements RaiseExceptionTImplements;
typedef ExceptionT<RaiseStatus> RaiseExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: RaiseExceptionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = RaiseExceptionTImplements,
 class TExtends = RaiseExceptionTExtends>

class _EXPORT_CLASS RaiseExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    RaiseExceptionT(RaiseStatus status): Extends(status) {}
    virtual ~RaiseExceptionT() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* StatusToChars() const {
        return RaiseStatusToChars(this->Status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef RaiseExceptionT<> RaiseException;

typedef ImplementBase RaisedTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: RaisedT
///////////////////////////////////////////////////////////////////////
template
<class TRaiseException = RaiseException,
 class TImplements = RaisedTImplements>

class _EXPORT_CLASS RaisedT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TRaiseException RaiseException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Raise() { return false; }
    virtual RaiseStatus TryRaise() { return RaiseFailed; }
    virtual RaiseStatus TimedRaise(mseconds_t milliseconds) { return RaiseFailed; }
    virtual RaiseStatus UntimedRaise() { return RaiseFailed; }
    virtual bool Lower() { return false; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef RaisedT<> Raised;

typedef Raised LoweredTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LoweredT
///////////////////////////////////////////////////////////////////////
template
<class TRaiseException = RaiseException,
 class TImplements = LoweredTImplements>

class _EXPORT_CLASS LoweredT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TRaiseException RaiseException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Raise() { return true; }
    virtual RaiseStatus TryRaise() { return RaiseSuccess; }
    virtual RaiseStatus TimedRaise(mseconds_t milliseconds) { return RaiseSuccess; }
    virtual RaiseStatus UntimedRaise() { return RaiseSuccess; }
    virtual bool Lower() { return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef LoweredT<> Lowered;

typedef ImplementBase RaiseTImplements;
typedef Base RaiseTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: RaiseT
///////////////////////////////////////////////////////////////////////
template
<class TRaised = Raised,
 class TRaiseException = RaiseException,
 class TImplements = RaiseTImplements,
 class TExtends = RaiseTExtends>

class _EXPORT_CLASS RaiseT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TRaised Raised;
    typedef TRaiseException RaiseException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    RaiseT(Raised& raised): m_raised(raised) {
        if (!(m_raised.Raise())) {
            RaiseException e(RaiseFailed);
            throw (e);
        }
    }
    virtual ~RaiseT() {
        if (!(m_raised.Lower())) {
            RaiseException e(LowerFailed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Raised& m_raised;
};
typedef RaiseT<> Raise;

} // namespace xos 

#endif // _XOS_BASE_RAISED_HPP 
