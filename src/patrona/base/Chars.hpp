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
///   File: Chars.hpp
///
/// Author: $author$
///   Date: 12/22/2018
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_BASE_CHARS_HPP
#define _PATRONA_BASE_CHARS_HPP

#include "patrona/base/Base.hpp"

namespace patrona {

///////////////////////////////////////////////////////////////////////
///  Class: CharsT
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char,
 typename TEndChar = TChar, TEndChar VEndChar = 0>

class _EXPORT_CLASS CharsT {
public:
    typedef CharsT Derives;

    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };
    typedef char_t (*to_case_t)(char_t what);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static char_t* Copy(char_t* toWhat, const char_t* what) {
        return Copy(toWhat, what, -1, end_char);
    }
    static char_t* Copy(char_t* toWhat, const char_t* what, ssize_t length) {
        return Copy(toWhat, what, length, end_char);
    }
    static char_t* Copy
    (char_t* toWhat, const char_t* what, ssize_t length, end_char_t end) {
        if (toWhat) {
            char_t c = 0;
            if (0 > length) {
                while ((c = (*what++)) != end) {
                    (*toWhat++) = c;
                }
                (*toWhat) = c;
            } else {
                while (0 < length) {
                    (*toWhat++) = (c = (*what++));
                    --length;
                }
            }
        }
        return toWhat;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static size_t Count(const char_t* what, end_char_t end = end_char) {
        size_t length = 0;
        if (what) {
            char_t c = 0;
            for (char_t e = ((char_t)end_char); ((c = *what) != e); ++what) {
                ++length;
            }
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int Compare(const char_t* what, const char_t* toWhat) {
        int unequal = CompareCased
        (what, -1, toWhat, -1, end_char, end_char, Derives::ToCase);
        return unequal;
    }
    static int Compare
    (const char_t* what, const char_t* toWhat, ssize_t length) {
        int unequal = CompareCased
        (what, length, toWhat, length, end_char, end_char, Derives::ToCase);
        return unequal;
    }
    static int Compare
    (const char_t* what, ssize_t length,
     const char_t* toWhat, ssize_t toLength) {
        int unequal = CompareCased
        (what, length, toWhat, toLength, end_char, end_char, Derives::ToCase);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int CompareCased(const char_t* what, const char_t* toWhat) {
        int unequal = CompareCased
        (what, -1, toWhat, -1, end_char, end_char, Derives::ToCase);
        return unequal;
    }
    static int CompareCased
    (const char_t* what, ssize_t length,
     const char_t* toWhat, ssize_t toLength,
     end_char_t end = end_char, end_char_t toEnd = end_char,
     to_case_t to_case = Derives::ToCase) {
        int unequal = 0;
        char_t c1 = 0, c2 = 0;

        if (what != toWhat) {
            if (what) {
                if (toWhat) {
                    if (0 > length) {
                        if (0 > toLength) {
                            for (c1 = *what, c2 = *toWhat;
                                 ((c1) != end) && ((c2) != toEnd);
                                 ++what, ++toWhat, c1 = *what, c2 = *toWhat) {
                                if ((c1 = to_case(c1)) > (c2 = to_case(c2))) {
                                    return 1;
                                } else {
                                    if (c1 < c2) {
                                        return -1;
                                    }
                                }
                            }
                            if (c1 != end) {
                                unequal = 1;
                            } else {
                                if (c2 != toEnd) {
                                    unequal = -1;
                                }
                            }
                        } else {
                            for (c1 = *what; ((c1) != end) && (0 < toLength);
                                 --toLength, ++what, ++toWhat, c1 = *what) {
                                c2 = *toWhat;
                                if ((c1 = to_case(c1)) > (c2 = to_case(c2))) {
                                    return 1;
                                } else {
                                    if (c1 < c2) {
                                        return -1;
                                    }
                                }
                            }
                            if (c1 != end) {
                                unequal = 1;
                            } else {
                                if (0 < toLength) {
                                    unequal = -1;
                                }
                            }
                        }
                    } else {
                        if (0 > toLength) {
                            for (c2 = *toWhat; (0 < length) && ((c2) != toEnd);
                                 --length, ++what, ++toWhat, c2 = *toWhat) {
                                c1 = *what;
                                if ((c1 = to_case(c1)) > (c2 = to_case(c2))) {
                                    return 1;
                                } else {
                                    if (c1 < c2) {
                                        return -1;
                                    }
                                }
                            }
                            if (0 < length) {
                                unequal = 1;
                            } else {
                                if (c2 != toEnd) {
                                    unequal = -1;
                                }
                            }
                        } else {
                            if (length > toLength) {
                                unequal = 1;
                                length = toLength;
                            } else {
                                if (toLength > length) {
                                    unequal = -1;
                                }
                            }
                            for (; 0 < length; --length, ++what, ++toWhat) {
                                c1 = *what; c2 = *toWhat;
                                if ((c1 = to_case(c1)) > (c2 = to_case(c2))) {
                                    return 1;
                                } else {
                                    if (c1 < c2) {
                                        return -1;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    unequal = 1;
                }
            } else {
                if (toWhat) {
                    unequal = -1;
                }
            }
        }
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int CompareUncased(const char_t* what, const char_t* toWhat) {
        int unequal = CompareUncased
        (what, -1, toWhat, -1, end_char, end_char);
        return unequal;
    }
    static int CompareUncased
    (const char_t* what, ssize_t length,
     const char_t* toWhat, ssize_t toLength,
     end_char_t end = end_char, end_char_t toEnd = end_char) {
        int unequal = CompareCased
        (what, length, toWhat, toLength, end, toEnd, Derives::Tolower);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static char_t Tolower(char_t what) {
        static const char_t A = ((char_t)'A');
        static const char_t Z = ((char_t)'Z');
        static const char_t a = ((char_t)'a');
        if ((what >= A) && (what <= Z)) {
            what = a + (what - A);
        }
        return what;
    }
    static char_t ToUpper(char_t what) {
        static const char_t A = ((char_t)'A');
        static const char_t a = ((char_t)'a');
        static const char_t z = ((char_t)'z');
        if ((what >= a) && (what <= z)) {
            what = A + (what - a);
        }
        return what;
    }
    static char_t ToCase(char_t what) {
        return what;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static signed ToSigned
    (const char_t* what, ssize_t length = -1, end_char_t end = end_char) {
        const char_t c0 = (char_t)('0');
        const char_t c9 = (char_t)('9');
        const char_t minus = (char_t)('-');
        bool negative = false;
        signed value = 0;
        size_t digits = 0, amount = 0;
        char_t c = 0, d = 0;

        if (what) {
            if (0 > length) {
                for (digits = 0, amount = 0; (c = what[amount]) != end; ++amount) {
                    if ((c >= c0) && (c <= c9)) {
                        value = (value*10) + (signed)(d = (char_t)(c - c0));
                        if ((d != 0) || digits)
                            ++digits;
                    } else {
                        if ((minus == c) && !(digits)) {
                            negative = !negative;
                        }
                    }
                }
            } else {
                for (digits = 0, amount = 0; amount < length; ++amount) {
                    if (((c = what[amount]) >= c0) && (c <= c9)) {
                        value = (value*10) + (signed)(d = (char_t)(c - c0));
                        if ((d != 0) || digits)
                            ++digits;
                    } else {
                        if ((minus == c) && !(digits)) {
                            negative = !negative;
                        }
                    }
                }
            }
        }
        if ((value) && (negative)) {
            value = -value;
        }
        return value;
    }
    static unsigned ToUnsigned
    (const char_t* what, ssize_t length = -1, end_char_t end = end_char) {
        const char_t c0 = (char_t)('0');
        const char_t c9 = (char_t)('9');
        unsigned value = 0;
        size_t digits = 0, amount = 0;
        char_t c = 0, d = 0;

        if (what) {
            if (0 > length) {
                for (digits = 0, amount = 0; (c = what[amount]) != end; ++amount) {
                    if ((c >= c0) && (c <= c9)) {
                        value = (value*10) + (unsigned)(d = (char_t)(c - c0));
                        if ((d != 0) || digits)
                            ++digits;
                    }
                }
            } else {
                for (digits = 0, amount = 0; amount < length; ++amount) {
                    if (((c = what[amount]) >= c0) && (c <= c9)) {
                        value = (value*10) + (unsigned)(d = (char_t)(c - c0));
                        if ((d != 0) || digits)
                            ++digits;
                    }
                }
            }
        }
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CharsT<char> Chars;
typedef CharsT<wchar_t> WChars;
typedef CharsT<tchar_t> TChars;

} // namespace patrona 

#endif // _PATRONA_BASE_CHARS_HPP 
