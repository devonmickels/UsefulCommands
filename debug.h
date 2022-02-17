//*****************************************************************************
//
// Mickels Debug Header
// Written by: Devon Mickels
//
// A collection of useful debug tools to be used with any firmware set in C/C++.
//
//*****************************************************************************

#ifndef _MICKELS_DEBUG_HEADER_
#define _MICKELS_DEBUG_HEADER_

//Written by Devon Mickels
//Custom Debug messages for colorized console using PuTTY.

#include "ansi.h"
#include <string.h>

//Comment out to disable all debug messages / sources
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#define DBGPRINT(w,...) UARTprintf ("\r" $TEXT_YELLOW "[DEBUG]" $TEXT_RESET $TEXT_UNBOLD " " w "\r\n", ##__VA_ARGS__)
#define CLEANPRINT(w,...) UARTprintf (w, ##__VA_ARGS__)
#define DBGVAR(w) UARTprintf("\r" $TEXT_YELLOW "[DEBUG]" $TEXT_RESET " " #w ": " $TEXT_BOLD "%d" $TEXT_UNBOLD "\r\n", w)
#define DBGVARF(w, format) UARTprintf("\r" $TEXT_YELLOW "[DEBUG]" $TEXT_RESET " " #w ": %" #format "\r\n", w)

#define INFOPRINT(w,...) UARTprintf ("\r" $TEXT_GREEN "[INFO]" $TEXT_RESET " " w "\r\n", ##__VA_ARGS__)
#define WARNPRINT(w,...) UARTprintf ("\r" $BACKGROUND_WHITE $TEXT_RED "[WARNING]" $TEXT_RESET " " w "\r\n", ##__VA_ARGS__)

#define DBG_ENTER_FUNC() DBG_TRACK_FUNC(__FILE__, __LINE__)
#define DBG_TRACK_IF(expr)   do                                                       \
                             {                                                        \
                                 if((expr))                                          \
                                 {                                                    \
                                     DBG_ENTER_FUNC();                                \
                                 }                                                    \
                             }                                                        \
                             while(0)
#else
#define DBGPRINT(w,...)     //Debug Function Stripped. Re-enable in debug.h
#define CLEANPRINT(w,...)   //Debug Function Stripped. Re-enable in debug.h
#define DBGVAR(w)           //Debug Function Stripped. Re-enable in debug.h
#define DBGVARF(w, format)  //Debug Function Stripped. Re-enable in debug.h

#define INFOPRINT(w,...)    //Debug Function Stripped. Re-enable in debug.h
#define WARNPRINT(w,...)    //Debug Function Stripped. Re-enable in debug.h

#define DBG_ENTER_FUNC()    //Debug Function Stripped. Re-enable in debug.h
#define DBG_TRACK_IF()      //Debug Function Stripped. Re-enable in debug.h
#endif

#define TRACKED_MESSAGE_COUNT 8
#define TRACKED_MESSAGE_LENGTH 64

void DBG_INIT();

void DBG_FREE();

void DBG_RESET_TRACKED();

void DBG_TRACK_FUNC(char *pcFilename, int lineNum);

void DBG_TRACK_MSG(char *str);

void DBG_PRINT_TRACKED();

#endif
