# naive-mutex-implementation-c
Naive mutex implementation in C (Linux)

Here's a naive example of implementing a simple mutex, but please be aware that it's far from being perfect, doesn't perform well, and is prone to many problems (like priority inversion and thread starvation). It's provided merely for educational purposes and should not be used in any serious or production code. This simple spinlock-style mutex uses atomic compare-and-swap (CAS) operations.

In this code:

 - The `Mutex` struct contains an atomic flag locked that indicates whether the mutex is locked or not.
 - `mutex_init` initializes the mutex to an unlocked state.
 - `mutex_lock` sets the flag to true (locked state). If it was already true, `atomic_flag_test_and_set` returns true and the function spins in a loop until it can set the flag.
 - `mutex_unlock` sets the flag to false (unlocked state).