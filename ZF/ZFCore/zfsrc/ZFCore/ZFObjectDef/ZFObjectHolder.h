/* ====================================================================== *
 * Copyright (c) 2010-2018 ZFFramework
 * Github repo: https://github.com/ZFFramework/ZFFramework
 * Home page: http://ZFFramework.com
 * Blog: http://zsaber.com
 * Contact: master@zsaber.com (Chinese and English only)
 * Distributed under MIT license:
 *   https://github.com/ZFFramework/ZFFramework/blob/master/LICENSE
 * ====================================================================== */
/**
 * @file ZFObjectHolder.h
 * @brief utilities for ZFObject
 */

#ifndef _ZFI_ZFObjectHolder_h_
#define _ZFI_ZFObjectHolder_h_

#include "ZFObjectSmartPointer.h"
#include "ZFTypeId.h"
#include "ZFPropertyDeclare.h"

ZF_NAMESPACE_GLOBAL_BEGIN

// ============================================================
// ZFObjectHolder
/**
 * @brief util object to hold a ZFObject but don't retain it
 *
 * most of classes and methods use auto-retain logic to hold a ZFObject,
 * so we supply this holder class that won't retain it's content,
 * use only if necessary\n
 * typically, you should use #ZFObject::objectHolder for most case
 */
zffinal zfclass ZF_ENV_EXPORT ZFObjectHolder : zfextends ZFObject
{
    ZFOBJECT_DECLARE(ZFObjectHolder, ZFObject)

public:
    /**
     * @brief set the holded object
     */
    inline void objectHoldedSet(ZF_IN ZFObject *obj)
    {
        this->_ZFP_objectHolded = obj;
    }
    /**
     * @brief set the holded object
     */
    template<typename T_ZFObject>
    inline void objectHoldedSet(ZF_IN T_ZFObject obj)
    {
        this->_ZFP_objectHolded = obj;
    }

protected:
    /** @brief see #ZFObject::objectOnInit */
    virtual void objectOnInit(ZF_IN ZFObject *obj)
    {
        this->objectOnInit();
        this->_ZFP_objectHolded = obj;
    }
    /** @brief see #ZFObject::objectOnInit */
    template<typename T_ZFObject>
    void objectOnInit(ZF_IN T_ZFObject const &obj)
    {
        this->objectOnInit();
        this->_ZFP_objectHolded = obj;
    }

    zfoverride
    virtual void objectOnInit(void)
    {
        zfsuper::objectOnInit();
    }

    zfoverride
    virtual void objectInfoOnAppend(ZF_IN_OUT zfstring &ret);

public:
    zfoverride
    virtual zfidentity objectHash(void);
    zfoverride
    virtual ZFCompareResult objectCompare(ZF_IN ZFObject *anotherObj);

public:
    ZFAny _ZFP_objectHolded;
};

ZF_NAMESPACE_GLOBAL_END
#endif // #ifndef _ZFI_ZFObjectHolder_h_

