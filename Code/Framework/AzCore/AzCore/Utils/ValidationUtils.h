/*
* Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/Component/Component.h>
#include <AzCore/Component/Entity.h>
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Debug/Trace.h>
#include <AzCore/std/smart_ptr/shared_ptr.h>
#include <AzCore/std/typetraits/is_pointer.h>
#include <AzCore/Asset/AssetCommon.h>
#include <Atom/RPI.Public/View.h>
#include <Atom/RPI.Public/Scene.h>
#include <Atom/RPI.Public/RenderPipeline.h>

namespace AZ
{
    // ---------------------------------------------------------------
    //! Validates whether a pointer is non-null. General-purpose utility.
    //! @param object Pointer to any object to be validated.
    //! @return True if the pointer is non-null, false otherwise.
    template<typename T>
    [[maybe_unused]] inline bool IsValid(const T* object)
    {
        return object != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether a shared pointer is set.
    //! @param smartPtr AZStd::shared_ptr to any resource.
    //! @return True if the shared pointer contains an allocation, false if it's empty.
    template<typename T>
    [[maybe_unused]] inline bool IsValid(const AZStd::shared_ptr<T>& smartPtr)
    {
        return smartPtr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZStd::unique_ptr is non-null.
    //! @param uniquePtr AZStd::unique_ptr to be validated.
    //! @return True if the unique pointer is non-null, false otherwise.
    template<typename T>
    [[maybe_unused]] inline bool IsValid(const AZStd::unique_ptr<T>& uniquePtr)
    {
        return uniquePtr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::Entity is non-null and active.
    //! @param entity Pointer to an AZ::Entity.
    //! @return True if the entity is non-null and in the active state, false otherwise.
    template<>
    [[maybe_unused]] inline bool IsValid(const AZ::Entity* entity)
    {
        return entity && entity->GetState() == AZ::Entity::State::Active;
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::Component is non-null and attached to an active entity.
    //! @param component Pointer to an AZ::Component.
    //! @return True if the component and its associated entity are active, false otherwise.
    template<>
    [[maybe_unused]] inline bool IsValid(const AZ::Component* component)
    {
        return component && component->GetEntity() && component->GetEntity()->GetState() == AZ::Entity::State::Active;
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::Data::Asset object is valid and loaded.
    //! @param asset AZ::Data::Asset reference to be validated.
    //! @return True if the asset is valid and ready for use, false otherwise.
    template<typename T>
    [[maybe_unused]] inline bool IsValid(const AZ::Data::Asset<T>& asset)
    {
        return asset.IsReady() && asset.GetId().IsValid();
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::RHI::Ptr is non-null.
    //! @param ptr AZ::RHI::Ptr to be validated.
    //! @return True if the pointer is non-null, false otherwise.
    template<typename T>
    [[maybe_unused]] inline bool IsValid(const AZ::RHI::Ptr<T>& ptr)
    {
        return ptr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether a RenderPipeline pointer is non-null.
    //! @param ptr AZ::RPI::Ptr to the RenderPipeline to be validated.
    //! @return True if the pointer is non-null, false otherwise.
    template<typename T>
    [[maybe_unused]] inline bool IsValid(const AZ::RPI::Ptr<T>& ptr)
    {
        return ptr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether a ViewPtr for rendering is non-null.
    //! @param ptr AZ::RPI::ViewPtr to be validated.
    //! @return True if the pointer is non-null, false otherwise.
    [[maybe_unused]] inline bool IsValid(const AZ::RPI::ViewPtr& ptr)
    {
        return ptr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether a ScenePtr for rendering is non-null.
    //! @param ptr AZ::RPI::ScenePtr to be validated.
    //! @return True if the pointer is non-null, false otherwise.
    [[maybe_unused]] inline bool IsValid(const AZ::RPI::ScenePtr& ptr)
    {
        return ptr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether a RenderPipelinePtr is non-null.
    //! @param ptr AZ::RPI::RenderPipelinePtr to be validated.
    //! @return True if the render pipeline pointer is non-null, false otherwise.
    [[maybe_unused]] inline bool IsValid(const AZ::RPI::RenderPipelinePtr& ptr)
    {
        return ptr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::RHI::ShaderResourceGroupPtr is non-null.
    //! @param ptr AZ::RHI::ShaderResourceGroupPtr to be validated.
    //! @return True if the pointer is non-null, false otherwise.
    [[maybe_unused]] inline bool IsValid(const AZ::RHI::ShaderResourceGroupPtr& ptr)
    {
        return ptr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::RHI::PipelineStatePtr is non-null.
    //! @param ptr AZ::RHI::PipelineStatePtr to be validated.
    //! @return True if the pipeline state pointer is non-null, false otherwise.
    [[maybe_unused]] inline bool IsValid(const AZ::RHI::PipelineStatePtr& ptr)
    {
        return ptr != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether a Data::Instance is non-null.
    //! @param instance AZ::Data::Instance reference to be validated.
    //! @return True if the instance is non-null, false otherwise.
    template<typename T>
    [[maybe_unused]] inline bool IsValid(const AZ::Data::Instance<T>& instance)
    {
        return instance != nullptr;
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::Outcome is successful.
    //! @param outcome AZ::Outcome object to be validated.
    //! @return True if the outcome is successful, false otherwise.
    template<typename T, typename E>
    [[maybe_unused]] inline bool IsValid(const AZ::Outcome<T, E>& outcome)
    {
        return outcome.IsSuccess();
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::Job pointer is non-null and not cancelled.
    //! @param job Pointer to an AZ::Job.
    //! @return True if the job is non-null and not cancelled, false otherwise.
    [[maybe_unused]] inline bool IsValid(const AZ::Job* job)
    {
        return job && !job->IsCancelled();
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::EBus is connected.
    //! @param bus AZ::EBus instance to be validated.
    //! @return True if the bus is connected, false otherwise.
    template<typename T>
    [[maybe_unused]] inline bool IsValid(const AZ::EBus<T>& bus)
    {
        return bus.IsConnected();
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::SerializeContext is initialized and ready.
    //! @param context Pointer to an AZ::SerializeContext.
    //! @return True if the context is non-null and ready, false otherwise.
    [[maybe_unused]] inline bool IsValid(const AZ::SerializeContext* context)
    {
        return context && context->IsReady();
    }

    // ---------------------------------------------------------------
    //! Validates whether an AZ::TickBus is connected.
    //! @param tickBus AZ::TickBus reference to be validated.
    //! @return True if the tick bus is connected, false otherwise.
    [[maybe_unused]] inline bool IsValid(const AZ::TickBus& tickBus)
    {
        return tickBus.IsConnected();
    }

} // namespace AZ
