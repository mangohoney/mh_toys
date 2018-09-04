#include <array>

int main()
{
    std::array<float, 10> a1 = {0};
    std::array<float, 10> a2 = 1.1 * a1;
    return 0;
}
