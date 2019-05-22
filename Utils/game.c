#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

void KeyboardEventProcess(int key,int event){
 	
    switch (event) {
	 	case KEY_DOWN:
			switch (key) {
			    case VK_UP:

                    break;
			    case VK_DOWN:

                    break;
			    case VK_LEFT:

                    break;
			    case VK_RIGHT:

                    break;
			}
			break;
		case KEY_UP:
			break;
	 }	 
}
