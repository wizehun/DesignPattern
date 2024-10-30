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
    // ���ͼ����� Proxy �Լ�
};

ICalc* load_proxy()
{
    // #1. DLL �� load �Ѵ�. (Linux������ dlopen(), Windows������ LoadLibrary() ���)
    void* addr = ec_load_module("CalcProxy.dll");

    // #2. DLL ���� ��ӵ� �Լ�("create")�� ã�´�. (Linux������ dlsym(), Windows������ GetProcAddress() ���)
    using FP = ICalc * (*)(); // �Լ� ������ Ÿ�� ���� = typedef ICalc*(*FP)()
    FP f = (FP)ec_get_function_address(addr, "create");

    // #3. ��ӵ� �Լ��� ȣ���ؼ� Proxy�� �����ؼ� ��ȯ
    return f(); // DLL ���ο��� new Calc;
}