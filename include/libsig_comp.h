#ifndef __LIBSIG_COMP_H
#define __LIBSIG_COMP_H

#include <sigc++/sigc++.h>
#include <sigc++/bind.h>

#ifdef SIGC_CXX_NAMESPACES
using namespace SigC;
#endif

#ifdef ENABLE_SIGC2

//wrap sigc++2.0 for sigc++1.2
typedef sigc::trackable Object;
typedef sigc::connection Connection;
template<class R> using Signal0 = sigc::signal<R>;
template<class R, typename A1> using Signal1 = sigc::signal<R, A1>;
template<class R, typename A1, typename A2> using Signal2 = sigc::signal<R, A1, A2>;
template<class R, typename A1, typename A2, typename A3> using Signal3 = sigc::signal<R, A1, A2, A3>;
template<class R, typename A1, typename A2, typename A3, typename A4> using Signal4 = sigc::signal<R, A1, A2, A3, A4>;
template<class R> using Slot0 = sigc::slot<R>;
template<class R, typename A1> using Slot1 = sigc::slot<R, A1>;
template<class R, typename A1, typename A2> using Slot2 = sigc::slot<R, A1, A2>;

template<class T_return >
inline Slot0<T_return> slot (T_return(*  _A_func))
    {
      return sigc::ptr_fun(_A_func);
    }
template<class T_return, class T_obj1, class T_obj2>
inline Slot0<T_return>  slot (T_obj1& _A_obj, T_return(T_obj2::* _A_func)())
    {
      return sigc::mem_fun(_A_obj, _A_func);
    }
template<class T_return, class T_obj>
inline Slot0<T_return> slot (T_return(T_obj::* _A_func)())
    {
      return sigc::mem_fun(_A_func);
    }

template<class T_return, class T_arg1>
inline Slot1<T_return, T_arg1> slot (T_return(*  _A_func)(T_arg1))
    {
      return sigc::ptr_fun(_A_func);
    }
template<class T_return, class T_obj, class T_arg1>
inline Slot1<T_return, T_arg1> slot (T_return(T_obj::* _A_func)(T_arg1))
    {
      return sigc::mem_fun(_A_func);
    }
template<class T_return, class T_arg1, class T_obj1, class T_obj2>
inline Slot1<T_return, T_arg1>  slot (T_obj1& _A_obj, T_return(T_obj2::* _A_func)(T_arg1))
    {
      return sigc::mem_fun(_A_obj, _A_func);
    }

template<class T_return, class T_arg1, class T_arg2>
inline Slot2<T_return, T_arg1, T_arg2> slot (T_return(*  _A_func)(T_arg1, T_arg2))
    {
      return sigc::ptr_fun(_A_func);
    }
template<class T_return, class T_obj, class T_arg1, class T_arg2>
inline Slot2<T_return, T_arg1, T_arg2> slot (T_return(T_obj::* _A_func)(T_arg1, T_arg2))
    {
      return sigc::mem_fun(_A_func);
    }
template<class T_return, class T_arg1, class T_arg2, class T_obj1, class T_obj2>
inline Slot2<T_return, T_arg1, T_arg2>  slot (T_obj1& _A_obj, T_return(T_obj2::* _A_func)(T_arg1, T_arg2))
    {
      return sigc::mem_fun(_A_obj, _A_func);
    }
#define CONNECT(SENDER, EMPFAENGER) SENDER.connect(sigc::mem_fun(*this, &EMPFAENGER))
#else
#define CONNECT(SENDER, EMPFAENGER) SENDER.connect(slot(*this, &EMPFAENGER))
// use this Makro to connect with a method
// void bla::foo(int x);
// to an
// Signal<void, int> testSig;
//
// CONNECT(testSig, bla::foo);
// signal and method (slot) must have the same signature
#endif //SIGC2

#define CONNECT_1_0(SENDER, EMPFAENGER, PARAM) SENDER.connect( bind( slot(*this, &EMPFAENGER) ,PARAM ) )
// use this for connect with a method
// void bla::foo(int);
// to an
// Signal0<void> testSig;
// CONNECT_1_0(testSig, bla:foo, 0);
// here the signal has no parameter, but the slot have an int
// the last parameter of the CONNECT_1_0 makro is the value that given to the paramater of the Slot method

#define CONNECT_2_0(SENDER, EMPFAENGER, PARAM1, PARAM2) SENDER.connect( bind( slot(*this, &EMPFAENGER) ,PARAM1, PARAM2 ) )

#define CONNECT_2_1(SENDER, EMPFAENGER, PARAM) SENDER.connect( bind( slot(*this, &EMPFAENGER) ,PARAM ) )

#endif // __LIBSIG_COMP_H
