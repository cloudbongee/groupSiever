# groupSiever

GroupSiever was made to find and prove non-simplicity for some of the groups: $2 \leq |G| \leq 59$, $61 \leq |G| < 168$.
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

Using `pkSieve 167` results in

```
> 4
> 8
> 16
> 32
> 64
> 128
> 9
> 27
> 81
> 25
> 125
> 49
> 121
With a count of 13 non-simple groups
```

## Groups under general sylow non-simplicity test

$|G| \text{ is not prime }, p \mid n$, $|G|$ is not simple if $\forall x \in \mathbb{N}: x \mid |G| \land x \equiv 1 \pmod{p} \implies x = 1$ 

### Proof

There are two cases for $|G|$

  1. $|G| = p^k$, then the theorem above for the center of a $p^k$ order group applies.
  2. $|G| = p^km$, then $\text{Syl}_p(G) < G$ (strictly), $[G:N(p)] \mid m \land [G:N(p)] \equiv 1 \pmod{p}$, if one is the only number to meet these requirements, then the count for a Sylow group is unique and therefore the $p-\text{Sylow}$ group is normal

### Implementation 

See [nSieve.c](nSieve.c), where 
  1. Two separate lists of primes and non primes are generated from a sieve.
  2. Pick a group size.
  3. For each of the primes, if a prime divides a group size, but there is no divisor of $|G|$ that is
     also equivalent to 1 modulo $p$, then the groups of specified group size are non-simple.

After running `nSieve 167`

```
Printing non-simple groups
> 4
> 6
> 8
> 9
> 10
> 14
> 15
> 15
> 16
> 18
> 20
> 21
> 22
> 25
> 26
> 27
> 28
> 32
> 33
> 33
> 34
> 35
> 35
> 38
> 39
> 40
> 42
> 44
> 45
> 45
> 46
> 49
> 50
> 51
> 51
> 52
> 54
> 55
> 57
> 58
> 62
> 63
> 64
> 65
> 65
> 66
> 68
> 69
> 69
> 70
> 70
> 74
> 75
> 76
> 77
> 77
> 78
> 81
> 82
> 84
> 85
> 85
> 86
> 87
> 87
> 88
> 91
> 91
> 92
> 93
> 94
> 95
> 95
> 98
> 99
> 99
> 100
> 102
> 104
> 106
> 110
> 111
> 114
> 115
> 115
> 116
> 117
> 118
> 119
> 119
> 121
> 122
> 123
> 123
> 124
> 125
> 126
> 128
> 129
> 130
> 133
> 133
> 134
> 135
> 135
> 136
> 138
> 140
> 140
> 141
> 141
> 142
> 143
> 143
> 145
> 145
> 146
> 147
> 148
> 152
> 153
> 153
> 154
> 155
> 156
> 158
> 159
> 159
> 161
> 161
> 162
> 164
> 165
> 166
```

## Non simplicity of groups $2n, n \in \mathbb{Z}^{\text{odd}}, n > 1$

$$ \vert G \vert = 2n \land n \in \mathbb{Z}^{\text{odd}} \land n > 1 \implies G \text{ is not simple}$$

### Proof

Given a $2n$ group size for an odd $n$, a mapping 

$$ \phi\colon x \mapsto \alpha_x $$

Where 

$$ \alpha_x\colon z \mapsto xz $$

is an isomorphism $G \cong \text{Sym}(G)$, where due to Cauchy's theorem we confirm an element of order $2$ we call $g$. Then $\alpha_g$ is representable as $n$ transpositions. Therefore the even permutations under the image of $G$ is normal, index 2.

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

Which leaves 56,72,105,112,120,132,144. 

## Other cases

### Embedding theorem

$$[G:H] = n \implies \exists K \leq A_n : G \cong K $$

### Proof

 $H\leq G : |G:H| = n$. Let $G$ be simple and $S_n$ represent the permutation of the $n$ left cosets.
 There is a homomorphism $\phi\colon G\to S_n$, but the kernel is normal, and due to simpleness it must then be trivial, making $\phi$ an isomorphism to a subgroup of $S_n$. $S_n$ has half even and half odd permutations, Due to simpleness, this subgroup can't be odd or else the even permutations would be a normal subgroup. Hence the isomorphism left is $A_n$.

