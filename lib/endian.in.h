/* endian.h - Byte order macros

   Copyright 2024 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by Collin Funk.  */

#ifndef _GL_ENDIAN_H
#define _GL_ENDIAN_H 1

/* This file uses _GL_INLINE, WORDS_BIGENDIAN.  */
#if !_GL_CONFIG_H_INCLUDED
 #error "Please include config.h first."
#endif

/* Define uint16_t and uint32_t.
   Define uint64_t if it is available.  */
#include <stdint.h>

/* Byteswap functions.  */
#include <byteswap.h>

_GL_INLINE_HEADER_BEGIN
#ifndef _GL_ENDIAN_INLINE
# define _GL_ENDIAN_INLINE _GL_INLINE
#endif

#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN 4321
#define PDP_ENDIAN 3412

#ifdef WORDS_BIGENDIAN
# define BYTE_ORDER BIG_ENDIAN
#else
# define BYTE_ORDER LITTLE_ENDIAN
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Big endian to host.  */

_GL_ENDIAN_INLINE uint16_t
be16toh (uint16_t x)
{
#if BYTE_ORDER == BIG_ENDIAN
  return x;
#else
  return bswap_16 (x);
#endif
}

_GL_ENDIAN_INLINE uint32_t
be32toh (uint32_t x)
{
#if BYTE_ORDER == BIG_ENDIAN
  return x;
#else
  return bswap_32 (x);
#endif
}

#ifdef UINT64_MAX
_GL_ENDIAN_INLINE uint64_t
be64toh (uint64_t x)
{
# if BYTE_ORDER == BIG_ENDIAN
  return x;
# else
  return bswap_64 (x);
# endif
}
#endif

/* Host to big endian.  */

_GL_ENDIAN_INLINE uint16_t
htobe16 (uint16_t x)
{
#if BYTE_ORDER == BIG_ENDIAN
  return x;
#else
  return bswap_16 (x);
#endif
}

_GL_ENDIAN_INLINE uint32_t
htobe32 (uint32_t x)
{
#if BYTE_ORDER == BIG_ENDIAN
  return x;
#else
  return bswap_32 (x);
#endif
}

#ifdef UINT64_MAX
_GL_ENDIAN_INLINE uint64_t
htobe64 (uint64_t x)
{
# if BYTE_ORDER == BIG_ENDIAN
  return x;
# else
  return bswap_64 (x);
# endif
}
#endif

/* Little endian to host.  */

_GL_ENDIAN_INLINE uint16_t
le16toh (uint16_t x)
{
#if BYTE_ORDER == BIG_ENDIAN
  return bswap_16 (x);
#else
  return x;
#endif
}

_GL_ENDIAN_INLINE uint32_t
le32toh (uint32_t x)
{
#if BYTE_ORDER == BIG_ENDIAN
  return bswap_32 (x);
#else
  return x;
#endif
}

#ifdef UINT64_MAX
_GL_ENDIAN_INLINE uint64_t
le64toh (uint64_t x)
{
# if BYTE_ORDER == BIG_ENDIAN
  return bswap_64 (x);
# else
  return x;
# endif
}
#endif

/* Host to little endian.  */

_GL_ENDIAN_INLINE uint16_t
htole16 (uint16_t x)
{
#if BYTE_ORDER == BIG_ENDIAN
  return bswap_16 (x);
#else
  return x;
#endif
}

_GL_ENDIAN_INLINE uint32_t
htole32 (uint32_t x)
{
#if BYTE_ORDER == BIG_ENDIAN
  return bswap_32 (x);
#else
  return x;
#endif
}

#ifdef UINT64_MAX
_GL_ENDIAN_INLINE uint64_t
htole64 (uint64_t x)
{
# if BYTE_ORDER == BIG_ENDIAN
  return bswap_64 (x);
# else
  return x;
# endif
}
#endif

#ifdef __cplusplus
}
#endif

_GL_INLINE_HEADER_END

#endif /* _GL_ENDIAN_H */