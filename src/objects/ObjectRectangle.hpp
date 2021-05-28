
#pragma once

#include "Object.hpp"
#include "../common/Size.hpp"

namespace PhysEn{
namespace Objects{

class ObjectRectangle : public Object{
	Size size;

public:
	ObjectRectangle(Maths::Vector pos, Size size);
	ObjectRectangle(Maths::Vector pos, Maths::Vector vel, Size size);
};

}
}