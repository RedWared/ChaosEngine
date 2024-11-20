#include <ChaosEngine/engine.hpp>
#include <xcb/xcb.h>
#include <unistd.h>

void Engine::CreateWin(string title, int x_pos, int y_pos, int width, int height){
	xcb_connection_t *conn = xcb_connect (NULL, NULL);
	xcb_screen_t *screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;
	xcb_window_t win = xcb_generate_id(conn);

	xcb_create_window(
		conn,
		XCB_COPY_FROM_PARENT,
		win,
		screen->root,
		x_pos, y_pos,
		width, height,
		10,
		XCB_WINDOW_CLASS_INPUT_OUTPUT,
		screen->root_visual,
		0, NULL
	);
	xcb_change_property(
		conn,
		XCB_PROP_MODE_REPLACE,
		win,
		XCB_ATOM_WM_NAME,
		XCB_ATOM_STRING,
		8,
		title.length(),
		title.c_str()
	);
	log("Creating window '"+title+"'");

	xcb_map_window(conn, win);
	xcb_flush(conn);

	pause();
	
	xcb_disconnect(conn);
}
