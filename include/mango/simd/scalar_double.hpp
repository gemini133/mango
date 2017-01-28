/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2017 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "simd.hpp"

#ifdef MANGO_SIMD_DOUBLE_SCALAR

namespace mango {
namespace simd {

    // -----------------------------------------------------------------
    // float64x4
    // -----------------------------------------------------------------

    template <int x, int y, int z, int w>
    inline float64x4 float64x4_shuffle(float64x4 v)
    {
        // .generic
        const double* s = reinterpret_cast<const double*>(&v);
        float64x4 n = { s[x], s[y], s[z], s[w] };
        return n;
    }

    template <>
    inline float64x4 float64x4_shuffle<0, 1, 2, 3>(float64x4 v)
    {
        // .xyzw
        return v;
    }

    // set component

    template <int Index>
    static inline float64x4 float64x4_set_component(float64x4 a, double s);

    template <>
    inline float64x4 float64x4_set_component<0>(float64x4 a, double x)
    {
        a.x = x;
        return a;
    }

    template <>
    inline float64x4 float64x4_set_component<1>(float64x4 a, double y)
    {
        a.y = y;
        return a;
    }

    template <>
    inline float64x4 float64x4_set_component<2>(float64x4 a, double z)
    {
        a.z = z;
        return a;
    }

    template <>
    inline float64x4 float64x4_set_component<3>(float64x4 a, double w)
    {
        a.w = w;
        return a;
    }

    // get component

    template <int Index>
    static inline double float64x4_get_component(float64x4 a);

    template <>
    inline double float64x4_get_component<0>(float64x4 a)
    {
        return a.x;
    }

    template <>
    inline double float64x4_get_component<1>(float64x4 a)
    {
        return a.y;
    }

    template <>
    inline double float64x4_get_component<2>(float64x4 a)
    {
        return a.z;
    }

    template <>
    inline double float64x4_get_component<3>(float64x4 a)
    {
        return a.w;
    }

    static inline float64x4 float64x4_zero()
    {
        float64x4 temp = { 0.0, 0.0, 0.0, 0.0 };
        return temp;
    }

    static inline float64x4 float64x4_set1(double s)
    {
        float64x4 temp = { s, s, s, s };
        return temp;
    }

    static inline float64x4 float64x4_set4(double x, double y, double z, double w)
    {
        float64x4 temp = { x, y, z, w };
        return temp;
    }

    static inline float64x4 float64x4_uload(const double* source)
    {
        float64x4 temp = { source[0], source[1], source[2], source[3] };
        return temp;
    }

    static inline void float64x4_ustore(double* dest, float64x4 a)
    {
        dest[0] = a.x;
        dest[1] = a.y;
        dest[2] = a.z;
        dest[3] = a.w;
    }

    static inline float64x4 float64x4_unpackhi(float64x4 a, float64x4 b)
    {
        float64x4 v = { a.y, b.y, a.w, b.w };
        return v;
    }

    static inline float64x4 float64x4_unpacklo(float64x4 a, float64x4 b)
    {
        float64x4 v = { a.x, b.x, a.z, b.z };
        return v;
    }

    // logical

    static inline float64x4 float64x4_and(float64x4 a, float64x4 b)
    {
        const Double x(Double(a.x).u & Double(b.x).u);
        const Double y(Double(a.y).u & Double(b.y).u);
        const Double z(Double(a.z).u & Double(b.z).u);
        const Double w(Double(a.w).u & Double(b.w).u);
        return float64x4_set4(x, y, z, w);
    }

    static inline float64x4 float64x4_nand(float64x4 a, float64x4 b)
    {
        const Double x(~Double(a.x).u & Double(b.x).u);
        const Double y(~Double(a.y).u & Double(b.y).u);
        const Double z(~Double(a.z).u & Double(b.z).u);
        const Double w(~Double(a.w).u & Double(b.w).u);
        return float64x4_set4(x, y, z, w);
    }

    static inline float64x4 float64x4_or(float64x4 a, float64x4 b)
    {
        const Double x(Double(a.x).u | Double(b.x).u);
        const Double y(Double(a.y).u | Double(b.y).u);
        const Double z(Double(a.z).u | Double(b.z).u);
        const Double w(Double(a.w).u | Double(b.w).u);
        return float64x4_set4(x, y, z, w);
    }

