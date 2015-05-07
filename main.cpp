/* Elizabeth Morrow
	May 2015
*/

#include "Object.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

void reportError(lua_State *L, int status)
{
	if (status != 0) {
		std::cerr << "-- " << lua_tostring(L, -1) << std::endl;
		lua_pop(L, 1);
	}
}

int main(int argc, char** argv) {
	for (int n = 1;n < argc;++n) {
		const char* file = argv[n];

		lua_State *L = luaL_newstate();
		luaL_openlibs(L);
		int s = luaL_loadfile(L, file);
		if (s == 0) {
			s = lua_pcall(L, 0, LUA_MULTRET, 0); // execute
		}
		reportError(L, s);
		lua_close(L);
	}

	// in case of debugging
	if (argc <2)
	{
		lua_State *L = luaL_newstate();
		luaL_openlibs(L);
		luaL_loadfile(L, "hello.lua");
		lua_pcall(L, 0, LUA_MULTRET, 0);
		lua_close(L);
	}

	system("PAUSE");
	return 0;
}