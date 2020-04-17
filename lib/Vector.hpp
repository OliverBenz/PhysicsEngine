#pragma once

#include <iostream>
   
struct Vector{
    float x;
    float y;
    float z;

    Vector();
    Vector(float x, float y, float z);

    // Betrag
    float getAmount();

    friend Vector operator +(Vector left, Vector right);
    friend Vector operator -(Vector left, Vector right);

    friend Vector operator *(float left, Vector right);
    friend Vector operator *(Vector left, float right);
    
    friend bool operator ==(Vector left, Vector right);
    friend std::ostream& operator << (std::ostream& os, Vector vec);
};