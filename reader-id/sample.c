/*
 * Copyright (C) 2011, Digital Persona, Inc.
 *
 * This file is a part of sample code for the UareU SDK 2.x.
 */

#include "helpers.h"
#include "menu.h"
#include "selection.h"
#include "enrollment.h"

#include <dpfpdd.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <locale.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main

int main(int argc, char** argv){
	//block all signals, SIGINT will be unblocked and handled in CaptureFinger()
	sigset_t sigmask;
	sigfillset(&sigmask);
	pthread_sigmask(SIG_BLOCK, &sigmask, NULL);

	setlocale(LC_ALL, "");

	//initialize capture library
	int result = dpfpdd_init();
	if(DPFPDD_SUCCESS != result) print_error("dpfpdd_init()", result);
	else{
		DPFPDD_DEV hReader = NULL; //handle of the selected reader
		char szReader[MAX_DEVICE_NAME_LENGTH]; //name of the selected reader

		hReader = SelectAndOpenReader(szReader, sizeof(szReader));
		Enrollment(hReader);

		//close reader
		if(NULL != hReader){
			result = dpfpdd_close(hReader);
			if(DPFPDD_SUCCESS != result) print_error("dpfpdd_close()", result);
			hReader = NULL;
		}

		//relese capture library
		dpfpdd_exit();
	}

	return 0;
}
