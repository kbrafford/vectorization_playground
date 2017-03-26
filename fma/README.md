## FMA - fused multiply-add

### Background
Floating point computations of the form:

```python
A = A * B + C
```

have to follow [IEEE-754](https://en.wikipedia.org/wiki/IEEE_floating_pointi "In-depth information about floating-point").  These rules include [specific rounding conventions](https://en.wikipedia.org/wiki/IEEE_floating_point#Rounding_rules) after each operation. Thus, our example form is actually implemented thusly:

```python
temp = round(A * B)
A = round(temp + C)
```

If one of the multiplicands of the first operation is a small number then the initial rounding step completely obliterates many valid bits, ruining the precision of the calculation.

The *Fused Multiply Add* suspends the normal rounding rule after the initial step.  All of the internal bits that were calculated in the multiply are kept around to be used in the addition operation.  Then the final result has correct IEEE-754 rounding applied.

### FMA

*Fused multiply-add* is not implemented in the x86 architecture as a normal floating-point operation.  Unfortunately it is only implemented in several flavors in various instruction set extenstions for [vector processing](https://en.wikipedia.org/wiki/Vector_processor). 

This mini-project only serves to expose the mathematical primitive to C and Go programs for the purpose of evaluating the mathematical merits of the FMA concept.

