class AInterface
{
public:
    virtual int test_function() = 0;
};
class AImplementation : AInterface
{
public:
    int test_function() override { return 5; };
};

int main()
{
    AImplementation test;
    return 0;
    /* code */
    // return test.test_function();
}
