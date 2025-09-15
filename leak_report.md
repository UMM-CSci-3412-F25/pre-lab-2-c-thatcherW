# Leak report

## Memory Leaks
- In `check_whitespace.c`, there was one memory leak. This was caused by the `is_clean()` function, as it did not de-allocate the memory of the variable it got from `strip()`
- In `check_whitespace_test.cpp`, there were four leaks, each caused by the same issue. As `strip` is called directly in the tests here instead of in something else, the return variable never gets de-allocated. There was also a fifth leak introduced by a change I made to the if statement for empty string checking in `check_whitespace.c`

## Leak Fixes
- For `check_whitespace.c`, I simply called `free()` on the `cleaned` variable, and then set it to NULL
- For `check_whitespace_test.cpp`, I used the same fix for all of the leaks. I saved the result of `strip()` or `is_clean()` to a variable, and sent that into the test. After the test runs, I then call `free()` on `result`, and set it NULL

I know NULL setting is not required, but from what I found it seemed like it was good practice, so I decided to start the habit early.