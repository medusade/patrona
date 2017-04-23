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
///   Date: 4/19/2017
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_CPP_XOS_IO_CRT_FILE_ATTACHED_HPP
#define _PATRONA_CPP_XOS_IO_CRT_FILE_ATTACHED_HPP

#include "patrona/cpp/xos/base/Attached.hpp"
#include "patrona/cpp/xos/base/Base.hpp"

namespace patrona {
namespace io {
namespace crt {
namespace file {

typedef FILE* AttachedTo;
///////////////////////////////////////////////////////////////////////
///  Class: AttachedT
///////////////////////////////////////////////////////////////////////
template
<typename TAttachedTo = AttachedTo,
 class TAttacherImplements = ImplementBase, class TAttachedExtends = Base,
 class TImplements = patrona::AttacherT<TAttachedTo, int, 0, TAttacherImplements>,
 class TExtends = patrona::AttachedT<TAttachedTo, int, 0, TImplements, TAttachedExtends> >

class _EXPORT_CLASS AttachedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TAttachedTo AttachedTo;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AttachedT(AttachedTo attachedTo = 0): Extends(attachedTo) {
    }
    AttachedT(const AttachedT& copy): Extends(copy) {
    }
    virtual ~AttachedT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetModeIsBinary(bool to = true) {
        return true;
    }
    virtual bool ModeIsBinary() const {
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef AttachedT<> Attached;

} // namespace file 
} // namespace crt 
} // namespace io 
} // namespace patrona 

#endif // _PATRONA_CPP_XOS_IO_CRT_FILE_ATTACHED_HPP 
