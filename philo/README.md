*This project has been created as part
of the 42 curriculum by leschunc.*

# Philosophers

## Description

**Philosophers** is an introduction to **parallelism**
we can task multiple **threads** to perform distinct actions while working in the same "space", that means that two threads can access and modify resources that are shared. To ensure safety, we must use **mutexes**, they act as a lock to certain parts of the code that are prone to **data races**: when a **write** (or modification) can happen while a **read** is also being performed.

Philosophers introduces us to problems that arise from **synchronization** or lack thereof:

- **Data races** happens when a shared resource is used simultaneously in an unsafe way (read, write at the same time).
- **Deadlocks** can arise from bad logic in routines, by waiting for resources circularly the threads can get stuck forever.
- **Performance** drops drastically with bad routine checks, emphasizing good synchronization techniques.

## Instructions

After running make from within the ./philo directory an executable file will be generated.

To run it, try the command by replacing the arguments with numbers in **miliseconds**:

``./philo  number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat``

Example `./philo 7 200 100 100`

The last argument is optional, when not used the simulation will run indefinitely or until one philosopher die.
 
 Eg.: `./philo 7 200 100 100 3`

## Resources

``man pthreads``
``man pthread_detach``
``man pthread_join``
``man pthread_mutex_init``
``man pthread_mutex_destroy``
``man pthread_mutex_lock``
``man pthread_mutex_unlock``

An LLM chat was widely used to ask about how these interact.

**Bonus**

- Look ``usleep(0)`` up.

**Challenge**

- This project never uses mutex_destroy and **will** be validated, find out why this works and doesn't leak system resources. Tip: search the files for malloc.