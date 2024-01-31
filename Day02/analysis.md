# Day 2

## Pre-coding analysis - Part 1

This first part doesn't seems to be hard, the first thing that comes to my mind to solve this is a struct, maybe
because I recently learned what a struct is, but I think it's a good idea, since every game will store it's own
information.

To determine if a game is possible or not, the values that track the amount of red, green, and blue cubes will only
contain the greatest amount that was revealed in a set.

So, the logic will go like this:

-   Get the number of the game
-   For each set (which is delimited with a semicolon) and for each color
    -   Get the cube count of the respective color
    -   Check for the stored values of the game
    -   If the stored value is smaller than the current draft count, update the stored value with the current draft
        count.
    -   Continue with the next color.
-   Check for the stored values. 
-   If any of the cube counts exceeds the given limit, mark the game as impossible.

I'm a little bit lost on how to implement the solution since, for me, working with strings in C isn't straightforward,
so I don't have the minimum idea on how to divide the sets, and less on how to get the cube count and get it's color,
but solving this will help me to get more comfortable with the language.

<div dir="rtl">

_Written at Jan 24, 2024_

</div>

## Post-coding analysis - Part 1

Writting the code to parse the input was fun, I had to search the `strings.h` library and find the functions that
worked for the case, finding about `sscanf` and `strncmp` was just what I needed to parse most of the input,
has been some days since I solved the first part and, in retrospective, the solution I came up with leaves me satified,
there are some things I should change, like setting some constants for the maximum number of cubes for each
color, or improving how much the line buffer pointer should skip ahead to reduce innecesary checks, but for now
since it works, I'll let it be.

<div dir="rtl">

_Written at Jan 30, 2024_

</div>

---

## Pre-coding analysis - Part 2

So for this part I have to take the minimum amount of cubes of each colour, multiply them, and sum the product.
Knowing this makes me happy of my decision to store the game data, because I already have the minimum
amount of cubes for the game to be possible, so I just need to multiply these values.

Now, the challenge in this case comes from my own impositions, since I want to have in diferent funcitons each
of the solutions. So the cuestion becomes, how can I solve both problems, having them in different functions,
but only process the whole file one time, I could just copy the first solution code to the second solution, but that
feels like cheating in my case.

My first idea is to extract the parsing process into it's own function, since both parts need the parsed data,
change it so it parses only the current game, and pass to the function of each part the game data, then each
function will return the desired value after processing the game data, and then it's added to the corresponding
part solution.

<div dir="rtl">

_Written at Jan 30, 2024_

</div>

## Post-coding analysis - Part 2

The first barrier I encountered was reformatting the input parser, after a few changes I was getting, you guessed
it, a lot of segmentation faults, so I had to rewrite the parser, luckily that was exactly what I wanted, just so I
could use more of the `string.h` library, understand a little bit more the algorithm that I used to parse the data
and check for some obvious optimisations.

What I encountered next was... Kind of bad.

The way that I stored the amount of cubes at each game wasn't what I thought. What happened, I think, was that
when checking the current set for the number of drawn cubes, and deciding if the (current) amount is greater
or less than the already stored values in the game, I got the logic wrong and stored the maximum value instead
of the minimum amount, and when checking if the game was possible I just flip-flopped the `<` and `>` symbols
to get the answer, since I already had the values to check. And when I encountered with the second part, I
thought that the stored values were the minimum.

So after facing the asumptions of the past me and the error of not checking if the values I get are the values I
expect, I think that from this puzzle I learned a decent amount of C, and not only that, I learned about where and
what I should improve, and what I think and do.

<div dir="rtl">

_Written at Jan 31, 2024_

</div>
