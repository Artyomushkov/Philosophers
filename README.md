# Philosophers

In this project, I learned the basics of threading a process. I created threads and discovered mutexes.

The problem of dining philosophers was designed to illustrate the challenges of avoiding deadlock, a system state in which no progress is possible.

In Philo problem was decided with threads and mutexes, in philo_bonus forks and semaphors were used.

## Problem

One or more philosophers sit at a round table.

There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep.

While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.

• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.

• Every philosopher needs to eat and should never starve.

• Philosophers don’t speak with each other.

• Philosophers don’t know if another philosopher is about to die.

• No need to say that philosophers should avoid dying

## Usage

There are makefiles in both folders. You can easily compile programs with make.

Programs needs to take 4 or 5 arguments:

◦ number_of_philosophers: The number of philosophers and also the number
of forks.

◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

The program displays optimal actions of philosophers to avoid death:

◦ timestamp_in_ms X has taken a fork

◦ timestamp_in_ms X is eating

◦ timestamp_in_ms X is sleeping

◦ timestamp_in_ms X is thinking

◦ timestamp_in_ms X died

X - number of philosopher

As soon as one of philosophers dies, the program stops.
