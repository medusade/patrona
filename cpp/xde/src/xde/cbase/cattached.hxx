/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cattached.hxx
 *
 * Author: $author$
 *   Date: 9/26/2017
 **********************************************************************
 */
#ifndef _XDE_CBASE_CATTACHED_HXX
#define _XDE_CBASE_CATTACHED_HXX

#include "xde/cbase/cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cAttachInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached = HANDLE,
 class TImplements = cInterfaceBase>

class c_INTERFACE_CLASS cAttachInterfaceT: virtual public TImplements {
public:
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Attach
    (TAttached attached, bool onlyUnattached=false) = 0;
};
/**
 **********************************************************************
 * Typedef: cAttachInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachInterfaceT<HANDLE, cInterfaceBase> cAttachInterface;

/**
 **********************************************************************
 *  Class: cDetachInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached = HANDLE,
 class TImplements = cInterfaceBase>

class c_INTERFACE_CLASS cDetachInterfaceT: virtual public TImplements {
public:
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Detach
    (TAttached& attached, bool onlyAttached=false) = 0;
};
/**
 **********************************************************************
 * Typedef: cDetachInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cDetachInterfaceT<HANDLE, cInterfaceBase> cDetachInterface;

/**
 **********************************************************************
 *  Class: cAttachImplementT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached = HANDLE,
 class TImplements = cAttachInterface>

class c_IMPLEMENT_CLASS cAttachImplementT: virtual public TImplements {
public:
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Attach
    (TAttached attached, bool onlyUnattached = false) {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
/**
 **********************************************************************
 * Typedef: cAttachImplementT
 *
 *  Author: $author$
 *    Date: 3/13/2007
 **********************************************************************
 */
typedef cAttachImplementT<HANDLE, cAttachInterface> cAttachImplement;

/**
 **********************************************************************
 *  Class: cDetachImplementT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached = HANDLE,
 class TImplements = cDetachInterface>

class c_IMPLEMENT_CLASS cDetachImplementT: virtual public TImplements {
public:
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Detach
    (TAttached& attached, bool onlyAttached = false) {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};
/**
 **********************************************************************
 * Typedef: cDetachImplementT
 *
 *  Author: $author$
 *    Date: 3/13/2007
 **********************************************************************
 */
typedef cDetachImplementT<HANDLE, cDetachInterface> cDetachImplement;

/**
 **********************************************************************
 *  Class: cAttachedInterfaceT
 *
 * Author: $author$
 *   Date: 3/26/2007
 **********************************************************************
 */
template
<class TAttached = HANDLE,
 class TAttachImplements = cAttachInterface,
 class TDetachImplements = cDetachInterface>

class c_INTERFACE_CLASS cAttachedInterfaceT
: virtual public TAttachImplements, virtual public TDetachImplements {
public:
};
/**
 **********************************************************************
 * Typedef: cAttachedInterface
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachedInterfaceT
<HANDLE, cAttachInterface, cDetachInterface> cAttachedInterface;

/**
 **********************************************************************
 *  Class: cAttachedT
 *
 * Author: $author$
 *   Date: 3/24/2007
 **********************************************************************
 */
template
<class TAttached = HANDLE,
 class TUnAttached = V_HANDLE,
 TUnAttached VUnattached = V_INVALID_HANDLE,
 class TImplements = cAttachedInterface,
 class TExtends = cBase>

class c_EXPORT_CLASS cAttachedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TAttached tAttached;

    TAttached m_attached;

    /**
     **********************************************************************
     * Constructor: cAttachedT
     *
     *      Author: $author$
     *        Date: 3/24/2007
     **********************************************************************
     */
    cAttachedT(TAttached attached=(TAttached)(VUnattached))
    : m_attached((TAttached)(VUnattached))
    {
        eError error;

        if ((TAttached)(VUnattached) != attached)
        if ((error = Attach(attached, true)))
            throw(error);
    }
    /**
     **********************************************************************
     *  Destructor: ~cAttachedT
     *
     *      Author: $author$
     *        Date: 3/24/2007
     **********************************************************************
     */
    virtual ~cAttachedT()
    {
        eError error;
        TAttached attached;

        if ((TAttached)(VUnattached) != m_attached)
        if ((error = Detach(attached, true)))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Attach
    (TAttached attached, bool onlyUnattached=false)
    {
        eError error = e_ERROR_NONE;

        if (onlyUnattached)
        if ((TAttached)(VUnattached) != m_attached)
            return e_ERROR_ALREADY_ATTACHED;

        m_attached = attached;
        return error;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 3/13/2007
     **********************************************************************
     */
    virtual eError Detach
    (TAttached& attached, bool onlyAttached=false)
    {
        eError error = e_ERROR_NONE;

        if (onlyAttached)
        if ((TAttached)(VUnattached) == m_attached)
            return e_ERROR_NOT_ATTACHED;

        attached = m_attached;
        m_attached = (TAttached)(VUnattached);
        return error;
    }
    /**
     **********************************************************************
     * Function: GetAttached
     *
     *   Author: $author$
     *     Date: 3/24/2007
     **********************************************************************
     */
    virtual TAttached GetAttached() const
    {
        return m_attached;
    }
    /**
     **********************************************************************
     * Function: Attached
     *
     *   Author: $author$
     *     Date: 3/24/2007
     **********************************************************************
     */
    virtual TAttached Attached() const
    {
        return m_attached;
    }
};
/**
 **********************************************************************
 * Typedef: cAttached
 *
 *  Author: $author$
 *    Date: 1/3/2008
 **********************************************************************
 */
typedef cAttachedT
<HANDLE, V_HANDLE, V_INVALID_HANDLE,
 cAttachedInterface, cBase> cAttached;

/**
 **********************************************************************
 *  Class: cAttachedImplementT
 *
 * Author: $author$
 *   Date: 9/28/2017
 **********************************************************************
 */
template
<class TAttached = HANDLE,
 class TUnAttached = V_HANDLE,
 TUnAttached VUnattached = V_INVALID_HANDLE,
 class TImplements = cAttachedInterface>

class c_EXPORT_CLASS cAttachedImplementT: virtual public TImplements {
public:
    typedef TImplements cImplements;
    typedef TAttached tAttached;

    /**
     **********************************************************************
     * Function: Attach
     *
     *   Author: $author$
     *     Date: 9/28/2017
     **********************************************************************
     */
    virtual eError Attach
    (TAttached attached, bool onlyUnattached=false) {
        eError error = e_ERROR_FAILED;
        return error;
    }
    /**
     **********************************************************************
     * Function: Detach
     *
     *   Author: $author$
     *     Date: 9/28/2017
     **********************************************************************
     */
    virtual eError Detach
    (TAttached& attached, bool onlyAttached=false) {
        eError error = e_ERROR_FAILED;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetAttached
     *
     *   Author: $author$
     *     Date: 9/28/2017
     **********************************************************************
     */
    virtual TAttached GetAttached() const {
        return (TAttached)VUnattached;
    }
    /**
     **********************************************************************
     * Function: Attached
     *
     *   Author: $author$
     *     Date: 9/28/2017
     **********************************************************************
     */
    virtual TAttached Attached() const {
        return (TAttached)VUnattached;
    }
};
/**
 **********************************************************************
 * Typedef: cAttachedImplement
 *
 *  Author: $author$
 *    Date: 9/28/2017
 **********************************************************************
 */
typedef cAttachedImplementT
<HANDLE, V_HANDLE, V_INVALID_HANDLE,
 cAttachedInterface> cAttachedImplement;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CBASE_CATTACHED_HXX */
