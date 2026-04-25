########################################################################
# Copyright (c) 1988-2024 $organization$
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
#   File: libpatrona.pro
#
# Author: $author$
#   Date: 2/26/2024
#
# os specific QtCreator project .pro file for medusade framework patrona static library libpatrona
########################################################################
# Depends: rostra;nadir;fila;crono
#
# Debug: patrona/build/os/QtCreator/Debug/lib/libpatrona
# Release: patrona/build/os/QtCreator/Release/lib/libpatrona
# Profile: patrona/build/os/QtCreator/Profile/lib/libpatrona
#
include(../../../../../build/QtCreator/patrona.pri)
include(../../../../QtCreator/patrona.pri)
include(../../patrona.pri)
include(../../../../QtCreator/lib/libpatrona/libpatrona.pri)

TARGET = $${libpatrona_TARGET}
TEMPLATE = $${libpatrona_TEMPLATE}
CONFIG += $${libpatrona_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libpatrona_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libpatrona_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libpatrona_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libpatrona_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libpatrona_HEADERS} \
$${libpatrona_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libpatrona_SOURCES} \

########################################################################
