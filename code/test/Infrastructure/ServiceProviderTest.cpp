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

class IService
{
public:
    virtual void method() = 0;
};

class Service : public IService
{
public:
    void method() override
    {
    }
};

TEST_F(ServiceProviderTest, testCreation)
{
    auto serviceProvider = ServiceProvider::getInstance();
    EXPECT_NE(serviceProvider, nullptr);
}

TEST_F(ServiceProviderTest, testServiceRegistration)
{
    auto serviceProvider = ServiceProvider::getInstance();
    EXPECT_NE(serviceProvider, nullptr);

    EXPECT_FALSE(serviceProvider->hasService<IService>());

    auto service1 = std::make_shared<Service>();
    EXPECT_TRUE(serviceProvider->registerService<IService>(service1));
    EXPECT_EQ(service1, serviceProvider->getService<IService>());

    EXPECT_FALSE(serviceProvider->registerService<IService>(service1));

    auto service2 = std::make_shared<Service>();
    EXPECT_TRUE(serviceProvider->registerService<IService>(service2, true));
    EXPECT_NE(service1, serviceProvider->getService<IService>());
    EXPECT_EQ(service2, serviceProvider->getService<IService>());
}
