#pragma once

struct IRefCount
{
    virtual void AddRef() = 0;
    virtual void Release() = 0;

    virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
    virtual int Add(int a, int b) = 0;
    virtual int Sub(int a, int b) = 0;
    virtual ~ICalc() {}
};

struct IMotorServerProxy : public IRefCount
{
    // 모터서버용 Proxy 함수
};

ICalc* load_proxy()
{
    // #1. DLL 을 load 한다. (Linux에서는 dlopen(), Windows에서는 LoadLibrary() 사용)
    void* addr = ec_load_module("CalcProxy.dll");

    // #2. DLL 에서 약속된 함수("create")를 찾는다. (Linux에서는 dlsym(), Windows에서는 GetProcAddress() 사용)
    using FP = ICalc * (*)(); // 함수 포인터 타입 문법 = typedef ICalc*(*FP)()
    FP f = (FP)ec_get_function_address(addr, "create");

    // #3. 약속된 함수를 호출해서 Proxy를 생성해서 반환
    return f(); // DLL 내부에서 new Calc;
}