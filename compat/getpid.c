/*****************************************************************************
 * getpid.c: POSIX getpid() replacement
 *****************************************************************************
 * Copyright © 2009 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "stdafx.h"

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <sys/types.h>
#ifdef _WIN32
# include <windows.h>
#endif

pid_t getpid (void)
{
#if defined (_WIN32)
    return (pid_t) GetCurrentProcessId ();
#elif defined (__native_client__)
    return 1;
#else
# error Unimplemented!
#endif
}