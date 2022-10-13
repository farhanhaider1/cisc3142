# Example 5

## ex 4.5

> **Determine the result of the FOLLOWING expressions.**

```
-30 * 3 + 21 / 5
//output: -90+4 = -86
```

```
-30 + 3 * 21 / 5
//output: -30+63/5 = -30+12 = -18
```

```
30 / 3 * 21 % 5
//output: 10*21%5 = 210%5 = 0
```

```
-30 / 3 * 21 % 4
//output: -10*21%4 = -210%4 = -2
```

## ex 4.17

> **Explain the difference between prefix and postfix increment.**

:o: `++i` will increment the value of i, and then return the incremented value. So basically it first increments then assigns a value to the expression.

:o: `i++` will increment the value of i, but return the original value that i held before being incremented. So basically it first assigns a value to expression and then increments the variable.

## ex 4.34

> **Given the variable definitions in this section, explain what conversions take place in the following expressions:
> (a) if (fval)
> (b) dval = fval + ival;
> (c) dval + ival \* cval;
> Remember that you may need to consider the associativity of the operators.**

```
if (fval) // fval is converted from float to boolean
```

```
dval = fval + ival; // ival from int to float, then result convert from float to double.
```

```
dval + ival * cval; // cval convert from char to int, then result convert from int to double.
```

## End
