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
///   File: Writer.hpp
///
/// Author: $author$
///   Date: 12/12/2016
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_CPP_XOS_IO_WRITER_HPP
#define _PATRONA_CPP_XOS_IO_WRITER_HPP

#include "patrona/cpp/xos/base/Base.hpp"

namespace patrona {
namespace io {

typedef ImplementBase WriterTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: WriterT
///////////////////////////////////////////////////////////////////////
template
<typename TSized, typename TWhat = TSized,
 class TImplements = WriterTImplements>

class _EXPORT_CLASS WriterT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TSized sized_t;
    typedef TWhat what_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Write (const what_t* what, size_t size) {
        ssize_t count = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef WriterT<char, void> CharWriter;
typedef WriterT<wchar_t, void> WCharWriter;
typedef WriterT<tchar_t, void> TCharWriter;

} // namespace io
} // namespace patrona

#endif // _PATRONA_CPP_XOS_IO_WRITER_HPP
