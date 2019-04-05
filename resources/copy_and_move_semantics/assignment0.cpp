#include <iostream>
#include <memory>
#include <cassert>

class NullableNumber
{
    public:
        NullableNumber() = default;
        NullableNumber(int v): m_value(std::make_unique<int>(v))
        {
        }

        //TASK: implement copy constructor and move constructor here

        bool has_value() const
        {
            return m_value != nullptr;
        }
        int value() const
        {
            assert(m_value); //DISC: what does assert-style error handling mean?
            return *m_value;
        }
    private:
        std::unique_ptr<int> m_value;
};

int consumeToIntOrDefault(NullableNumber num, int default_value)
{
    if(num.has_value())
        return num.value();
    else
        return default_value;
}

int main()
{
    NullableNumber num1(5);

    std::cout << "num1 has value? " << num1.has_value() << "\n";
    std::cout << "num1 is " << num1.value() << "\n";

    NullableNumber num1_copy(num1); //DISC: what is another syntax of invoking the copy constructor here?

    std::cout << "num1_copy has value? " << num1_copy.has_value() << "\n";
    std::cout << "num1_copy is " << num1_copy.value() << "\n";

    int producedInt = -1; //TASK: replace the -1 with a call to consumeToIntOrDefault(..., 0); that properly uses moves to consume num1 and turn it into an integer value

    std::cout << "producedInt: " << producedInt << "\n";
    std::cout << "consumed num1 has value? " << num1.has_value() << "\n";
}
