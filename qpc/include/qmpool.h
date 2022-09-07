/*$file${include::qmpool.h} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: qpc.qm
* File:  ${include::qmpool.h}
*
* This code has been generated by QM 5.2.1 <www.state-machine.com/qm>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This code is covered by the following QP license:
* License #    : LicenseRef-QL-dual
* Issued to    : Any user of the QP/C real-time embedded framework
* Framework(s) : qpc
* Support ends : 2023-12-31
* License scope:
*
* Copyright (C) 2005 Quantum Leaps, LLC <state-machine.com>.
*
* SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-QL-commercial
*
* This software is dual-licensed under the terms of the open source GNU
* General Public License version 3 (or any later version), or alternatively,
* under the terms of one of the closed source Quantum Leaps commercial
* licenses.
*
* The terms of the open source GNU General Public License version 3
* can be found at: <www.gnu.org/licenses/gpl-3.0>
*
* The terms of the closed source Quantum Leaps commercial licenses
* can be found at: <www.state-machine.com/licensing>
*
* Redistributions in source code must retain this top-level comment block.
* Plagiarizing this software to sidestep the license obligations is illegal.
*
* Contact information:
* <www.state-machine.com/licensing>
* <info@state-machine.com>
*/
/*$endhead${include::qmpool.h} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*!
* @date Last updated on: 2022-06-14
* @version Last updated for: @ref qpc_7_0_1
*
* @file
* @brief QP native, platform-independent memory pool ::QMPool interface.
*/
#ifndef QMPOOL_H
#define QMPOOL_H

/*==========================================================================*/
#ifndef QF_MPOOL_SIZ_SIZE
    /*! macro to override the default ::QMPoolSize size [bytes].
    * Valid values 1U, 2U, or 4U; default 2U
    */
    #define QF_MPOOL_SIZ_SIZE 2U
#endif
#if (QF_MPOOL_SIZ_SIZE == 1U)

    /*! The data type to store the block-size based on the macro
    * #QF_MPOOL_SIZ_SIZE.
    * @details
    * The dynamic range of this data type determines the maximum size
    * of blocks that can be managed by the native QF event pool.
    */
    typedef uint8_t QMPoolSize;
#elif (QF_MPOOL_SIZ_SIZE == 2U)

    typedef uint16_t QMPoolSize;
#elif (QF_MPOOL_SIZ_SIZE == 4U)
    typedef uint32_t QMPoolSize;
#else
    #error "QF_MPOOL_SIZ_SIZE defined incorrectly, expected 1U, 2U, or 4U"
#endif

/*==========================================================================*/
#ifndef QF_MPOOL_CTR_SIZE
    /*! macro to override the default ::QMPoolCtr size [bytes].
    * Valid values 1U, 2U, or 4U; default 2U
    */
    #define QF_MPOOL_CTR_SIZE 2U
#endif
#if (QF_MPOOL_CTR_SIZE == 1U)

    /*! The data type to store the block-counter based on the macro
    * #QF_MPOOL_CTR_SIZE.
    * @details
    * The dynamic range of this data type determines the maximum number
    * of blocks that can be stored in the pool.
    */
    typedef uint8_t QMPoolCtr;
#elif (QF_MPOOL_CTR_SIZE == 2U)
    typedef uint16_t QMPoolCtr;
#elif (QF_MPOOL_CTR_SIZE == 4U)
    typedef uint32_t QMPoolCtr;
#else
    #error "QF_MPOOL_CTR_SIZE defined incorrectly, expected 1U, 2U, or 4U"
#endif

/*! Memory pool element to allocate correctly aligned storage
* for QMPool class.
* @param[in] evType_ event type (name of the subclass of QEvt)
*/
#define QF_MPOOL_EL(evType_) \
    struct { void *sto_[((sizeof(evType_) - 1U)/sizeof(void*)) + 1U]; }

