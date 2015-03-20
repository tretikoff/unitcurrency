#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include <boost/test/unit_test.hpp>

#include "util.h"

BOOST_AUTO_TEST_SUITE(getarg_tests)

static void
ResetArgs(const std::string& strArg)
{
    std::vector<std::string> vecArg;
    boost::split(vecArg, strArg, boost::is_space(), boost::token_compress_on);

    // Insert dummy executable name:
    vecArg.insert(vecArg.begin(), "testbitcoin");

    // Convert to char*:
    std::vector<const char*> vecChar;
    BOOST_FOREACH(std::string& s, vecArg)
        vecChar.push_back(s.c_str());

    ParseParameters(vecChar.size(), &vecChar[0]);
}

BOOST_AUTO_TEST_CASE(boolarg)
{
    ResetArgs("-unit");
    BOOST_CHECK(GetBoolArg("-unit"));
    BOOST_CHECK(GetBoolArg("-unit", false));
    BOOST_CHECK(GetBoolArg("-unit", true));

    BOOST_CHECK(!GetBoolArg("-fo"));
    BOOST_CHECK(!GetBoolArg("-fo", false));
    BOOST_CHECK(GetBoolArg("-fo", true));

    BOOST_CHECK(!GetBoolArg("-unito"));
    BOOST_CHECK(!GetBoolArg("-unito", false));
    BOOST_CHECK(GetBoolArg("-unito", true));

    ResetArgs("-unit=0");
    BOOST_CHECK(!GetBoolArg("-unit"));
    BOOST_CHECK(!GetBoolArg("-unit", false));
    BOOST_CHECK(!GetBoolArg("-unit", true));

    ResetArgs("-unit=1");
    BOOST_CHECK(GetBoolArg("-unit"));
    BOOST_CHECK(GetBoolArg("-unit", false));
    BOOST_CHECK(GetBoolArg("-unit", true));

    // New 0.6 feature: auto-map -nosomething to !-something:
    ResetArgs("-nounit");
    BOOST_CHECK(!GetBoolArg("-unit"));
    BOOST_CHECK(!GetBoolArg("-unit", false));
    BOOST_CHECK(!GetBoolArg("-unit", true));

    ResetArgs("-nounit=1");
    BOOST_CHECK(!GetBoolArg("-unit"));
    BOOST_CHECK(!GetBoolArg("-unit", false));
    BOOST_CHECK(!GetBoolArg("-unit", true));

    ResetArgs("-unit -nounit");  // -unit should win
    BOOST_CHECK(GetBoolArg("-unit"));
    BOOST_CHECK(GetBoolArg("-unit", false));
    BOOST_CHECK(GetBoolArg("-unit", true));

    ResetArgs("-unit=1 -nounit=1");  // -unit should win
    BOOST_CHECK(GetBoolArg("-unit"));
    BOOST_CHECK(GetBoolArg("-unit", false));
    BOOST_CHECK(GetBoolArg("-unit", true));

    ResetArgs("-unit=0 -nounit=0");  // -unit should win
    BOOST_CHECK(!GetBoolArg("-unit"));
    BOOST_CHECK(!GetBoolArg("-unit", false));
    BOOST_CHECK(!GetBoolArg("-unit", true));

    // New 0.6 feature: treat -- same as -:
    ResetArgs("--unit=1");
    BOOST_CHECK(GetBoolArg("-unit"));
    BOOST_CHECK(GetBoolArg("-unit", false));
    BOOST_CHECK(GetBoolArg("-unit", true));

    ResetArgs("--nounit=1");
    BOOST_CHECK(!GetBoolArg("-unit"));
    BOOST_CHECK(!GetBoolArg("-unit", false));
    BOOST_CHECK(!GetBoolArg("-unit", true));

}

BOOST_AUTO_TEST_CASE(stringarg)
{
    ResetArgs("");
    BOOST_CHECK_EQUAL(GetArg("-unit", ""), "");
    BOOST_CHECK_EQUAL(GetArg("-unit", "eleven"), "eleven");

    ResetArgs("-unit -bar");
    BOOST_CHECK_EQUAL(GetArg("-unit", ""), "");
    BOOST_CHECK_EQUAL(GetArg("-unit", "eleven"), "");

    ResetArgs("-unit=");
    BOOST_CHECK_EQUAL(GetArg("-unit", ""), "");
    BOOST_CHECK_EQUAL(GetArg("-unit", "eleven"), "");

    ResetArgs("-unit=11");
    BOOST_CHECK_EQUAL(GetArg("-unit", ""), "11");
    BOOST_CHECK_EQUAL(GetArg("-unit", "eleven"), "11");

    ResetArgs("-unit=eleven");
    BOOST_CHECK_EQUAL(GetArg("-unit", ""), "eleven");
    BOOST_CHECK_EQUAL(GetArg("-unit", "eleven"), "eleven");

}

BOOST_AUTO_TEST_CASE(intarg)
{
    ResetArgs("");
    BOOST_CHECK_EQUAL(GetArg("-unit", 11), 11);
    BOOST_CHECK_EQUAL(GetArg("-unit", 0), 0);

    ResetArgs("-unit -bar");
    BOOST_CHECK_EQUAL(GetArg("-unit", 11), 0);
    BOOST_CHECK_EQUAL(GetArg("-bar", 11), 0);

    ResetArgs("-unit=11 -bar=12");
    BOOST_CHECK_EQUAL(GetArg("-unit", 0), 11);
    BOOST_CHECK_EQUAL(GetArg("-bar", 11), 12);

    ResetArgs("-unit=NaN -bar=NotANumber");
    BOOST_CHECK_EQUAL(GetArg("-unit", 1), 0);
    BOOST_CHECK_EQUAL(GetArg("-bar", 11), 0);
}

BOOST_AUTO_TEST_CASE(doubledash)
{
    ResetArgs("--unit");
    BOOST_CHECK_EQUAL(GetBoolArg("-unit"), true);

    ResetArgs("--unit=verbose --bar=1");
    BOOST_CHECK_EQUAL(GetArg("-unit", ""), "verbose");
    BOOST_CHECK_EQUAL(GetArg("-bar", 0), 1);
}

BOOST_AUTO_TEST_CASE(boolargno)
{
    ResetArgs("-nounit");
    BOOST_CHECK(!GetBoolArg("-unit"));
    BOOST_CHECK(!GetBoolArg("-unit", true));
    BOOST_CHECK(!GetBoolArg("-unit", false));

    ResetArgs("-nounit=1");
    BOOST_CHECK(!GetBoolArg("-unit"));
    BOOST_CHECK(!GetBoolArg("-unit", true));
    BOOST_CHECK(!GetBoolArg("-unit", false));

    ResetArgs("-nounit=0");
    BOOST_CHECK(GetBoolArg("-unit"));
    BOOST_CHECK(GetBoolArg("-unit", true));
    BOOST_CHECK(GetBoolArg("-unit", false));

    ResetArgs("-unit --nounit");
    BOOST_CHECK(GetBoolArg("-unit"));

    ResetArgs("-nounit -unit"); // unit always wins:
    BOOST_CHECK(GetBoolArg("-unit"));
}

BOOST_AUTO_TEST_SUITE_END()
