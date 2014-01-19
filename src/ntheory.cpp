#include "ntheory.h"

namespace CSymPy {

RCP<Integer> gcd(const Integer &a, const Integer &b)
{
    mpz_class g;

    mpz_gcd(g.get_mpz_t(), a.as_mpz().get_mpz_t(), b.as_mpz().get_mpz_t());

    return integer(g);
}

void gcd_ext(const Integer &a, const Integer &b, const Ptr<RCP<Integer>> &g,
                         const Ptr<RCP<Integer>> &s, const Ptr<RCP<Integer>> &t)
{
    mpz_t g_t;
    mpz_t s_t;
    mpz_t t_t;
    
    mpz_init(g_t);
    mpz_init(s_t);
    mpz_init(t_t);
    
    mpz_gcdext(g_t, s_t, t_t, a.as_mpz().get_mpz_t(), b.as_mpz().get_mpz_t());
    *g = integer(mpz_class(g_t));
    *s = integer(mpz_class(s_t));
    *t = integer(mpz_class(t_t));
    
    mpz_clear(g_t);
    mpz_clear(s_t);
    mpz_clear(t_t);
}

RCP<Integer> lcm(const Integer &a, const Integer &b)
{
    mpz_class c;

    mpz_lcm(c.get_mpz_t(), a.as_mpz().get_mpz_t(), b.as_mpz().get_mpz_t());

    return integer(c);
}

int mod_inverse(const Integer &a, const Integer &m, const Ptr<RCP<Integer>> &b)
{
    int ret_val;
    mpz_t inv_t;
    mpz_init(inv_t);
    
    ret_val = mpz_invert(inv_t, a.as_mpz().get_mpz_t(), m.as_mpz().get_mpz_t());
    *b = integer(mpz_class(inv_t));
    
    mpz_clear(inv_t);
    
    return ret_val;
}

int probab_prime_p(const Integer &a, int reps)
{
    return mpz_probab_prime_p(a.as_mpz().get_mpz_t(), reps);
}

RCP<Integer> nextprime(const Integer &a)
{
    mpz_class c;

    mpz_nextprime(c.get_mpz_t(), a.as_mpz().get_mpz_t());

    return integer(c);
}

} // CSymPy
