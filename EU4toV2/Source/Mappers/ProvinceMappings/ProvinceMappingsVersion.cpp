#include "ProvinceMappingsVersion.h"
#include "ParserHelpers.h"

mappers::ProvinceMappingsVersion::ProvinceMappingsVersion(const std::string& versionString, std::istream& theStream)
{
	registerKeys();
	parseStream(theStream);
	clearRegisteredKeywords();
	version = GameVersion(versionString);
}

void mappers::ProvinceMappingsVersion::registerKeys()
{
	registerKeyword("link", [this](const std::string& unused, std::istream& theStream) {
		const ProvinceMapping newMapping(theStream);
		if (newMapping.getEU4Provinces().empty() && newMapping.getVic2Provinces().empty())
			return; // comment.
		mappings.push_back(newMapping);
	});
	registerRegex(commonItems::catchallRegex, commonItems::ignoreItem);
}
