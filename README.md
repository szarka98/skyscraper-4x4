# skyscraper-4x4
display the solution to terminal on every set of valid views

# approach
- create all possible, valid maps (i.e. no repetition in any row or column), and use it as a *playbook*
- calculate all the values of each view for the valid maps (i.e. create an array of view-values for each map), and use it as a *dictionary* for *playbook*
- if you get a request with a set of views as an input, search for it in the *dictionary*, and get the related map from the *playbook*

# usage
`gcc skyscraper.c`                              // compile the code<br>
`./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"`     // run with any set of views
