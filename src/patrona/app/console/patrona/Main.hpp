///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 12/22/2018
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_APP_CONSOLE_PATRONA_MAIN_HPP
#define _PATRONA_APP_CONSOLE_PATRONA_MAIN_HPP

#include "patrona/console/getopt/Main.hpp"
#include "patrona/lib/patrona/Version.hpp"

namespace patrona {
namespace app {
namespace console {
namespace patrona {

typedef ::patrona::console::getopt::Main::Implements MainTImplements;
typedef ::patrona::console::getopt::Main MainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainTImplements, class TExtends = MainTExtends>
class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::char_t char_t;
    typedef typename Extends::endchar_t endchar_t;
    static const endchar_t endchar = Extends::endchar;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT() {
    }
    virtual ~MainT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t**argv, char_t** env) {
        const ::patrona::lib::Version& version = ::patrona::lib::patrona::Version::Which();
        int err = 0;
        this->OutL(version.Name(), " version = ", version.ToString().Chars(), NULL);
        this->OutLn();
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS MainT
typedef MainT<> Main;

} /// namespace patrona
} /// namespace console
} /// namespace app
} /// namespace patrona

#endif /// ndef _PATRONA_APP_CONSOLE_PATRONA_MAIN_HPP
