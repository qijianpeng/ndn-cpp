/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2014 Andrey Semashev
 */
/*!
 * \file   atomic/detail/ops_extending_cas_based.hpp
 *
 * This header contains a boilerplate of the \c operations template implementation that requires sign/zero extension in arithmetic operations.
 */

#ifndef NDNBOOST_ATOMIC_DETAIL_OPS_EXTENDING_CAS_BASED_HPP_INCLUDED_
#define NDNBOOST_ATOMIC_DETAIL_OPS_EXTENDING_CAS_BASED_HPP_INCLUDED_

#include <ndnboost/memory_order.hpp>
#include <ndnboost/atomic/detail/config.hpp>
#include <ndnboost/atomic/detail/storage_type.hpp>

#ifdef NDNBOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace ndnboost {
namespace atomics {
namespace detail {

template< typename Base, unsigned int Size, bool Signed >
struct extending_cas_based_operations :
    public Base
{
    typedef typename Base::storage_type storage_type;
    typedef typename make_storage_type< Size, Signed >::type emulated_storage_type;

    static NDNBOOST_FORCEINLINE storage_type fetch_add(storage_type volatile& storage, storage_type v, memory_order order) NDNBOOST_NOEXCEPT
    {
        storage_type old_val = Base::load(storage, memory_order_relaxed);
        emulated_storage_type new_val;
        do
        {
            new_val = static_cast< emulated_storage_type >(old_val) + static_cast< emulated_storage_type >(v);
        }
        while (!Base::compare_exchange_weak(storage, old_val, static_cast< storage_type >(new_val), order, memory_order_relaxed));
        return old_val;
    }

    static NDNBOOST_FORCEINLINE storage_type fetch_sub(storage_type volatile& storage, storage_type v, memory_order order) NDNBOOST_NOEXCEPT
    {
        storage_type old_val = Base::load(storage, memory_order_relaxed);
        emulated_storage_type new_val;
        do
        {
            new_val = static_cast< emulated_storage_type >(old_val) - static_cast< emulated_storage_type >(v);
        }
        while (!Base::compare_exchange_weak(storage, old_val, static_cast< storage_type >(new_val), order, memory_order_relaxed));
        return old_val;
    }
};

} // namespace detail
} // namespace atomics
} // namespace ndnboost

#endif // NDNBOOST_ATOMIC_DETAIL_OPS_EXTENDING_CAS_BASED_HPP_INCLUDED_
