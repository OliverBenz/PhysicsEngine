#include "gtest/gtest.h"

#include "Physics/Optics.hpp"
#include "Maths/Vector.hpp"

namespace PhysEn {
namespace GTest {

TEST(Optics, Path){
	Maths::Vector light{2, 0.2};

	Optics::Lens lens;
	lens.n = 1.5;
	lens.r1 = 0.02;
	lens.r2 = -0.04;
	lens.w = 0.03;

	Maths::Matrix lensMatrix = Optics::GetLens(lens, 1, 1);

	/*
	Path path(0.25);
	light = path.update(light);
	EXPECT_NEAR(light[0], 34, 0.0001);
	EXPECT_NEAR(light[1], 34, 0.0001);
	 */
}

} // namespace GTest
} // namespace PhysEn