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
///   File: Created.hpp
///
/// Author: $author$
///   Date: 8/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_CREATED_HPP
#define _XOS_BASE_CREATED_HPP

#include "xos/base/Attached.hpp"
#include "xos/base/Exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Enum: CreateStatus
///////////////////////////////////////////////////////////////////////
enum CreateStatus {
    DestroySuccess,
    CreateSuccess = DestroySuccess,
    CreateFailed,
    DestroyFailed
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const char* CreateStatusToChars(CreateStatus status) {
    switch (status) {
    case CreateSuccess: return "CreateSuccess";
    case CreateFailed: return "CreateFailed";
    case DestroyFailed: return "DestroyFailed";
    }
    return "Unknown";
}

typedef ExceptionTImplements CreateExceptionTImplements;
typedef ExceptionT<CreateStatus> CreateExceptionTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CreateExceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = CreateExceptionTImplements,
 class TExtends = CreateExceptionTExtends>

class _EXPORT_CLASS CreateExceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CreateExceptiont(CreateStatus status): Extends(status) {}
    virtual ~CreateExceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* StatusToChars() const {
        return CreateStatusToChars(this->Status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CreateExceptiont<> CreateException;

typedef ImplementBase CreateTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: CreateT
///////////////////////////////////////////////////////////////////////
template
<class TException = CreateException, class TImplements = CreateTImplements>
class _EXPORT_CLASS CreateT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TException CreateException;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create() { return false; }
    virtual bool Destroy() { return false; }
    virtual bool Created() {
        if (!(IsCreated())) {
            return Create();
        }
        return true; }
    virtual bool Destroyed() {
        if ((IsCreated())) {
            return Destroy();
        }
        return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsCreated(bool isTrue = true) { return false; }
    virtual bool IsCreated() const { return false; }
    virtual bool IsDestroyed() const { return !IsCreated(); }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CreateT<> Create;

typedef Create CreatedTImplements;
typedef Base CreatedTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CreatedT
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TException = CreateException,
 class TImplements = AttachT
  <TAttached, TUnattached, VUnattached, CreatedTImplements>,
 class TExtends = AttachedT
 <TAttached, TUnattached, VUnattached, TImplements, CreatedTExtends> >

class _EXPORT_CLASS CreatedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TException CreateException;
    typedef TAttached Attached;
    static const TUnattached Unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CreatedT(Attached attachedTo, bool isCreated)
    : Extends(attachedTo), m_isCreated(isCreated) {
    }
    CreatedT(const CreatedT& copy)
    : Extends(copy.AttachedTo()), m_isCreated(false) {
    }
    CreatedT()
    : Extends(((Attached)Unattached)), m_isCreated(false) {
    }
    virtual ~CreatedT() {
        if (!(this->Destroyed())) {
            CreateException e(DestroyFailed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create() {
        Attached detached = ((Attached)Unattached);
        if (((Attached)Unattached) != (detached = CreateAttached())) {
            this->SetIsCreated();
            return true;
        }
        return false;
    }
    virtual bool Destroy() {
        Attached detached = ((Attached)Unattached);
        if (((Attached)Unattached) != (detached = this->Detach())) {
            if ((DestroyDetached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached CreateAttached() {
        Attached detached = ((Attached)Unattached);
        if ((detached = CreateDetached())) {
            this->Attach(detached);
        }
        return detached;
    }
    virtual Attached CreateDetached() const {
        Attached detached = ((Attached)Unattached);
        return detached;
    }
    virtual bool DestroyDetached(Attached detached) const {
        if (((Attached)Unattached) != (detached)) {
            bool success = false;
            return success;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached AttachCreated
    (Attached attachedTo, bool isCreated = true) {
        attachedTo = this->Attach(attachedTo);
        this->SetIsCreated(isCreated);
        return attachedTo;
    }
    virtual Attached DetachCreated(bool& isCreated){
        Attached detached = this->Detach();
        isCreated = this->IsCreated();
        this->SetIsCreated(false);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached Attach(Attached attachedTo) {
        attachedTo = Extends::Attach(attachedTo);
        this->SetIsCreated(false);
        return attachedTo;
    }
    virtual Attached Detach(){
        Attached detached = Extends::Detach();
        this->SetIsCreated(false);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsCreated(bool isTrue = true) {
        m_isCreated = isTrue;
        return m_isCreated;
    }
    virtual bool IsCreated() const {
        return m_isCreated;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_isCreated;
};

} // namespace xos

#endif // _XOS_BASE_CREATED_HPP 
