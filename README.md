# axle

A Lightweight, object-oriented C++ game development framework based on Raylib.

## Usage

1. Clone the Axle repository in the root of your project. You can also add it as a submodule.
2. Run the build script to initialize the build system :

   ```bash
   bash axle/axle.sh init
   ```

   The script will automatically download Raylib, create a CMakeLists.txt file in your project, and add a shortcut to this script in the root of your project. Any subsequent call to this script can now be done using the following command :

   ```bash
   ./axle.sh <args>
   ```

3. Create an entry point called `main.cpp` inside of a `src` directory :

   ```cpp
   // src/main.cpp

   #include <hello.h> // Include the axle library's header

   int main()
   {
      say_hello(); // Call the function from axle
      return 0;
   }
   ```

4. Build and run the project :

   ```bash
   ./axle.sh run
   ```

5. The project can also be built, without running it using the following command :

   ```bash
   ./axle.sh build
   ```

6. The project's build cache can be cleared by running the following command :

   ```bash
   ./axle.sh clean
   ```

7. Update the CMakeLists file to add other source files to your project.
