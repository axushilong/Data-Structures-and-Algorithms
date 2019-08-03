#include "stack/linkliststack/linkliststack.hpp"
#include <iostream>

/**
 * @function    依次将元素弹出栈，显示到控制台上。
 * @paras       kStack   栈
 * @return      none。
 */
template <typename T>
void ShowStack(LinkListStack<T> &kStack);

/**
 * @function    针对不同存储类型的栈，进行测试。
 * @paras       pdata       待测试的数组。
 *              kDatasize    数组大小。
 * @return      测试结果。
 */
template <typename T>
int TestStack(T *pdata, const size_t &kDatasize);

int main()
{
    std::cout << "int" << std::endl;
    int isum[10] = {1, 43, 4, 3, 2, 9, 35, 654, 65, 732};
    TestStack(isum, 10);

    std::cout << std::endl << "double" << std::endl;

    double dsum[7] = {1.62, 89.854, 42.0254, 57.9513, 726.8913, 71345, 5251.54};
    TestStack(dsum, 7);

    std::cout << std::endl << "string" << std::endl;

    std::string strsum[12] = {"a1", "1.62", "c1", "42.0254", "e1", "f1", "aa2", "bb2", "cc2", "dd2", "ee2", "ff2"};
    TestStack(strsum, 12);

    return 0;
}

template <typename T>
void ShowStack(LinkListStack<T> &kStack)
{
    T data;
    while (kStack.Pop(data) == 0)
    {
        std::cout << data << "、";
    }
    std::cout << std::endl;
}

template <typename T>
int TestStack(T *pdata, const size_t &kDatasize)
{
    LinkListStack<T> stack;
    if (stack.Create() != 0)
    {
        std::cout << "Create ArrayStack failed." << std::endl;
        return -1;
    }

    for (size_t i = 0; i < kDatasize; i++)
    {
        if (stack.Push(&pdata[i]) != 0)
        {
            std::cout << pdata[i] << " can't push stack." << std::endl;
        }
    }
    ShowStack(stack);
    return 0;
}