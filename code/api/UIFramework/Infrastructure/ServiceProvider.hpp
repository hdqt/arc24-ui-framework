#pragma once

// --------------------------------------------------------------------> START
// * INCLUDES
// ---------------------------------------------------------------------------
// Built-in includes
#include <map>
#include <memory>
#include <mutex>
#include <typeindex>

// Libraries includes

// Qt framework includes

// Project includes
// <---------------------------------------------------------------------- END

// --------------------------------------------------------------------> START
// * CLASSES DECLARATION
// ---------------------------------------------------------------------------

// <---------------------------------------------------------------------- END

class ServiceProvider
{
public:
    // ***********************************************************************
    // * PUBLIC FUNCTIONS
    // ***********************************************************************
    static std::shared_ptr<ServiceProvider> getInstance();

    static bool clearInstance();

    template <typename ServiceType>
    bool hasService()
    {
        std::lock_guard<std::mutex> lock{m_accessMutex};
        auto serviceId = std::type_index(typeid(ServiceType));
        return m_serviceRegistry.count(serviceId) != 0;
    }

    template <typename ServiceType>
    std::shared_ptr<ServiceType> getService()
    {
        std::lock_guard<std::mutex> lock{m_accessMutex};
        auto serviceId = std::type_index(typeid(ServiceType));
        std::shared_ptr<ServiceType> service{nullptr};
        if (m_serviceRegistry.count(serviceId))
        {
            service = std::static_pointer_cast<ServiceType>(m_serviceRegistry.at(serviceId));
        }
        return service;
    }

    template <typename ServiceType>
    bool registerService(std::shared_ptr<ServiceType> service, bool overwrite = false)
    {
        std::lock_guard<std::mutex> lock{m_accessMutex};
        auto serviceId = std::type_index(typeid(ServiceType));
        bool status{false};
        if (overwrite || m_serviceRegistry.count(serviceId) == 0)
        {
            m_serviceRegistry[serviceId] = service;
            status = true;
        }
        return status;
    }

    // ***********************************************************************
    // * PUBLIC VARIABLES
    // ***********************************************************************

protected:
    // ***********************************************************************
    // * PROTECTED FUNCTIONS
    // ***********************************************************************

    // ***********************************************************************
    // * PROTECTED VARIABLES
    // ***********************************************************************

private:
    // ***********************************************************************
    // * PRIVATE FUNCTIONS
    // ***********************************************************************

    // ***********************************************************************
    // * PRIVATE VARIABLES
    // ***********************************************************************
    static std::shared_ptr<ServiceProvider> m_instance;
    static std::mutex m_creationMutex;

    std::mutex m_accessMutex;
    std::map<std::type_index, std::shared_ptr<void>> m_serviceRegistry;
};
