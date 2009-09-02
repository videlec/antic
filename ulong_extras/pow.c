/*============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

===============================================================================*/
/****************************************************************************

   Copyright (C) 2009 William Hart

*****************************************************************************/

#include <mpir.h>
#include "flint.h"
#include "ulong_extras.h"

mp_limb_t n_pow(mp_limb_t n, ulong exp)
{
   mp_limb_t res = 1UL;

   if (n == 0L) return 0UL;
   if (exp == 1UL) return n;
   if (exp == 0UL) return 1UL;

   for (ulong i = 0; i < exp; i++)
   {
      res *= n;
   }

   return res;
}
