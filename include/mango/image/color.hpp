/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2019 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "../core/configure.hpp"
#include "../core/endian.hpp"
#include "../core/bits.hpp"

namespace mango
{

    constexpr u32 makeBGRA(u32 red, u32 green, u32 blue, u32 alpha) noexcept
    {
        return (alpha << 24) | (red << 16) | (green << 8) | blue;
    }

    constexpr u32 makeRGBA(u32 red, u32 green, u32 blue, u32 alpha) noexcept
    {
        return (alpha << 24) | (blue << 16) | (green << 8) | red;
    }

    struct ColorBGRA
    {
        union
        {
            u8 component[4];
            struct { u8 b, g, r, a; };
        };

        constexpr ColorBGRA()
            : component { 0, 0, 0, 0 }
        {
        }

        ColorBGRA(u8 red, u8 green, u8 blue, u8 alpha)
            : component { blue, green, red, alpha }
        {
        }

        ColorBGRA(u32 value)
        {
            ustore32le(this, value);
        }

        operator u32 () const
        {
            return uload32le(this);
        }

        u8& operator [] (int index)
        {
            return component[index];
        }

        u8 operator [] (int index) const
        {
            return component[index];
        }
    };

    struct ColorRGBA
    {
        union
        {
            u8 component[4];
            struct { u8 r, g, b, a; };
        };

        constexpr ColorRGBA()
            : component { 0, 0, 0, 0 }
        {
        }

        ColorRGBA(u8 red, u8 green, u8 blue, u8 alpha)
            : component { red, green, blue, alpha }
        {
        }

        ColorRGBA(u32 value)
        {
            ustore32le(this, value);
        }

        operator u32 () const
        {
            return uload32le(this);
        }

        u8& operator [] (int index)
        {
            return component[index];
        }

        u8 operator [] (int index) const
        {
            return component[index];
        }
    };

    struct Palette
    {
        u32 size { 0 };
        ColorBGRA color[256];

        ColorBGRA& operator [] (int index)
        {
            return color[index];
        }

        ColorBGRA operator [] (int index) const
        {
            return color[index];
        }
    };

} // namespace mango