    static inline float64x4 float64x4_xor(float64x4 a, float64x4 b)
    {
        const Double x(Double(a.x).u ^ Double(b.x).u);
        const Double y(Double(a.y).u ^ Double(b.y).u);
        const Double z(Double(a.z).u ^ Double(b.z).u);
        const Double w(Double(a.w).u ^ Double(b.w).u);
        return float64x4_set4(x, y, z, w);
    }

    static inline float64x4 float64x4_min(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = std::min(a.x, b.x);
        v.y = std::min(a.y, b.y);
        v.z = std::min(a.z, b.z);
        v.w = std::min(a.w, b.w);
        return v;
    }

    static inline float64x4 float64x4_max(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = std::max(a.x, b.x);
        v.y = std::max(a.y, b.y);
        v.z = std::max(a.z, b.z);
        v.w = std::max(a.w, b.w);
        return v;
    }

    static inline float64x4 float64x4_clamp(float64x4 a, float64x4 vmin, float64x4 vmax)
    {
        float64x4 v;
        v.x = std::min(vmax.x, std::max(vmin.x, a.x));
        v.y = std::min(vmax.y, std::max(vmin.y, a.y));
        v.z = std::min(vmax.z, std::max(vmin.z, a.z));
        v.w = std::min(vmax.w, std::max(vmin.w, a.w));
        return v;
    }

    static inline float64x4 float64x4_abs(float64x4 a)
    {
        float64x4 v;
        v.x = std::abs(a.x);
        v.y = std::abs(a.y);
        v.z = std::abs(a.z);
        v.w = std::abs(a.w);
        return v;
    }

    static inline float64x4 float64x4_neg(float64x4 a)
    {
        float64x4 v = { -a.x, -a.y, -a.z, -a.w };
        return v;
    }

    static inline float64x4 float64x4_add(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        v.z = a.z + b.z;
        v.w = a.w + b.w;
        return v;
    }

    static inline float64x4 float64x4_sub(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        v.z = a.z - b.z;
        v.w = a.w - b.w;
        return v;
    }

    static inline float64x4 float64x4_mul(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = a.x * b.x;
        v.y = a.y * b.y;
        v.z = a.z * b.z;
        v.w = a.w * b.w;
        return v;
    }

    static inline float64x4 float64x4_div(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = a.x / b.x;
        v.y = a.y / b.y;
        v.z = a.z / b.z;
        v.w = a.w / b.w;
        return v;
    }

    static inline float64x4 float64x4_div(float64x4 a, double b)
    {
        float64x4 v;
        v.x = a.x / b;
        v.y = a.y / b;
        v.z = a.z / b;
        v.w = a.w / b;
        return v;
    }

    static inline float64x4 float64x4_madd(float64x4 a, float64x4 b, float64x4 c)
    {
        float64x4 v;
        v.x = a.x + b.x * c.x;
        v.y = a.y + b.y * c.y;
        v.z = a.z + b.z * c.z;
        v.w = a.w + b.w * c.w;
        return v;
    }

    static inline float64x4 float64x4_msub(float64x4 a, float64x4 b, float64x4 c)
    {
        float64x4 v;
        v.x = a.x - b.x * c.x;
        v.y = a.y - b.y * c.y;
        v.z = a.z - b.z * c.z;
        v.w = a.w - b.w * c.w;
        return v;
    }

    static inline float64x4 float64x4_fast_reciprocal(float64x4 a)
    {
        float64x4 v;
        v.x = 1.0 / a.x;
        v.y = 1.0 / a.y;
        v.z = 1.0 / a.z;
        v.w = 1.0 / a.w;
        return v;
    }

    static inline float64x4 float64x4_fast_rsqrt(float64x4 a)
    {
        float64x4 v;
        v.x = 1.0 / std::sqrt(a.x);
        v.y = 1.0 / std::sqrt(a.y);
        v.z = 1.0 / std::sqrt(a.z);
        v.w = 1.0 / std::sqrt(a.w);
        return v;
    }

    static inline float64x4 float64x4_fast_sqrt(float64x4 a)
    {
        float64x4 v;
        v.x = std::sqrt(a.x);
        v.y = std::sqrt(a.y);
        v.z = std::sqrt(a.z);
        v.w = std::sqrt(a.w);
        return v;
    }

    static inline float64x4 float64x4_reciprocal(float64x4 a)
    {
        return float64x4_fast_reciprocal(a);
    }

    static inline float64x4 float64x4_rsqrt(float64x4 a)
    {
        return float64x4_fast_rsqrt(a);
    }

