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
///   File: Waited.hpp
///
/// Author: $author$
///   Date: 11/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_WAITED_HPP
#define _XOS_BASE_WAITED_HPP

#include "xos/base/Exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
/// Enum: WaitStatus
///////////////////////////////////////////////////////////////////////
enum WaitStatus {
    ContinueSuccess,
    WaitSuccess = ContinueSuccess,

    WaitFailed,
    WaitBusy,
    WaitInterrupted,
    WaitInvalid,

    ContinueFailed,
    ContinueBusy,
    ContinueInterrupted,
    ContinueInvalid
};

///////////////////////////////////////////////////////////////////////
/// Function: WaitStatusToChars
///////////////////////////////////////////////////////////////////////
inline const char* WaitStatusToChars(WaitStatus status) {
    switch (status) {
    case WaitSuccess: return "WaitSuccess";
    case WaitFailed: return "WaitFailed";
    case WaitBusy: return "WaitBusy";
    case WaitInterrupted: return "WaitInterrupted";
    case WaitInvalid: return "WaitInvalid";

    case ContinueFailed: return "ContinueFailed";
    case ContinueBusy: return "ContinueBusy";
    case ContinueInterrupted: return "ContinueInterrupted";
    case ContinueInvalid: return "ContinueInvalid";
    }
    return "Unknown";
}

typedef ExceptionTImplements WaitExceptionTImplements;
typedef ExceptionT<WaitStatus> WaitExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: WaitExceptionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = WaitExceptionTImplements,
 class TExtends = WaitExceptionTExtends>

class _EXPORT_CLASS WaitExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WaitExceptionT(WaitStatus status): Extends(status) {}
    virtual ~WaitExceptionT() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* StatusToChars() const {
        return WaitStatusToChars(this->Status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WaitExceptionT<> WaitException;

typedef ImplementBase WaitedTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: WaitedT
///////////////////////////////////////////////////////////////////////
template
<class TWaitException = WaitException,
 class TImplements = WaitedTImplements>

class _EXPORT_CLASS WaitedT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWaitException WaitException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Wait() { return false; }
    virtual WaitStatus TryWait() { return WaitFailed; }
    virtual WaitStatus TimedWait(mseconds_t milliseconds) { return WaitFailed; }
    virtual WaitStatus UntimedWait() { return WaitFailed; }
    virtual bool Continue() { return false; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WaitedT<> Waited;

typedef ImplementBase WaitTImplements;
typedef Base WaitTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: WaitT
///////////////////////////////////////////////////////////////////////
template
<class TWaited = Waited,
 class TWaitException = WaitException,
 class TImplements = WaitTImplements,
 class TExtends = WaitTExtends>

class _EXPORT_CLASS WaitT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWaited Waited;
    typedef TWaitException WaitException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WaitT(Waited& waited, mseconds_t milliseconds): m_waited(waited) {
        WaitStatus status = WaitSuccess;
        if (WaitSuccess != (status = m_waited.TimedWait(milliseconds))) {
            WaitException e(WaitFailed);
            throw (e);
        }
    }
    WaitT(Waited& waited): m_waited(waited) {
        if (!(m_waited.Wait())) {
            WaitException e(WaitFailed);
            throw (e);
        }
    }
    virtual ~WaitT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Waited& m_waited;
};
typedef WaitT<> Wait;

typedef ImplementBase ContinueTImplements;
typedef Base ContinueTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ContinueT
///////////////////////////////////////////////////////////////////////
template
<class TWaited = Waited,
 class TAcquireException = AcquireException,
 class TImplements = ContinueTImplements,
 class TExtends = ContinueTExtends>

class _EXPORT_CLASS ContinueT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWaited Waited;
    typedef TAcquireException AcquireException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ContinueT(Waited& waited, mseconds_t milliseconds): m_waited(waited) {
        AcquireStatus status = AcquireSuccess;
        if (AcquireSuccess != (status = m_waited.TimedContinue(milliseconds))) {
            AcquireException e(ContinueFailed);
            throw (e);
        }
    }
    ContinueT(Waited& waited): m_waited(waited) {
        if (!(m_waited.Continue())) {
            AcquireException e(ContinueFailed);
            throw (e);
        }
    }
    virtual ~ContinueT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Waited& m_waited;
};
typedef ContinueT<> Continue;

} // namespace xos 

#endif // _XOS_BASE_WAITED_HPP 

        

