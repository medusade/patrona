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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 9/23/2016
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_CPP_XOS_BASE_BASE_HPP
#define _PATRONA_CPP_XOS_BASE_BASE_HPP

#include "nadir/base/base.hpp"
#include "nadir/base/array.hpp"
#include "nadir/base/string.hpp"
#include "nadir/base/to_string.hpp"

namespace patrona {

typedef ::nadir::pointer_t pointer_t;
typedef ::nadir::unsigned_t unsigned_t;
typedef ::nadir::signed_t signed_t;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::nadir::implement_base implement_base;
typedef ::nadir::base base;

typedef ::nadir::char_array char_array;
typedef ::nadir::tchar_array tchar_array;
typedef ::nadir::wchar_array wchar_array;

typedef ::nadir::char_string char_string;
typedef ::nadir::tchar_string tchar_string;
typedef ::nadir::wchar_string wchar_string;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::nadir::bool_to_string bool_to_string;
typedef ::nadir::bool_to_tstring bool_to_tstring;
typedef ::nadir::bool_to_wstring bool_to_wstring;

typedef ::nadir::chars_to_string chars_to_string;
typedef ::nadir::chars_to_tstring chars_to_tstring;
typedef ::nadir::chars_to_wstring chars_to_wstring;

typedef ::nadir::int_to_string int_to_string;
typedef ::nadir::int_to_tstring int_to_tstring;
typedef ::nadir::int_to_wstring int_to_wstring;

typedef ::nadir::signed_to_string signed_to_string;
typedef ::nadir::signed_to_tstring signed_to_tstring;
typedef ::nadir::signed_to_wstring signed_to_wstring;

typedef ::nadir::unsigned_to_string unsigned_to_string;
typedef ::nadir::unsigned_to_tstring unsigned_to_tstring;
typedef ::nadir::unsigned_to_wstring unsigned_to_wstring;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned_t& to_unsigned(const unsigned_t& v) { return v; }
inline const signed_t& to_signed(const signed_t& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline seconds_t mseconds_seconds
(mseconds_t mseconds) { return nadir::mseconds_seconds(mseconds); }

inline mseconds_t mseconds_mseconds
(mseconds_t mseconds) { return nadir::mseconds_mseconds(mseconds); }

inline useconds_t mseconds_useconds
(mseconds_t mseconds) { return nadir::mseconds_useconds(mseconds); }

inline nseconds_t mseconds_nseconds
(mseconds_t mseconds) { return nadir::mseconds_nseconds(mseconds); }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef implement_base ImplementBase;
typedef base Base;

typedef char_array CharArray;
typedef tchar_array TCharArray;
typedef wchar_array WCharArray;

typedef char_string String;
typedef tchar_string TString;
typedef wchar_string WString;

typedef chars_to_string CharsToString;
typedef chars_to_tstring CharsToTString;
typedef chars_to_wstring CharsToWString;

} // namespace patrona

#endif // _PATRONA_CPP_XOS_BASE_BASE_HPP