/*==========================================================================*/
/*$declare${QF::QMPool} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${QF::QMPool} ............................................................*/
/*! @brief Native QF Memory Pool
* @class QMPool
*
* @details
* A fixed block-size memory pool is a very fast and efficient data
* structure for dynamic allocation of fixed block-size chunks of memory.
* A memory pool offers fast and deterministic allocation and recycling of
* memory blocks and is not subject to fragmenation.<br>
*
* The ::QMPool class describes the native QF memory pool, which can be used as
* the event pool for dynamic event allocation, or as a fast, deterministic
* fixed block-size heap for any other objects in your application.
*
* @note
* ::QMPool contains only data members for managing a memory pool, but
* does not contain the pool storage, which must be provided externally
* during the pool initialization.
*
* @note
* The native QF event pool is configured by defining the macro
* #QF_EPOOL_TYPE_ as ::QMPool in the specific QF port header file.
*/
typedef struct {
/* private: */

    /*! start of the memory managed by this memory pool
    * @private @memberof QMPool
    */
    void * start;

    /*! end of the memory managed by this memory pool
    * @private @memberof QMPool
    */
    void * end;

    /*! head of linked list of free blocks
    * @private @memberof QMPool
    */
    void * volatile free_head;

    /*! maximum block size (in bytes)
    * @private @memberof QMPool
    */
    QMPoolSize blockSize;

    /*! total number of blocks
    * @private @memberof QMPool
    */
    QMPoolCtr nTot;

    /*! number of free blocks remaining
    * @private @memberof QMPool
    */
    QMPoolCtr volatile nFree;

    /*! minimum number of free blocks ever present in this pool
    * @private @memberof QMPool
    *
    * @details
    * this attribute remembers the low watermark of the pool, which
    * provides a valuable information for sizing event pools.
    * @sa QF_getPoolMin().
    */
    QMPoolCtr nMin;
} QMPool;

/* public: */

/*! Initializes the native QF memory pool
* @public @memberof QMPool
*
* @details
* Initialize a fixed block-size memory pool by providing it with the pool
* memory to manage, size of this memory, and the block size.
*
* @param[in,out] me       pointer (see @ref oop)
* @param[in]     poolSto  pointer to the memory buffer for pool storage
* @param[in]     poolSize size of the storage buffer in bytes
* @param[in]     blockSize fixed-size of the memory blocks in bytes
*
* @attention
* The caller of QMPool::init() must make sure that the @p poolSto
* pointer is properly **aligned**. In particular, it must be possible to
* efficiently store a pointer at the location pointed to by @p poolSto.
* Internally, the QMPool_init() function rounds up the block size
* @p blockSize so that it can fit an integer number of pointers.
* This is done to achieve proper alignment of the blocks within the pool.
*
* @note
* Due to the rounding of block size the actual capacity of the pool might
* be less than (@p poolSize / @p blockSize). You can check the capacity
* of the pool by calling the QF_getPoolMin() function.
*
* @note
* This function is **not** protected by a critical section, because
* it is intended to be called only during the initialization of the system,
* when interrupts are not allowed yet.
*
* @note
* Many QF ports use memory pools to implement the event pools.
*
* @usage
* The following example illustrates how to invoke QMPool_init():
* @include qmp_init.c
*/
void QMPool_init(QMPool * const me,
    void * const poolSto,
    uint_fast32_t poolSize,
    uint_fast16_t blockSize);

/*! Obtains a memory block from a memory pool.
* @public @memberof QMPool
*
* @details
* The function allocates a memory block from the pool and returns a pointer
* to the block back to the caller.
*
* @param[in,out] me      pointer (see @ref oop)
* @param[in]     margin  the minimum number of unused blocks still available
*                        in the pool after the allocation.
*
* @returns
* A pointer to a memory block or NULL if no more blocks are available in
* the memory pool.
*
* @note
* This function can be called from any task level or ISR level.
*
* @note
* The memory pool @p me must be initialized before any events can
* be requested from it. Also, the QMPool_get() function uses internally a
* QF critical section, so you should be careful not to call it from within
* a critical section when nesting of critical section is not supported.
*
* @attention
* An allocated block must be later returned back to the **same** pool
* from which it has been allocated.
*
* @sa QMPool_put()
*
* @usage
* The following example illustrates how to use QMPool_get():
* @include qmp_use.c
*/
void * QMPool_get(QMPool * const me,
    uint_fast16_t const margin,
    uint_fast8_t const qs_id);

/*! Recycles a memory block back to a memory pool.
* @public @memberof QMPool
*
* @details
* Recycle a memory block to the fixed block-size memory pool.
*
* @param[in,out] me   pointer (see @ref oop)
* @param[in]     b    pointer to the memory block that is being recycled
*
* @attention
* The recycled block must be allocated from the **same** memory pool
* to which it is returned.
*
* @note
* This function can be called from any task level or ISR level.
*
* @sa
* QMPool_get()
*
* @usage
* The following example illustrates how to use QMPool_put():
* @include qmp_use.c
*/
void QMPool_put(QMPool * const me,
    void * const b,
    uint_fast8_t const qs_id);
/*$enddecl${QF::QMPool} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

#endif  /* QMPOOL_H */