### Elimination of the rest of the groups

Cases 56, 105, and 132 can be negated by looking at their factorizations

  - $56 = 7 \cdot 8$
  - $105 = 3 \cdot 5 \cdot 7 $
  - $132 = 2^2 \cdot 3 \cdot 11$

Look first at the modular relationship between these numbers

  - $8\equiv 1 \pmod{7}$
  - $15 \equiv 1 \pmod{7}$
  - $12 \equiv 1 \pmod{11}$ and $22 \equiv 1 \pmod{3}$

Initiate a contradiction by assuming that not any $p-\text{Sylow}$ group is not normal due to group simpleness, therefore not unique (In the examples above, the modulos are starring the contradiction).

Observe first that $|\text{Syl}_p(G)|=p$, then the intersection of two distinct $p-\text{Sylow}$ subgroups of that size has to divide $p$, obligating it to only be $1$. Therefore the amount of new elements that the union of all the $p-\text{Sylow}$ subgroups generate is $(p-1) m$ (Given that $|G| = pm$, $m$ is the only other number that follows the third Sylow theorem, and the intersection should only be trivial). On the other hand, if $|G| = p^km$, the union of two $p-\text{Sylow}$ subgroups $H,K$ must be $2p^k - |H\cap K|$. We can set a lower bound for $H\cap K$'s order using Lagrange's theorem to find the maximum strict divisor of the order of $K$ and $H$. We call it $d$, and the lower bound $L = 2p^k - d - 1$. 

Respectively, we notice that this logic leads to a count of distinct elements:
  - $(7-1)\cdot 8 + (16 - 4 - 1) + 1 = 60$ (plus one from the identity)
  - $(7-1)\cdot 15 + 4 \cdot 21 = 174$
  - $120 + 44 = 164$

All of those are far greater than the original count of elements of the groups. Therefore creating a contradiction.

This leaves only 72, 112, 120, and 144 now.


If $|G|=72=2^3 \cdot 3^2$, $1\equiv n_3 \pmod{3} \land n_3 \mid 8$. Only $4,1$ are valid, and accepting $4$ would imply a homomorphic $G$ to $S_4$, where if trivial, the isomorphism formed is invalid due to the distinct cardinalities, and if the homomorphism were trivial (or the kernel is total), then the Sylow groups would also be normal, but accepting an index $4$ implies they should not be normal. Hence there is a contradiction. 

If $|G| = 2^4 \cdot 7= 112$, by embedding theorem we have that there is an isomorphism to a subgroup of $A_7$, however $112\nmid 7!/2$, therefore it can't be equivalent to a subgroup of $A_7$. That is a contradiction.

If $120 = 2^3\cdot 3\cdot5 $, we let the index of sylow-5 groups be 6. Due to our contradiction assumption of non simpleness, then the group is embedded in $S_6$, but $S_5$ has the same cardinality as $G$, there is an isomorphism $G$ to $S_5$ by conjugation. $S_5$ has the normal subgroup $A_5$. 

If $144 = 2^4\cdot 3^2$, would lead us to an embedding (from the index of the 3 sylow) to $S_4$, but $S_4$ is order 24. Way lesser than the group it contains. Therefore there is a contradiction.

This finishes all proofs :).

## Make
As any good chef, I leave my recipes open to the world.

```
make all
```
Will throw many executables assuming you have `gcc`, `stdio.h`, `stdlib.h`, `math.h`, and can run makefiles.

### Flags
In the makefile, the variables

```
LATEXFLAG = 1
VALGRIND = 1
```

can be toggled, to deactivate latex output (and change to CVS output of the format $pq, p, q, p \text{ or } q$, with the last field depending on whether the found Sylow subgroup is a $p$ or a $q$ Sylow). And to deactivate the `-g` flag used in GCC for valgrind.
