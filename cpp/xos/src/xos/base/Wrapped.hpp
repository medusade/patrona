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
///   File: Wrapped.hpp
///
/// Author: $author$
///   Date: 9/19/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_WRAPPED_HPP
#define _XOS_BASE_WRAPPED_HPP

#include "xos/base/Base.hpp"

namespace xos {

typedef int WrappedTInitalized_t;
enum { WrappedTInitalized = 0 };
typedef ImplementBase WrappedTImplements;
typedef Base WrappedTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: WrappedT
///////////////////////////////////////////////////////////////////////
template
<typename TWrapped,
 typename TInitialized = WrappedTInitalized_t,
 TInitialized VInitialized = WrappedTInitalized,
 class TImplements = WrappedTImplements, class TExtends = WrappedTExtends>

class _EXPORT_CLASS WrappedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TWrapped wrapped_t;
    typedef TInitialized initialized_t;
    enum { initialized = VInitialized };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WrappedT(initialized_t initialized) {
        this->set(initialized);
    }
    WrappedT(const wrapped_t& copy) {
        this->copy(copy);
    }
    WrappedT(const WrappedT& copy) {
        this->copy(copy);
    }
    WrappedT() {
    }
    virtual ~WrappedT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual WrappedT& copy(const WrappedT& copy) {
        memcpy(&m_wrapped, &copy.m_wrapped, sizeof(wrapped_t));
        return *this;
    }
    virtual WrappedT& copy(const wrapped_t& copy) {
        memcpy(&m_wrapped, &copy, sizeof(wrapped_t));
        return *this;
    }
    virtual WrappedT& set(initialized_t initialized) {
        memset(&m_wrapped, initialized, sizeof(wrapped_t));
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual WrappedT& operator = (const WrappedT& copy) {
        memcpy(&m_wrapped, &copy.m_wrapped, sizeof(wrapped_t));
        return *this;
    }
    virtual WrappedT& Wrapper() const {
        return (WrappedT&)(*this);
    }
    virtual wrapped_t& Wrapped() const {
        return (wrapped_t&)(m_wrapped);
    }
    virtual operator wrapped_t& () const {
        return (wrapped_t&)(m_wrapped);
    }
    virtual wrapped_t& operator >> (wrapped_t& to) const {
        memcpy(&to, &m_wrapped, sizeof(wrapped_t));
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    wrapped_t m_wrapped;
};

} // namespace xos

#endif // _XOS_BASE_WRAPPED_HPP 
