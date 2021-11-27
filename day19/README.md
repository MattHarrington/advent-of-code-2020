# Advent of Code 2020
## Day 19

Solution to https://adventofcode.com/2020/day/19

Very slow performance, some due to `std::regex` but some due to my unoptimized
string manipulations.

Part two changes rules 8 and 11 to:

```
8: 42 | 42 8
11: 42 31 | 42 11 31
```

The new rule 8 is just like `+` in a regular expression. That was easy enough
to put into code.

I'm not sure how to express the new rule 11 as a regular expression. So, I
examined my problem's rules and saw I only needed to nest **42 31** 8 levels
deep. As the problem states:

> Remember, you only need to handle the rules you have; building a solution
> that could handle any hypothetical combination of rules would be
> significantly more difficult.
