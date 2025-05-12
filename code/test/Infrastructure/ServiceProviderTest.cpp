// --------------------------------------------------------------------> START
// * INCLUDES
// ---------------------------------------------------------------------------
// Built-in includes

// Libraries includes
#include <gtest/gtest.h>

// Qt framework includes

// Project includes
#include "UIFramework/Infrastructure/ServiceProvider.hpp"
// <---------------------------------------------------------------------- END

using namespace testing;

class ServiceProviderTest : public Test
{
public:
    ServiceProviderTest() = default;

    ~ServiceProviderTest() override = default;

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(ServiceProviderTest, testCreation)
{
    auto serviceProvider = ServiceProvider::getInstance();
    EXPECT_NE(serviceProvider, nullptr);
}
