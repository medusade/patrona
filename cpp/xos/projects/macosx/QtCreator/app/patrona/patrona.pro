########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: patrona.pro
#
# Author: $author$
#   Date: 9/15/2017
#
# QtCreator .pro file for patrona executable patrona
########################################################################
include(../../../../../build/QtCreator/patrona.pri)
include(../../../../QtCreator/patrona.pri)
include(../../patrona.pri)
include(../../../../QtCreator/app/patrona/patrona.pri)

TARGET = $${patrona_exe_TARGET}

########################################################################
INCLUDEPATH += \
$${patrona_exe_INCLUDEPATH} \

DEFINES += \
$${patrona_exe_DEFINES} \

########################################################################
HEADERS += \
$${patrona_exe_HEADERS} \

SOURCES += \
$${patrona_exe_SOURCES} \

########################################################################
LIBS += \
$${patrona_exe_LIBS} \
