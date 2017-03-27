## FMA - fused multiply-add

### Background
Floating point computations of the form:

```python
A = A * B + C
```

have to follow [IEEE-754](https://en.wikipedia.org/wiki/IEEE_floating_point "In-depth information about floating-point").  These rules include [specific rounding conventions](https://en.wikipedia.org/wiki/IEEE_floating_point#Rounding_rules) after each operation. Our example form is actually implemented thusly:

```python
temp = round(A * B)
A = round(temp + C)
```

If one of the multiplicands of the first operation is a small number then the initial rounding step completely obliterates many valid bits, ruining the precision of the calculation.

The *Fused Multiply Add* suspends the normal rounding rule after the initial step.  All of the internal bits that were calculated in the multiply are kept around to be used in the addition operation.  Then the final result has correct IEEE-754 rounding applied.

### FMA

*Fused multiply-add* is not implemented in the x86 architecture as a normal floating-point operation.  Unfortunately it is only implemented in several flavors in various instruction set extenstions for [vector processing](https://en.wikipedia.org/wiki/Vector_processor). 

Here is a good discussion of the real usage of the FMA instructions: http://stackoverflow.com/questions/13292013/is-there-any-scenario-where-function-fma-in-libc-can-be-used

This mini-project only serves to expose the mathematical primitive to [C](https://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0131103628/ref=sr_1_1?ie=UTF8&qid=1490511096&sr=8-1&keywords=the+c+programming+language) and [Go](https://www.amazon.com/Programming-Language-Addison-Wesley-Professional-Computing/dp/0134190440/ref=sr_1_1?ie=UTF8&qid=1490511148&sr=8-1&keywords=the+go+programming+language) programs for the purpose of evaluating the mathematical merits of the FMA concept.