    static inline float64x4 float64x4_sqrt(float64x4 a)
    {
        return float64x4_fast_sqrt(a);
    }

    static inline float64x4 float64x4_dot4(float64x4 a, float64x4 b)
    {
        const double s = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
        return float64x4_set1(s);
    }

    // compare

    static inline float64x4 float64x4_compare_neq(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = Double(uint64(a.x != b.x ? 0xffffffffffffffff : 0));
        v.y = Double(uint64(a.y != b.y ? 0xffffffffffffffff : 0));
        v.z = Double(uint64(a.z != b.z ? 0xffffffffffffffff : 0));
        v.w = Double(uint64(a.w != b.w ? 0xffffffffffffffff : 0));
        return v;
    }

    static inline float64x4 float64x4_compare_eq(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = Double(uint64(a.x == b.x ? 0xffffffffffffffff : 0));
        v.y = Double(uint64(a.y == b.y ? 0xffffffffffffffff : 0));
        v.z = Double(uint64(a.z == b.z ? 0xffffffffffffffff : 0));
        v.w = Double(uint64(a.w == b.w ? 0xffffffffffffffff : 0));
        return v;
    }

    static inline float64x4 float64x4_compare_lt(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = Double(uint64(a.x < b.x ? 0xffffffffffffffff : 0));
        v.y = Double(uint64(a.y < b.y ? 0xffffffffffffffff : 0));
        v.z = Double(uint64(a.z < b.z ? 0xffffffffffffffff : 0));
        v.w = Double(uint64(a.w < b.w ? 0xffffffffffffffff : 0));
        return v;
    }

    static inline float64x4 float64x4_compare_le(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = Double(uint64(a.x <= b.x ? 0xffffffffffffffff : 0));
        v.y = Double(uint64(a.y <= b.y ? 0xffffffffffffffff : 0));
        v.z = Double(uint64(a.z <= b.z ? 0xffffffffffffffff : 0));
        v.w = Double(uint64(a.w <= b.w ? 0xffffffffffffffff : 0));
        return v;
    }

    static inline float64x4 float64x4_compare_gt(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = Double(uint64(a.x > b.x ? 0xffffffffffffffff : 0));
        v.y = Double(uint64(a.y > b.y ? 0xffffffffffffffff : 0));
        v.z = Double(uint64(a.z > b.z ? 0xffffffffffffffff : 0));
        v.w = Double(uint64(a.w > b.w ? 0xffffffffffffffff : 0));
        return v;
    }

    static inline float64x4 float64x4_compare_ge(float64x4 a, float64x4 b)
    {
        float64x4 v;
        v.x = Double(uint64(a.x >= b.x ? 0xffffffffffffffff : 0));
        v.y = Double(uint64(a.y >= b.y ? 0xffffffffffffffff : 0));
        v.z = Double(uint64(a.z >= b.z ? 0xffffffffffffffff : 0));
        v.w = Double(uint64(a.w >= b.w ? 0xffffffffffffffff : 0));
        return v;
    }

    static inline float64x4 float64x4_select(float64x4 mask, float64x4 a, float64x4 b)
    {
        return float64x4_or(float64x4_and(mask, a), float64x4_nand(mask, b));
    }

    // rounding

    static inline float64x4 float64x4_round(float64x4 s)
    {
        float64x4 v;
        v.x = std::round(s.x);
        v.y = std::round(s.y);
        v.z = std::round(s.z);
        v.w = std::round(s.w);
        return v;
    }

    static inline float64x4 float64x4_trunc(float64x4 s)
    {
        float64x4 v;
        v.x = std::trunc(s.x);
        v.y = std::trunc(s.y);
        v.z = std::trunc(s.z);
        v.w = std::trunc(s.w);
        return v;
    }

    static inline float64x4 float64x4_floor(float64x4 s)
    {
        float64x4 v;
        v.x = std::floor(s.x);
        v.y = std::floor(s.y);
        v.z = std::floor(s.z);
        v.w = std::floor(s.w);
        return v;
    }

    static inline float64x4 float64x4_ceil(float64x4 s)
    {
        float64x4 v;
        v.x = std::ceil(s.x);
        v.y = std::ceil(s.y);
        v.z = std::ceil(s.z);
        v.w = std::ceil(s.w);
        return v;
    }

    static inline float64x4 float64x4_fract(float64x4 s)
    {
        return float64x4_sub(s, float64x4_floor(s));
    }

} // namespace simd
} // namespace mango

#endif // MANGO_SIMD_DOUBLE_SCALAR