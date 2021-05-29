#include "ObjectCircle.hpp"

namespace PhysEn{
namespace Objects{

// Constructors
ObjectCircle::ObjectCircle(Maths::Vector pos, float radius){
	position = std::move(pos);
	this->radius = radius;
}
ObjectCircle::ObjectCircle(Maths::Vector pos, Maths::Vector vel, float radius){
	position = std::move(pos);
	velocity = std::move(vel);
	this->radius = radius;
}

}
}