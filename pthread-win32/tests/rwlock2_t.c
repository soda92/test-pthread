/*
 * rwlock2_t.c
 *
 *
 * --------------------------------------------------------------------------
 *
 *      pthreads-win32 - POSIX Threads Library for Win32
 *      Copyright(C) 1998 John E. Bossom
 *      Copyright(C) 1999-2021 pthreads-win32 / pthreads4w contributors
 *
 *      Homepage1: http://sourceware.org/pthreads-win32/
 *      Homepage2: http://sourceforge.net/projects/pthreads4w/
 *
 *      The current list of contributors is contained
 *      in the file CONTRIBUTORS included with the source
 *      code distribution. The list can also be seen at the
 *      following World Wide Web location:
 *      http://sources.redhat.com/pthreads-win32/contributors.html
 *
 *      This library is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU Lesser General Public
 *      License as published by the Free Software Foundation; either
 *      version 2 of the License, or (at your option) any later version.
 *
 *      This library is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *      Lesser General Public License for more details.
 *
 *      You should have received a copy of the GNU Lesser General Public
 *      License along with this library in the file COPYING.LIB;
 *      if not, write to the Free Software Foundation, Inc.,
 *      59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 *
 * --------------------------------------------------------------------------
 *
 * Declare a static rwlock object, timed-lock it,
 * and then unlock it again.
 *
 * Depends on API functions:
 *	pthread_rwlock_timedrdlock()
 *	pthread_rwlock_unlock()
 */

#include "test.h"
#include <sys/timeb.h>

static pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

#ifndef MONOLITHIC_PTHREAD_TESTS
int
main()
#else
int
test_rwlock2_t(void)
#endif
{
  struct timespec abstime, reltime = { 1, 0 };

  (void) pthread_win32_getabstime_np(&abstime, &reltime);

  assert(rwlock == PTHREAD_RWLOCK_INITIALIZER);

  assert(pthread_rwlock_timedrdlock(&rwlock, &abstime) == 0);

  assert(rwlock != PTHREAD_RWLOCK_INITIALIZER);

  assert(rwlock != NULL);

  assert(pthread_rwlock_unlock(&rwlock) == 0);

  assert(pthread_rwlock_destroy(&rwlock) == 0);

  assert(rwlock == NULL);

  return 0;
}
