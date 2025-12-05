# groupSiever

GroupSiever was made to aid myself with finding and counting for me the non-simple groups of non prime $2 \leq |G| < 168$.

Made with a smile.

## Non simplicity of groups order $pq$

### Theory
Given a group $\vert G\vert = p^km$, due to the consequence of Sylow's theorem, $n_p:=[G:N(p)]$ follows 
the property $n_p \mid m \land n_p \equiv 1 \pmod{p}$. One of the easiest type of groups to look into
are the ones of order $pq$.

Let $p,q\in\mathbb{Z}^{\text{prime}}$, if we look into the $p-\text{Sylow}$ subgroups of $|G|=pq$, then $n_p \mid q$ must hold.
However, $n_p = 1 \lor n_p = q$, due to $q$'s primality. Thus, we only need to look into whether:

$$ q \equiv 1 \pmod{p} $$

If the previous is true, then the count of groups could either be one or $q$. Case for which other lemmas and studies of the 
group structure must be done to determine the count of $p-\text{Sylow}$ groups.

However, if it is not true, then the count of $1$ is the only valid count for $p-\text{Sylow}$ subgroups of $G$. Consequently, the unique $p-\text{Sylow}$ subgroup is a normal subgroup of $G$.

An equivalent process can be taken to determine the uniqueness of $q-\text{Sylow}$ subgroups. And since $p < pq$ and $q < pq$. Following the aforementioned logical process over all combinations of $p\neq q$ with $pq$ lesser than a given bound will let us confirm simpleness (or the lack thereof) of groups of $pq$ order.

### Proof

If we give an ordering $q < p$, if we look for the $q-\text{Sylow}$ group, then $q\not\equiv 1\pmod{p}$ is granted.

### Implementation
Given a $m$ max-cardinality.

  1. Eratosthenes prime sieve is applied to a max bound of $\left\lceil\dfrac{m}{2}\right\rceil$.
     The sieve is scanned to retrieve primes.
     
  3. A double loop is used over $p$ and $q$ ensuring that once $pq$ is evaluated, $qp$ is later ignored.
     Negating simpleness of the group if $p \not\equiv 1 \pmod{q}$ or $q \not\equiv 1 \pmod{p}$. 

See [pqSieve.c](pqSieve.c) with usage

```
pqSieve [maxGroupSize]
```

Using it with up to 167 order group yields results in the format `|G|, p, q, either-p-or-q-subgroup-negating-simpleness`

```
> 6,2,3,3
> 10,2,5,5
> 14,2,7,7
> 22,2,11,11
> 26,2,13,13
> 34,2,17,17
> 38,2,19,19
> 46,2,23,23
> 58,2,29,29
> 62,2,31,31
> 74,2,37,37
> 82,2,41,41
> 86,2,43,43
> 94,2,47,47
> 106,2,53,53
> 118,2,59,59
> 122,2,61,61
> 134,2,67,67
> 142,2,71,71
> 146,2,73,73
> 158,2,79,79
> 166,2,83,83
> 15,3,5,5
> 15,3,5,3
> 21,3,7,7
> 33,3,11,11
> 33,3,11,3
> 39,3,13,13
> 51,3,17,17
> 51,3,17,3
> 57,3,19,19
> 69,3,23,23
> 69,3,23,3
> 87,3,29,29
> 87,3,29,3
> 93,3,31,31
> 111,3,37,37
> 123,3,41,41
> 123,3,41,3
> 129,3,43,43
> 141,3,47,47
> 141,3,47,3
> 159,3,53,53
> 159,3,53,3
> 35,5,7,7
> 35,5,7,5
> 55,5,11,11
> 65,5,13,13
> 65,5,13,5
> 85,5,17,17
> 85,5,17,5
> 95,5,19,19
> 95,5,19,5
> 115,5,23,23
> 115,5,23,5
> 145,5,29,29
> 145,5,29,5
> 155,5,31,31
> 77,7,11,11
> 77,7,11,7
> 91,7,13,13
> 91,7,13,7
> 119,7,17,17
> 119,7,17,7
> 133,7,19,19
> 133,7,19,7
> 161,7,23,23
> 161,7,23,7
> 143,11,13,13
> 143,11,13,11
50/50
```

## Non-simplicity of groups order $p^k$

### Theory

Let $|G| = p^k$, such that $k\geq 2$, then $Z(G) \neq \{e\}$

### Proof

As a consequence of Lagrange's theorem, we know that $\vert G:C(a) \vert \mid p^k$ for any $a\in G$. It should be a prime power we call $p^r$. 

Using the class equation

$$\vert G \vert = \vert Z(G) \vert + \sum\limits_{a \in G-Z(G)}\vert G:C(a)\vert$$
$$\vert G \vert -  \sum\limits_{a \in G-Z(G)}\vert G:C(a)\vert = \vert Z(G) \vert$$

If we assume assume $p^r = p^k$ then $\vert Z(G) \vert = 0$, which is impossible. Since the number $p^r$ is a divisor, it must be lesser than $p^k$.

