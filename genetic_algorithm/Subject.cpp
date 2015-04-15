#include "Subject.h"

Subject::Subject() : gen()
{
}

Subject::Subject(const Subject &parentA, const Subject &parentB) : gen(parentA.gen, parentB.gen)
{
}
