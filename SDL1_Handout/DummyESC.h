#ifndef __DUMMYESC_H__
#define __DUMMYESC_H__

#include "Module.h"
#include "Globals.h"
#include <conio.h>

class DummyESC : public Module
{
	bool Init()
	{
		LOG("Dummy Init!");
		return true;
	}

	update_status PreUpdate()
	{
		int ch;

		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) {
				LOG("USER PRESSED ESCAPE! UPDATE_STOP INTENSIFIES!!!!!!");
				return update_status::UPDATE_STOP;
			}
		}
		LOG("Dummy PreUpdate!");
		return update_status::UPDATE_CONTINUE;
	}

	update_status Update()
	{
		LOG("Dummy Update!");
		return update_status::UPDATE_CONTINUE;
	}

	update_status PostUpdate()
	{
		LOG("Dummy PostUpdate!");
		return update_status::UPDATE_CONTINUE;
	}

	bool CleanUp()
	{
		LOG("Dummy CleanUp!");
		delete this;
		return true;
	}
};

#endif // __DUMMYESC_H__