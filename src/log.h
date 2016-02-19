#ifndef HK_LOG_H
#define HK_LOG_H

#include "core.h"

#define HK_INFO 1
#define HK_DEBUG 2
#define HK_WARN 3
#define HK_ERR 4
#define HK_FATAL 5

#define HK_RED "\033[22;31m"
#define HK_GREEN "\033[22;32m"
#define HK_YELLOW "\033[22;33m"
#define HK_BLUE "\033[22;34m"
#define HK_MAGENTA "\033[22;35m"
#define HK_CYAN "\033[22;36m"
#define HK_WHITE "\033[22;37m"
#define HK_RED_BOLD "\033[01;31m"
#define HK_GREEN_BOLD "\033[01;32m"
#define HK_YELLOW_BOLD "\033[01;33m"
#define HK_BLUE_BOLD "\033[01;34m"
#define HK_MAGENTA_BOLD "\033[01;35m"
#define HK_CYAN_BOLD "\033[01;36m"
#define HK_WHITE_BOLD "\033[01;37m"
#define HK_UNCOLOR "\033[22;0m"

#define hklog(...) hk_log(__FUNCTION__, __VA_ARGS__)
#define hklog_prefix(...) hk_log_prefix(__FUNCTION__, __VA_ARGS__)

#define hk_info(...) hklog(HK_INFO, __VA_ARGS__)
#define hk_debug(...) hklog(HK_DEBUG, __VA_ARGS__)
#define hk_warn(...) hklog(HK_WARN, __VA_ARGS__)
#define hk_err(...) hklog(HK_ERR, __VA_ARGS__)
#define hk_fatal(...) hklog(HK_FATAL, __VA_ARGS__); 

void hk_init(char* name);
void hk_log(const char *caller, int level, char *format, ...);
void hk_log_prefix(const char *caller, int level);

#endif /* !HK_LOG_H */
