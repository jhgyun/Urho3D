// Copyright (c) 2008-2022 the Urho3D project
// License: MIT

#pragma once

#include "../Container/HashMap.h"
#include "../Container/Ptr.h"

namespace Urho3D
{

class Component;
class Node;

using ComponentId = id32;
using NodeId = id32;

/// Utility class that resolves node & component IDs after a scene or partial scene load.
class URHO3D_API SceneResolver
{
public:
    /// Construct.
    SceneResolver();
    /// Destruct.
    ~SceneResolver();

    /// Reset. Clear all remembered nodes and components.
    void Reset();
    /// Remember a created node.
    void AddNode(NodeId oldID, Node* node);
    /// Remember a created component.
    void AddComponent(ComponentId oldID, Component* component);
    /// Resolve component and node ID attributes and reset.
    void Resolve();

private:
    /// Nodes.
    HashMap<NodeId, WeakPtr<Node>> nodes_;
    /// Components.
    HashMap<ComponentId, WeakPtr<Component>> components_;
};

}
