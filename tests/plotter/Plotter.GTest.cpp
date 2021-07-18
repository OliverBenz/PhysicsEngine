#include "gtest/gtest.h"

#include "Plotter/Window.hpp"

namespace PhysEn {
namespace GTest {

TEST(Plotter, Simple){
	Plotter::Window window(400, 200);
	window.Create();

	// TODO: Memory leak with window
	// Just temporarily show window for testing
	int temp = 999999;
	while(temp-- > 0){
		window.drawBackground();
	}
}

} // namespace GTest
} // namespace PhysEn
