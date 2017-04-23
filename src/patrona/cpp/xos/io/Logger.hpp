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
///   File: Logger.hpp
///
/// Author: $author$
///   Date: 4/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _PATRONA_CPP_XOS_IO_LOGGER_HPP
#define _PATRONA_CPP_XOS_IO_LOGGER_HPP

#include "patrona/cpp/xos/base/Base.hpp"

#if defined(USE_CRONO_LOGGER)
#include "crono/io/Logger.hpp"
#else // defined(USE_CRONO_LOGGER)
#define PATRONA_LOG_ERROR CRONO_LOG_ERROR
#define PATRONA_LOG_DEBUG CRONO_LOG_DEBUG
#define PATRONA_LOG_TRACE CRONO_LOG_TRACE
#if defined(USE_NADIR_LOGGER)
#include "nadir/io/Logger.hpp"
#define PATRONA_LOG_ERROR NADIR_LOG_ERROR
#define PATRONA_LOG_DEBUG NADIR_LOG_DEBUG
#define PATRONA_LOG_TRACE NADIR_LOG_TRACE
#else // defined(USE_NADIR_LOGGER)
#define PATRONA_LOG_ERROR(...)
#define PATRONA_LOG_DEBUG(...)
#define PATRONA_LOG_TRACE(...)
#endif // defined(USE_NADIR_LOGGER)
#endif // defined(USE_CRONO_LOGGER)

namespace patrona {
namespace io {

} // namespace io 
} // namespace patrona 

#endif // _PATRONA_CPP_XOS_IO_LOGGER_HPP 
