/*
 * Copyright 2023 Magnopus LLC

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/// @file ButtonSpaceComponent.h
/// @brief Definitions and support for button components.

#pragma once

#include "CSP/CSPCommon.h"
#include "CSP/Common/String.h"
#include "CSP/Multiplayer/ComponentBase.h"
#include "CSP/Multiplayer/Components/Interfaces/IEnableableComponent.h"
#include "CSP/Multiplayer/Components/Interfaces/IVisibleComponent.h"
#include "CSP/Multiplayer/SpaceTransform.h"


namespace csp::multiplayer
{

/// @brief Enumerates the list of properties that can be replicated for a button component.
enum class ButtonPropertyKeys
{
	Name = 0,
	LabelText,
	IconAssetId,
	AssetCollectionId,
	Position,
	Rotation,
	Scale,
	IsVisible,
	IsEnabled,
	IsARVisible,
	Num
};


/// @ingroup ButtonSpaceComponent
/// @brief Data representation of an ButtonSpaceComponent.
class CSP_API ButtonSpaceComponent : public ComponentBase, public IEnableableComponent, public IVisibleComponent
{
public:
	/// @brief Constructs the button space component, and associates it with the specified Parent space entity.
	/// @param Parent The Space entity that owns this component.
	ButtonSpaceComponent(SpaceEntity* Parent);

	/// @brief Gets the text of the label of this button.
	/// @return The text on the label of this button.
	const csp::common::String& GetLabelText() const;

	/// @brief Sets the text of the label of this button.
	/// @param Value The text on the label of this button.
	void SetLabelText(const csp::common::String& Value);

	/// @brief Gets the ID of the icon asset associated with the button of this component.
	/// @note This is used to show a specific icon on the button by ID.
	/// @return The ID of the icon asset associated with the button of this component.
	const csp::common::String& GetIconAssetId() const;

	/// @brief Sets the ID of the icon asset associated with the button of this component.
	/// @note This is used to show a specific icon on the button by ID.
	/// @param Value The ID of the icon asset associated with the button of this component.
	void SetIconAssetId(const csp::common::String& Value);

	/// @brief Gets the ID of the asset collection associated with this component.
	/// @note To retrieve this component's button asset, both the Asset ID and the Asset Collection ID are required.
	/// @return The ID of the asset collection associated with this component.
	const csp::common::String& GetAssetCollectionId() const;

	/// @brief Sets the ID of the asset collection associated with this component.
	/// @note To retrieve this component's button asset, both the Asset ID and the Asset Collection ID are required.
	/// @param Value The ID of the asset collection associated with this component.
	void SetAssetCollectionId(const csp::common::String& Value);

	/// @brief Gets the position of the origin of this component in world space.
	/// @note The coordinate system used follows the glTF 2.0 specification, in meters.
	///       - Right handed coordinate system
	///       - +Y is UP
	///       - +X is left (facing forward)
	///       - +Z is forward
	/// @return The 3D position as vector (left, up, forward) in meters.
	const csp::common::Vector3& GetPosition() const;

	/// @brief Sets the position of the origin of this component in world space.
	/// @note The coordinate system used follows the glTF 2.0 specification, in meters.
	///       - Right handed coordinate system
	///       - +Y is UP
	///       - +X is left (facing forward)
	///       - +Z is forward
	void SetPosition(const csp::common::Vector3& Value);

	/// @brief Gets a quaternion representing the rotation of the origin of this component, expressed in radians.
	/// @note The coordinate system respects the following conventions:
	///       - Right handed coordinate system
	///       - Positive rotation is counterclockwise
	///       - The geographic North is along the positive Z axis (+Z) at an orientation of 0 degrees.
	///       - North: +Z
	///       - East: -X
	///       - South: -Z
	///       - West: +X
	const csp::common::Vector4& GetRotation() const;

	/// @brief Sets the rotation of the origin of this component according to the specified quaternion "Value", expressed in radians.
	/// @note The coordinate system respects the following conventions:
	///       - Right handed coordinate system
	///       - Positive rotation is counterclockwise
	///       - The geographic North is along the positive Z axis (+Z) at an orientation of 0 degrees.
	///       - North: +Z
	///       - East: -X
	///       - South: -Z
	///       - West: +X
	/// @param Value The quaternion in radians to use as new rotation of this component.
	void SetRotation(const csp::common::Vector4& Value);

	/// @brief Gets the scale of the origin of this component in world space.
	/// @note The coordinate system used follows the glTF 2.0 specification.
	///       - Right handed coordinate system
	///       - +Y is UP
	///       - +X is left (facing forward)
	///       - +Z is forward
	/// @return The 3D scale as vector (left, up, forward).
	const csp::common::Vector3& GetScale() const;

	/// @brief Sets the scale of the origin of this component in world space to the specified "Value".
	/// @param Value The new value expressed as vector (left, up, forward).
	/// @note The coordinate system used follows the glTF 2.0 specification.
	///       - Right handed coordinate system
	///       - +Y is UP
	///       - +X is left (facing forward)
	///       - +Z is forward
	void SetScale(const csp::common::Vector3& Value);


	/// \addtogroup IClickableComponent
	/// @{
	/// @copydoc IClickableComponent::GetIsEnabled()
	bool GetIsEnabled() const override;
	/// @copydoc IClickableComponent::SetIsEnabled()
	void SetIsEnabled(bool InValue) override;
	/// @}


	/* IVisibleComponent */
	/// \addtogroup IVisibleComponent
	/// @{
	/// @copydoc IVisibleComponent::GetIsVisible()
	bool GetIsVisible() const override;
	/// @copydoc IVisibleComponent::SetIsVisible()
	void SetIsVisible(bool InValue) override;
	/// @copydoc IVisibleComponent::GetIsARVisible()
	bool GetIsARVisible() const override;
	/// @copydoc IVisibleComponent::SetIsARVisible()
	void SetIsARVisible(bool InValue) override;
	/// @}
};

} // namespace csp::multiplayer
