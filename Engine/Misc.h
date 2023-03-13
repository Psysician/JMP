#pragma once


// ASSERT(e)
// Assert truthfulness
#define ASSERT(e) ((e) ? (void)0 : (assertion_exception_handler(__FILE__, __LINE__, __FUNCTION__) ? throw : (void)0))



// DEBUG_ASSERT(e)
// Assert truthfulness in debug mode only, discard e otherwise

// DEBUG_ASSERT_EVAL(e)
// Assert truthfulness in debug mode only, but still evaluate e

#ifdef NDEBUG
	#define DEBUG_ASSERT(e)
	#define DEBUG_ASSERT_EVAL(e) (e)
#else
	#define DEBUG_ASSERT(e) ASSERT(e)
	#define DEBUG_ASSERT_EVAL(e) ASSERT(e)
#endif

bool assertion_exception_handler(const char* file, unsigned int line, const char* func);
