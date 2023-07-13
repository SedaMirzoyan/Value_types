
#include <iostream>

class A {
    std::string m_str;

public:
    A()
    {
        std::cout << __func__ << std::endl;
    }

    A(const std::string& s) :m_str(s)
    {
        std::cout << __func__ << std::endl;
    }

    A(const A& ob)
    {
        std::cout << "copy " << __func__ << std::endl;

        m_str = ob.m_str;
    }

    A& operator=(const A& ob)
    {
        std::cout << "operator " << __func__ << std::endl;

        if (this != &ob)
        {
            m_str = ob.m_str;
        }
        return *this;
    }

    ~A()
    {
        std::cout << __func__ << std::endl;
    }

public:

    std::string getStrLvalue()
    {
        return m_str;
    }

    std::string getStrRvalue()
    {
        return "rvalue type";
    }

    //functions

    void print(A ob)
    {
        std::cout << "rvalue: " << ob.getStrRvalue() << std::endl;
    }

    void print(std::string l)
    {
        std::cout << "lvalue: " << l << std::endl;
    }

    void print(A &ob, std::string& lr)
    {
        std::cout << "lvalue reference: " << lr << std::endl;
    }


    void print(A ob, std::string&& rf)
    {
        std::cout << "rvalue reference: " << rf << std::endl;
    }

    void print(const A& ob, const std::string& clr) const
    {
        std::cout << "const lvalue reference: " <<  std::endl;
    }

    void print(const A&& ob)const
    {
        std::cout << "const rvalue reference: " << std::endl;
    }

};


int main()
{
    //lvalue ref
    std::string str = "Sun is shining";
    std::string& lr = str;

    A ob;
    ob.print(ob, lr);

    //rvalue
    A ob1("ola");
    ob1.print(ob1);

    //lvalue
    A ob2;
    ob2.print(str);

    //rvalue ref
    std::string str1 = "Birds are singing";
    ob.print(ob, std::move(str1));

    //const lvalue ref
    const std::string cs = "Sky is blue";
    const std::string& csr = cs;

    const A ob4(cs);
    const A& ob_ref = ob4;

    ob_ref.print(ob_ref, csr);

    //const rvalue ref
    const A ob3;
    ob3.print(A());
  
    return 0;
}

