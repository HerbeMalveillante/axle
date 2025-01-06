#ifndef AXLE_MAIN_H
#define AXLE_MAIN_H

#include "examples.h"
#include "window.h"
#include "shapes.h"
#include "color.h"
#include "vector2.h"

/**
 * @brief The main namespace of the Axle engine. All the features of the engine are contained within this namespace.
 */
namespace Axle
{
}

/**
 * @brief The Example namespace contains ports of the examples from the Raylib library.
 *
 * To run an example, simply call the corresponding function from this namespace :
 *
 *```cpp
 * #include <axle.h>
 * int main()
 * {
 *     Axle::Examples::basicWindow();
 *     return 0;
 * }
 *```
 *
 * @note The original examples can be found at https://www.raylib.com/examples.html
 */
namespace Axle::Examples
{
}

/**
 * @brief The Math namespace contains all the mathematical functions and classes used by the engine.
 */
namespace Axle::Math
{
}

#endif // AXLE_MAIN_H
