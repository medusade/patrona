///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: Reader.hpp
///
/// Author: $author$
///   Date: 12/12/2016
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_CPP_XOS_IO_READER_HPP
#define _PATRONA_CPP_XOS_IO_READER_HPP

#include "patrona/cpp/xos/base/Base.hpp"

namespace patrona {
namespace io {

typedef ImplementBase ReaderTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: ReaderT
///////////////////////////////////////////////////////////////////////
template
<typename TSized, typename TWhat = TSized,
 class TImplements = ReaderTImplements>

class _EXPORT_CLASS ReaderT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TSized sized_t;
    typedef TWhat what_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(what_t* what, size_t size) {
        ssize_t count = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef ReaderT<char, void> CharReader;
typedef ReaderT<wchar_t, void> WCharReader;
typedef ReaderT<tchar_t, void> TCharReader;

} // namespace io
} // namespace patrona

#endif // _PATRONA_CPP_XOS_IO_READER_HPP
