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
///   File: Stream.hpp
///
/// Author: $author$
///   Date: 12/12/2016
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_CPP_XOS_IO_STREAM_HPP
#define _PATRONA_CPP_XOS_IO_STREAM_HPP

#include "patrona/cpp/xos/io/Reader.hpp"
#include "patrona/cpp/xos/io/Writer.hpp"

namespace patrona {
namespace io {

typedef ImplementBase StreamTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: StreamT
///////////////////////////////////////////////////////////////////////
template
<typename TSized, typename TWhat = TSized,
 class TImplements = StreamTImplements,
 class TReaderImplements = ReaderT<TSized, TWhat, TImplements>,
 class TWriterImplements = WriterT<TSized, TWhat, TImplements> >

class _EXPORT_CLASS StreamT
: virtual public TReaderImplements, virtual public TWriterImplements {
public:
    typedef TReaderImplements ReaderImplements;
    typedef TWriterImplements WriterImplements;
};

typedef StreamT<char, void> CharStream;
typedef StreamT<wchar_t, void> WCharStream;
typedef StreamT<tchar_t, void> TCharStream;

} // namespace io
} // namespace patrona

#endif // _PATRONA_CPP_XOS_IO_STREAM_HPP 
