/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Zeeno from Atlantis wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Zeeno from Atlantis
 * ----------------------------------------------------------------------------
 */

#pragma once
#ifndef _ZEENO_ACTIVE_MUTEX_HPP
#	define _ZEENO_ACTIVE_MUTEX_HPP

#	include <atomic>

namespace Zeeno {

class active_mutex {
	std::atomic_bool flag{true};

public:
	void lock() {
		while (!flag.exchange(false, std::memory_order_relaxed)) {
		}
		std::atomic_thread_fence(std::memory_order_acquire);
	}

	bool try_lock() {
		bool b = flag.exchange(false, std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);
		return b;
	}

	void unlock() {
		std::atomic_thread_fence(std::memory_order_release);
		flag.store(true, std::memory_order_relaxed);
	}
};

} // namespace Zeeno

#endif // _ZEENO_ACTIVE_MUTEX_HPP
