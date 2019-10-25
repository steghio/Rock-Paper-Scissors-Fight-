# Rock! Paper! Scissors! Fight!

This C++ exercise implements a full game of Rock, Paper, Scissors against an AI opponent.

## Round input

You must first insert the desired number of rounds, which must be an odd number and at least one.
If you win (or lose) at least `round / 2 + 1` rounds, the game ends with a clear winner (or loser).

## Move input

The game allows three moves:

- `R` or `r`: ROCK - wins over SCISSORS
- `P` or `p`: PAPER - wins over ROCK
- `S` or `s`: SCISSORS - wins over PAPER

## Input validation

Input is validate so any wrong value will result in an error message and a request to reenter it.

## Game round

The AI is initialized with [random](http://www.cplusplus.com/reference/random/) and will each round pick one of the three available moves.

If your move is the winning one, you get a point, otherwise the AI gets a point.
If you choose the same move, the round is a draw and must be played again.

When either you or the AI reaches the victory limit, the game ends even if there are rounds left.
