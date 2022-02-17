//*****************************************************************************
//
// Mickels Debug Header
// Written by: Devon Mickels
//
// A collection of useful debug tools to be used with any firmware set in C/C++.
//
//*****************************************************************************

#include "debug.h"
#include "Cpu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef ENABLE_DEBUG
int _head = 0;
char TRACKED_MSGS[TRACKED_MESSAGE_COUNT][TRACKED_MESSAGE_LENGTH];
char PRINT_TRACKED_MSG[TRACKED_MESSAGE_COUNT * TRACKED_MESSAGE_LENGTH + (TRACKED_MESSAGE_COUNT * 3)];

void DBG_INIT()
{
    strcpy(PRINT_TRACKED_MSG, "");
}

void DBG_FREE()
{
    free(TRACKED_MSGS);
    free(PRINT_TRACKED_MSG);
}

void DBG_RESET_TRACKED()
{
    int i = 0;
    for(i = 0; i < TRACKED_MESSAGE_COUNT; i++){
        strcpy(TRACKED_MSGS[i], "");
    }
}

void DBG_TRACK_FUNC(char *pcFilename, int lineNum)
{
    char temp[64];
    sprintf(temp, "%s: %d", pcFilename, lineNum);
    DBG_TRACK_MSG(temp);
}

void DBG_TRACK_MSG(char *str)
{
    strcpy(TRACKED_MSGS[_head], str);
    _head++;
    if(_head >= TRACKED_MESSAGE_COUNT)
        _head = 0;
}

void DBG_PRINT_TRACKED()
{
    strcpy(PRINT_TRACKED_MSG, "");
    int i = 0;
    for(i = 0; i < TRACKED_MESSAGE_COUNT; i++){
        if(strcmp(TRACKED_MSGS[i], "") != 0){
            strcat(PRINT_TRACKED_MSG, TRACKED_MSGS[i]);
            strcat(PRINT_TRACKED_MSG, "->");
        }
    }
    CLEANPRINT("\r\n" $TEXT_RED "[DBG DUMP] " $TEXT_RESET "%s \r\n\n", PRINT_TRACKED_MSG);
}
#endif
