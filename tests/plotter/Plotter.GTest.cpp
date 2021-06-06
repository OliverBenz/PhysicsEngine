#include "gtest/gtest.h"

#include "../../src/plotter/Window.hpp"

TEST(Plotter, Simple){
	Window window(400, 200);
	window.Create();

	// TODO: Memory leak with window
	// Just temporarily show window for testing
	int temp = 999999;
	while(temp-- > 0){
		window.drawBackground();
	}
}