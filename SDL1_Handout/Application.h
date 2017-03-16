#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "Dummy.h"
#include "DummyESC.h"

#define NUM_MODULES 1

class Application
{
public:

	Module* modules[NUM_MODULES];

public:

	Application()
	{
		modules[0] = new DummyESC();
		// TODO 7: Create your new module "DummyESC"
		// it should check if player hit ESC key use kbhit()
		// http://www.cprogramming.com/fod/kbhit.html
	}

	// TODO 5: Make sure that if Init() / PreUpdate/Update/PostUpdate/CleanUP return
	// an exit code App exits correctly.

	// INIT all modules
	bool Init() 
	{
		for (int i = 0; i < NUM_MODULES; ++i) {
			if (!modules[i]->Init())
				return false;
		}
		return true; 
	}

	// TODO 4: Add PreUpdate and PostUpdate calls

	// UPDATE all modules
	// TODO 2: Make sure all modules receive its update
	update_status Update() {

		update_status status;
		for (int i = 0; i < NUM_MODULES; i++)
		{
			status = modules[i]->PreUpdate();
			if (status != UPDATE_CONTINUE)
				break;
			status = modules[i]->Update();
			if (status != UPDATE_CONTINUE)
				break;
			status = modules[i]->PostUpdate();
			if (status != UPDATE_CONTINUE)
				break;
		}
		return status;
	}

	// EXIT Update 
	// TODO 3: Make sure all modules have a chance to cleanup
	bool CleanUp()
	{
		for (int i = NUM_MODULES - 1; i >= 0; i--)
		{
			if (!modules[i]->CleanUp())
				return false;
		}
		return true;
	}

};

#endif // __APPLICATION_H__