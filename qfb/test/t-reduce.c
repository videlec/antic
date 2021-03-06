/*=============================================================================

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

=============================================================================*/
/******************************************************************************

    Copyright (C) 2012 William Hart

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "flint.h"
#include "ulong_extras.h"
#include "fmpz.h"
#include "qfb.h"

int main(void)
{
    int result;
    flint_rand_t state;
    slong i;

    printf("reduce....");
    fflush(stdout);

    flint_randinit(state);

    for (i = 1; i < 100000; i++) 
    {
        fmpz_t D;
        qfb_t r;
        
        fmpz_init(D);
        qfb_init(r);
            
        do
        {
           fmpz_randtest_unsigned(r->a, state, 100);
           if (fmpz_is_zero(r->a))
              fmpz_set_ui(r->a, 1);
 
           fmpz_randtest(r->b, state, 100);
           fmpz_randtest(r->c, state, 100);

           qfb_discriminant(D, r);
        } while (fmpz_sgn(D) >= 0);

        qfb_reduce(r, r, D);

        result = (qfb_is_reduced(r));
        if (!result)
        {
           printf("FAIL:\n");
           qfb_print(r); printf("\n");
           abort();
        }
           
        fmpz_clear(D);
        qfb_clear(r);
    }

    flint_randclear(state);
    _fmpz_cleanup();
    printf("PASS\n");
    return 0;
}
