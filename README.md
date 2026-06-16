# push_swap

> Sort a stack of integers using a limited set of stack operations — while keeping the number of operations as low as possible. A 42 school project.

---

## 🇬🇧 English

### Principle

`push_swap` is given a list of integers and must sort them in ascending order.
The catch: it can only use two stacks (`a` and `b`) and a **restricted set of
operations**. There is no random access — everything is done by swapping,
pushing and rotating stack tops. The challenge is not just *sorting*, but
sorting with **as few operations as possible**.

The program reads the integers from the command line, computes a valid sequence
of operations that sorts stack `a`, and prints that sequence to standard output
(one operation per line).

### Allowed operations

| Operation | Effect |
|-----------|--------|
| `sa` | swap the first two elements of stack `a` |
| `sb` | swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | push the top of `b` onto `a` |
| `pb` | push the top of `a` onto `b` |
| `ra` | rotate `a` up (first element becomes last) |
| `rb` | rotate `b` up |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate `a` (last element becomes first) |
| `rrb` | reverse rotate `b` |
| `rrr` | `rra` and `rrb` at the same time |

### Algorithm

This implementation uses a **cost-based greedy strategy** (the "Turk"
algorithm), not a fixed chunk/radix split. The data is held in a **linked-list
stack** where every node carries metadata (`index`, `push_cost`, `target_node`,
`above_median`, `cheapest`).

The flow (`srcs/algorithm/sorting.c`, `init_a_to_b.c`, `init_b_to_a.c`):

1. **Tiny cases first.** 2 elements → at most one `sa`; 3 elements → a dedicated
   `sort_three` that places the max and swaps if needed.
2. **Drain `a` into `b`.** The first couple of elements are pushed blindly, then
   for each remaining element the program:
   - computes each node's **target** in `b` (the closest smaller value, wrapping
     to the max when none is smaller),
   - computes a **push cost** = rotations needed in `a` + rotations needed in `b`
     (using the median to decide whether rotating up or down is cheaper),
   - selects the **cheapest** node and moves it, combining rotations with
     `rr`/`rrr` whenever both stacks rotate in the same direction.
3. **Sort the last 3** left in `a` with `sort_three`.
4. **Push everything back from `b` to `a`**, each time pre-rotating `a` so the
   element lands in the right place.
5. **Finish** by rotating the minimum value to the top so `a` is fully sorted.

The operation primitives live in `srcs/instructions/` (`swap.c`, `push.c`,
`rotate.c`, `reverse_rotate.c`), and each one prints its own name when it runs.

### Build & Run

The Makefile clones the author's own libft (`LIB_C`) and links against it, then
builds the `push_swap` binary.

```bash
make            # clone LIB_C, compile, produce ./push_swap
make re         # full rebuild
make fclean     # remove objects, binary and LIB_C
```

Run it by passing the integers either as separate arguments or as a single
quoted string:

```bash
./push_swap 3 2 5 1
# integers as separate arguments

./push_swap "4 2 1 3 8"
# arguments as one string also works
```

You can pipe the output into any standard 42 `checker` to validate the sequence:

```bash
ARG="4 2 1"; ./push_swap $ARG | ./checker $ARG
# prints OK if the operations sort the stack, KO otherwise
```

> Note: this repository contains only the mandatory `push_swap` part — there is
> no `checker` in the Makefile. Use the official 42 `checker_OS` (or a bonus
> checker) for validation.

Invalid input (non-numeric tokens, values outside `INT_MIN..INT_MAX`,
duplicates, empty arguments) makes the program print `Error` and exit.

### What I learned

- **Sorting algorithms** under hard constraints, and how a cost-driven greedy
  approach beats naive selection sort on operation count.
- **Algorithmic complexity** and measuring efficiency by operation count rather
  than wall-clock time.
- **Stack / linked-list data structures**, augmenting nodes with metadata to
  drive decisions.
- **Optimizing the number of operations** by merging simultaneous rotations
  (`rr`, `rrr`) and choosing the cheapest move each step.
- **Input parsing and validation** in C: tokenizing, overflow checks, duplicate
  detection and clean error handling without leaks.

---

## 🇫🇷 Français

### Principe

`push_swap` reçoit une liste d'entiers et doit les trier en ordre croissant.
La contrainte : on ne dispose que de deux piles (`a` et `b`) et d'un **jeu
d'opérations limité**. Pas d'accès direct — tout se fait en échangeant, poussant
et faisant tourner les sommets des piles. Le défi n'est pas seulement de *trier*,
mais de trier avec **le moins d'opérations possible**.

