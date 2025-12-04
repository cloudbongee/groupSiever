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


## Non simplicity of groups $2n, n \in \mathbb{Z}^{\text{odd}}, n > 1$

### Proof
See [Cayley's theorem] below. 

## Lemmas
### Cayley's theorem

## Flags
In the makefile, the variables

```
LATEXFLAG = 1
VALGRIND = 1
```

can be toggled, to deactivate latex output (and change to CVS output of the format $pq, p, q, p \text{ or } q$, with the last field depending on whether the found Sylow subgroup is a $p$ or a $q$ Sylow). And to deactivate the `-g` flag used in GCC for valgrind.
