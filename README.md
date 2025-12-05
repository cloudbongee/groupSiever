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

## The rest of the entries

If $G$ is finite, and $H<G$ has $\vert G \vert \nmid  |G : H|! $, then $\exists K \leq H : \\{e\\} \neq K \triangleleft G$.

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

For all the even numbers $|G|$ above, the pattern is the consistent possible subgroup size $\dfrac{|G|}{2}$. Notice that $|D_n|= 2n$, and notice that $\text{Rot}(D_n) = \\{R_{0}, R_{360/2}, \dots, R_{360/(n)}\\}\leq D_n$ has 
$\text{Rot}(D_n) = n$. The rotations are closed under composition, and every rotation has an inverse, and the identity; therefore we have found a group and a subgroup pair of the form $(2n, n)$ that satisfies the condition for non normality for every even $|G|$.

Leaving only 105.

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