Furthermore

$$ p^k - p^r = p^h(p^{k-h} - p^{r-h}) = |Z(G)| \implies p \mid |Z(G)|$$

Therefore $Z(G)$ cannot have an order of one, otherwise it's not divisible by $p$. Thus, it's nontrivial.

### Implementation

Simply lists all group sizes of order $p^k \leq n$ for a given $n$. Not much magic going on.

See [pkSieve.c](pkSieve.c) with usage

```
pkSieve [maxGroupSize]
```

## Groups under general sylow non-simplicity test

$|G| \text{ is not prime }, p \mid n$, $|G|$ is not simple if $\forall x \in \mathbb{N}: x \mid |G| \land x \equiv 1 \pmod{p} \implies x = 1$ 

### Proof

There are two cases for $|G|$

  1. $|G| = p^k$, then the theorem above applies.
  2. $|G| = p^km$, then $\text{Syl}_p(G) < G$ (strictly), $[G:N(p)] \mid m \land [G:N(p)] \equiv 1 \pmod{p}$

## Non simplicity of groups $2n, n \in \mathbb{Z}^{\text{odd}}, n > 1$

$$ \vert G \vert = 2n \land n \in \mathbb{Z}^{\text{odd}} \land n > 1 \implies G \text{ is not simple}$$

### Proof
See [Cayley's theorem] below. 

## Lemmas
### Cayley's theorem

## Index theorem using Sylow subgroups

If $G$ is finite, and $H<G$ has $\vert G \vert \nmid  |G : H|! $, then $\exists K \leq H : \\{e\\} \neq K \triangleleft G$ (Index theorem).

Check [remaining.c](remaining.c) to see how the remaining groups were extracted from the concatenation of the results of `pqSieve.c`, `nSieve.c`, and `pkSieve.c`.

With a remaining list of orders $|G| \in \\{ 12, 24, 36, 48, 56, 60, 72, 80, 96, 105, 108, 112, 120, 132, 144, 160 \\}$, we do the following process to find possible subgroups sizes that would undermine
non simplicity:

  1. Using lagrange's theorem we find all strict, greater than one, $a \mid \vert G\vert$
  2. For each $a$ as specified, we check if $\hspace{0.2ex}\dfrac{|G|}{a}! \equiv 0 \pmod{|G|}$.
     If that doesn't happen, then $a$ is listed as a possible subgroup size that would prove existence of a normal group in $G$
     
Utilizing [indexSieveBruteForce.c](indexSieveBruteForce.c) we get a list, where the format is `|G|, Possible |H| that would normalize`:

```
12, 4
12, 6
24, 8
24, 12
36, 2
36, 9
36, 12
36, 18
48, 2
48, 3
48, 12
48, 16
48, 24
56, 2
56, 4
56, 14
56, 28
60, 2
60, 3
60, 4
60, 15
60, 20
60, 30
72, 3
72, 4
72, 18
72, 24
72, 36
80, 4
80, 5
80, 16
80, 20
80, 40
96, 3
96, 4
96, 6
96, 16
96, 24
96, 32
96, 48
105, 5
105, 7
105, 21
105, 35
108, 4
108, 6
108, 18
108, 27
108, 36
108, 54
112, 4
112, 7
112, 8
112, 28
112, 56
120, 4
120, 5
120, 6
120, 8
120, 30
120, 40
120, 60
132, 4
132, 6
132, 22
132, 33
132, 44
132, 66
144, 6
144, 8
144, 9
144, 36
144, 48
144, 72
160, 5
160, 8
160, 10
160, 32
160, 40
160, 80
```

Utilizing the index theorem, through the selection of maximal $p-\text{Sylow}$ subgroups, as specified in [indexSieveSylow.c](indexSieveSylow.c), we get

```
12 is nonsimple with max sylow group order 4
24 is nonsimple with max sylow group order 8
36 is nonsimple with max sylow group order 9
48 is nonsimple with max sylow group order 16
56 is non-conclusive
60 is non-conclusive
72 is non-conclusive
80 is nonsimple with max sylow group order 16
96 is nonsimple with max sylow group order 32
105 is non-conclusive
108 is nonsimple with max sylow group order 27
112 is non-conclusive
120 is non-conclusive
132 is non-conclusive
144 is non-conclusive
160 is nonsimple with max sylow group order 32
```

Which leaves 56,60,72,105,112,120,132,144. 

## Make
As any good chef, I leave my recipes open to the world.

```
make all
```
Will throw an executable assuming you have `gcc`, `stdio.h`, `stdlib.h`, `math.h`, and can run makefiles.

### Flags
In the makefile, the variables

```
LATEXFLAG = 1
VALGRIND = 1
```

can be toggled, to deactivate latex output (and change to CVS output of the format $pq, p, q, p \text{ or } q$, with the last field depending on whether the found Sylow subgroup is a $p$ or a $q$ Sylow). And to deactivate the `-g` flag used in GCC for valgrind.
