#include <stdatomic.h>

typedef struct
{
    atomic_flag locked;
} Mutex;

void mutex_init(Mutex* mutex)
{
    atomic_flag_clear(&mutex->locked);
}

void mutex_lock(Mutex* mutex)
{
    while (atomic_flag_test_and_set(&mutex->locked))
        ;  // spin until unlocked
}

void mutex_unlock(Mutex* mutex)
{
    atomic_flag_clear(&mutex->locked);
}

int main(void) {
    
    Mutex mtx;

    mutex_init(&mtx);
    mutex_lock(&mtx);
    mutex_unlock(&mtx);

    return 0;
}