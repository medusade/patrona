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
#   File: patrona.pri
#
# Author: $author$
#   Date: 8/2/2017
########################################################################

OTHER_PKG = ../../../../../../../..
OTHER_BLD = ..

########################################################################
# rostra
ROSTRA_PKG = $${OTHER_PKG}/rostra/cpp/xos
ROSTRA_PRJ = $${ROSTRA_PKG}
ROSTRA_SRC = $${ROSTRA_PKG}/src

rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

rostra_DEFINES += \

rostra_LIBS += \

########################################################################
# nadir
NADIR_PKG = $${OTHER_PKG}/nadir/cpp/xos
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

nadir_LIBS += \

########################################################################
# patrona
PATRONA_PKG = ../../../../..
PATRONA_BLD = ../..

PATRONA_PRJ = $${PATRONA_PKG}
PATRONA_BIN = $${PATRONA_BLD}/bin
PATRONA_LIB = $${PATRONA_BLD}/lib
PATRONA_SRC = $${PATRONA_PKG}/src

CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
patrona_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
patrona_DEFINES += RELEASE_BUILD
}

patrona_INCLUDEPATH += \
$${PATRONA_SRC} \
$${nadir_INCLUDEPATH} \
$${rostra_INCLUDEPATH} \
$${build_patrona_INCLUDEPATH} \

patrona_DEFINES += \
$${rostra_DEFINES} \
$${nadir_DEFINES} \
$${build_patrona_DEFINES} \

patrona_LIBS += \
-L$${PATRONA_LIB}/libpatrona \
-lpatrona \
