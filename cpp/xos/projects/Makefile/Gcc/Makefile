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
#   File: Makefile
#
# Author: $author$
#   Date: 9/1/2017
#
# generic Gcc Makefile for patrona
########################################################################


PATRONA_PKG = ${PKG}
PATRONA_SRC = ${PATRONA_PKG}/src
PATRONA_BLD = ${PATRONA_PKG}/${BLD}/${BUILD_TYPE}
PATRONA_LIB = ${PATRONA_BLD}/lib
PATRONA_BIN = ${PATRONA_BLD}/bin

########################################################################
# rostra
ROSTRA_PKG = ${PATRONA_PKG}/../../../rostra/cpp/xos
ROSTRA_SRC = ${ROSTRA_PKG}/src
ROSTRA_BLD = ${ROSTRA_PKG}/${BLD}/${BUILD_TYPE}
ROSTRA_LIB = ${ROSTRA_BLD}/lib
ROSTRA_BIN = ${ROSTRA_BLD}/bin


########################################################################
# patrona
patrona_USRDEFINES += \
${build_patrona_USRDEFINES} \

patrona_USRINCLUDES += \
-I${PATRONA_SRC} \
-I${ROSTRA_SRC} \
${build_patrona_USRINCLUDES} \

patrona_USRCXXFLAGS += \
${build_patrona_USRCXXFLAGS} \

patrona_USRLIBDIRS += \
-L${PATRONA_LIB} \
-L${ROSTRA_LIB} \
${build_patrona_USRLIBDIRS} \

patrona_LIBS += \
-lpatrona \
-lrostra \
${build_patrona_LIBS} \

########################################################################