Le programme lit les entiers depuis la ligne de commande, calcule une séquence
d'opérations valide qui trie la pile `a`, puis affiche cette séquence sur la
sortie standard (une opération par ligne).

### Opérations autorisées

| Opération | Effet |
|-----------|-------|
| `sa` | échange les deux premiers éléments de la pile `a` |
| `sb` | échange les deux premiers éléments de la pile `b` |
| `ss` | `sa` et `sb` en même temps |
| `pa` | dépile le sommet de `b` vers `a` |
| `pb` | dépile le sommet de `a` vers `b` |
| `ra` | rotation de `a` vers le haut (le premier devient dernier) |
| `rb` | rotation de `b` vers le haut |
| `rr` | `ra` et `rb` en même temps |
| `rra` | rotation inverse de `a` (le dernier devient premier) |
| `rrb` | rotation inverse de `b` |
| `rrr` | `rra` et `rrb` en même temps |

### Algorithme

Cette implémentation repose sur une **stratégie gloutonne basée sur le coût**
(l'algorithme « Turk »), et non sur un découpage fixe en chunks/radix. Les
données sont stockées dans une **liste chaînée de piles** où chaque nœud porte
ses métadonnées (`index`, `push_cost`, `target_node`, `above_median`,
`cheapest`).

Le déroulement (`srcs/algorithm/sorting.c`, `init_a_to_b.c`, `init_b_to_a.c`) :

1. **Petits cas d'abord.** 2 éléments → au plus un `sa` ; 3 éléments → un
   `sort_three` dédié qui place le maximum puis échange si besoin.
2. **Vider `a` vers `b`.** Les deux premiers éléments sont poussés directement,
   puis pour chaque élément restant le programme :
   - calcule la **cible** de chaque nœud dans `b` (la plus grande valeur
     inférieure, en bouclant vers le max s'il n'y en a pas),
   - calcule un **coût de push** = rotations nécessaires dans `a` + rotations
     dans `b` (en utilisant la médiane pour choisir la rotation la moins chère),
   - sélectionne le nœud le **moins cher** et le déplace, en combinant les
     rotations avec `rr`/`rrr` quand les deux piles tournent dans le même sens.
3. **Trier les 3 derniers** éléments de `a` avec `sort_three`.
4. **Tout repousser de `b` vers `a`**, en pré-tournant `a` à chaque fois pour
   que l'élément arrive au bon endroit.
5. **Terminer** en ramenant le minimum au sommet pour que `a` soit trié.

Les primitives d'opérations se trouvent dans `srcs/instructions/` (`swap.c`,
`push.c`, `rotate.c`, `reverse_rotate.c`) ; chacune affiche son propre nom à
l'exécution.

### Compilation & Lancement

Le Makefile clone le libft maison de l'auteur (`LIB_C`), le lie au projet, puis
construit le binaire `push_swap`.

```bash
make            # clone LIB_C, compile, produit ./push_swap
make re         # recompilation complète
make fclean     # supprime objets, binaire et LIB_C
```

On lance le programme en passant les entiers soit en arguments séparés, soit en
une seule chaîne entre guillemets :

```bash
./push_swap 3 2 5 1
# entiers en arguments séparés

./push_swap "4 2 1 3 8"
# les arguments en une seule chaîne fonctionnent aussi
```

On peut rediriger la sortie vers n'importe quel `checker` standard de 42 pour
valider la séquence :

```bash
ARG="4 2 1"; ./push_swap $ARG | ./checker $ARG
# affiche OK si les opérations trient la pile, KO sinon
```

> Note : ce dépôt ne contient que la partie obligatoire `push_swap` — il n'y a
> pas de `checker` dans le Makefile. Utilisez le `checker_OS` officiel de 42 (ou
> un checker bonus) pour la validation.

Une entrée invalide (jeton non numérique, valeur hors `INT_MIN..INT_MAX`,
doublon, argument vide) fait afficher `Error` et termine le programme.

### Ce que ça m'a apporté

- Les **algorithmes de tri** sous fortes contraintes, et comment une approche
  gloutonne pilotée par le coût bat un tri par sélection naïf en nombre
  d'opérations.
- La **complexité algorithmique** et la mesure de l'efficacité par le nombre
  d'opérations plutôt que par le temps d'exécution.
- Les **structures de pile / liste chaînée**, enrichies de métadonnées pour
  guider les décisions.
- L'**optimisation du nombre d'opérations** en fusionnant les rotations
  simultanées (`rr`, `rrr`) et en choisissant le mouvement le moins coûteux.
- Le **parsing et la validation d'entrée** en C : découpage, contrôle de
  débordement, détection des doublons et gestion propre des erreurs sans fuites.
