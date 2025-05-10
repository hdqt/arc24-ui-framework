#include "UIFramework/Infrastructure/ServiceProvider.hpp"

// --------------------------------------------------------------------> START
// * INCLUDES
// ---------------------------------------------------------------------------
// Built-in includes
#include <atomic>

// Libraries includes

// Qt framework includes

// Project includes
// <---------------------------------------------------------------------- END

// --------------------------------------------------------------------> START
// * GLOBAL DEFINITIONS
// ---------------------------------------------------------------------------
std::shared_ptr<ServiceProvider> ServiceProvider::m_instance;
std::mutex ServiceProvider::m_creationMutex;

// <---------------------------------------------------------------------- END


// ***************************************************************************
// * PUBLIC FUNCTIONS
// ***************************************************************************
std::shared_ptr<ServiceProvider> ServiceProvider::getInstance()
{
    auto instance = std::atomic_load(&m_instance);
    if (instance == nullptr)
    {
        std::lock_guard<std::mutex> lock{m_creationMutex};
        instance = std::atomic_load(&m_instance);
        if (instance == nullptr)
        {
            struct ServiceProviderInstantiateHelper : public ServiceProvider
            {
            };
            instance = std::make_shared<ServiceProviderInstantiateHelper>();
            std::atomic_store(&m_instance, instance);
        }
    }
    return instance;
}

bool ServiceProvider::clearInstance()
{
    bool status{false};
    std::lock_guard<std::mutex> lock{m_creationMutex};
    auto instance = std::atomic_load(&m_instance);
    if (instance)
    {
        std::atomic_store(&m_instance, std::shared_ptr<ServiceProvider>(nullptr));
        status = true;
    }
    return status;
}


// ***************************************************************************
// * PROTECTED FUNCTIONS
// ***************************************************************************


// ***************************************************************************
// * PRIVATE FUNCTIONS
// ***************************************************************************
