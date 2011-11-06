/*
 * injector.cpp
 *
 *  Created on: 02.11.2011
 *      Author: ich
 */


#include <iostream>
#include <windows.h>
#include <cstring>
#include "libDllLoader/loader.h"

using namespace std;

int usage(char* name) {
	cout << "Usage:" << endl;
	cout << name << " -i <processname> <dll>\t injects dll into processname" << endl;
	cout << name << " -ip <process pid> <dll>\t injects dll into process pid" << endl;
	cout << name << " -s <processname> <dll>\t starts process with dll" << endl;
	return -1;
}

int main(int argc, char * argv[]) {
	if (argc != 4) {
		return usage(argv[0]);
	}
	bool success = false;
	if (strcmp(argv[1], "-i") == 0) {
		success = inject_dll_into_processnameA(argv[2], argv[3]);
	}

	else if (strcmp(argv[1], "-ip") == 0) {
		success = inject_dll_into_processidA((DWORD) atoi(argv[2]), argv[3]);
	} else if (strcmp(argv[1], "-s") == 0) {
		//success = start_process_with_dllA(argv[2], NULL, NULL, argv[3]);
	} else {
		return usage(argv[0]);
	}

	if (success) {
		cout << "[+] DLL Loaded!" << endl;
	} else {
		cout << "[-] DLL Not Loaded!" << endl;
		return -2;
	}
	return 0;
}
