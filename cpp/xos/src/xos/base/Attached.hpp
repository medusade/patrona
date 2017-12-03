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
///   File: Attached.hpp
///
/// Author: $author$
///   Date: 8/2/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ATTACHED_HPP
#define _XOS_BASE_ATTACHED_HPP

#include "xos/base/Exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Enum: AttachStatus
///////////////////////////////////////////////////////////////////////
enum AttachStatus {
    DetachSuccess,
    AttachSuccess = DetachSuccess,
    AttachFailed,
    DetachFailed
};

///////////////////////////////////////////////////////////////////////
/// Function: AttachStatusToChars
///////////////////////////////////////////////////////////////////////
inline const char* AttachStatusToChars(AttachStatus status) {
    switch (status) {
    case AttachSuccess: return "AttachSuccess";
    case AttachFailed: return "AttachFailed";
    case DetachFailed: return "DetachFailed";
    }
    return "Unknown";
}

typedef ExceptionTImplements AttachExceptionTImplements;
typedef ExceptionT<AttachStatus> AttachExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AttachExceptionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = AttachExceptionTImplements,
 class TExtends = AttachExceptionTExtends>

class _EXPORT_CLASS AttachExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AttachExceptionT(AttachStatus status): Extends(status) {}
    virtual ~AttachExceptionT() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* StatusToChars() const {
        return AttachStatusToChars(this->Status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AttachExceptionT<> AttachException;

typedef ImplementBase AttachTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: AttachT
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = AttachException,
 class TImplements = AttachTImplements>

class _EXPORT_CLASS AttachT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TException AttachException;
    typedef TAttached Attached;
    typedef TUnattached Unattached_t;
    static const Unattached_t Unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached Attach(Attached attachedTo) {
        return ((Attached)Unattached);
    }
    virtual Attached Detach() {
        return ((Attached)Unattached);
    }
    virtual bool Detached() {
        if (((Attached)Unattached) != (this->AttachedTo())) {
            if (((Attached)Unattached) == (this->Detach())) {
                return false;
            }
        }
        return true;
    }
    virtual Attached AttachedTo() const {
        return ((Attached)Unattached);
    }
    virtual operator Attached() const {
        return AttachedTo();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef Base AttachedTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AttachedT
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = AttachException,
 class TImplements = AttachT
 <TAttached, TUnattached, VUnattached, TException, AttachTImplements>,
 class TExtends = AttachedTExtends>

class _EXPORT_CLASS AttachedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TException AttachException;
    typedef TAttached Attached;
    typedef TUnattached Unattached_t;
    static const Unattached_t Unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AttachedT(Attached attachedTo): m_attachedTo(attachedTo) {
    }
    AttachedT(const AttachedT& copy): m_attachedTo(copy.m_attachedTo) {
    }
    AttachedT(): m_attachedTo(((Attached)Unattached)) {
    }
    virtual ~AttachedT() {
        if (!(this->Detached())) {
            AttachException e(DetachFailed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached Attach(Attached attachedTo) {
        return m_attachedTo = attachedTo;
    }
    virtual Attached Detach() {
        Attached detached = m_attachedTo;
        m_attachedTo = ((Attached)Unattached);
        return detached;
    }
    virtual Attached AttachedTo() const {
        return m_attachedTo;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Attached m_attachedTo;
};

} // namespace xos

#endif // _XOS_BASE_ATTACHED_HPP 

        

