#include <gtest/gtest.h>

#include <Account.h>
#include <Transaction.h>

TEST(ACCOUUNT, All)
{
    Account ac1(1000, 1000);

    EXPECT_EQ(1000, ac1.GetBalance());

    ac1.ChangeBalance(2000);

    EXPECT_EQ(2000, ac1.GetBalance());

    ac1.Lock();

    try
    {
        ac1.ChangeBalance(3000);
    }
    catch (const std::runtime_error &e)
    {
        std::string s1 = "already locked";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }

    try
    {
        ac1.Lock();
    }
    catch (const std::runtime_error &e)
    {
        std::string s1 = "at first lock the account";
        std::string s2 = e.what();
        EXPECT_EQ(s1, s2);
    }

    ac1.Unlock();
}

TEST(TRANSACTION, All)
{
	
		Account ac1(100, 100);
		Account ac2(100, 300);
		Transaction t1;
		t1.Make(ac2, ac1, 100);

		EXPECT_EQ(200, ac1.GetBalance());
		EXPECT_EQ(200, ac2.GetBalance());

		EXPECT_FALSE(t1.Make(ac2, ac1, 123));

		try
		{
			t1.Make(ac2, ac1, -10);
		}
		catch (const std::runtime_error &e)
		{
			std::string s1 = "sum can't be negative";
			std::string s2 = e.what();
			EXPECT_EQ(s1, s2);
		}
		try
		{
			t1.Make(ac2, ac1, 10);
		}
		catch (const std::runtime_error &e)
		{
			std::string s1 = "too small";
			std::string s2 = e.what();
			EXPECT_EQ(s1, s2);
		}
		try
		{
			t1.Make(ac2, ac2, 1011);
		}
		catch (const std::runtime_error &e)
		{
			std::string s1 = "invalid action";
			std::string s2 = e.what();
			EXPECT_EQ(s1, s2);
		}

		Transaction t1 //t2 //:: public t2;
		t1.Credit(ac2, 1000);

		EXPECT_EQ(ac2.GetBalance(), 1000);

		EXPECT_TRUE(t2.Debit(ac2, 800));
		EXPECT_FALSE(t2.Debit(ac2, 800));
}
