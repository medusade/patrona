%########################################################################
%# Copyright (c) 1988-2017 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: Exception-cpp.t
%#
%# Author: $author$
%#   Date: 5/10/2017
%########################################################################
%with(%
%which,%(%else-then(%which%,%(Which)%)%)%,%
%Which,%(%else-then(%Which%,%(%which%)%)%)%,%
%WHICH,%(%else-then(%WHICH%,%(%toupper(%Which%)%)%)%)%,%
%which,%(%else-then(%_Which%,%(%tolower(%Which%)%)%)%)%,%
%what,%(%else-then(%what%,%(What)%)%)%,%
%What,%(%else-then(%What%,%(%what%)%)%)%,%
%WHAT,%(%else-then(%WHAT%,%(%toupper(%What%)%)%)%)%,%
%what,%(%else-then(%_What%,%(%tolower(%What%)%)%)%)%,%
%implements,%(%else-then(%implements%,%(ImplementBase)%)%)%,%
%Implements,%(%else-then(%Implements%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%extends,%(%else-then(%extends%,%(Base)%)%)%,%
%Extends,%(%else-then(%Extends%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%class,%(%else-then(%class%,%(Exception)%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%status,%(%else-then(%status%,%(Status)%)%)%,%
%Status,%(%else-then(%Status%,%(%status%)%)%)%,%
%STATUS,%(%else-then(%STATUS%,%(%toupper(%Status%)%)%)%)%,%
%status,%(%else-then(%_Status%,%(%tolower(%Status%)%)%)%)%,%
%string,%(%else-then(%string%,%(String)%)%)%,%
%String,%(%else-then(%String%,%(%string%)%)%)%,%
%STRING,%(%else-then(%STRING%,%(%toupper(%String%)%)%)%)%,%
%string,%(%else-then(%_String%,%(%tolower(%String%)%)%)%)%,%
%%(
typedef %Implements% %What%%Class%TImplements;
typedef %Extends% %What%%Class%TExtends;
///////////////////////////////////////////////////////////////////////
///  Class: %What%%Class%T
///////////////////////////////////////////////////////////////////////
template
<class TImplements = %What%%Class%Implements,
 class TExtends = %What%%Class%Extends>

class _EXPORT_CLASS %What%%Class%T
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    %What%%Class%T(%What%%Status% status): m_status(status) {}
    virtual ~%What%%Class%T() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual %What%%Status% Status() const {
        return m_status;
    }
    virtual %String% StatusToString() const {
        %String% to(StatusToChars());
        return to;
    }
    virtual const char* StatusToChars() const {
        return StatusToChars(Status());
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    %What%%Status% m_status;
};
typedef %What%%Class%T<> %What%%Class%;
)%)%