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
///   File: Writer.hpp
///
/// Author: $author$
///   Date: 4/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_CPP_XOS_IO_CRT_FILE_WRITER_HPP
#define _PATRONA_CPP_XOS_IO_CRT_FILE_WRITER_HPP

#include "patrona/cpp/xos/io/crt/file/Stream.hpp"

namespace patrona {
namespace io {
namespace crt {
namespace file {

typedef StreamTImplements WriterTImplements;
typedef Stream WriterTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: WriterT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = WriterTImplements, class TExtends = WriterTExtends>

class _EXPORT_CLASS WriterT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::attached_t attached_t;
    typedef typename Extends::sized_t sized_t;
    typedef typename Extends::what_t what_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WriterT(attached_t attachedTo = 0, bool isOpen = false)
    : Extends(attachedTo, isOpen) {
    }
    WriterT(const WriterT& copy): Extends(copy) {
    }
    virtual ~WriterT() {
        if (!(this->Closed())) {
            OpenException e(CloseFailed);
            PATRONA_LOG_ERROR("...throw (OpenException e(CloseFailed))...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Open;
    virtual bool Open(const char* name) {
        return this->Open(name, file::ModeWriteBinary);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Read(what_t* what, size_t size) {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* Mode(const file::Mode& mode) const {
        switch (mode) {
        case file::ModeBinary: return this->ModeWriteBinary();
        }
        return Extends::Mode(mode);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* ModeRead() const {
        return 0;
    }
    virtual const char* ModeReadBinary() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WriterT<> Writer;

} // namespace file 
} // namespace crt 
} // namespace io 
} // namespace patrona 

#endif // _PATRONA_CPP_XOS_IO_CRT_FILE_WRITER_HPP 
