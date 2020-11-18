# active_mutex

Header-only mutex library, it is very lightweight and performant, the price is busy waiting

Mutex with the ability to puth the thread into the sleep state is always a kernel-space call. Atomic variables on the other hand are only user-space structures. And in this era of all the CPU security bugs one of the method to mitigiate it is to flush the context before and after the kernel call. This means big performance hit. With this mutex being only user-space, the performance is marvelous. There is one limitation however, busy waiting.

With this mutex, you want your critical section to be as small as possible to prevent long busy waits.

# Usage

It satisfies the [Lockable](https://en.cppreference.com/w/cpp/named_req/Lockable) named requirement.

## Step 1

Use it instead of standard std::mutex

## Step 2

Buy me a beer if you want

# Keywords

 - C++11
 - Header-only
 - Can lock, unlock, try_lock, ...
 - Simple
 - Performance
 - Busy wait
