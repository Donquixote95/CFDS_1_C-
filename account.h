/*
The Account class is an abstract superclass with the default
characteristics of a bank account. It maintains a balance and a current
number of transactions. It does not have a full implementation of
EndMonth() behavior which should be filled in by its subclasses.
*/

class Account {
    public:
        Account(void);
        virtual void Withdraw (float amt);
        virtual void Deposit (float amt);
        virtual float GetBalance(void);
        virtual void Endmonth(void) = 0;
        
    protected:
        float balance;
        int transactions;
        void EndMonthUtil(void);

    // Class Function
    public:
        static void TestOneMonth(void);
};