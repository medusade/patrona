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
#   File: libpatrona.pri
#
# Author: $author$
#   Date: 9/9/2017
#
# QtCreator .pri file for patrona library libpatrona
########################################################################

libpatrona_TARGET = patrona

########################################################################
libpatrona_INCLUDEPATH += \
$${patrona_INCLUDEPATH} \

libpatrona_DEFINES += \
$${patrona_DEFINES} \

########################################################################
# patrona
libpatrona_HEADERS += \
$${PATRONA_SRC}/xos/base/locked.hpp \

libpatrona_SOURCES += \
$${PATRONA_SRC}/xos/base/locked.cpp \

########################################################################




