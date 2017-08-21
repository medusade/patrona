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
///   File: Logged.hpp
///
/// Author: $author$
///   Date: 8/12/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LOGGED_HPP
#define _XOS_BASE_LOGGED_HPP

#include "xos/base/Base.hpp"

namespace xos {

typedef ImplementBase LoggedTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LoggedT
///////////////////////////////////////////////////////////////////////
template <bool VIsLogged = true, class TImplements = LoggedTImplements>

class _EXPORT_CLASS LoggedT: virtual public TImplements {
public:
    typedef TImplements Implements;
    static const bool isLogged = VIsLogged;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsLogged(bool to = true) {
        return IsLogged();
    }
    virtual bool IsLogged() const {
        return isLogged;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef LoggedT<> Logged;

} // namespace xos 

#endif // _XOS_BASE_LOGGED_HPP 
