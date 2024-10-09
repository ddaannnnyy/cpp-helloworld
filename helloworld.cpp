#include <iostream>
#include <vector>

// namespaces allow for the redeclaration of variables, see the std::cout for namespaces below
namespace first
{
    int a = 1;
}

namespace second
{
    int a = 2;
}

int main()
{
    // printing to the console
    std::cout << "Hello" << std::endl; // endl clears the buffer, but usually \n is fine
    std::cout << "World" << '\n';

    // data types
    int a = 10;
    double b = 1.99;
    char c = 'a';
    bool d = true;

    // string is not a base type, the std namespace provides it.
    std::string e = "Hello";

    // you can shortcut advanced types with a typedef, so instead of the built in pairlist from the vector namespace, we can just call it a pairlist_t
    // it's a naming convention to end custom type definitions with _t to stop conflicts with variables
    typedef std::vector<std::pair<std::string, int>> pairlist_t;
    // then...
    pairlist_t pairlist;
    // typedef is pretty oldschool, prefer to use `using` as it works better with templates
    using string_t = std::string;
    string_t hello = "world";
    std::cout << hello << '\n';

    // const are also available
    // const has a naming convention of the variable being all uppercase, multiword variables are snake case
    const double PI = 3.14159;
    const double LIGHT_SPEED = 299792458;

    // for variables with a namespace overload the default behaviour is locally scoped
    std::cout << a << '\n'; // 10;

    // you can also override the whole local block with a namespace
    // NOTE for this to work you'd have to declare the namespace at the top of the function
    using namespace first;
    std::cout << a << '\n'; // 1

    // to fetch a variable from a namespace WITHOUT overriding the whole local scope you prefix it with namespace:: e.g. std is a built in namespace
    // NOTE because c++ is an oldschool top down language you have to define the namespace BEFORE you can use it.
    std::cout << second::a << std::endl;

    // incrementation is normal
    int count = 0;
    count = count + 1; // count == 1
    count += 1;        // count == 2
    count++;           // count == 3
    count = count - 1; // count == 2
    count -= 1;        // count == 1
    count--;           // count == 0
    count = 2;         // count set at 2
    count *= 10;       // count == 20
    count /= 2;        // count == 10
    count /= 3;        // count == 3 ! remember it's an int so you'll lose decimals in division
    count %= 2;        // count == 1

    // type conversion
    // implicit
    int implicitDoubleToInt = 3.14;         // implicitDoubleToInt == 3
    double explicitDoubleToInt = (int)3.14; // explicitDoubleToInt == 3

    char implicitIntToChar = 100;   // std::cout << implicitIntToChar returns 'd' (ASCII lookup for decimal 100)
    std::cout << (char)100 << '\n'; // this also prints 'd'

    int correctAnswers = 8;
    int totalQuestions = 10;
    double score = correctAnswers / totalQuestions * 100;                // score = 0 because the initial division resulted in an int = 0.8, which was truncated to 0. Then 0 * 100 == 0;
    double correctScore = correctAnswers / (double)totalQuestions * 100; // correctScore = 80. I'm actually not sure why you don't have to cast both to doubles but hey free bytes.

    // successful return condition
    return 0;
}
