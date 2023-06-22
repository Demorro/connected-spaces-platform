#pragma once

#include "Olympus/Common/String.h"
#include "Olympus/Multiplayer/ComponentBase.h"
#include "Olympus/Multiplayer/Components/Interfaces/IVisibleComponent.h"
#include "Olympus/Multiplayer/SpaceTransform.h"
#include "Olympus/OlympusCommon.h"


namespace oly_multiplayer
{

enum class StaticModelPropertyKeys
{
	Name = 0,
	ModelAssetId,
	AssetCollectionId,
	Position,
	Rotation,
	Scale,
	IsVisible,
	IsARVisible,
	Num
};


/// @ingroup StaticModelSpaceComponent
/// @brief Data representation of an StaticModelSpaceComponent.
class OLY_API StaticModelSpaceComponent : public ComponentBase, public IVisibleComponent
{
public:
	StaticModelSpaceComponent(SpaceEntity* Parent);

	[[deprecated("Due to the introduction of LODs it doesn't make sense to set a specific asset anymore")]] const oly_common::String&
		GetModelAssetId() const;

	[[deprecated("Due to the introduction of LODs it doesn't make sense to set a specific asset anymore")]] void
		SetModelAssetId(const oly_common::String& Value);

	const oly_common::String& GetAssetCollectionId() const;
	void SetAssetCollectionId(const oly_common::String& Value);
	const oly_common::Vector3& GetPosition() const;
	void SetPosition(const oly_common::Vector3& Value);
	const oly_common::Vector4& GetRotation() const;
	void SetRotation(const oly_common::Vector4& Value);
	const oly_common::Vector3& GetScale() const;
	void SetScale(const oly_common::Vector3& Value);

	/* IVisibleComponent */

	bool GetIsVisible() const override;
	void SetIsVisible(bool InValue) override;

	bool GetIsARVisible() const override;
	void SetIsARVisible(bool InValue) override;
};

} // namespace oly_multiplayer
