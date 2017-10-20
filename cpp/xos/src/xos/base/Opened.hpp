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
///   File: Opened.hpp
///
/// Author: $author$
///   Date: 8/23/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_OPENED_HPP
#define _XOS_BASE_OPENED_HPP

#include "xos/base/Attached.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Enum: OpenStatus
///////////////////////////////////////////////////////////////////////
enum OpenStatus {
    CloseSuccess,
    OpenSuccess = CloseSuccess,
    OpenFailed,
    CloseFailed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* OpenStatusToChars(OpenStatus status) {
    switch (status) {
    case OpenSuccess: return "OpenSuccess";
    case OpenFailed: return "OpenFailed";
    case CloseFailed: return "CloseFailed";
    }
    return "Unknown";
}

typedef ExceptionTImplements OpenExceptionTImplements;
typedef ExceptionT<OpenStatus> OpenExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: OpenExceptionT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = OpenExceptionTImplements,
 class TExtends = OpenExceptionTExtends>

class _EXPORT_CLASS OpenExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    OpenExceptionT(OpenStatus status): Extends(status) {}
    OpenExceptionT(const OpenExceptionT& copy): Extends(copy.Status()) {}
    virtual ~OpenExceptionT() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* StatusToChars() const {
        return OpenStatusToChars(this->Status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef OpenExceptionT<> OpenException;

typedef ImplementBase OpenTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: OpenT
///////////////////////////////////////////////////////////////////////
template
<class TException = OpenException, class TImplements = OpenTImplements>
class _EXPORT_CLASS OpenT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TException OpenException;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open() {
        return false;
    }
    virtual bool Close() {
        return false;
    }
    virtual bool Opened() {
        if (!(this->IsOpen())) {
            return this->Open();
        }
        return true;
    }
    virtual bool Closed() {
        if ((this->IsOpen())) {
            return this->Close();
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsOpen(bool to = true) {
        return this->IsOpen();
    }
    virtual bool IsOpen() const {
        return false;
    }
    virtual bool IsClosed() const {
        return !this->IsOpen();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef OpenT<> Open;

typedef Open OpenedTImplements;
typedef Base OpenedTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: OpenedT
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = OpenException,
 class TImplement = AttachT
  <TAttached, TUnattached, VUnattached, AttachException, OpenedTImplements>,
 class TExtend = AttachedT
 <TAttached, TUnattached, VUnattached, AttachException, TImplement, OpenedTExtends>,
 class TImplements = TImplement, class TExtends = TExtend>

class _EXPORT_CLASS OpenedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TException OpenException;
    typedef TAttached Attached;
    typedef TUnattached Unattached_t;
    static const Unattached_t Unattached = VUnattached;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    OpenedT(Attached attachedTo, bool isOpen)
    : Extends(attachedTo), m_isOpen(isOpen) {
    }
    OpenedT(Attached attachedTo)
    : Extends(attachedTo), m_isOpen(false) {
    }
    OpenedT(const OpenedT& copy)
    : Extends(copy.AttachedTo()), m_isOpen(false) {
    }
    OpenedT()
    : Extends(((Attached)Unattached)), m_isOpen(false) {
    }
    virtual ~OpenedT() {
        if (!(this->Closed())) {
            OpenException e(CloseFailed);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open() {
        Attached detached = ((Attached)Unattached);
        if (((Attached)Unattached) != (detached = OpenAttached())) {
            this->SetIsOpen();
            return true;
        }
        return false;
    }
    virtual bool Close() {
        Attached detached = ((Attached)Unattached);
        if (((Attached)Unattached) != (detached = this->Detach())) {
            if ((CloseDetached(detached))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached OpenAttached() {
        Attached detached = ((Attached)Unattached);
        if ((detached = OpenDetached())) {
            this->Attach(detached);
        }
        return detached;
    }
    virtual Attached OpenDetached() const {
        Attached detached = ((Attached)Unattached);
        return detached;
    }
    virtual bool CloseDetached(Attached detached) const {
        if (((Attached)Unattached) != (detached)) {
            bool success = false;
            return success;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached AttachOpened
    (Attached attachedTo, bool isOpen = true) {
        attachedTo = this->Attach(attachedTo);
        this->SetIsOpen(isOpen);
        return attachedTo;
    }
    virtual Attached DetachOpened(bool& isOpen){
        Attached detached = this->Detach();
        isOpen = this->IsOpen();
        this->SetIsOpen(false);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached Attach(Attached attachedTo) {
        attachedTo = Extends::Attach(attachedTo);
        this->SetIsOpen(false);
        return attachedTo;
    }
    virtual Attached Detach(){
        Attached detached = Extends::Detach();
        this->SetIsOpen(false);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsOpen(bool to = true) {
        m_isOpen = to;
        return m_isOpen;
    }
    virtual bool IsOpen() const {
        return m_isOpen;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_isOpen;
};

} // namespace xos

#endif // _XOS_BASE_OPENED_HPP 
