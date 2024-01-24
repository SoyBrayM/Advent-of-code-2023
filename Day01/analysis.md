# Day 1 Analysis

## General Thoughts

This being the first challenge, I didn't think about the structure in the solution.
Going forward i should implement a function for each part of the solution, something like:<br>

```
firstPartSolution(FILE *pInput) {
    // First part solution code goes here...
}

secondPartSolution(FILE *pInput) {
    // Second part solution code goes here...
}
```

And also extract into a function  from the solutions any part that is used in both parts of the challenge, so it's 
easier to understand the code intention and the full picture of the logic.

Also, now that I think about it, i should document my thoughts and analysis before coding, so for this day I wont,
because I'm writing this days after completing the challenge, but going forward I will be writing it.

## Code and logic analysis - Post completion

1.  The first thing i want to tackle is the ```replaceNumberNamesWithDigits``` function, I know that i only have to get
    the first number of the string, but, replacing every written number with it's corresponding digit has it's own
    challenge, since the name of some numbers start with the ending letter of other number, it's interesting to
    write the code to handle those cases, for example:

    In the case of the string "oneighthree", the resulting string should be "183".

    >The numbers '1', '3', '5', and '9', end with the letter 'e'. '8' starts with the letter e.<br>
    >The number '8' ends with the letter 't', '3' starts with the letter 't'.
    
    And this is only some of the cases, there are more, and even more if instead from being the numbers from one
    through nine, we take the numbers from 1 through 20, the cases in which things like this happens will only
    increase. So it's interesting to think about this kind of scenario.

-----------------------------------------------------------------------------------------------------------------

My solution to this was to check for the current character and increase the pointer address to check for the
following characters, and only decrease it if any of the previous characters were the starting characters of any
other number.

Altough I abused those switch statements to check for those cases, and even if I may (surely) have forgotten 
(already fogor :)) the thought proccess behind my decissions, the my solution was correct and, I think, it's good
enough.

I think there should be a smarter way to handle this cases, and if anyone who gets to read this knows how can
be handled, please let me know how. 

-----------------------------------------------------------------------------------------------------------------

2.  For how i did the rest of the code, I think it's okay, I'm still learning the know-hows of the language, but 
    I believe that what I wrote its good code, so i have no objections or special thought about it.
